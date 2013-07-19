#!/bin/bash


############################ TEST FUNCTIONS ############################

### test41a: run fsx-linux with no mmap
SPEED[test41a]=medium
TEST_TYPE[test41a]=dev,admin,prod
NEEDS_ROOT[test41a]=no
function test41a
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 -R -W $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}

### test41b: run fsx-linux with mmap on write
SPEED[test41b]=medium
TEST_TYPE[test41b]=dev,admin,prod
NEEDS_ROOT[test41b]=no
function test41b
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 -R $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}

### test41c: run fsx-linux with mmap on read
SPEED[test41c]=medium
TEST_TYPE[test41c]=dev,admin,prod
NEEDS_ROOT[test41c]=no
function test41c
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 -W $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}


### test41d: run fsx-linux with mmap on read+write
SPEED[test41d]=medium
TEST_TYPE[test41d]=dev,admin,prod
NEEDS_ROOT[test41d]=no
function test41d
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir
    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 $file  || error "error running fsx-linux on $file"
	
    # clean test dir
    rm -rf $dir
}

### test42b: run bonnie++ with a reduced memory size
SPEED[test42b]=longest
TEST_TYPE[test42b]=dev
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

### test43f: run fsstress on 30 procs
SPEED[test43f]=slow
TEST_TYPE[test43f]=dev
NEEDS_ROOT[test43f]=no
function test43f
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"

    mkdir -p $dir
    $LTPDIR/testcases/bin/fsstress -d $dir -l 10 -n 100 -p 30 -v -S || error "error running fsstress on $dir"
	
    # clean test dir
    rm -rf $dir
}

### test44f: run LTP's growfiles fast tests
SPEED[test44f]=fast
TEST_TYPE[test44f]=dev
NEEDS_ROOT[test44f]=no
function test44f
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"

    mkdir -p $dir
    $LTPDIR/testcases/bin/growfiles -W gf02 -b -e 1 -L 10 -i 100 -I p -S 2 -u -f gf03_ -d $dir || error "error running growfiles's gf02"
    $LTPDIR/testcases/bin/growfiles -W gf03 -b -e 1 -g 1 -i 1 -S 150 -u -f gf05_ -d $dir || error "error running growfiles's gf03"
    $LTPDIR/testcases/bin/growfiles -W gf04 -b -e 1 -g 4090 -i 500 -t 39000 -u -f gf06_ -d $dir || error "error running growfiles's gf04"
    $LTPDIR/testcases/bin/growfiles -W gf05 -b -e 1 -g 5000 -i 500 -t 49900 -T10 -c9 -I p -u -f gf07_ -d $dir || error "error running growfiles's gf05"
    $LTPDIR/testcases/bin/growfiles -W gf19 -b -e 1 -g 5000 -i 500 -t 49900 -T10 -c9 -I p -o O_RDWR,O_CREAT,O_TRUNC -u -f gf08i_ -d $dir || error "error running growfiles's gf19"
    $LTPDIR/testcases/bin/growfiles -W gf21 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -g 20480 -T 10 -t 20480 -f gf-bld-$$ -d $dir || error "error running growfiles's gf21"
    $LTPDIR/testcases/bin/growfiles -W gf22 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -g 20480 -T 10 -t 20480 -f gf-bldf-$$ -d $dir || error "error running growfiles's gf22"
    $LTPDIR/testcases/bin/growfiles -W gf24 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -g 20480 -f gf-jbld-$$ -d $dir || error "error running growfiles's gf24"
    $LTPDIR/testcases/bin/growfiles -W gf25 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -r 1024000-2048000:2048 -R 4095-2048000 -T 1 -f gf-large-gs-$$ -d $dir || error "error running growfiles's gf25"
    $LTPDIR/testcases/bin/growfiles -W gf27 -b -D 0 -w -g 8b -C 1 -b -i 1000 -u -f gfsparse-1-$$ -d $dir || error "error running growfiles's gf27"
    $LTPDIR/testcases/bin/growfiles -W gf28 -b -D 0 -w -g 16b -C 1 -b -i 1000 -u -f gfsparse-2-$$ -d $dir || error "error running growfiles's gf28"
    $LTPDIR/testcases/bin/growfiles -W gf30 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -o O_RDWR,O_CREAT,O_SYNC -g 20480 -T 10 -t 20480 -f gf-sync-$$ -d $dir || error "error running growfiles's gf30"
    $LTPDIR/testcases/bin/growfiles -W gf30 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -o O_RDWR,O_CREAT,O_SYNC -g 20480 -T 10 -t 20480 -f gf-sync-$$ -d $dir || error "error running growfiles's gf30"
	
    # clean test dir
    rm -rf $dir
}

### test44s: run LTP's growfiles slow tests
SPEED[test44s]=longest
TEST_TYPE[test44s]=dev
NEEDS_ROOT[test44s]=no
function test44s
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"

    mkdir -p $dir
    $LTPDIR/testcases/bin/growfiles -W gf01 -b -e 1 -u -i 0 -L 20 -w -C 1 -l -I r -T 10 -f glseek20 -S 2 -d $dir || error "error running growfiles's gf01"
    $LTPDIR/testcases/bin/growfiles -W gf06 -b -e 1 -u -r 1-5000 -R 0--1 -i 0 -L 30 -C 1 -f g_rand10 -S 2 -d $dir || error "error running growfiles's gf06"
    $LTPDIR/testcases/bin/growfiles -W gf07 -b -e 1 -u -r 1-5000 -R 0--2 -i 0 -L 30 -C 1 -I p -f g_rand13 -S 2 -d $dir || error "error running growfiles's gf07"
    $LTPDIR/testcases/bin/growfiles -W gf08 -b -e 1 -u -r 1-5000 -R 0--2 -i 0 -L 30 -C 1 -f g_rand11 -S 2 -d $dir || error "error running growfiles's gf08"
    $LTPDIR/testcases/bin/growfiles -W gf09 -b -e 1 -u -r 1-5000 -R 0--1 -i 0 -L 30 -C 1 -I p -f g_rand12 -S 2 -d $dir || error "error running growfiles's gf09"
    $LTPDIR/testcases/bin/growfiles -W gf10 -b -e 1 -u -r 1-5000 -i 0 -L 30 -C 1 -I l -f g_lio14 -S 2 -d $dir || error "error running growfiles's gf10"
    $LTPDIR/testcases/bin/growfiles -W gf11 -b -e 1 -u -r 1-5000 -i 0 -L 30 -C 1 -I L -f g_lio15 -S 2 -d $dir || error "error running growfiles's gf11"
    $LTPDIR/testcases/bin/growfiles -W gf14 -b -e 1 -u -i 0 -L 20 -w -l -C 1 -T 10 -f glseek19 -S 2 -d $dir || error "error running growfiles's gf14"
    $LTPDIR/testcases/bin/growfiles -W gf15 -b -e 1 -u -r 1-49600 -I r -u -i 0 -L 120 -f Lgfile1 -d $dir || error "error running growfiles's gf15"
    $LTPDIR/testcases/bin/growfiles -W gf16 -b -e 1 -i 0 -L 120 -u -g 4090 -T 101 -t 408990 -l -C 10 -c 1000 -S 10 -f Lgf02_ -d $dir || error "error running growfiles's gf16"
    $LTPDIR/testcases/bin/growfiles -W gf17 -b -e 1 -i 0 -L 120 -u -g 5000 -T 101 -t 499990 -l -C 10 -c 1000 -S 10 -f Lgf03_ -d $dir || error "error running growfiles's gf17"
    $LTPDIR/testcases/bin/growfiles -W gf18 -b -e 1 -i 0 -L 120 -w -u -r 10-5000 -I r -l -S 2 -f Lgf04_ -d $dir || error "error running growfiles's gf18"
    $LTPDIR/testcases/bin/growfiles -W gf20 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -r 1-256000:512 -R 512-256000 -T 4 -f gfbigio-$$ -d $dir || error "error running growfiles's gf20"
    $LTPDIR/testcases/bin/growfiles -W gf23 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -r 512-64000:1024 -R 1-384000 -T 4 -f gf-inf-$$ -d $dir || error "error running growfiles's gf23"
    $LTPDIR/testcases/bin/growfiles -W gf26 -D 0 -b -i 0 -L 60 -u -B 1000b -e 1 -r 128-32768:128 -R 512-64000 -T 4 -f gfsmallio-$$ -d $dir || error "error running growfiles's gf26"
    $LTPDIR/testcases/bin/growfiles -W gf29 -b -D 0 -r 1-4096 -R 0-33554432 -i 0 -L 60 -C 1 -u -f gfsparse-3-$$ -d $dir || error "error running growfiles's gf29"
	
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
  run_test test43f  "LTPFS: run fsstress on 30 procs                    "
  run_test test44f  "LTPFS: run LTP's growfiles fast tests              "
  run_test test44s  "LTPFS: run LTP's growfiles slow tests              "
}

