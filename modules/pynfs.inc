#!/bin/bash

########################## TEST HELPERS ##################

function test_pynfs40
{
  name=$1
  mytest=$2

  tmpfile=/tmp/test$name.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --outfile $tmpfile --maketree $PYNFS_URL40 $mytest
  failed=`$PYNFS_DIR/nfs4.0/showresults.py $tmpfile | grep FAILURE | wc -l`
  rm  $tmpfile

  if (( $failed != 0 )) ; then
  	error "ERROR when running tests/NFSv4.0/$mytest"
  fi

}

function test_pynfs41
{
  name=$1
  mytest=$2

  tmpfile=/tmp/test$name.$$ 
  cd $PYNFS_DIR/nfs4.1 
  ./testserver.py  --outfile $tmpfile --maketree $PYNFS_URL41 $mytest
  failed=`$PYNFS_DIR/showresults.py $tmpfile | grep FAILURE | wc -l`
  rm  $tmpfile

  if (( $failed != 0 )) ; then
  	error "ERROR when running tests/NFSv4.1/$mytest"
  fi

}


############################ TEST FUNCTIONS ############################

### test51a: pynfs4.0 tests related to access
SPEED[test51a]=fast
TEST_TYPE[test51a]=dev,admin
NEEDS_ROOT[test51a]=yes
function test51a
{
    export -f test_pynfs40

    test_pynfs40 51a access
}

### test51c: pynfs4.0 tests related to close
SPEED[test51c]=fast
TEST_TYPE[test51c]=dev,admin
NEEDS_ROOT[test51c]=yes
function test51c
{
    export -f test_pynfs40

    test_pynfs40 51c close
}

### test51C: pynfs4.0 tests related to commit
SPEED[test51C]=fast
TEST_TYPE[test51C]=dev,admin
NEEDS_ROOT[test51C]=yes
function test51C
{
    export -f test_pynfs40

    test_pynfs40 51C commit
}

### test52c: pynfs4.0 tests related to create
SPEED[test52c]=fast
TEST_TYPE[test52c]=dev,admin
NEEDS_ROOT[test52c]=yes
function test52c
{
    export -f test_pynfs40

    test_pynfs40 52c create
}

### test52g: pynfs4.0 tests related to getattr
SPEED[test52g]=fast
TEST_TYPE[test52g]=dev,admin
NEEDS_ROOT[test52g]=yes
function test52g
{
    export -f test_pynfs40

    test_pynfs40 52g getattr
}

### test52G: pynfs4.0 tests related to getfh
SPEED[test52G]=fast
TEST_TYPE[test52G]=dev,admin
NEEDS_ROOT[test52G]=yes
function test52G
{
    export -f test_pynfs40

    test_pynfs40 52G getfh
}

### test52l: pynfs4.0 tests related to link
SPEED[test52l]=fast
TEST_TYPE[test52l]=dev,admin
NEEDS_ROOT[test52l]=yes
function test52l
{
    export -f test_pynfs40

    test_pynfs40 52l link
}

### test53l: pynfs4.0 tests related to lock
SPEED[test53l]=fast
TEST_TYPE[test53l]=dev,admin
NEEDS_ROOT[test53l]=yes
function test53l
{
    export -f test_pynfs40

    test_pynfs40 53l lock
}

### test53t: pynfs4.0 tests related to lockt
SPEED[test53t]=fast
TEST_TYPE[test53t]=dev,admin
NEEDS_ROOT[test53t]=yes
function test53t
{
    export -f test_pynfs40

    test_pynfs40 53t lockt
}

### test53u: pynfs4.0 tests related to locku
SPEED[test53u]=fast
TEST_TYPE[test53u]=dev,admin
NEEDS_ROOT[test53u]=yes
function test53u
{
    export -f test_pynfs40

    test_pynfs40 53u locku
}

### test54l: pynfs4.0 tests related to lookup
SPEED[test54l]=fast
TEST_TYPE[test54l]=dev,admin
NEEDS_ROOT[test54l]=yes
function test54l
{
    export -f test_pynfs40

    test_pynfs40 54l lookup
}

### test54L: pynfs4.0 tests related to lookupp
SPEED[test54L]=fast
TEST_TYPE[test54L]=dev,admin
NEEDS_ROOT[test54L]=yes
function test54L
{
    export -f test_pynfs40

    test_pynfs40 54L lookupp
}

### test54n: pynfs4.0 tests related to nverify
SPEED[test54n]=fast
TEST_TYPE[test54n]=dev,admin
NEEDS_ROOT[test54n]=yes
function test54n
{
    export -f test_pynfs40

    test_pynfs40 54n nverify
}

### test54o: pynfs4.0 tests related to open
SPEED[test54o]=fast
TEST_TYPE[test54o]=dev,admin
NEEDS_ROOT[test54o]=yes
function test54o
{
    export -f test_pynfs40

    test_pynfs40 54o open
}

### test54c: pynfs4.0 tests related to openconfirm
SPEED[test54c]=fast
TEST_TYPE[test54c]=dev,admin
NEEDS_ROOT[test54c]=yes
function test54c
{
    export -f test_pynfs40

    test_pynfs40 54c openconfirm
}

### test54d: pynfs4.0 tests related to opendowngrade
SPEED[test54d]=fast
TEST_TYPE[test54d]=dev,admin
NEEDS_ROOT[test54d]=yes
function test54d
{
    export -f test_pynfs40

    test_pynfs40 54d opendowngrade
}

### test55p: pynfs4.0 tests related to putfh
SPEED[test55p]=fast
TEST_TYPE[test55p]=dev,admin
NEEDS_ROOT[test55p]=yes
function test55p
{
    export -f test_pynfs40

    test_pynfs40 55p putfh
}

### test55P: pynfs4.0 tests related to putpubfh
SPEED[test55P]=fast
TEST_TYPE[test55P]=dev,admin
NEEDS_ROOT[test55P]=yes
function test55P
{
    export -f test_pynfs40

    test_pynfs40 55P putpubfh
}

### test55r: pynfs4.0 tests related to putrootfh
SPEED[test55r]=fast
TEST_TYPE[test55r]=dev,admin
NEEDS_ROOT[test55r]=yes
function test55r
{
    export -f test_pynfs40

    test_pynfs40 55r putrootfh
}

### test56r: pynfs4.0 tests related to read
SPEED[test56r]=fast
TEST_TYPE[test56r]=dev,admin
NEEDS_ROOT[test56r]=yes
function test56r
{
    export -f test_pynfs40

    test_pynfs40 56r read
}

### test56d: pynfs4.0 tests related to readdir
SPEED[test56d]=fast
TEST_TYPE[test56d]=dev,admin
NEEDS_ROOT[test56d]=yes
function test56d
{
    export -f test_pynfs40

    test_pynfs40 56d readdir
}

### test56l: pynfs4.0 tests related to readlink
SPEED[test56l]=fast
TEST_TYPE[test56l]=dev,admin
NEEDS_ROOT[test56l]=yes
function test56l
{
    export -f test_pynfs40

    test_pynfs40 56l readlink
}

### test56L: pynfs4.0 tests related to releaselockowner
SPEED[test56L]=fast
TEST_TYPE[test56L]=dev,admin
NEEDS_ROOT[test56L]=yes
function test56L
{
    export -f test_pynfs40

    test_pynfs40 56L releaselockowner
}

### test56u: pynfs4.0 tests related to remove
SPEED[test56u]=fast
TEST_TYPE[test56u]=dev,admin
NEEDS_ROOT[test56u]=yes
function test56u
{
    export -f test_pynfs40

    test_pynfs40 56u remove
}

### test56R: pynfs4.0 tests related to rename
SPEED[test56R]=fast
TEST_TYPE[test56R]=dev,admin
NEEDS_ROOT[test56R]=yes
function test56R
{
    export -f test_pynfs40

    test_pynfs40 56R rename
}

### test57r: pynfs4.0 tests related to renew
SPEED[test57r]=medium
TEST_TYPE[test57r]=dev,admin
NEEDS_ROOT[test57r]=yes
function test57r
{
    export -f test_pynfs40

    test_pynfs40 57r renew
}

### test57R: pynfs4.0 tests related to restorefh
SPEED[test57R]=fast
TEST_TYPE[test57R]=dev,admin
NEEDS_ROOT[test57R]=yes
function test57R
{
    export -f test_pynfs40

    test_pynfs40 57R restorefh
}

### test57s: pynfs4.0 tests related to savefh
SPEED[test57s]=fast
TEST_TYPE[test57s]=dev,admin
NEEDS_ROOT[test57s]=yes
function test57s
{
    export -f test_pynfs40

    test_pynfs40 57s savefh
}

### test57S: pynfs4.0 tests related to secinfo
SPEED[test57S]=fast
TEST_TYPE[test57S]=dev,admin
NEEDS_ROOT[test57S]=yes
function test57S
{

  tmpfile=/tmp/test57S.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --outfile $tmpfile --maketree $PYNFS_URL40 SEC1 SEC2 SEC3 SEC4 SEC5 SEC6
  failed=`$PYNFS_DIR/nfs4.0/showresults.py $tmpfile | grep FAILURE | wc -l`
  rm  $tmpfile

  if (( $failed != 0 )) ; then
  	error "ERROR when running tests/NFSv4.0/secinfo"
  fi

}


### test57a: pynfs4.0 tests related to setattr
SPEED[test57a]=fast
TEST_TYPE[test57a]=dev,admin
NEEDS_ROOT[test57a]=yes
function test57a
{
    export -f test_pynfs40

    test_pynfs40 57a setattr
}

### test57c: pynfs4.0 tests related to setclientid
SPEED[test57c]=fast
TEST_TYPE[test57c]=dev,admin
NEEDS_ROOT[test57c]=yes
function test57c
{
    export -f test_pynfs40

    test_pynfs40 57c setclientid
}

### test57C: pynfs4.0 tests related to setclientidconfirm
SPEED[test57C]=fast
TEST_TYPE[test57C]=dev,admin
NEEDS_ROOT[test57C]=yes
function test57C
{
    export -f test_pynfs40

    test_pynfs40 57C setclientidconfirm
}

### test57v: pynfs4.0 tests related to verify
SPEED[test57v]=fast
TEST_TYPE[test57v]=dev,admin
NEEDS_ROOT[test57v]=yes
function test57v
{
    export -f test_pynfs40

    test_pynfs40 57v verify
}

### test57w: pynfs4.0 tests related to write
SPEED[test57w]=fast
TEST_TYPE[test57w]=dev,admin
NEEDS_ROOT[test57w]=yes
function test57w
{
    export -f test_pynfs40

    test_pynfs40 57w write
}

### test58a: pynfs4.0 tests related to acl
SPEED[test58a]=fast
TEST_TYPE[test58a]=dev,admin
NEEDS_ROOT[test58a]=yes
function test58a
{
    export -f test_pynfs40

    test_pynfs40 58a acl
}

### test58b: pynfs4.0 tests related to badid
SPEED[test58b]=fast
TEST_TYPE[test58b]=dev,admin
NEEDS_ROOT[test58b]=yes
function test58b
{
    export -f test_pynfs40

    test_pynfs40 58b badid
}

### test58B: pynfs4.0 tests related to block
SPEED[test58B]=fast
TEST_TYPE[test58B]=dev,admin
NEEDS_ROOT[test58B]=yes
function test58B
{
    export -f test_pynfs40

    test_pynfs40 58B block
}

### test58c: pynfs4.0 tests related to char
SPEED[test58c]=fast
TEST_TYPE[test58c]=dev,admin
NEEDS_ROOT[test58c]=yes
function test58c
{
    export -f test_pynfs40

    test_pynfs40 58c char
}

### test58C: pynfs4.0 tests related to compound
SPEED[test58C]=fast
TEST_TYPE[test58C]=dev,admin
NEEDS_ROOT[test58C]=yes
function test58C
{
    export -f test_pynfs40

    test_pynfs40 58C compound
}

### test58D: pynfs4.0 tests related to delegations
SPEED[test58D]=medium
TEST_TYPE[test58D]=dev,admin
NEEDS_ROOT[test58D]=yes
function test58D
{
    export -f test_pynfs40

    test_pynfs40 58D delegations
}

### test58d: pynfs4.0 tests related to dir
SPEED[test58d]=fast
TEST_TYPE[test58d]=dev,admin
NEEDS_ROOT[test58d]=yes
function test58d
{
    export -f test_pynfs40

    test_pynfs40 58d dir
}

### test58p: pynfs4.0 tests related to dots
SPEED[test58p]=fast
TEST_TYPE[test58p]=dev,admin
NEEDS_ROOT[test58p]=yes
function test58p
{
    export -f test_pynfs40

    test_pynfs40 58p dots
}

### test58e: pynfs4.0 tests related to emptyfh
SPEED[test58e]=fast
TEST_TYPE[test58e]=dev,admin
NEEDS_ROOT[test58e]=yes
function test58e
{
    export -f test_pynfs40

    test_pynfs40 58e emptyfh
}

### test58F: pynfs4.0 tests related to fairlocks
SPEED[test58F]=fast
TEST_TYPE[test58F]=dev,admin
NEEDS_ROOT[test58F]=yes
function test58F
{
    export -f test_pynfs40

    test_pynfs40 58f fairlocks
}

### test58P: pynfs4.0 tests related to fifo
SPEED[test58P]=fast
TEST_TYPE[test58P]=dev,admin
NEEDS_ROOT[test58P]=yes
function test58P
{
    export -f test_pynfs40

    test_pynfs40 58P fifo
}

### test58f: pynfs4.0 tests related to file
SPEED[test58f]=fast
TEST_TYPE[test58f]=dev,admin
NEEDS_ROOT[test58f]=yes
function test58f
{
    export -f test_pynfs40

    test_pynfs40 58f file
}

### test58g: pynfs4.0 tests related to ganesha
SPEED[test58g]=fast
TEST_TYPE[test58g]=dev,admin
NEEDS_ROOT[test58g]=yes
function test58g
{
    export -f test_pynfs40

    test_pynfs40 58g ganesha
}

### test59l: pynfs4.0 tests related to longname
SPEED[test59l]=fast
TEST_TYPE[test59l]=dev,admin
NEEDS_ROOT[test59l]=yes
function test59l
{
    export -f test_pynfs40

    test_pynfs40 59l longname
}

### test59m: pynfs4.0 tests related to mode000
SPEED[test59m]=fast
TEST_TYPE[test59m]=dev,admin
NEEDS_ROOT[test59m]=yes
function test59m
{
    export -f test_pynfs40

    test_pynfs40 59m mode000
}

### test59o: pynfs4.0 tests related to oldid
SPEED[test59o]=fast
TEST_TYPE[test59o]=dev,admin
NEEDS_ROOT[test59o]=yes
function test59o
{
    export -f test_pynfs40

    test_pynfs40 59o oldid
}

### test59r: pynfs4.0 tests related to replay
SPEED[test59r]=fast
TEST_TYPE[test59r]=dev,admin
NEEDS_ROOT[test59r]=yes
function test59r
{
    export -f test_pynfs40

    test_pynfs40 59r replay
}

### test59s: pynfs4.0 tests related to seqid
SPEED[test59s]=fast
TEST_TYPE[test59s]=dev,admin
NEEDS_ROOT[test59s]=yes
function test59s
{
    export -f test_pynfs40

    test_pynfs40 59s seqid
}

### test59S: pynfs4.0 tests related to socket
SPEED[test59S]=fast
TEST_TYPE[test59S]=dev,admin
NEEDS_ROOT[test59S]=yes
function test59S
{
    export -f test_pynfs40

    test_pynfs40 59S socket
}

### testXXY: pynfs4.0 tests related to socketall
SPEED[test59q]=fast
TEST_TYPE[test59q]=dev,admin
NEEDS_ROOT[test59q]=yes
function test59q
{
    export -f test_pynfs40

    test_pynfs40 59q socketall
}

### test59i: pynfs4.0 tests related to staleid
SPEED[test59i]=fast
TEST_TYPE[test59i]=dev,admin
NEEDS_ROOT[test59i]=yes
function test59i
{
    export -f test_pynfs40

    test_pynfs40 59i staleid
}

### test59j: pynfs4.0 tests related to symlink
SPEED[test59j]=fast
TEST_TYPE[test59j]=dev,admin
NEEDS_ROOT[test59j]=yes
function test59j
{
    export -f test_pynfs40

    test_pynfs40 59j symlink
}

### test59t: pynfs4.0 tests related to testtree
SPEED[test59t]=fast
TEST_TYPE[test59t]=dev,admin
NEEDS_ROOT[test59t]=yes
function test59t
{
    export -f test_pynfs40

    test_pynfs40 59t testtree
}

### test59T: pynfs4.0 tests related to timed
SPEED[test59T]=medium
TEST_TYPE[test59T]=dev,admin
NEEDS_ROOT[test59T]=yes
function test59T
{
    export -f test_pynfs40

    test_pynfs40 59T timed
}

### test59u: pynfs4.0 tests related to utf8
SPEED[test59u]=fast
TEST_TYPE[test59u]=dev,admin
NEEDS_ROOT[test59u]=yes
function test59u
{
    export -f test_pynfs40

    test_pynfs40 59u utf8
}

### testXXY: pynfs4.0 tests related to writedelegations
SPEED[test59w]=fast
TEST_TYPE[test59w]=dev,admin
NEEDS_ROOT[test59w]=yes
function test59w
{
    export -f test_pynfs40

    test_pynfs40 59w writedelegations
}


############################ TEST FUNCTIONS ############################

### test61g: pynfs4.1 tests related to getfh
SPEED[test61g]=fast
TEST_TYPE[test61g]=dev,admin
NEEDS_ROOT[test61g]=yes
function test61g
{
    export -f test_pynfs41

    test_pynfs41 61g getfh
}

### test61p: pynfs4.1 tests related to putfh
SPEED[test61p]=fast
TEST_TYPE[test61p]=dev,admin
NEEDS_ROOT[test61p]=yes
function test61p
{
    export -f test_pynfs41

    test_pynfs41 61l putfh
}

### test62l: pynfs4.1 tests related to getfh
SPEED[test62l]=fast
TEST_TYPE[test62l]=dev,admin
NEEDS_ROOT[test62l]=yes
function test62l
{
    export -f test_pynfs41

    test_pynfs41 62l lookup
}

### test62p: pynfs4.1 tests related to getfh
SPEED[test62p]=fast
TEST_TYPE[test62p]=dev,admin
NEEDS_ROOT[test62p]=yes
function test62p
{
    export -f test_pynfs41

    test_pynfs41 62p lookupp
}

### test63r: pynfs4.1 tests related to rename
SPEED[test63r]=medium
TEST_TYPE[test63r]=dev,admin
NEEDS_ROOT[test63r]=yes
function test63r
{
    export -f test_pynfs41

    test_pynfs41 63r rename
}

### test63v: pynfs4.1 tests related to verify
SPEED[test63v]=fast
TEST_TYPE[test63v]=dev,admin
NEEDS_ROOT[test63v]=yes
function test63v
{
    export -f test_pynfs41

    test_pynfs41 63v verify
}

### test64d: pynfs4.1 tests related to destroy_clientid
SPEED[test64d]=fast
TEST_TYPE[test64d]=dev,admin
NEEDS_ROOT[test64d]=yes
function test64d
{
    export -f test_pynfs41

    test_pynfs41 64d destroy_clientid
}


### test65d: pynfs4.1 tests related to dirs
SPEED[test65d]=fast
TEST_TYPE[test65d]=dev,admin
NEEDS_ROOT[test65d]=yes
function test65d
{
    export -f test_pynfs41

    test_pynfs41 65d dir
}

### test66d: pynfs4.1 tests related to dots
SPEED[test66d]=fast
TEST_TYPE[test66d]=dev,admin
NEEDS_ROOT[test66d]=yes
function test66d
{
    export -f test_pynfs41

    test_pynfs41 66d dots
}

### test66e: pynfs4.1 tests related to emptyfh
SPEED[test66e]=fast
TEST_TYPE[test66e]=dev,admin
NEEDS_ROOT[test66e]=yes
function test66e
{
    export -f test_pynfs41

    test_pynfs41 66e emptyfh
}

### test67f: pynfs4.1 tests related to file
SPEED[test67f]=fast
TEST_TYPE[test67f]=dev,admin
NEEDS_ROOT[test67f]=yes
function test67f
{
    export -f test_pynfs41

    test_pynfs41 67f file
}

### test67F: pynfs4.1 tests related to fifo
SPEED[test67F]=fast
TEST_TYPE[test67F]=dev,admin
NEEDS_ROOT[test67F]=yes
function test67F
{
    export -f test_pynfs41

    test_pynfs41 67F fifo
}

### test67S: pynfs4.1 tests related to socket
SPEED[test67S]=fast
TEST_TYPE[test67S]=dev,admin
NEEDS_ROOT[test67S]=yes
function test67S
{
    export -f test_pynfs41

    test_pynfs41 67S socket
}

### test67s: pynfs4.1 tests related to symlink
SPEED[test67s]=fast
TEST_TYPE[test67s]=dev,admin
NEEDS_ROOT[test67s]=yes
function test67s
{
    export -f test_pynfs41

    test_pynfs41 67s symlink
}

### test68s: pynfs4.1 tests related to reclaim_complete
SPEED[test68s]=fast
TEST_TYPE[test68s]=dev,admin
NEEDS_ROOT[test68s]=yes
function test68s
{
    export -f test_pynfs41

    test_pynfs41 68s reclaim_complete
}

### test68r: pynfs4.1 tests related to secinfo_no_name
SPEED[test68r]=fast
TEST_TYPE[test68r]=dev,admin
NEEDS_ROOT[test68r]=yes
function test68r
{
    export -f test_pynfs41

    test_pynfs41 68r secinfo_no_name
}

### test68t: pynfs4.1 tests related to trunking
SPEED[test68t]=fast
TEST_TYPE[test68t]=dev,admin
NEEDS_ROOT[test68t]=yes
function test68t
{
    export -f test_pynfs41

    test_pynfs41 68t trunking
}

### test68u: pynfs4.1 tests related to utf8
SPEED[test68u]=fast
TEST_TYPE[test68u]=dev,admin
NEEDS_ROOT[test68u]=yes
function test68u
{
    export -f test_pynfs41

    test_pynfs41 68u utf8
}

### test69u: pynfs4.1 tests related to all test that should suceed
SPEED[test69a]=slow
TEST_TYPE[test69a]=dev,admin
NEEDS_ROOT[test69a]=yes
function test69a
{
  tmpfile=/tmp/test69a.$$ 
  cd $PYNFS_DIR/nfs4.1 
  ./testserver.py  --outfile $tmpfile --maketree $PYNFS_URL41 $PYNFS_TEST_LIST
  failed=`$PYNFS_DIR/showresults.py $tmpfile | grep FAILURE | wc -l`
  rm  $tmpfile

  if (( $failed != 0 )) ; then
  	error "ERROR when running tests/NFSv4.1/all_succeed"
  fi

}


######################## DEFINE TEST LIST HERE ####################

function run_pynfs
{
  export -f test_pynfs40
  export -f test_pynfs41


  run_test test51a  "tests/NFSv4.0/access"                                                                   
  run_test test51c  "tests/NFSv4.0/close"                                                                    
  run_test test51C  "tests/NFSv4.0/commit"                                                                   
  run_test test52c  "tests/NFSv4.0/create"                                                                   
  run_test test52g  "tests/NFSv4.0/getattr"                                                                  
  run_test test52G  "tests/NFSv4.0/getfh"                                                                    
  run_test test52l  "tests/NFSv4.0/link"                                                                     
  run_test test53l  "tests/NFSv4.0/lock"                                                                     
  run_test test53t  "tests/NFSv4.0/lockt"                                                                    
  run_test test53u  "tests/NFSv4.0/locku"                                                                    
  run_test test54l  "tests/NFSv4.0/lookup"                                                                   
  run_test test54L  "tests/NFSv4.0/lookupp"                                                                  
  run_test test54n  "tests/NFSv4.0/nverify"
  run_test test54o  "tests/NFSv4.0/open"
  run_test test54c  "tests/NFSv4.0/openconfirm"
  run_test test54d  "tests/NFSv4.0/opendowngrade"
  run_test test55p  "tests/NFSv4.0/putfh"
  run_test test55P  "tests/NFSv4.0/putpubfh"
  run_test test55r  "tests/NFSv4.0/putrootfh"
  run_test test56r  "tests/NFSv4.0/read"
  run_test test56d  "tests/NFSv4.0/readdir"
  run_test test56l  "tests/NFSv4.0/readlink"
  run_test test56L  "tests/NFSv4.0/releaselockowner"
  run_test test56u  "tests/NFSv4.0/remove"
  run_test test56R  "tests/NFSv4.0/rename"
  run_test test57r  "tests/NFSv4.0/renew"
  run_test test57R  "tests/NFSv4.0/restorefh"
  run_test test57s  "tests/NFSv4.0/savefh"
  run_test test57S  "tests/NFSv4.0/secinfo"
  run_test test57a  "tests/NFSv4.0/setattr"
  run_test test57c  "tests/NFSv4.0/setclientid"
  run_test test57C  "tests/NFSv4.0/setclientidconfirm"
  run_test test57v  "tests/NFSv4.0/verify"
  run_test test57w  "tests/NFSv4.0/write"
  run_test test58a  "tests/NFSv4.0/acl"
  run_test test58b  "tests/NFSv4.0/badid"
  run_test test58B  "tests/NFSv4.0/block"
  run_test test58c  "tests/NFSv4.0/char"
  run_test test58C  "tests/NFSv4.0/compound"
  run_test test58D  "tests/NFSv4.0/delegations"
  run_test test58d  "tests/NFSv4.0/dir"
  run_test test58p  "tests/NFSv4.0/dots"
  run_test test58e  "tests/NFSv4.0/emptyfh"
  run_test test58F  "tests/NFSv4.0/fairlocks"
  run_test test58P  "tests/NFSv4.0/fifo"
  run_test test58f  "tests/NFSv4.0/file"
  run_test test58g  "tests/NFSv4.0/ganesha"
  run_test test59l  "tests/NFSv4.0/longname"
  run_test test59m  "tests/NFSv4.0/mode000"
  run_test test59o  "tests/NFSv4.0/oldid"
  run_test test59r  "tests/NFSv4.0/replay"
  run_test test59s  "tests/NFSv4.0/seqid"
  run_test test59S  "tests/NFSv4.0/socket"
  run_test test59q  "tests/NFSv4.0/socketall"
  run_test test59i  "tests/NFSv4.0/staleid"
  run_test test59j  "tests/NFSv4.0/symlink"
  run_test test59t  "tests/NFSv4.0/testtree"
  run_test test59T  "tests/NFSv4.0/timed"
  run_test test59u  "tests/NFSv4.0/utf8"
  run_test test59w  "tests/NFSv4.0/writedelegations"
  run_test test61g  "tests/NFSv4.1/getfh"
  run_test test61p  "tests/NFSv4.1/putfh"
  run_test test62l  "tests/NFSv4.1/lookup"
  run_test test62p  "tests/NFSv4.1/lookupp"
  run_test test63r  "tests/NFSv4.1/rename"
  run_test test63v  "tests/NFSv4.1/verify"
  run_test test64d  "tests/NFSv4.1/destroy_clientid"
  run_test test65d  "tests/NFSv4.1/dir"
  run_test test66d  "tests/NFSv4.1/dots"
  run_test test66e  "tests/NFSv4.1/emptyfh"
  run_test test67f  "tests/NFSv4.1/file"
  run_test test67F  "tests/NFSv4.1/fifo"
  run_test test67S  "tests/NFSv4.1/socket"
  run_test test67s  "tests/NFSv4.1/symlink"
  run_test test68r  "tests/NFSv4.1/reclaim_complete"
  run_test test68s  "tests/NFSv4.1/secinfo_no_name"
  run_test test68t  "tests/NFSv4.1/trunking"
  run_test test68u  "tests/NFSv4.1/utf8"
  run_test test69a  "tests/NFSv4.1/all_succeed"


  # display test summary / generate outputs

  test_finalize
}


