#!/bin/bash

########################## TEST HELPERS ##################


############################ TEST FUNCTIONS ############################

### test71c: check that file creation is properly forbidden under .lustre/
SPEED[test71c]=fast
TEST_TYPE[test71c]=dev,admin,prod
NEEDS_ROOT[test71c]=no
function test71c
{
    file="file.$TEST_USER.$$"

    touch $TEST_DIR/.lustre/$file && error "File creation forbidden under .lustre"

    # cleanup just in case...
    rm -rf $TEST_DIR/.lustre/$file
}

### test71d: check that directory creation is properly forbidden under .lustre/
SPEED[test71d]=fast
TEST_TYPE[test71d]=dev,admin,prod
NEEDS_ROOT[test71d]=no
function test71d
{
    dir="dir.$TEST_USER.$$"

    mkdir $TEST_DIR/.lustre/$dir && error "Directory creation forbidden under .lustre"

    # cleanup just in case...
    rm -rf $TEST_DIR/.lustre/$dir
}

### test71h: check that hardlink creation is properly forbidden under .lustre/
SPEED[test71h]=fast
TEST_TYPE[test71h]=dev,admin,prod
NEEDS_ROOT[test71h]=no
function test71h
{
    file="dir.$TEST_USER.$$"

    touch $TEST_DIR/$file
    ln $TEST_DIR/$file $TEST_DIR/.lustre/$file && error "Hardlink creation forbidden under .lustre"

    # cleanup just in case...
    rm -rf $TEST_DIR/$file $TEST_DIR/.lustre/$file
}

### test72: check that attempts to unlink .lustre/ fail
SPEED[test72]=fast
TEST_TYPE[test72]=dev,admin
NEEDS_ROOT[test72]=no
function test72
{
    rm -rf $TEST_DIR/.lustre && error "Unlinking .lustre/ is not permitted"
}

### test73: Execute binaries from lustre
SPEED[test73]=fast
TEST_TYPE[test73]=dev,admin,prod
NEEDS_ROOT[test73]=no
function test73
{
    BIN=`which ls`
    cp $BIN $TEST_DIR/ls
    chmod go+rw $TEST_DIR/ls
    $TEST_DIR/ls / >> /dev/null || error "Cannot run binaries from lustre"
    rm -f $TEST_DIR/ls
}


# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_lustre
{
  run_test test71c  "file creation forbidden under .lustre"
  run_test test71d  "directory creation forbidden under .lustre"
  run_test test71h  "hardlinking forbidden under .lustre"
  run_test test72   "unlinking .lustre should fail"
  run_test test73   "running binaries from lustre"
}

