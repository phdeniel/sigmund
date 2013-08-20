#!/bin/bash

DIRNUMBER=1000
PREFIX=p
PSEUDOFS_SETUP=1

############################ TEST FUNCTIONS ############################

### setup_pseudofs: Setup the export config on Ganesha server 
SPEED[setup_pseudofs]=fast
TESTTYPE[setup_pseudofs]=dev,admin,prod
NEEDS_ROOT[setup_pseudofs]=yes
function setup_pseudofs
{
    # setup only once
    if (($PSEUDOFS_SETUP == 1)); then
        newexportconfig=$EXPORTFILE.pseudofstest

        # copy export config from server
        scp root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE $BUILD_TEST_DIR/
        cp $BUILD_TEST_DIR/$EXPORTFILE $BUILD_TEST_DIR/$newexportconfig

        # generate new exports and append to server's export config
        $BUILD_TEST_DIR/createmanyexports.pl \
            $FS_DIR \
            $PREFIX \
            $GANVERSION \
            $DIRNUMBER \
            $FSAL >> $BUILD_TEST_DIR/$newexportconfig

        # copy export config to server
        scp $BUILD_TEST_DIR/$newexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
        
        # restart server
        ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"
	sleep 20
    fi
}

### testwr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[cleanup_pseudofs]=fast
TESTTYPE[cleanup_pseudofs]=dev,admin,prod
NEEDS_ROOT[cleanup_pseudofs]=yes
function cleanup_pseudofs
{
    # cleanup only once
    if (($PSEUDOFS_SETUP == 1)); then
        PSEUDOFS_SETUP=0
        # make sure previous export config is available
        # then copy previous export config to server
        if [ -e "$BUILD_TEST_DIR/$EXPORTFILE" ]; then
            scp $BUILD_TEST_DIR/$EXPORTFILE root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
        else
            echo error "Could not reinstate previous export config on server!!"
        fi

        # restart server
        ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"
	sleep 20
    fi
}

### testwr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[testwr]=fast
TESTTYPE[testwr]=dev,admin,prod
NEEDS_ROOT[testwr]=yes
PRE_TEST[testwr]=setup_pseudofs
function testwr
{
    # create user directory
    file="$TESTROOT_DIR/testwr"
    touch $file
    [[ $? != 0 ]] || error "we should not be able to create a file in a pseudofs directory: $file"

    file="$TESTROOT_DIR/many"
    touch $file
    [[ $? != 0 ]] || error "we should not be able to modify a pseudofs node: $file"
}

### testrd: 
SPEED[testrd]=fast
TESTTYPE[testrd]=dev,admin,prod
NEEDS_ROOT[testrd]=yes
PRE_TEST[testrd]=setup_pseudofs
function testrd
{
    # create user directory
    file="$TESTROOT_DIR/pseudofs_test"
    cat $file
    [[ $? != 0 ]] || error "$file doesn't exist, but we could read it in a pseudo fs directory!"

    file="$TESTROOT_DIR/many"
    cat $file
    [[ $? != 0 ]] || error "$file does exist, but we shouldn't be able to read it in a pseudo fs directory!"
}

### testrm: 
SPEED[testrm]=fast
TESTTYPE[testrm]=dev,admin,prod
NEEDS_ROOT[testrm]=yes
PRE_TEST[testrm]=setup_pseudofs
function testrm
{
    # rm pseudofs node
    file="$TESTROOT_DIR/pseudofs_test"
    rm $file
    [[ $? != 0 ]] || error "$file doesn't exist, but we could remove it: $file"

    file="$TESTROOT_DIR/many"
    rm $file
    [[ $? != 0 ]] || error "$file does exist, but we shouldn't be able to remove a pseudo fs node!"
}

### testlookup: 
SPEED[testlookup]=fast
TESTTYPE[testlookup]=dev,admin,prod
NEEDS_ROOT[testlookup]=yes
PRE_TEST[testlookup]=setup_pseudofs
function testlookup
{
    # lookup pseudofs node
    file="$TESTROOT_DIR/pseudofs_test"
    ls $file
    [[ $? != 0 ]] || error "$file doesn't exist, but we a lookup succeeded: $file!"

    file="$TESTROOT_DIR/many/$PREFIX1"
    ls $file
    [[ $? == 0 ]] || error "$file does exist and a lookup should have succeeded!"
}

### testreaddir: 
SPEED[testreaddir]=fast
TESTTYPE[testreaddir]=dev,admin,prod
NEEDS_ROOT[testreaddir]=yes
PRE_TEST[testreaddir]=setup_pseudofs
function testreaddir
{
    # create user directory
    dir="$TESTROOT_DIR/many/"
    ls -l $dir
    [[ $? == 0 ]] || error "$dir does exist with $DIRNUMBER entries and a readdir should have succeeded!"

    #    ls -l $dir | wc -l
    # check if proper number of entries returned
}

### testls_junction: 
SPEED[testls_junction]=fast
TESTTYPE[testls_junction]=dev,admin,prod
NEEDS_ROOT[testls_junction]=yes
PRE_TEST[testls_junction]=setup_pseudofs
function testls_junction
{
    # create user directory
    file="$TESTROOT_DIR/many/$PREFIX1"
    ls $file
    [[ $? == 0 ]] || error "$file does exist, is a junction to a real FS, and a ls should have succeeded!"
}

### testcheck_inode: 
SPEED[testcheck_inode]=fast
TESTTYPE[testcheck_inode]=dev,admin,prod
NEEDS_ROOT[testcheck_inode]=yes
PRE_TEST[testcheck_inode]=setup_pseudofs
function testcheck_inode
{
    # First get the inode number from NFS
    file="$TESTROOT_DIR/many/$PREFIX10"
    inode1=`stat -c "%i" $file`

    # Second get the inode number from server local filesystem
    inode2=`ssh -tt root@$SERVERHOSTNAME stat -c "%i" ${FS_DIR}/${PREFIX}10`

    # Now compare
    if [inode1 != inode2]; then
        [[ $? == 0 ]] || error "The inode in the server's local FS doesn't match inode seen in "
    fi

}

### testremove_lookup: 
SPEED[testremove_lookup]=fast
TESTTYPE[testremove_lookup]=dev,admin,prod
NEEDS_ROOT[testremove_lookup]=yes
PRE_TEST[testremove_lookup]=setup_pseudofs
function testremove_lookup
{
    prevexportconfig=$EXPORTFILE.fromremovelookup
    newexportconfig=$EXPORTFILE.pseudofstest
    removedexport=10

    # first have client cache result of pseudofs node
    file="$TESTROOT_DIR/many/$PREFIX$removedexport"
    ls $file
    [[ $? == 0 ]] || error "$file wasn't removed yet, but a lookup failed!"

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
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"    
    sleep 20
    
    # First get the inode number from NFS
    file="$TESTROOT_DIR/many/$PREFIX$removedexport"
    ls $file
    [[ $? != 0 ]] || error "$file was removed, but a lookup succeeded!"

    # restore previous config and restart
    scp $BUILD_TEST_DIR/$prevexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"    
    sleep 20

}

### testremove_readdir: 
SPEED[testremove_readdir]=fast
TESTTYPE[testremove_readdir]=dev,admin,prod
NEEDS_ROOT[testremove_readdir]=yes
PRE_TEST[testremove_readdir]=setup_pseudofs
function testremove_readdir
{
    prevexportconfig=$EXPORTFILE.fromremovereaddir
    newexportconfig=$EXPORTFILE.pseudofstest
    removedexport=20

    # first have client cache result of pseudofs node
    file="$TESTROOT_DIR/many"
    ls $file | grep "$PREFIX$removedexport"
    [[ $? == 0 ]] || error "$file wasn't removed yet, but readdir isn't showing it!"

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
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"    
    sleep 20
    
    # First get the inode number from NFS
    file="$TESTROOT_DIR/many"
    ls $file | grep "$PREFIX$removedexport"
    [[ $? != 0 ]] || error "$file was removed, but a readdir still lists it!"

    # restore previous config and restart
    scp $BUILD_TEST_DIR/$prevexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"    
    sleep 20

}

### testremove_stat: 
SPEED[testremove_stat]=fast
TESTTYPE[testremove_stat]=dev,admin,prod
NEEDS_ROOT[testremove_stat]=yes
PRE_TEST[testremove_stat]=setup_pseudofs
function testremove_stat
{
    prevexportconfig=$EXPORTFILE.fromremovereaddir
    newexportconfig=$EXPORTFILE.pseudofstest
    removedexport=20

    # first get a list of inode numbers for files
    file="$TESTROOT_DIR/many/$PREFIX$removedexport"
    ls $file
    [[ $? == 0 ]] || error "$file wasn't removed yet, but a lookup failed!"

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
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"    
    sleep 20
    
    # Now check if the inode numbers are consistent after removal of pseudo nodes
    file="$TESTROOT_DIR/many"
    ls $file | grep "$PREFIX$removedexport"
    [[ $? != 0 ]] || error "$file was removed, but a readdir still lists it!"

    # restore previous config and restart
    scp $BUILD_TEST_DIR/$prevexportconfig root@$SERVERHOSTNAME:$EXPORTCONFDIR/$EXPORTFILE
    ssh -tt root@$SERVERHOSTNAME service nfs-ganesha-gpfs restart || error "Could not restart ganesha server over ssh"    
    sleep 20

}

# syntax: ONLY=2,3 ./run_test.sh [-j] <testdir>

######################## DEFINE TEST LIST HERE ####################

function run_pseudofs
{
  run_test setup_pseudofs      " PSEUDOFS: Preparing server for tests                             "

  run_test testwr             " PSEUDOFS: Attempt write of pseudofs node                         "
  run_test testrd             " PSEUDOFS: Attempt read of pseudofs node                          "
  run_test testrm             " PSEUDOFS: Attempt removal of pseudofs node                       "
  run_test testlookup         " PSEUDOFS: Lookup a single pseudfs node                           "
  run_test testreaddir        " PSEUDOFS: Execute readdirplus on large directory                 "
  run_test testls_junction    " PSEUDOFS: Cross a junction point and list directory              "
  run_test testcheck_inode    " PSEUDOFS: Check if junction shows fs inode                       "
  run_test testremove_lookup  " PSEUDOFS: Remove export from server, make sure lookup fails      "
#  run_test testremove_readdir " PSEUDOFS: Remove export from server, make sure it's gone in dir  "
#  run_test testremove_stat    " PSEUDOFS: Remove export from server, make sure inodes stay same  "
#  run_test testadd_lookup     " PSEUDOFS: Add an export from server, make sure it's gone         "
#  run_test testadd_stat       " PSEUDOFS: Add an export from server, make sure inodes stay same  "

  run_test cleanup_pseudofs    " PSEUDOFS: Cleaning up server environment                         "
}

