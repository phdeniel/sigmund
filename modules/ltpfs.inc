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
SPEED[test41c]=medium
NEEDS_ROOT[test41c]=no
function test41c
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




######################## DEFINE TEST LIST HERE ####################

function run_ltpfs
{
  run_test test41a  " LTPFS: fsx-linux with no mmap             "
  run_test test41b  " LTPFS: fsx-linux with mmap on write       "
  run_test test41c  " LTPFS: fsx-linux with mmap on read        "
  run_test test41c  " LTPFS: fsx-linux with mmap on read+write  "
}

