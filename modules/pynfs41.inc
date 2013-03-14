#!/bin/bash

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################

function test61d
{
  tmpfile=/tmp/test61d.$$ 
  cd $PYNFS_DIR/nfs4.1 
  ./testserver.py  --maketree $PYNFS_URL  dir  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test6/NFSv4.1/dir"
}

function test62f
{
  tmpfile=/tmp/test62f.$$ 
  cd $PYNFS_DIR/nfs4.1 
  ./testserver.py  --maketree $PYNFS_URL  file  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running test6/NFSv4.1/file"
}
# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_pynfs41
{
  run_test test61d  "test6/NFSv4.1/dir "
  run_test test62f  "test6/NFSv4.1/file"

  # display test summary / generate outputs

  test_finalize
}

