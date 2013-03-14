#!/bin/sh

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################

### test51 : access test
function test51a
{
  tmpfile=/tmp/test51a.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force  access  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test5/NFSv4.0/access"

}

function test52c
{
  tmpfile=/tmp/test52c.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force create  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test5/NFSv4.0/create"
}

function test53l 
{
  tmpfile=/tmp/test53l.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force lock lockt locku  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test5/NFSv4.0/locks"
}

function test54a 
{
  tmpfile=/tmp/test54a.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force getattr setattr  | tee $tmpfile 
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test5/NFSv4.0/attrs"
}

function test55r
{
  tmpfile=/tmp/test55r.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force readdir  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test5/NFSv4.0/readdir"
}

function test56l
{
  tmpfile=/tmp/test56l.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force lookup  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test5/NFSv4.0/readdir"
}

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_test540
{
  run_test test51a  "test5/NFSv4.0/access"
  run_test test52c  "test5/NFSv4.0/create"
  run_test test53l  "test5/NFSv4.0/locks "
  run_test test54a  "test5/NFSv4.0/attrs "
  run_test test55r  "test5/NFSv4.0/rddir "
  run_test test56l  "test5/NFSv4.0/lookup"

  # display test summary / generate outputs

  test_finalize
}

