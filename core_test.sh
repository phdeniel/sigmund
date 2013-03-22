#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))
RUNDIR=$CURDIR
RCFILE=$(dirname $(readlink -m $0))/run_test.rc 

# include test framework
. $CURDIR/test_framework.inc

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

export BUILD_TEST_DIR
export RCFILE

echo "$MODULES;$ONLY"

######################## DEFINE TEST LIST HERE ####################
# Tests modules to be used
if [[ -z $MODULES ]] ; then
  MODULES="allfs"
fi

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>
for m in  $MODULES ; do
  .  $CURDIR/modules/$m.inc
  RUN_CMD="run_$m"
  eval $RUN_CMD
done

# display test summary / generate outputs
test_finalize
