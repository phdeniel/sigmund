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

### testg011: dirstress
SPEED[testg011]=fast
TEST_TYPE[testg011]=dev
NEEDS_ROOT[testg011]=no
function testg011
{
    cd $XFSTESTS_DIR 
    ./tests/generic/011 || error "error running XFSTESTS generic/011" 
}

### testg013: fsstress
SPEED[testg013]=fast
TEST_TYPE[testg013]=dev
NEEDS_ROOT[testg013]=no
function testg013
{
    cd $XFSTESTS_DIR 
    ./tests/generic/013 || error "error running XFSTESTS generic/013" 
}

### testg014: truncfile
SPEED[testg014]=fast
TEST_TYPE[testg014]=dev
NEEDS_ROOT[testg014]=no
function testg014
{
    cd $XFSTESTS_DIR 
    ./tests/generic/014 || error "error running XFSTESTS generic/014" 
}

### testg074: fstest
SPEED[testg074]=fast
TEST_TYPE[testg074]=dev
NEEDS_ROOT[testg074]=no
function testg074
{
    cd $XFSTESTS_DIR 
    ./tests/generic/074 || error "error running XFSTESTS generic/074" 
}

### testg075: fsx
SPEED[testg075]=fast
TEST_TYPE[testg075]=dev
NEEDS_ROOT[testg075]=no
function testg075
{
    cd $XFSTESTS_DIR 
    ./tests/generic/075 || error "error running XFSTESTS generic/075" 
}

### testg088: test CAP_DAC_OVERRIDE and CAP_DAC_SEARCH
SPEED[testg088]=fast
TEST_TYPE[testg088]=dev
NEEDS_ROOT[testg088]=no
function testg088
{
    cd $XFSTESTS_DIR 
    ./tests/generic/088 || error "error running XFSTESTS generic/088" 
}

### testg089: emulates /etc/mtab manipulation
SPEED[testg089]=fast
TEST_TYPE[testg089]=dev
NEEDS_ROOT[testg089]=no
function testg089
{
    cd $XFSTESTS_DIR 
    ./tests/generic/089 || error "error running XFSTESTS generic/089" 
}

### testg091: fsx with direct-io
SPEED[testg091]=fast
TEST_TYPE[testg091]=dev
NEEDS_ROOT[testg091]=no
function testg091
{
    cd $XFSTESTS_DIR 
    ./tests/generic/091 || error "error running XFSTESTS generic/091" 
}

### testg131: lockfile_simple
SPEED[testg131]=fast
TEST_TYPE[testg131]=dev
NEEDS_ROOT[testg131]=no
function testg131
{
    cd $XFSTESTS_DIR 
    ./tests/generic/131 || error "error running XFSTESTS generic/131" 
}

### testg184: mknod
SPEED[testg184]=fast
TEST_TYPE[testg184]=dev
NEEDS_ROOT[testg184]=no
function testg184
{
    cd $XFSTESTS_DIR 
    ./tests/generic/184 || error "error running XFSTESTS generic/184" 
}

function run_xfstests
{
   run_test testg001  "xfstests generic/001, Random file copier + diff"
   run_test testg002  "xfstests generic/002, Link count on regular file"
   run_test testg005  "xfstests generic/005, test symlinks and ELOOP"
   run_test testg006  "xfstests generic/006, permname"
   run_test testg007  "xfstests generic/007, nametest program"
   run_test testg010  "xfstests generic/010, dbtest program"
   run_test testg011  "xfstests generic/011, dirstress " 
   run_test testg013  "xfstests generic/013, fsstress " 
   run_test testg014  "xfstests generic/014, truncfile " 
   run_test testg074  "xfstests generic/074, fstest " 
   run_test testg075  "xfstests generic/075, fsx " 
   run_test testg088  "xfstests generic/088, CAP_DAC_OVERRIDE/CAP_DAC_SEARC" 
   run_test testg089  "xfstests generic/089, emulates /etc/mtab manipulation" 
   run_test testg091  "xfstests generic/091, fsx with direct-io" 
   run_test testg131  "xfstests generic/131, lockfile_simple" 
   run_test testg184  "xfstests generic/184, mknod" 
}
