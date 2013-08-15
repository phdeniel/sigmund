#!/bin/bash

########################## TEST HELPERS ##################

function space_used
{
    df -k $TEST_DIR | xargs | awk '{ print $(NF-3)}'
}

function write_small_file
{
    file_arg=$1
    dd if=/dev/zero "of=$file_arg" bs=1M count=10 || error "ERROR writing 1OMB to $file_arg"
}

function write_small_file_random
{
    file_arg=$1
    dd if=/dev/urandom "of=$file_arg" bs=1M count=10 || error "ERROR writing 1OMB to $file_arg"
}

function write_med_file_random
{
    file_arg=$1
    dd if=/dev/urandom "of=$file_arg" bs=10M count=10 || error "ERROR writing 1O0MB to $file_arg"
}

function append_file
{
    file_arg=$1
    dd if=/dev/zero "of=$file_arg" bs=1M count=10  conv=notrunc oflag=append || error "ERROR appending 1OMB to $file_arg"
}

function get_test_user
{
    # get the first user which is not in group 0 (root)
    # and who is allowed to login
    grep -v nologin /etc/passwd | grep -v ':0:' | head -1 | cut -d ':' -f 1
}

function empty_client_cache
{
    [ "$DEBUG" = "1" ] && echo "emptying client cache (data+metadata)"
    echo 3 > /proc/sys/vm/drop_caches
}

function create_tree
{
    local ROOT=$1
    local DEPTH=$2
    local WIDTH=$3

    [ -n "$ROOT" ] || error "invalid arg to $0: $1"
    [ -n "$DEPTH" ] || error "invalid arg to $0: $2"
    [ -n "$WIDTH" ] || error "invalid arg to $0: $3"

    if (($DEPTH > 0)); then
        # create a subdir
        ((nb_file=$WIDTH - 1))
        [ "$DEBUG" = "1" ] && echo "mkdir $ROOT/subdir"
        mkdir $ROOT/subdir
        create_tree $ROOT/subdir $(($DEPTH - 1)) $WIDTH
    else
        nb_file=$WIDTH
    fi

    for f in $(seq 1 $nb_file); do
        [ "$DEBUG" = "1" ] && echo "touch $ROOT/file.$f"
        touch $ROOT/file.$f
    done
}

############################ TEST FUNCTIONS ############################

### test_wr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[setup_pseudofs]=fast
TEST_TYPE[setup_pseudofs]=dev,admin,prod
NEEDS_ROOT[setup_pseudofs]=yes
function setup_pseudofs
{
    # setup only once

    # setup export config on server
    
}

### test_wr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[cleanup_pseudofs]=fast
TEST_TYPE[cleanup_pseudofs]=dev,admin,prod
NEEDS_ROOT[cleanup_pseudofs]=yes
function cleanup_pseudofs
{
    # cleanup only once

    # cleanup export config on server
}

### test_wr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[test_wr]=fast
TEST_TYPE[test_wr]=dev,admin,prod
NEEDS_ROOT[test_wr]=yes
PRE_TEST[test_wr]=setup_pseudofs
function test_wr
{
    # create user directoru
    file="$TEST_ROOT_DI/test_wr"
    touch $file
    (! $?) || "error, we should not be able to create a file in a pseudofs directory: $file"
}

### test_wr: check if writes in a pseudofs directory is allowed. Should return an error.
SPEED[test_rd]=fast
TEST_TYPE[test_rd]=dev,admin,prod
NEEDS_ROOT[test_rd]=yes
PRE_TEST[test_wr]=setup_pseudofs
function test_rd
{
    # create user directoru
    file="$TEST_ROOT_DIR/pseudofs_test"
    cat $file
    (! $?) || "error, we should not be able to create a file in a pseudofs directory: $file"
}

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_pseudofs
{
  run_test setup_pseudofs      " PSEUDOFS: Preparing server for tests                             "

  run_test test_wr             " PSEUDOFS: Attempt write of pseudofs node                         "
  run_test test_rd             " PSEUDOFS: Attempt read of pseudofs node                          "
  run_test test_rm             " PSEUDOFS: Attempt removal of pseudofs node                       "
  run_test test_lookup         " PSEUDOFS: Lookup a single pseudfs node                           "
  run_test test_readdir        " PSEUDOFS: Execute readdirplus on large directory                 "
  run_test test_ls_junction    " PSEUDOFS: Cross a junction point and list directory              "
  run_test test_check_inode    " PSEUDOFS: Check if junction shows fs inode                       "
  run_test test_remove_lookup  " PSEUDOFS: Remove export from server, make sure it's gone         "
  run_test test_remove_stat    " PSEUDOFS: Remove export from server, make sure inodes stay same  "
  run_test test_add_lookup     " PSEUDOFS: Add an export from server, make sure it's gone         "
  run_test test_add_stat       " PSEUDOFS: Add an export from server, make sure inodes stay same  "

  run_test cleanup_pseudofs    " PSEUDOFS: Cleaning up server environment                         "
}

