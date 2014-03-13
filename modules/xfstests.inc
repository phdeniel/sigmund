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
SPEED[testg006]=medium
TEST_TYPE[testg006]=dev
NEEDS_ROOT[testg006]=no
function testg006
{
    cd $XFSTESTS_DIR 
    ./tests/generic/006 || error "error running XFSTESTS generic/006"
}

### testg007: xfstests generic/007, nametest program
SPEED[testg007]=medium
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
SPEED[testg011]=medium
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

### testg215: c/mtimes updates after mapped writes
SPEED[testg215]=fast
TEST_TYPE[testg215]=dev
NEEDS_ROOT[testg215]=no
function testg215
{
    cd $XFSTESTS_DIR 
    ./tests/generic/215 || error "error running XFSTESTS generic/215" 
}

### testg221: calling futimens without UTIME_OMIT
SPEED[testg221]=fast
TEST_TYPE[testg221]=dev
NEEDS_ROOT[testg221]=no
function testg221
{
    cd $XFSTESTS_DIR 
    ./tests/generic/221 || error "error running XFSTESTS generic/221" 
}

### testg236: check ctime on linked file
SPEED[testg236]=fast
TEST_TYPE[testg236]=dev
NEEDS_ROOT[testg236]=no
function testg236
{
    cd $XFSTESTS_DIR 
    ./tests/generic/236 || error "error running XFSTESTS generic/236" 
}

### testg241: dbench
SPEED[testg241]=fast
TEST_TYPE[testg241]=dev
NEEDS_ROOT[testg241]=no
function testg241
{
    cd $XFSTESTS_DIR 
    ./tests/generic/241 || error "error running XFSTESTS generic/241" 
}

### testg246: truncation after failed writes
SPEED[testg246]=medium
TEST_TYPE[testg246]=dev
NEEDS_ROOT[testg246]=no
function testg246
{
    cd $XFSTESTS_DIR 
    ./tests/generic/246 || error "error running XFSTESTS generic/246" 
}

### testg248: pwrite on mapped pages
SPEED[testg248]=fast
TEST_TYPE[testg248]=dev
NEEDS_ROOT[testg248]=no
function testg248
{
    cd $XFSTESTS_DIR 
    ./tests/generic/248 || error "error running XFSTESTS generic/248" 
}

### testg249: simple splice test
SPEED[testg249]=fast
TEST_TYPE[testg249]=dev
NEEDS_ROOT[testg249]=no
function testg249
{
    cd $XFSTESTS_DIR 
    ./tests/generic/249 || error "error running XFSTESTS generic/249" 
}

### testg257: check if seek() works
SPEED[testg257]=fast
TEST_TYPE[testg257]=dev
NEEDS_ROOT[testg257]=no
function testg257
{
    cd $XFSTESTS_DIR 
    ./tests/generic/257 || error "error running XFSTESTS generic/257" 
}

### testg263: fsx with direct-io
SPEED[testg263]=medium
TEST_TYPE[testg263]=dev
NEEDS_ROOT[testg263]=no
function testg263
{
    cd $XFSTESTS_DIR 
    ./tests/generic/263 || error "error running XFSTESTS generic/263" 
}

### testg285: SEEK_DATA/SEEK_HOLE sanity tests
SPEED[testg285]=fast
TEST_TYPE[testg285]=dev
NEEDS_ROOT[testg285]=no
function testg285
{
    cd $XFSTESTS_DIR 
    ./tests/generic/285 || error "error running XFSTESTS generic/285" 
}

### testg286: SEEK_DATA/SEEK_HOLE copy tests
SPEED[testg286]=fast
TEST_TYPE[testg286]=dev
NEEDS_ROOT[testg286]=no
function testg286
{
    cd $XFSTESTS_DIR 
    ./tests/generic/286 || error "error running XFSTESTS generic/286" 
}

### testg308: commit
SPEED[testg308]=fast
TEST_TYPE[testg308]=dev
NEEDS_ROOT[testg308]=no
function testg308
{
    cd $XFSTESTS_DIR 
    ./tests/generic/308 || error "error running XFSTESTS generic/308" 
}

### testg309: directory c/time when moving file onto existing file
SPEED[testg309]=fast
TEST_TYPE[testg309]=dev
NEEDS_ROOT[testg309]=no
function testg309
{
    cd $XFSTESTS_DIR 
    ./tests/generic/309 || error "error running XFSTESTS generic/309" 
}

### testg310: race in-between two threads
SPEED[testg310]=medium
TEST_TYPE[testg310]=dev
NEEDS_ROOT[testg310]=no
function testg310
{
    cd $XFSTESTS_DIR 
    ./tests/generic/310 || error "error running XFSTESTS generic/310" 
}

### testg313: check c/mtime with truncate() and ftruncate()
SPEED[testg313]=fast
TEST_TYPE[testg313]=dev
NEEDS_ROOT[testg313]=no
function testg313
{
    cd $XFSTESTS_DIR 
    ./tests/generic/313 || error "error running XFSTESTS generic/313" 
}

### testg315: fallocate/truncate with FL_KEEP_SIZE
SPEED[testg315]=fast
TEST_TYPE[testg315]=dev
NEEDS_ROOT[testg315]=no
function testg315
{
    cd $XFSTESTS_DIR 
    ./tests/generic/315 || error "error running XFSTESTS generic/315" 
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
   run_test testg215  "xfstests generic/215, c/mtimes updates after mapped writes"
   run_test testg221  "xfstests generic/221, calling futimens without UTIME_OMIT"
   run_test testg236  "xfstests generic/236, check ctime on linked file"
   run_test testg241  "xfstests generic/241, dbench " 
   run_test testg246  "xfstests generic/246, truncation after failed writes"
   run_test testg248  "xfstests generic/248, pwrite on mapped pages " 
   run_test testg249  "xfstests generic/249, simple splice test" 
   run_test testg257  "xfstests generic/257, check if seek() works " 
   run_test testg263  "xfstests generic/263, fsx with direct-io" 
   run_test testg285  "xfstests generic/285, SEEK_DATA/SEEK_HOLE sanity tests" 
   run_test testg286  "xfstests generic/286, SEEK_DATA/SEEK_HOLE copy tests"
   run_test testg308  "xfstests generic/308, commit" 
   run_test testg309  "xfstests generic/309, dir c/time when moving file onto existing file"
   run_test testg310  "xfstests generic/310, race in-between two threads" 
   run_test testg313  "xfstests generic/313, check c/mtime with truncate() and ftruncate()" 
   run_test testg315  "xfstests generic/315, fallocate/truncate with FL_KEEP_SIZE"
}
