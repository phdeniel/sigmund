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

### test1m: check that a user can copy 444 file
SPEED[test1m]=fast
NEEDS_ROOT[test1m]=no
function test1m
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir || error "error mkdir $dir"
    #chown $TEST_USER $dir

    # create a file as user in this dir
    dd if=/dev/zero of=$file bs=1M count=1 || "error writing $file"

    # set file 444
    chmod 444 "$file" || error "error chmod 444 $file"

    # copy the file as user
    cp $file $file.copy || "error copying $file to $file.copy"

    ls -l $file.copy || error "target file $file.copy not found"
    
    # clean test dir
    rm -rf $dir
}

### test1r: check if altgroups are correctly managed by the FS
SPEED[test1g]=fast
NEEDS_ROOT[test1g]=no
PRE_TEST[test1g]=pre_test1g
function test1g
{
    # create user directoru
    dir="$TEST_DIR/dir.$TEST_USER.$$"

    cd $dir/$GROUP1/$GROUP2 || "error when traversing tree with different group owners"
}

function pre_test1g
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"

    
    mkdir -p $dir || error "error mkdir $dir"
    chown $TEST_USER $dir

    cd $dir
    mkdir -m 700 $GROUP1
    chown  $TEST_USER:$GROUP1 $GROUP1

    cd  $GROUP1
    mkdir -m 700 $GROUP2
    chown  $TEST_USER:$GROUP2 $GROUP2

    cd  $dir
    cd $GROUP1/$GROUP2 || "error when traversing tree with different group owners"
}



### test1w: write a 1GB large file
SPEED[test1w]=slow
NEEDS_ROOT[test1w]=no
function test1w
{
    # create user directory
    dir="$TEST_DIR/dir.$TEST_USER.$$"
    file="$dir/test_file"

    mkdir -p $dir || error "error mkdir $dir"

    # create a file as user in this dir
    dd if=/dev/zero of=$file bs=1M count=1024 || "error writing $file"

    # clean test dir
    rm -rf $dir
}


### test2r: check recursive removal of large directories
SPEED[test2r]=very_slow
NEEDS_ROOT[test2r]=no
function test2r
{
    dir="$TEST_DIR/dir.$$"

    mkdir -p $dir

    echo "creating wide namespace..."
    create_tree $dir 2 10000
    empty_client_cache

    count=$(find $dir | wc -l)
    [ $count = 30003 ] || error "unexpected entry count in $dir"

    rm -r $dir || error "couldn't remove $dir"
}

### test3b : cthon04's basic tests
SPEED[test3b]=medium
NEEDS_ROOT[test3b]=no
function test3b
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   cd $CTHON04_DIR/basic
   export NFSTESTDIR=$dir   

   timeout -s KILL 5m ./runtests || error "ERROR while running cthon04's basic tests"
}

### test3g : cthon04's general tests
SPEED[test3g]=medium
NEEDS_ROOT[test3g]=no
function test3g
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   cd $CTHON04_DIR/general
   export NFSTESTDIR=$dir   

   timeout -s KILL 5m ./runtests || error "ERROR while running cthon04's general tests"
}

### test3s : cthon04's special tests
SPEED[test3s]=medium
NEEDS_ROOT[test3s]=no
function test3s
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   cd $CTHON04_DIR/special
   export NFSTESTDIR=$dir   

   timeout -s KILL 5m ./runtests || error "ERROR while running cthon04's special tests"
}

### test3l : cthon04's lock tests
SPEED[test3l]=slow
NEEDS_ROOT[test3l]=no
function test3l
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   cd $CTHON04_DIR/lock
   export NFSTESTDIR=$dir   

   timeout -s KILL 5m ./runtests || error "ERROR while running cthon04's lock tests"
}

### test4g : git clone a local repository
SPEED[test4g]=slow
NEEDS_ROOT[test4g]=no
function test4g
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   cd $dir
   git clone $GIT_CLONE_URL || error "ERROR while cloning a git repository"
}


### test4s : force a utimes on a symlink via a tar 
SPEED[test4s]=fast
NEEDS_ROOT[test4s]=no
function test4s
{
  
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   cd $dir

   # build the tar
   mkdir testln
   touch testln/file
   ln -s file testln/link
   tar czf testln.tar.gz testln
   rm -rf testln

   # Untar the tarball
   tar xf testln.tar.gz  || error "ERROR while forcing a utimes on symbolic link via tar"
}

### test4k : untar a kernel tarball and compiles kernel
SPEED[test4k]=very_slow
NEEDS_ROOT[test4k]=no
function test4k
{
  
   dir="$TEST_DIR/dir.$$"
   kdir=`basename  $KERNEL_TAR | sed -e 's/\.tar.*$//g'`
   
   mkdir -p $dir
   cd $dir

   tar xvf $KERNEL_TAR || error "ERROR while decompresssing kernel archive"
   cd $kdir

   ( make defconfig && make -j 17 && make -j 17 modules ) ||  error "ERROR while compiling kernel"
}

### test4r : use mmap() to read a file
SPEED[test4r]=fast
NEEDS_ROOT[test4r]=no
function test4r
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   PROG=$BUILD_TEST_DIR/test_mmap_read ;
   echo "This is the fully useless content of a file to be read with mmap() !!!!!" >  $dir/file_mmap_read
   $PROG $dir/file_mmap_read || error "ERROR while reading a file using mmap()"
}


### test4w : use mmap() to write a file
SPEED[test4w]=fast
NEEDS_ROOT[test4w]=no
function test4w
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir
 
   PROG=$BUILD_TEST_DIR/test_mmap_write ;
   $PROG $dir/file_mmap_write || error "ERROR while writing a file using mmap()"
}



# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_allfs
{
  run_test test1m  " ALLFS: copy file with 444 mode            "
  run_test test1g  " ALLFS: traverse 700 dirs with altgroups   "
  run_test test1w  " ALLFS: writes a 1GB file                  "
  run_test test2r  " ALLFS: rm -rf of wide namespace           "
  run_test test3b  " ALLFS: cthon04's basic tests              "
  run_test test3g  " ALLFS: cthon04's general tests            "
  run_test test3s  " ALLFS: cthon04's special tests            "
  run_test test3l  " ALLFS: cthon04's lock tests               "
  run_test test4g  " ALLFS: git clone a local repository       "
  run_test test4s  " ALLFS: Tar calls utimes on symlink        "
  run_test test4r  " ALLFS: Use mmap() to read a file          "
  run_test test4w  " ALLFS: Use mmap() to write a file         "
  run_test test4k  " ALLFS: decompress kernel tar + compilation"

}

