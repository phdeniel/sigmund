#!/bin/bash


############################ TEST FUNCTIONS ############################

### test41a: run fsx-linux with no mmap
SPEED[test41a]=medium
TEST_TYPE[test41a]=dev,admin,prod
NEEDS_ROOT[test41a]=no
function test41a
{
    file="test_file"

    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 -R -W $file  || error "error running fsx-linux on $file"
}

### test41b: run fsx-linux with mmap on write
SPEED[test41b]=medium
TEST_TYPE[test41b]=dev,admin,prod
NEEDS_ROOT[test41b]=no
function test41b
{
    file="test_file"

    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 -R $file  || error "error running fsx-linux on $file"
}

### test41c: run fsx-linux with mmap on read
SPEED[test41c]=medium
TEST_TYPE[test41c]=dev,admin,prod
NEEDS_ROOT[test41c]=no
function test41c
{
    file="test_file"

    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 -W $file  || error "error running fsx-linux on $file"
}


### test41d: run fsx-linux with mmap on read+write
SPEED[test41d]=medium
TEST_TYPE[test41d]=dev,admin,prod
NEEDS_ROOT[test41d]=no
function test41d
{
    file="test_file"

    touch $file

    $LTPDIR/testcases/bin/fsx-linux -N 10000 -c 40 $file  || error "error running fsx-linux on $file"
}

### test42b: run bonnie++ with a reduced memory size
SPEED[test42b]=longest
TEST_TYPE[test42b]=dev
NEEDS_ROOT[test42b]=no
function test42b
{
    dir="test_dir"

    mkdir -p $dir
    bonnie++ -d $dir -c 10  -u 0 -s 1:256 -x 1 -r 2
}

### test43f: run fsstress on 30 procs
SPEED[test43f]=medium
TEST_TYPE[test43f]=dev
NEEDS_ROOT[test43f]=no
function test43f
{
    # create user directory
    dir="test_dir"

    mkdir -p $dir
    $LTPDIR/testcases/bin/fsstress -d $dir -l 10 -n 100 -p 30 -v -S || error "error running fsstress on $dir"
}

### test44f: run LTP's growfiles fast tests
SPEED[test44f]=medium
TEST_TYPE[test44f]=dev,admin,prod
NEEDS_ROOT[test44f]=no
function test44f
{
    # growfiles catches sigint and exits OK, thus keeps on running.
    # catch it so we don't need to continue
    trap "exit 1" INT

    # create user directory
    dir="test_dir"

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
}

### test44s: run LTP's growfiles slow tests
SPEED[test44s]=longest
TEST_TYPE[test44s]=dev
NEEDS_ROOT[test44s]=no
function test44s
{
    # growfiles catches sigint and exits OK, thus keeps on running.
    # catch it so we don't need to continue
    trap "exit 1" INT

    # create user directory
    dir="test_dir"

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
}

### test45a: run LTP's chdir tests
SPEED[test45a]=fast
TEST_TYPE[test45a]=dev,admin
NEEDS_ROOT[test45a]=no
function test45a
{
    $LTPDIR/testcases/bin/chdir01 || error "error running chdir01"
    $LTPDIR/testcases/bin/chdir02 || error "error running chdir02"
    $LTPDIR/testcases/bin/chdir03 || error "error running chdir03"
    $LTPDIR/testcases/bin/chdir04 || error "error running chdir04"
}

### test45b: run LTP's chmod tests
SPEED[test45b]=fast
TEST_TYPE[test45b]=dev,admin
NEEDS_ROOT[test45b]=yes
function test45b
{
    $LTPDIR/testcases/bin/chmod01 || error "error running chmod01"
    $LTPDIR/testcases/bin/symlink01 -T chmod01 || error "error running symlink01"
    $LTPDIR/testcases/bin/chmod02 || error "error running chmod02"
    $LTPDIR/testcases/bin/chmod03 || error "error running chmod03"
    $LTPDIR/testcases/bin/chmod04 || error "error running chmod04"
    $LTPDIR/testcases/bin/chmod05 || error "error running chmod04"
    $LTPDIR/testcases/bin/chmod06 || error "error running chmod04"
    $LTPDIR/testcases/bin/chmod07 || error "error running chmod07"
}

### test45c: run LTP's chown tests
SPEED[test45c]=fast
TEST_TYPE[test45c]=dev,admin
NEEDS_ROOT[test45c]=no
function test45c
{
    $LTPDIR/testcases/bin/chown01 || error "error running chown01"
    $LTPDIR/testcases/bin/chown02 || error "error running chown02"
    $LTPDIR/testcases/bin/chown03 || error "error running chown02"
    $LTPDIR/testcases/bin/chown04 || error "error running chown02"
    $LTPDIR/testcases/bin/chown05 || error "error running chown05"

    #PL, 1 juin 2016, TCONF==32 returned by ltpfs
    #$LTPDIR/testcases/bin/chown01_16 || error "error running chown01_16"
    $LTPDIR/testcases/bin/chown01_16 || ret_code=$?
    if (( ret_code != 32 && ret_code != 0 )); then
        error "error running chown01_16"
    fi 
    #$LTPDIR/testcases/bin/chown02_16 || error "error running chown02_16"
    $LTPDIR/testcases/bin/chown02_16 || ret_code=$?
    if (( ret_code != 32 && ret_code != 0 )); then
        error "error running chown02_16"
    fi 
    #$LTPDIR/testcases/bin/chown03_16 || error "error running chown02_16"
    $LTPDIR/testcases/bin/chown03_16 || ret_code=$?
    if (( ret_code != 32 && ret_code != 0 )); then
        error "error running chown03_16"
    fi 
    #$LTPDIR/testcases/bin/chown04_16 || error "error running chown02_16"
    $LTPDIR/testcases/bin/chown04_16 || ret_code=$?
    if (( ret_code != 32 && ret_code != 0 )); then
        error "error running chown04_16"
    fi 
    #$LTPDIR/testcases/bin/chown05_16 || error "error running chown05_16"
    $LTPDIR/testcases/bin/chown05_16 || ret_code=$?
    if (( ret_code != 32 && ret_code != 0 )); then
        error "error running chown05_16"
    fi 
}

### test45d: run LTP's chroot tests
SPEED[test45d]=fast
TEST_TYPE[test45d]=dev,admin
NEEDS_ROOT[test45d]=yes
function test45d
{
    $LTPDIR/testcases/bin/chroot01 || error "error running chroot01"
    $LTPDIR/testcases/bin/chroot02 || error "error running chroot02"
    $LTPDIR/testcases/bin/chroot03 || error "error running chroot03"
    $LTPDIR/testcases/bin/chroot04 || error "error running chroot04"
}

### test45e: run LTP's close tests
SPEED[test45e]=fast
TEST_TYPE[test45e]=dev,admin
NEEDS_ROOT[test45e]=no
function test45e
{
    $LTPDIR/testcases/bin/close01 || error "error running close01"
    $LTPDIR/testcases/bin/close02 || error "error running close02"
    $LTPDIR/testcases/bin/close08 || error "error running close08"
}

### test45f: run LTP's creat tests
SPEED[test45f]=fast
TEST_TYPE[test45f]=dev,admin
NEEDS_ROOT[test45f]=no
function test45f
{
    $LTPDIR/testcases/bin/creat01 || error "error running creat01"
    $LTPDIR/testcases/bin/creat03 || error "error running creat03"
    $LTPDIR/testcases/bin/creat04 || error "error running creat04"
    $LTPDIR/testcases/bin/creat05 || error "error running creat05"
    $LTPDIR/testcases/bin/creat06 || error "error running creat06"
    $LTPDIR/testcases/bin/creat08 || error "error running creat08"
    $LTPDIR/testcases/bin/creat09 || error "error running creat07"
}

######################## DEFINE TEST LIST HERE ####################

function run_ltpfs
{
  run_test test41a  "fsx-linux with no mmap"
  run_test test41b  "fsx-linux with mmap on write"
  run_test test41c  "fsx-linux with mmap on read"
  run_test test41d  "fsx-linux with mmap on read+write"
  run_test test42b  "run bonnie++ with a reduced memory size"
  run_test test43f  "run fsstress on 30 procs"
  run_test test44f  "run LTP's growfiles fast tests"
  run_test test44s  "run LTP's growfiles slow tests"
  run_test test45a  "run LTP's chdir tests"
  run_test test45b  "run LTP's chmod tests"
  run_test test45c  "run LTP's chown tests"
  run_test test45d  "run LTP's chroot tests"
  run_test test45e  "run LTP's close tests"
  run_test test45f  "run LTP's creat tests"
}

