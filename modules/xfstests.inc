#!/bin/bash


############################ TEST FUNCTIONS ############################

### testg001: xfstests generic/001, Random file copier + diff
SPEED[testg001]=medium
TEST_TYPE[testg001]=dev
NEEDS_ROOT[testg001]=no
function testg001
{
    cd $XFSTESTS_DIR 
    ./tests/generic/001 || error "error running XFSTESTS generic/001"
}

### testg002: xfstests generic/002, Link count on regular file
SPEED[testg002]=fast
TEST_TYPE[testg002]=dev
NEEDS_ROOT[testg002]=no
function testg002
{
    cd $XFSTESTS_DIR 
    ./tests/generic/002 || error "error running XFSTESTS generic/002"
}

### testg005: xfstests generic/005, test symlinks and ELOOP
SPEED[testg005]=fast
TEST_TYPE[testg005]=dev
NEEDS_ROOT[testg005]=no
function testg005
{
    cd $XFSTESTS_DIR 
    ./tests/generic/005 || error "error running XFSTESTS generic/005"
}

### testg006: xfstests generic/006, pername
SPEED[testg006]=fast
TEST_TYPE[testg006]=dev
NEEDS_ROOT[testg006]=no
function testg006
{
    cd $XFSTESTS_DIR 
    ./tests/generic/006 || error "error running XFSTESTS generic/006"
}

### testg007: xfstests generic/007, nametest program
SPEED[testg007]=fast
TEST_TYPE[testg007]=dev
NEEDS_ROOT[testg007]=no
function testg007
{
    cd $XFSTESTS_DIR 
    ./tests/generic/007 || error "error running XFSTESTS generic/007"
}

### testg010: xfstests generic/010, dbtest program
SPEED[testg010]=fast
TEST_TYPE[testg010]=dev
NEEDS_ROOT[testg010]=no
function testg010
{
    cd $XFSTESTS_DIR 
    ./tests/generic/010 || error "error running XFSTESTS generic/010"
}

### test87: xfstests generic/010, dbtest program
SPEED[test87]=fast
TEST_TYPE[test87]=dev
NEEDS_ROOT[test87]=no
function test87
{
    cd $XFSTESTS_DIR 
    ./tests/generic/010 || error "error running XFSTESTS generic/010"
}

### test88: xfstests generic/010, dbtest program
SPEED[test88]=fast
TEST_TYPE[test88]=dev
NEEDS_ROOT[test88]=no
function test88
{
    cd $XFSTESTS_DIR 
    ./tests/generic/010 || error "error running XFSTESTS generic/010"
}

### testg010: xfstests generic/010, dbtest program
SPEED[testg010]=fast
TEST_TYPE[testg010]=dev
NEEDS_ROOT[testg010]=no
function testg010
{
    cd $XFSTESTS_DIR 
    ./tests/generic/010 || error "error running XFSTESTS generic/010"
}

function run_xfstests
{
   run_test testg001  "xfstests generic/001, Random file copier + diff"
   run_test testg002  "xfstests generic/002, Link count on regular file"
   run_test testg005  "xfstests generic/005, test symlinks and ELOOP"
   run_test testg006  "xfstests generic/006, permname"
   run_test testg007  "xfstests generic/007, nametest program"
   run_test testg010  "xfstests generic/010, dbtest program"
}
