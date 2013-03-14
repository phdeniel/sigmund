#!/bin/sh

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################

### pynfs1 : access test
function pynfs1a
{
  tmpfile=/tmp/pynfs1a.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force  access  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.0/access"

}

function pynfs2c
{
  tmpfile=/tmp/pynfs2c.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force create  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.0/create"
}

function pynfs3l 
{
  tmpfile=/tmp/pynfs3l.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force lock lockt locku  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.0/locks"
}

function pynfs4a 
{
  tmpfile=/tmp/pynfs4a.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force getattr setattr  | tee $tmpfile 
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.0/attrs"
}

function pynfs5r
{
  tmpfile=/tmp/pynfs5r.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force readdir  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.0/readdir"
}

function pynfs6l
{
  tmpfile=/tmp/pynfs6l.$$ 
  cd $PYNFS_DIR/nfs4.0 
  ./testserver.py  --maketree $PYNFS_URL  --secure --force lookup  | tee $tmpfile
  failed=`grep FAILURE $tmpfile | wc -l`
  rm  $tmpfile

  $failed || error "ERROR when running pynfs/NFSv4.0/readdir"
}

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>

######################## DEFINE TEST LIST HERE ####################

function run_pynfs40
{
  run_test pynfs1a  "pynfs/NFSv4.0/access"
  run_test pynfs2c  "pynfs/NFSv4.0/create"
  run_test pynfs3l  "pynfs/NFSv4.0/locks "
  run_test pynfs4a  "pynfs/NFSv4.0/attrs "
  run_test pynfs5r  "pynfs/NFSv4.0/rddir "
  run_test pynfs6l  "pynfs/NFSv4.0/lookup"

  # display test summary / generate outputs

  test_finalize
}

