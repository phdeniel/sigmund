#!/bin/bash


############################ TEST FUNCTIONS ############################

### test41a: run fsx-linux with no mmap
SPEED[test41a]=medium
NEEDS_ROOT[test41a]=no
function test41a
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/kernel/fs/fsx-linux/fsx-linux -N 10000 -c 40 -R -W $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}

### test41b: run fsx-linux with mmap on write
SPEED[test41b]=medium
NEEDS_ROOT[test41b]=no
function test41b
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/kernel/fs/fsx-linux/fsx-linux -N 10000 -c 40 -R $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}

### test41c: run fsx-linux with mmap on read
SPEED[test41c]=medium
NEEDS_ROOT[test41c]=no
function test41c
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/kernel/fs/fsx-linux/fsx-linux -N 10000 -c 40 -W $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}


### test41d: run fsx-linux with mmap on read+write
SPEED[test41d]=medium
NEEDS_ROOT[test41d]=no
function test41d
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/kernel/fs/fsx-linux/fsx-linux -N 10000 -c 40 $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}

### test42b: run bonnie++ with a reduced memory size
SPEED[test42b]=longest
NEEDS_ROOT[test42b]=no
function test42b
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"


    mkdir -p $dir
    bonnie++ -d $dir -c 10  -u 0 -s 1:256 -x 1 -r 2
	
    # clean test dir
    rm -rf $dir
}

######################## DEFINE TEST LIST HERE ####################

function run_ltpfs
{
  run_test test41a  "LTPFS: fsx-linux with no mmap                      "
  run_test test41b  "LTPFS: fsx-linux with mmap on write                "
  run_test test41c  "LTPFS: fsx-linux with mmap on read                 "
  run_test test41d  "LTPFS: fsx-linux with mmap on read+write           "
  run_test test42b  "LTPFS: run bonnie++ with a reduced memory size     "
}

