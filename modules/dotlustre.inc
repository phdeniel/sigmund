#!/bin/bash

########################## TEST HELPERS ##################


############################ TEST FUNCTIONS ############################

### test71c: check that creation is properly forbidden under .lustre/
SPEED[test71c]=fast
NEEDS_ROOT[test71c]=no
function test71c
{
    file="file.$TEST_USER.$$"
    dir="dir.$TEST_USER.$$"

    touch $TEST_DIR/.lustre/$file && error "File creation forbidden under .lustre"
    mkdir $TEST_DIR/.lustre/$dir  && error "Directory creation forbidden under .lustre"

    # cleanup just in case...
    rm -rf $TEST_DIR/.lustre/$file $TEST_DIR/.lustre/$dir
}

### test71u: check that attempts to unlink .lustre/ fail
SPEED[test71u]=fast
NEEDS_ROOT[test71u]=no
function test71u
{
    rm -rf $TEST_DIR/.lustre && error "Unlinking .lustre/ is not permitted"
}


# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_dotlustre
{
  run_test test71c  " DOTLUSTRE: creation forbidden under .lustre     "
  run_test test71u  " DOTLUSTRE: unlinking .lustre should fail        "
}

