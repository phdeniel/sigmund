#!/usr/bin/env python

import os
import stat
import space9
from threading import Thread

CHMOD_MASK=0777
CHMOD_NONE=0
CHMOD_RW=0666
woflags = space9.O_WRONLY|space9.O_CREAT|space9.O_TRUNC
roflags = space9.O_RDONLY
DSIZE=1048576
BUFSZ=8192

def dirtree(handle, lev, files, dirs, fname, dname, currentdir) :
        if lev == 1 :
                return
        f = 0
        d = 0
        for f in range(0,files) :
                name= "%s/%s%d" % (currentdir, fname, f)
                fid = handle.open( name, space9.O_RDWR | space9.O_CREAT, 0644 )
                fid.clunk()
        for d in range(0, dirs) :
                name= "%s/%s%d" % (currentdir, dname, d)
                handle.mkdir( name, 0777 )
                dirtree( handle, lev-1, files, dirs, fname, dname, name )
        return

def rmdirtree(handle, lev, files, dirs, fname, dname, currentdir) :
        if lev == 1 :
                return
        f = 0
        d = 0
        for f in range(0,files) :
                name= "%s/%s%d" % (currentdir, fname, f)
                handle.rm( name )
        for d in range(0, dirs) :
                name= "%s/%s%d" % (currentdir, dname, d)
                rmdirtree( handle, lev-1, files, dirs, fname, dname, name )
		handle.rm( name ) 
        return

def test1( handle, levels, files, dirs, fname, dname, currentdir ):
	return dirtree(  handle, levels, files, dirs, fname, dname, currentdir )


def test2( handle, levels, files, dirs, fname, dname, currentdir ):
	return rmdirtree(  handle, levels, files, dirs, fname, dname, currentdir )

def test4( handle, count, files, fname, dname, currentdir ):
	dirtree( handle, 2, files, 0, fname, dname, currentdir )
	
	for c in range( 0, count ) :
		for fi in range( 0, files ) :
			name = "%s/%s%d" % (currentdir, fname, fi ) 

			handle.chmod( name, CHMOD_NONE ) 
			bufstat = handle.stat( name ) 
                	if (bufstat['mode'] &  CHMOD_MASK )!= 0 :
				print "Error file ", name, "has mode ", bufstat['mode'], "should be ", CHMOD_NONE
				exit( 1 ) 
		
			handle.chmod( name, CHMOD_RW ) # CHMOD_RW = 0666 
			bufstat = handle.stat( name ) 
                	if (bufstat['mode'] & CHMOD_MASK ) != CHMOD_RW:
				print "Error file ", name, "has mode ", bufstat['mode'], "should be ", CHMOD_RW 
				exit( 1 ) 
	rmdirtree( handle, 2, files, 0, fname, dname, currentdir )

def test5( handle, size, bufsz, currentdir ):
	name = "%s/bigfile" % (currentdir )
	buf=""
	for i in range( 0, bufsz ):
		buf += "%d" % (i%10)

	filefid = handle.open( name, woflags, CHMOD_RW )

	bufstat = handle.stat( name ) 
	if bufstat['size'] != 0 :
		print "File ", name, " does not have size 0"

	si = size 
	while si > 0 :
		bytes = min( bufsz, si )
		filefid.write( buf, bytes )
		si -= bufsz
	filefid.clunk() 

	bufstat = handle.stat( name ) 
	if bufstat['size'] != size :
		print "File ", name, " does not have size ", size

	handle.rm( name )


def test6( handle, count, files, fname, dname, currentdir ):
	dirtree( handle, 2, files, 0, fname, dname, currentdir )
	
	for c in range( 0, count ) :
		dot = 0 
		dotdot = 0 
		dirlist = handle.ls( currentdir ) 
		for dirent in dirlist:
			if dirent == ".":
				if dot == 1 :
					print "Error '.' dirent read twice !!!!" 		
					exit( 1 ) 
				dot = 1 
	
			if dirent == "..":
				if dotdot == 1 :
					print "Error '..' dirent read twice !!!!" 		
					exit( 1 ) 
	
				dotdot = 1 
	
	dirlist =  handle.ls( currentdir ) 
	while dirlist != ['.', '..'] :
		lastdirent=dirlist[-1]
		name= "%s/%s" % (currentdir, lastdirent )
		handle.rm( name )
		dirlist = handle.ls( currentdir) 

def test7(  handle, count, files, fname, dname, nname, currentdir ):
	dirtree( handle, 2, files, 0, fname, dname, currentdir )
	
	for c in range( 0, count ) :
		for fi in range( 0, files ) :
			str = "%s/%s%d" % (currentdir, fname, fi )
			new = "%s/%s%d" % (currentdir, nname, fi )
			handle.mv( str, new ) 
			error= 0 
			try:
				handle.stat( str )  # Should fail
			except IOError:
				error=1
			if error == 0 :
				print "Error, file ", str, "should not be there"
				exit( 1 ) 
	
	
			bufstat = handle.stat( new ) # Should succeed
			if bufstat['nlink'] != 1:
				print "Error: file ", new, "has ", bufstat['nlink'], " after rename (expect 1)" 	
				exit( 1 ) 
	
			handle.link( new, str ) 
			bufstat = handle.stat( new )
			if bufstat['nlink'] != 2:
				print "Error: file ", new, "has ", bufstat['nlink'], " after rename (expect 1)" 	
				exit( 1 ) 
			
			handle.stat( str ) # Should now succeed 
	
			handle.rm( new ) 
			bufstat = handle.stat( str )
			if bufstat['nlink'] != 1:
				print "Error: file ", str, "has ", bufstat['nlink'], " after rename (expect 1)" 	
				exit( 1 ) 
	rmdirtree( handle, 2, files, 0, fname, dname, currentdir )

def test8( handle, count, files, fname, sname, currentdir ):
	for c in range( 0, count ) :
		for fi in range( 0, files ) :
			str = "%s/%s%d" % (currentdir, fname, fi )
			new = "%s%d" % (sname, fi )

			handle.symlink(new, str)

			bufstat = handle.lstat( str ) 
			if not stat.S_ISLNK(bufstat['mode']) :
				print "Error ", str, " is not a symlink"

			linkcontent = handle.readlink( str ) 
			if linkcontent != new :
				print "Error ", str, " has bad content ", linkcontent
			handle.rm( str ) 

def test9( handle, count ):
	for c in range( 0, count ) :
		handle.statfs() 

def cthon04( handle, levels, count, files, dirs, fname, dname, nname, sname,  dsize, bufsz, currentdir):
	print "==== Test 1: ", currentdir, " ===="
	test1( handle, levels, files, dirs, fname, dname, currentdir )

	print "==== Test 2: ", currentdir, " ===="
	test2( handle, levels, files, dirs, fname, dname, currentdir )

	print "==== Test 4: ", currentdir, " ===="
	test4( handle, count, files, fname, dname, currentdir )

	print "==== Test 5: ", currentdir, " ===="
	test5( handle, DSIZE, BUFSZ, currentdir )

	print "==== Test 6: ", currentdir, " ===="
	test6( handle, count, files, fname, dname, currentdir )

	print "==== Test 7: ", currentdir, " ===="
	test7(  handle, count, files, fname, dname, nname, currentdir )

	print "==== Test 8: ", currentdir, " ===="
	test8( handle, count, files, fname, sname, currentdir )

	print "==== Test 9: ", currentdir, " ===="
	test9( handle, count )

def cthon04_thread( myrank, iter, currentdir ):
	my_currentdir = "%s/thread.%u.%u" % (currentdir, os.getpid(), myrank )
	handle = space9.p9_handle( "./sample.conf")
	handle.mkdir( my_currentdir, 0777 )
	for i in range( 0, iter ):
		cthon04( handle, base_levels, base_count, base_files, base_dirs, base_fname, base_dname, base_nname, base_sname,  DSIZE, BUFSZ, 
			 my_currentdir)
	handle.rm( my_currentdir ) 


# MAIN
base_files=5
base_dirs=3
base_dname="dir."
base_fname="file."
base_nname="newfile."
base_sname="/this/is/a/symlink" 
base_currentdir="deniel/mine"
base_count=50
base_levels=5

nbthread=1
nbiter=2 

for i in range( 0, nbthread ):
	Thread(target = cthon04_thread, args = (i, nbiter, base_currentdir )).start()
