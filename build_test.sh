#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))
# include test framework
. $CURDIR/test_framework.inc
export BUILD_TEST_DIR
export GIT_PYNFS_URL

if [ -z "$1" ]; then
    RCFILE=$CURDIR/run_test.rc
else
    RCFILE=$1
fi

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

######################## DEFINE TEST LIST HERE ####################

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>
SAVED=`pwd`

# Create BUILD_TEST_DIR
mkdir -p $BUILD_TEST_DIR || exit 1 

cd $CURDIR
MODULES=`ls  modules/ | sed -e 's/\.inc//g'` 

cd test_progs
for m in  $MODULES ; do
	make $m
done
cd $SAVED
