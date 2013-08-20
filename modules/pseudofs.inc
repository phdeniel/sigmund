#!/bin/bash

DIRNUMBER=200
PREFIX=p
PSEUDOFS_SETUP=1

############################ TEST FUNCTIONS ############################

### testsetup: Setup the export config on Ganesha server 
SPEED[testsetup]=fast
TESTTYPE[testsetup]=dev,admin,prod
NEEDS_ROOT[testsetup]=yes
function testsetup
{
    echo "** Checking if we need to run pseudofs setup for the first time."
    # setup only once
    if [[ ! -d $BUILD_TEST_DIR ]]; then
	error "Test directory does not exist. Perhaps you need to run ./build_test.sh"
    fi

    if [[ ! -e $BUILD_TEST_DIR/createmanyexports.pl ]]; then
	error "Test script BUILD_TEST_DIR/createmanyexports.pl does not exist. Perhaps you need to run ./build_test.sh"
    fi

    if (($PSEUDOFS_SETUP == 1)); then
	echo "** Creating export configuration file and test directories."
	PSEUDOFS_SETUP=0
        newexportconfig=$EXPORTFILE.pseudofstest

        # copy export config from server
	echo "** Copying export config from NFS server to local storage"
        scp root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE $BUILD_TEST_DIR/$EXPORTFILE
        cp $BUILD_TEST_DIR/$EXPORTFILE $BUILD_TEST_DIR/$newexportconfig

        # generate new exports and append to server's export config
	echo "** Building new export config at $BUILD_TEST_DIR/$newexportconfig"
        echo "$BUILD_TEST_DIR/createmanyexports.pl $FS_DIR $PREFIX $GANVERSION $DIRNUMBER $FSAL >> $BUILD_TEST_DIR/$newexportconfig"

        $BUILD_TEST_DIR/createmanyexports.pl \
            $FS_DIR \
            $PREFIX \
            $GANVERSION \
            $DIRNUMBER \
            $FSAL >> $BUILD_TEST_DIR/$newexportconfig

	ssh -tt root@$SERVERHOSTNAME "mkdir -p $FS_DIR/$PREFIX{1..$DIRNUMBER}"

        # copy export config to server
	echo "** Copying new export config to NFS server"
	echo "        scp $BUILD_TEST_DIR/$newexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE"
        scp $BUILD_TEST_DIR/$newexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
        
        # restart server
	echo "** Restarting NFS server"
        ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"
	sleep 5
    fi
}

### testcleanup: replace export config on server and cleanup any files created during test
SPEED[testcleanup]=fast
TESTTYPE[testcleanup]=dev,admin,prod
NEEDS_ROOT[testcleanup]=yes
function testcleanup
{
    # cleanup only once
    if (($PSEUDOFS_SETUP == 0)); then
        PSEUDOFS_SETUP=1
        # make sure previous export config is available
        # then copy previous export config to server
        if [ -e "$BUILD_TEST_DIR/$EXPORTFILE" ]; then
            scp $BUILD_TEST_DIR/$EXPORTFILE root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
        else
            echo error "** Could not reinstate previous export config on server!!"
        fi

        # restart server
        ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"
	sleep 5
    fi
}

### testwr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[testwr]=fast
TESTTYPE[testwr]=dev,admin,prod
NEEDS_ROOT[testwr]=yes
PRE_TEST[testwr]=testsetup
function testwr
{
    # create user directory
    echo "** Attempting to create file in pseudofs directory"
    file="$TESTROOT_DIR$PSEUDOFS_DIR/testwr"
    result=$((touch $file) 2>&1)
    if [[ ! "$result" =~ "Read-only file system" ]]; then
	echo "Received: $result"
	error "** we should receive a read-only filesystem error when creating a file in the pseudofs: $file"
    else
	echo "** Could not ... good"
    fi

    echo "** Attempting to change a pseudofs directory"
    file="$TESTROOT_DIR$PSEUDOFS_DIR"
    result=$((touch $file) 2>&1)
    if [[ ! "$result" =~ "Read-only file system" ]]; then
	echo "Received: $result"
	error "** we should receive a read-only filesystem error when attempting to change a pseudofs node: $file"
    else
	echo "** Could not ... good"
    fi
}

### testrd: 
SPEED[testrd]=fast
TESTTYPE[testrd]=dev,admin,prod
NEEDS_ROOT[testrd]=yes
PRE_TEST[testrd]=testsetup
function testrd
{

    file="$TESTROOT_DIR$PSEUDOFS_DIR/asdfljdsaf"
    echo "** Attempting to read nonexistent pseudofs directory ${file}"
    result=$((cat $file) 2>&1)
    if [[ ! "$result" =~ "No such file or directory" ]]; then
	echo "Received: $result"
	error "** $file exists, but it shouldn't"
    elif [[ "$result" == "" ]]; then
	echo "Received: $result"
	error "** cat of a nonexistent pseudofs directory succeeded. This should not have happened."
    else
	echo "** Could not ... good"
    fi

    file="$TESTROOT_DIR$PSEUDOFS_DIR"
    echo "** Attempting to read existent pseudofs directory ${file}"
    result=$((cat $file) 2>&1)
    if [[ "$result" =~ "No such file or directory" ]]; then
	echo "Received: $result"
	error "** $file doesn't exist, but it should."
    elif [[ "$result" == "" ]]; then
	echo "Received: $result"
	error "** cat of a pseudofs directory succeeded. This should not have happened."
    elif [[ "$result" =~ "Is a directory" ]]; then
	echo "** Could not because it's a directory ... good"
    else
	echo "** Could not ... good"
    fi
}

### testrm: 
SPEED[testrm]=fast
TESTTYPE[testrm]=dev,admin,prod
NEEDS_ROOT[testrm]=yes
PRE_TEST[testrm]=testsetup
function testrm
{
    # rm pseudofs node
    echo "** Attempting to remove a nonexistent file in a pseudofs directory"
    file="$TESTROOT_DIR$PSEUDOFS_DIR/pasldkfjaldskfj"
    result=$((rm -r $file) 2>&1)
    if [[ ! "$result" =~ "No such file or directory" ]]; then
	echo "Received: $result"
	error "** Didn't receive \"No such file or directory\" error though file shouldn't exist."
    elif [[ "$result" == "" ]]; then
	echo "Received: $result"
	error "** removal of $file succeeded! This should not have happened."
    else
	echo "** Could not ... good"
    fi

    echo "** Attempting to remove an existing pseudofs directory"
    file="$TESTROOT_DIR$PSEUDOFS_DIR/p1"
    result=$((rm -r $file) 2>&1)
    if [[ "$result" =~ "No such file or directory" ]]; then
	echo "Received: $result"
	error "** Received \"No such file or directory\" error, but file $file should exist."
    elif [[ ! "$result" =~ "Device or resource busy" ]]; then
	echo "Received: $result"
	error "** Didn't receive \"Device or resource busy\" as expected."
    elif [[ "$result" == "" ]]; then
	echo "Received: $result"
	error "** $file does exist, but we shouldn't be able to remove a pseudo fs node!"
    else
	echo "** Could not ... good"
    fi
}

### testlookup: 
SPEED[testlookup]=fast
TESTTYPE[testlookup]=dev,admin,prod
NEEDS_ROOT[testlookup]=yes
PRE_TEST[testlookup]=testsetup
function testlookup
{
    # lookup pseudofs node
    file="$TESTROOT_DIR$PSEUDOFS_DIR/lkajdsflkajdsf"
    echo "** Attempting to lookup a nonexistent pseudofs directory ${file}"
    result=$((ls $file) 2>&1)
    echo "RESULT: $result ..."
    if [[ ! "$result" =~ "No such file or directory" ]]; then
	error "** Did not receive \"No such file or directory\" error as expected."
	echo "Received: $result"
    else
	echo "** Could not ... good"
    fi

    file="$TESTROOT_DIR$PSEUDOFS_DIR/${PREFIX}1"
    echo "** Attempting to lookup a nonexistent pseudofs directory ${file}"
    result=$((ls $file) 2>&1)
    echo "RESULT: $result ..."
    if [[ "$result" =~ "No such file or directory" ]]; then
	error "** We received \"No such file or directory\" error for a directory that should exist."
	echo "Received: $result"
    elif [[ "$result" == "" ]]; then
	echo "** Succeeded ... good"
    else
	error "** We should not receive any output. We are trying to list an empty directory."
	echo "Received: $result"
    fi
}

### testreaddir: 
SPEED[testreaddir]=fast
TESTTYPE[testreaddir]=dev,admin,prod
NEEDS_ROOT[testreaddir]=yes
PRE_TEST[testreaddir]=testsetup
function testreaddir
{
    # create user directory
    dir="$TESTROOT_DIR/many/"
    ls -l $dir
    [[ $? == 0 ]] || error "** $dir does exist with $DIRNUMBER entries and a readdir should have succeeded!"

    #    ls -l $dir | wc -l
    # check if proper number of entries returned
}

### testls_junction: 
SPEED[testls_junction]=fast
TESTTYPE[testls_junction]=dev,admin,prod
NEEDS_ROOT[testls_junction]=yes
PRE_TEST[testls_junction]=testsetup
function testls_junction
{
    # create user directory
    file="$TESTROOT_DIR/many/$PREFIX1"
    ls $file
    [[ $? == 0 ]] || error "** $file does exist, is a junction to a real FS, and a ls should have succeeded!"
}

### testcheck_inode: 
SPEED[testcheck_inode]=fast
TESTTYPE[testcheck_inode]=dev,admin,prod
NEEDS_ROOT[testcheck_inode]=yes
PRE_TEST[testcheck_inode]=testsetup
function testcheck_inode
{
    # First get the inode number from NFS
    file="$TESTROOT_DIR$PSEUDOFS_DIR/${PREFIX}2"
    echo "** Attempting to stat pseudofs directory ${file} from client"
    inode1=`stat -c "%i" $file`
    echo "** ${file} inode: \"${inode1}\""

    # Second get the inode number from server local filesystem
    echo "** Attempting to stat local directory ${FS_DIR}/${PREFIX}2 from server."
    inode2=`ssh -tt root@$SERVERHOSTNAME stat -c "%i" ${FS_DIR}/${PREFIX}2 | sed 's/[^0-9]*//g'`
    echo "** ${FS_DIR}/${PREFIX}2 inode: \"${inode2}\""

    # Now compare
    [[ ${inode1} == ${inode2} ]] || error "** The inode in the server's local FS doesn't match inode seen in the local filesystem."
}

### testremove_lookup: 
SPEED[testremove_lookup]=fast
TESTTYPE[testremove_lookup]=dev,admin,prod
NEEDS_ROOT[testremove_lookup]=yes
PRE_TEST[testremove_lookup]=testsetup
function testremove_lookup
{
    prevexportconfig=$EXPORTFILE.fromremovelookup
    newexportconfig=$EXPORTFILE.pseudofstest
    removedexport=10

    # first have client cache result of pseudofs node
    file="$TESTROOT_DIR$PSEUDOFS_DIR/${PREFIX}${removedexport}"
    echo "** Attempting to stat an existent pseudofs directory ${file}"
    result=$((stat $file) 2>&1)
    echo "RESULT: $result ..."
    if [[ "$result" =~ "No such file or directory" ]]; then
	error "** We received \"No such file or directory\" error for a directory that should exist."
	echo "Received: $result"
    elif [[ "$result" == "" ]]; then
	error "** Should have received _some_ output."
	echo "Received: $result"
    elif [[ "$result" =~ "Links\:\ 2" ]]; then
	echo "** Looks like it probably worked!"
    else
	error "** Should have shown 2 links to pseudofs directory."
	echo "Received: $result"
    fi

    # copy export config from server
    scp root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE $BUILD_TEST_DIR/$prevexportconfig
    cp $BUILD_TEST_DIR/$EXPORTFILE $BUILD_TEST_DIR/$newexportconfig
    
    # generate new exports and append to server's export config
    $BUILD_TEST_DIR/createmanyexports.pl \
        $FS_DIR \
        $PREFIX \
        $GANVERSION \
        $DIRNUMBER \
        $FSAL $removedexport >> $BUILD_TEST_DIR/$newexportconfig
    
    # copy export config to server and restart
    scp $BUILD_TEST_DIR/$newexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"    
    sleep 5
    
    # First get the inode number from NFS
    file="$TESTROOT_DIR$PSEUDOFS_DIR/${PREFIX}${removedexport}"
    echo "** Attempting to stat a nonexistent pseudofs directory ${file}"
    result=$((stat $file) 2>&1)
    echo "RESULT: $result ..."

    if [[ "$result" =~ "Stale NFS file handle" ]]; then
	echo "We received Stale NFS file handle error. Let's try this again!"
	echo "** Once again Attempting to readdir an existent pseudofs directory ${file}"
	result=$((stat $file) 2>&1)
	echo "RESULT: $result ..."
    fi

    if [[ "$result" =~ "No such file or directory" ]]; then
	echo "** Received \"No such file or directory\" error as expected."
    else
	error "** Received unexpected output."
	echo "Received: $result"
    fi

    # restore previous config and restart
    scp $BUILD_TEST_DIR/$prevexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"    
    sleep 5
}

### testremove_readdir: 
SPEED[testremove_readdir]=fast
TESTTYPE[testremove_readdir]=dev,admin,prod
NEEDS_ROOT[testremove_readdir]=yes
PRE_TEST[testremove_readdir]=testsetup
function testremove_readdir
{
    prevexportconfig=$EXPORTFILE.fromremovereaddir
    newexportconfig=$EXPORTFILE.pseudofstest
    removedexport=20

    # Attempt a readdir of the pseudofs directory before removing
    file="$TESTROOT_DIR$PSEUDOFS_DIR/${PREFIX}${removedexport}"
    echo "** Attempting to readdir an existent pseudofs directory ${file}"
    result=$((ls $file) 2>&1)
    if [[ "$result" =~ "No such file or directory" ]]; then
	error "** We received \"No such file or directory\" error for a directory that should exist."
	echo "Received: $result"
    elif [[ "$result" == "" ]]; then
	echo "** Succeeded ... good"
    else
	error "** We should not receive any output. We are trying to list an empty directory."
	echo "Received: $result"
    fi

    # copy export config from server
    scp root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE $BUILD_TEST_DIR/$prevexportconfig
    cp $BUILD_TEST_DIR/$EXPORTFILE $BUILD_TEST_DIR/$newexportconfig
    
    # generate new exports and append to server's export config
    $BUILD_TEST_DIR/createmanyexports.pl \
        $FS_DIR \
        $PREFIX \
        $GANVERSION \
        $DIRNUMBER \
        $FSAL $removedexport >> $BUILD_TEST_DIR/$newexportconfig
    
    # copy export config to server and restart
    echo "** Replacing export configuration on server"
    scp $BUILD_TEST_DIR/$newexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"    
    sleep 5
    
    # Attempt a readdir of the pseudofs directory after removing
    file="$TESTROOT_DIR$PSEUDOFS_DIR/${PREFIX}${removedexport}"
    echo "** Attempting to readdir an existent pseudofs directory ${file}"
    result=$((ls $file) 2>&1)
    echo "RESULT: $result ..."
    if [[ "$result" =~ "Stale NFS file handle" ]]; then
	echo "We received Stale NFS file handle error. Let's try this again!"
	echo "** Once again Attempting to readdir an existent pseudofs directory ${file}"
	result=$((ls $file) 2>&1)
	echo "RESULT: $result ..."
    fi

    if [[ "$result" =~ "No such file or directory" ]]; then
	echo "** Received \"No such file or directory\" error as expected."
    elif [[ "$result" =~ "Stale NFS file handle" ]]; then
	error"** Is this good enough?"
	echo "RESULT: $result ..."
    elif [[ "$result" == "" ]]; then
	error "** $file was removed, but a lookup succeeded!"
	echo "** Succeeded ... good"
    else
	error "** Received unexpected output."
	echo "Received: $result"
    fi

    # restore previous config and restart
    scp $BUILD_TEST_DIR/$prevexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"    
    sleep 5

}

### testremove_stat: 
SPEED[testremove_stat]=fast
TESTTYPE[testremove_stat]=dev,admin,prod
NEEDS_ROOT[testremove_stat]=yes
PRE_TEST[testremove_stat]=testsetup
function testremove_stat
{
    prevexportconfig=$EXPORTFILE.fromremovereaddir
    newexportconfig=$EXPORTFILE.pseudofstest
    removedexport=20

    # first get a list of inode numbers for files
    file="$TESTROOT_DIR/many/$PREFIX$removedexport"
    ls $file
    [[ $? == 0 ]] || error "** $file wasn't removed yet, but a lookup failed!"

    # copy export config from server
    scp root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE $BUILD_TEST_DIR/$prevexportconfig
    cp $BUILD_TEST_DIR/$EXPORTFILE $BUILD_TEST_DIR/$newexportconfig
    
    # generate new exports and append to server's export config
    $BUILD_TEST_DIR/createmanyexports.pl \
        $FS_DIR \
        $PREFIX \
        $GANVERSION \
        $DIRNUMBER \
        $FSAL $removedexport >> $BUILD_TEST_DIR/$newexportconfig
    
    # copy export config to server and restart
    scp $BUILD_TEST_DIR/$newexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"    
    sleep 5
    
    # Now check if the inode numbers are consistent after removal of pseudo nodes
    file="$TESTROOT_DIR/many"
    ls $file | grep "$PREFIX$removedexport"
    [[ $? != 0 ]] || error "** $file was removed, but a readdir still lists it!"

    # restore previous config and restart
    scp $BUILD_TEST_DIR/$prevexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha restart || error "** Could not restart ganesha server over ssh"    
    sleep 5

}

# syntax: ONLY=2,3 ./run_test.sh [-j] <testdir>

######################## DEFINE TEST LIST HERE ####################

function run_pseudofs
{
#  run_test testsetup          " PSEUDOFS: Preparing server for tests                             "
  run_test testwr             " PSEUDOFS: Attempt write of pseudofs node                         "
  run_test testrd             " PSEUDOFS: Attempt read of pseudofs node                          "
  run_test testrm             " PSEUDOFS: Attempt removal of pseudofs node                       "
  run_test testlookup         " PSEUDOFS: Lookup a single pseudfs node                           "
  run_test testcheck_inode    " PSEUDOFS: Check if junction shows fs inode or pseudofs inode     "
  run_test testremove_lookup  " PSEUDOFS: Remove export from server, make sure lookup fails      "
  run_test testremove_readdir " PSEUDOFS: Remove export from server, make sure it's gone in dir  "

  run_test testreaddir        " PSEUDOFS: Execute readdirplus on large directory                 "
  run_test testls_junction    " PSEUDOFS: Cross a junction point and list directory              "
#  run_test testremove_stat    " PSEUDOFS: Remove export from server, make sure inodes stay same  "
#  run_test testadd_lookup     " PSEUDOFS: Add an export from server, make sure it's gone         "
#  run_test testadd_stat       " PSEUDOFS: Add an export from server, make sure inodes stay same  "

  run_test testcleanup         " PSEUDOFS: Cleaning up server environment                         "
}

