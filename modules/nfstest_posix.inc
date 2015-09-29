#!/bin/bash

########################## TEST HELPERS ##################

function test_nfstest
{
  mytest=$2

  nfstest_posix --server=$NFSTEST_SERVER --export=$NFSTEST_EXPORT \
	--runtest=$mytest --nomount --mtpoint=`pwd`
}

############################ TEST FUNCTIONS ############################

### testnfsposix00: nfstest_posix tests related to access
SPEED[testnfsposix00]=fast
TEST_TYPE[testnfsposix00]=dev,admin,skip
NEEDS_ROOT[testnfsposix00]=yes
function testnfsposix00
{
    export -f test_nfstest

    test_nfstest posixnfs0 access
}

### testnfsposix01: nfstest_posix tests related to chdir
SPEED[testnfsposix01]=fast
TEST_TYPE[testnfsposix01]=dev,admin
NEEDS_ROOT[testnfsposix01]=yes
function testnfsposix01
{
    export -f test_nfstest

    test_nfstest posixnfs1 chdir
}

### testnfsposix02: nfstest_posix tests related to creat
SPEED[testnfsposix02]=fast
TEST_TYPE[testnfsposix02]=dev,admin
NEEDS_ROOT[testnfsposix02]=yes
function testnfsposix02
{
    export -f test_nfstest

    test_nfstest posixnfs2 creat
}

### testnfsposix03: nfstest_posix tests related to fcntl
SPEED[testnfsposix03]=fast
TEST_TYPE[testnfsposix03]=dev,admin
NEEDS_ROOT[testnfsposix03]=yes
function testnfsposix03
{
    export -f test_nfstest

    test_nfstest posixnfs3 fcntl
}

### testnfsposix04: nfstest_posix tests related to fdatasync
SPEED[testnfsposix04]=fast
TEST_TYPE[testnfsposix04]=dev,admin
NEEDS_ROOT[testnfsposix04]=yes
function testnfsposix04
{
    export -f test_nfstest

    test_nfstest posixnfs4 fdatasync
}

### testnfsposix05: nfstest_posix tests related to fstat
SPEED[testnfsposix05]=fast
TEST_TYPE[testnfsposix05]=dev,admin
NEEDS_ROOT[testnfsposix05]=yes
function testnfsposix05
{
    export -f test_nfstest

    test_nfstest posixnfs5 fstat
}

### testnfsposix06: nfstest_posix tests related to fstatvfs
SPEED[testnfsposix06]=fast
TEST_TYPE[testnfsposix06]=dev,admin
NEEDS_ROOT[testnfsposix06]=yes
function testnfsposix06
{
    export -f test_nfstest

    test_nfstest posixnfs6 fstatvfs
}

### testnfsposix07: nfstest_posix tests related to fsync
SPEED[testnfsposix07]=fast
TEST_TYPE[testnfsposix07]=dev,admin
NEEDS_ROOT[testnfsposix07]=yes
function testnfsposix07
{
    export -f test_nfstest

    test_nfstest posixnfs7 fsync
}

### testnfsposix08: nfstest_posix tests related to link
SPEED[testnfsposix08]=fast
TEST_TYPE[testnfsposix08]=dev,admin
NEEDS_ROOT[testnfsposix08]=yes
function testnfsposix08
{
    export -f test_nfstest

    test_nfstest posixnfs8 link
}

### testnfsposix09: nfstest_posix tests related to lseek
SPEED[testnfsposix09]=fast
TEST_TYPE[testnfsposix09]=dev,admin
NEEDS_ROOT[testnfsposix09]=yes
function testnfsposix09
{
    export -f test_nfstest

    test_nfstest posixnfs9 lseek
}

### testnfsposix10: nfstest_posix tests related to lstat
SPEED[testnfsposix10]=fast
TEST_TYPE[testnfsposix10]=dev,admin
NEEDS_ROOT[testnfsposix10]=yes
function testnfsposix10
{
    export -f test_nfstest

    test_nfstest posixnfs10 lstat
}

### testnfsposix11: nfstest_posix tests related to mkdir
SPEED[testnfsposix11]=fast
TEST_TYPE[testnfsposix11]=dev,admin
NEEDS_ROOT[testnfsposix11]=yes
function testnfsposix11
{
    export -f test_nfstest

    test_nfstest posixnfs11 mkdir
}

### testnfsposix12: nfstest_posix tests related to opendir
SPEED[testnfsposix12]=fast
TEST_TYPE[testnfsposix12]=dev,admin
NEEDS_ROOT[testnfsposix12]=yes
function testnfsposix12
{
    export -f test_nfstest

    test_nfstest posixnfs12 opendir
}

### testnfsposix13: nfstest_posix tests related to read
SPEED[testnfsposix13]=fast
TEST_TYPE[testnfsposix13]=dev,admin
NEEDS_ROOT[testnfsposix13]=yes
function testnfsposix13
{
    export -f test_nfstest

    test_nfstest posixnfs13 read
}

### testnfsposix14: nfstest_posix tests related to readdir
SPEED[testnfsposix14]=fast
TEST_TYPE[testnfsposix14]=dev,admin
NEEDS_ROOT[testnfsposix14]=yes
function testnfsposix14
{
    export -f test_nfstest

    test_nfstest posixnfs14 readdir
}

### testnfsposix15: nfstest_posix tests related to readlink
SPEED[testnfsposix15]=fast
TEST_TYPE[testnfsposix15]=dev,admin
NEEDS_ROOT[testnfsposix15]=yes
function testnfsposix15
{
    export -f test_nfstest

    test_nfstest posixnfs15 readlink
}

### testnfsposix16: nfstest_posix tests related to rename
SPEED[testnfsposix16]=fast
TEST_TYPE[testnfsposix16]=dev,admin
NEEDS_ROOT[testnfsposix16]=yes
function testnfsposix16
{
    export -f test_nfstest

    test_nfstest posixnfs16 rename
}

### testnfsposix17: nfstest_posix tests related to rewinddir
SPEED[testnfsposix17]=fast
TEST_TYPE[testnfsposix17]=dev,admin
NEEDS_ROOT[testnfsposix17]=yes
function testnfsposix17
{
    export -f test_nfstest

    test_nfstest posixnfs17 rewinddir
}

### testnfsposix18: nfstest_posix tests related to rmdir
SPEED[testnfsposix18]=fast
TEST_TYPE[testnfsposix18]=dev,admin
NEEDS_ROOT[testnfsposix18]=yes
function testnfsposix18
{
    export -f test_nfstest

    test_nfstest posixnfs18 rmdir
}

### testnfsposix19: nfstest_posix tests related to seekdir
SPEED[testnfsposix19]=fast
TEST_TYPE[testnfsposix19]=dev,admin,skip
NEEDS_ROOT[testnfsposix19]=yes
function testnfsposix19
{
    export -f test_nfstest

    test_nfstest posixnfs19 seekdir
}

### testnfsposix20: nfstest_posix tests related to stat
SPEED[testnfsposix20]=fast
TEST_TYPE[testnfsposix20]=dev,admin
NEEDS_ROOT[testnfsposix20]=yes
function testnfsposix20
{
    export -f test_nfstest

    test_nfstest posixnfs20 stat
}

### testnfsposix21: nfstest_posix tests related to statvfs
SPEED[testnfsposix21]=fast
TEST_TYPE[testnfsposix21]=dev,admin
NEEDS_ROOT[testnfsposix21]=yes
function testnfsposix21
{
    export -f test_nfstest

    test_nfstest posixnfs21 statvfs
}

### testnfsposix22: nfstest_posix tests related to symlink
SPEED[testnfsposix22]=fast
TEST_TYPE[testnfsposix22]=dev,admin
NEEDS_ROOT[testnfsposix22]=yes
function testnfsposix22
{
    export -f test_nfstest

    test_nfstest posixnfs22 symlink
}

### testnfsposix23: nfstest_posix tests related to sync
SPEED[testnfsposix23]=fast
TEST_TYPE[testnfsposix23]=dev,admin
NEEDS_ROOT[testnfsposix23]=yes
function testnfsposix23
{
    export -f test_nfstest

    test_nfstest posixnfs23 sync
}

### testnfsposix24: nfstest_posix tests related to telldir
SPEED[testnfsposix24]=fast
TEST_TYPE[testnfsposix24]=dev,admin,skip
NEEDS_ROOT[testnfsposix24]=yes
function testnfsposix24
{
    export -f test_nfstest

    test_nfstest posixnfs24 telldir
}

### testnfsposix25: nfstest_posix tests related to unlink
SPEED[testnfsposix25]=fast
TEST_TYPE[testnfsposix25]=dev,admin
NEEDS_ROOT[testnfsposix25]=yes
function testnfsposix25
{
    export -f test_nfstest

    test_nfstest posixnfs25 unlink
}

### testnfsposix26: nfstest_posix tests related to write
SPEED[testnfsposix26]=fast
TEST_TYPE[testnfsposix26]=dev,admin
NEEDS_ROOT[testnfsposix26]=yes
function testnfsposix26
{
    export -f test_nfstest

    test_nfstest posixnfs26 write
}

### testnfsposix27: nfstest_posix tests related to open
SPEED[testnfsposix27]=slow
TEST_TYPE[testnfsposix27]=dev,admin
NEEDS_ROOT[testnfsposix27]=yes
function testnfsposix27
{
    export -f test_nfstest

    test_nfstest posixnfs27 open
}

### testnfsposix28: nfstest_posix tests related to chmod
SPEED[testnfsposix28]=slow
TEST_TYPE[testnfsposix28]=dev,admin
NEEDS_ROOT[testnfsposix28]=yes
function testnfsposix28
{
    export -f test_nfstest

    test_nfstest posixnfs28 chmod
}

### testnfsposix29: nfstest_posix tests related to closedir
SPEED[testnfsposix29]=fast
TEST_TYPE[testnfsposix29]=dev,admin
NEEDS_ROOT[testnfsposix29]=yes
function testnfsposix29
{
    export -f test_nfstest

    test_nfstest posixnfs29 closedir
}

### testnfsposix30: nfstest_posix tests related to close
SPEED[testnfsposix30]=fast
TEST_TYPE[testnfsposix30]=dev,admin
NEEDS_ROOT[testnfsposix30]=yes
function testnfsposix30
{
    export -f test_nfstest

    test_nfstest posixnfs30 close
}

######################## DEFINE TEST LIST HERE ####################

function run_nfstest_posix
{
  export -f test_nfstest

  # display test summary / generate outputs


  run_test testnfsposix00 nfstest_posix/access
  run_test testnfsposix01 nfstest_posix/chdir
  run_test testnfsposix02 nfstest_posix/creat
  run_test testnfsposix03 nfstest_posix/fcntl
  run_test testnfsposix04 nfstest_posix/fdatasync
  run_test testnfsposix05 nfstest_posix/fstat
  run_test testnfsposix06 nfstest_posix/fstatvfs
  run_test testnfsposix07 nfstest_posix/fsync
  run_test testnfsposix08 nfstest_posix/link
  run_test testnfsposix09 nfstest_posix/lseek
  run_test testnfsposix10 nfstest_posix/lstat
  run_test testnfsposix11 nfstest_posix/mkdir
  run_test testnfsposix12 nfstest_posix/opendir
  run_test testnfsposix13 nfstest_posix/read
  run_test testnfsposix14 nfstest_posix/readdir
  run_test testnfsposix15 nfstest_posix/readlink
  run_test testnfsposix16 nfstest_posix/rename
  run_test testnfsposix17 nfstest_posix/rewinddir
  run_test testnfsposix18 nfstest_posix/rmdir
  run_test testnfsposix19 nfstest_posix/seekdir
  run_test testnfsposix20 nfstest_posix/stat
  run_test testnfsposix21 nfstest_posix/statvfs
  run_test testnfsposix22 nfstest_posix/symlink
  run_test testnfsposix23 nfstest_posix/sync
  run_test testnfsposix24 nfstest_posix/telldir
  run_test testnfsposix25 nfstest_posix/unlink
  run_test testnfsposix26 nfstest_posix/write
  run_test testnfsposix27 nfstest_posix/open
  run_test testnfsposix28 nfstest_posix/chmod
  run_test testnfsposix29 nfstest_posix/closedir
  run_test testnfsposix30 nfstest_posix/close
}
