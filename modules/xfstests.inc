#!/bin/bash


############################ TEST FUNCTIONS ############################

### testg001: xfstests 001, Random file copier + diff
SPEED[testg001]=medium
TEST_TYPE[testg001]=dev
NEEDS_ROOT[testg001]=no
function testg001
{
    cd $XFSTESTS_DIR 
    ./001 || error "error running XFSTESTS 001"
}

### testg002: xfstests 002, Link count on regular file
SPEED[testg002]=fast
TEST_TYPE[testg002]=dev
NEEDS_ROOT[testg002]=no
function testg002
{
    cd $XFSTESTS_DIR 
    ./002 || error "error running XFSTESTS 002"
}

### testg005: xfstests 005, test symlinks and ELOOP
SPEED[testg005]=fast
TEST_TYPE[testg005]=dev
NEEDS_ROOT[testg005]=no
function testg005
{
    cd $XFSTESTS_DIR 
    ./005 || error "error running XFSTESTS 005"
}

### testg006: xfstests 006, pername
SPEED[testg006]=medium
TEST_TYPE[testg006]=dev
NEEDS_ROOT[testg006]=no
function testg006
{
    cd $XFSTESTS_DIR 
    ./006 || error "error running XFSTESTS 006"
}

### testg007: xfstests 007, nametest program
SPEED[testg007]=medium
TEST_TYPE[testg007]=dev
NEEDS_ROOT[testg007]=no
function testg007
{
    cd $XFSTESTS_DIR 
    ./007 || error "error running XFSTESTS 007"
}

### testg010: xfstests 010, dbtest program
SPEED[testg010]=fast
TEST_TYPE[testg010]=dev
NEEDS_ROOT[testg010]=no
function testg010
{
    cd $XFSTESTS_DIR 
    ./010 || error "error running XFSTESTS 010"
}

### test87: xfstests 010, dbtest program
SPEED[test87]=fast
TEST_TYPE[test87]=dev
NEEDS_ROOT[test87]=no
function test87
{
    cd $XFSTESTS_DIR 
    ./010 || error "error running XFSTESTS 010"
}

### test88: xfstests 010, dbtest program
SPEED[test88]=fast
TEST_TYPE[test88]=dev
NEEDS_ROOT[test88]=no
function test88
{
    cd $XFSTESTS_DIR 
    ./010 || error "error running XFSTESTS 010"
}

### testg010: xfstests 010, dbtest program
SPEED[testg010]=fast
TEST_TYPE[testg010]=dev
NEEDS_ROOT[testg010]=no
function testg010
{
    cd $XFSTESTS_DIR 
    ./010 || error "error running XFSTESTS 010"
}

### testg011: dirstress
SPEED[testg011]=medium
TEST_TYPE[testg011]=dev
NEEDS_ROOT[testg011]=no
function testg011
{
    cd $XFSTESTS_DIR 
    ./011 || error "error running XFSTESTS 011" 
}

### testg013: fsstress
SPEED[testg013]=fast
TEST_TYPE[testg013]=dev
NEEDS_ROOT[testg013]=no
function testg013
{
    cd $XFSTESTS_DIR 
    ./013 || error "error running XFSTESTS 013" 
}

### testg014: truncfile
SPEED[testg014]=fast
TEST_TYPE[testg014]=dev
NEEDS_ROOT[testg014]=no
function testg014
{
    cd $XFSTESTS_DIR 
    ./014 || error "error running XFSTESTS 014" 
}

### testg074: fstest
SPEED[testg074]=fast
TEST_TYPE[testg074]=dev
NEEDS_ROOT[testg074]=no
function testg074
{
    cd $XFSTESTS_DIR 
    ./074 || error "error running XFSTESTS 074" 
}

### testg088: test CAP_DAC_OVERRIDE and CAP_DAC_SEARCH
SPEED[testg088]=fast
TEST_TYPE[testg088]=dev
NEEDS_ROOT[testg088]=no
function testg088
{
    cd $XFSTESTS_DIR 
    ./088 || error "error running XFSTESTS 088" 
}

### testg089: emulates /etc/mtab manipulation
SPEED[testg089]=fast
TEST_TYPE[testg089]=dev
NEEDS_ROOT[testg089]=no
function testg089
{
    cd $XFSTESTS_DIR 
    ./089 || error "error running XFSTESTS 089" 
}

### testg131: lockfile_simple
SPEED[testg131]=fast
TEST_TYPE[testg131]=dev
NEEDS_ROOT[testg131]=no
function testg131
{
    cd $XFSTESTS_DIR 
    ./131 || error "error running XFSTESTS 131" 
}

### testg184: mknod
SPEED[testg184]=fast
TEST_TYPE[testg184]=dev
NEEDS_ROOT[testg184]=no
function testg184
{
    cd $XFSTESTS_DIR 
    ./184 || error "error running XFSTESTS 184" 
}

### testg215: c/mtimes updates after mapped writes
SPEED[testg215]=fast
TEST_TYPE[testg215]=dev
NEEDS_ROOT[testg215]=no
function testg215
{
    cd $XFSTESTS_DIR 
    ./215 || error "error running XFSTESTS 215" 
}

### testg221: calling futimens without UTIME_OMIT
SPEED[testg221]=fast
TEST_TYPE[testg221]=dev
NEEDS_ROOT[testg221]=no
function testg221
{
    cd $XFSTESTS_DIR 
    ./221 || error "error running XFSTESTS 221" 
}

### testg236: check ctime on linked file
SPEED[testg236]=fast
TEST_TYPE[testg236]=dev
NEEDS_ROOT[testg236]=no
function testg236
{
    cd $XFSTESTS_DIR 
    ./236 || error "error running XFSTESTS 236" 
}

### testg241: dbench
SPEED[testg241]=fast
TEST_TYPE[testg241]=dev
NEEDS_ROOT[testg241]=no
function testg241
{
    cd $XFSTESTS_DIR 
    ./241 || error "error running XFSTESTS 241" 
}

### testg246: truncation after failed writes
SPEED[testg246]=medium
TEST_TYPE[testg246]=dev
NEEDS_ROOT[testg246]=no
function testg246
{
    cd $XFSTESTS_DIR 
    ./246 || error "error running XFSTESTS 246" 
}

### testg248: pwrite on mapped pages
SPEED[testg248]=fast
TEST_TYPE[testg248]=dev
NEEDS_ROOT[testg248]=no
function testg248
{
    cd $XFSTESTS_DIR 
    ./248 || error "error running XFSTESTS 248" 
}

### testg249: simple splice test
SPEED[testg249]=fast
TEST_TYPE[testg249]=dev
NEEDS_ROOT[testg249]=no
function testg249
{
    cd $XFSTESTS_DIR 
    ./249 || error "error running XFSTESTS 249" 
}

### testg257: simple splice test
SPEED[testg257]=fast
TEST_TYPE[testg257]=dev
NEEDS_ROOT[testg257]=no
function testg257
{
    cd $XFSTESTS_DIR 
    ./257 || error "error running XFSTESTS 257" 
}

function run_xfstests
{
   run_test testg001  "xfstests 001, Random file copier + diff"
   run_test testg002  "xfstests 002, Link count on regular file"
   run_test testg005  "xfstests 005, test symlinks and ELOOP"
   run_test testg006  "xfstests 006, permname"
   run_test testg007  "xfstests 007, nametest program"
   run_test testg010  "xfstests 010, dbtest program"
   run_test testg011  "xfstests 011, dirstress " 
   run_test testg013  "xfstests 013, fsstress " 
   run_test testg014  "xfstests 014, truncfile " 
   run_test testg074  "xfstests 074, fstest " 
   run_test testg088  "xfstests 088, CAP_DAC_OVERRIDE/CAP_DAC_SEARC" 
   run_test testg089  "xfstests 089, emulates /etc/mtab manipulation" 
   run_test testg131  "xfstests 131, lockfile_simple" 
   run_test testg184  "xfstests 184, mknod" 
   run_test testg215  "xfstests 215, c/mtimes updates after mapped writes"
   run_test testg221  "xfstests 221, calling futimens without UTIME_OMIT"
   run_test testg236  "xfstests 236, check ctime on linked file"
   run_test testg241  "xfstests 241, dbench " 
   run_test testg246  "xfstests 246, truncation after failed writes"
   run_test testg248  "xfstests 248, pwrite on mapped pages " 
   run_test testg249  "xfstests 249, simple splice test" 
   run_test testg257  "xfstests 257, check if seek() works " 
}
