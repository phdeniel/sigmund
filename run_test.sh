#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))
RUNDIR=$CURDIR
# include test framework
. $CURDIR/test_framework.inc

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

export BUILD_TEST_DIR

######################## DEFINE TEST LIST HERE ####################
# Tests modules to be used
if [[ -z $MODULES ]] ; then
  MODULES="allfs"
fi

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>
echo $MODULES
for m in  $MODULES ; do
  echo "==> $m"
  .  $CURDIR/modules/$m.inc
  RUN_CMD="run_$m"
  eval $RUN_CMD
done

