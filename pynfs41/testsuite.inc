#!/bin/sh

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################

function pynfs1d
{
  tmpfile=/tmp/pynfs1d.$$ 
  cd $PYNFS_DIR/nfs4.1 
  ./testserver.py  --maketree $PYNFS_URL  dir  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.1/dir"
}

function pynfs2f
{
  tmpfile=/tmp/pynfs2f.$$ 
  cd $PYNFS_DIR/nfs4.1 
  ./testserver.py  --maketree $PYNFS_URL  file  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.1/file"
}
# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_pynfs41
{
  run_test pynfs1d  "pynfs/NFSv4.1/dir "
  run_test pynfs2f  "pynfs/NFSv4.1/file"

  # display test summary / generate outputs

  test_finalize
}

