#!/bin/sh

CURDIR=`dirname $0`
# include test framework
. $CURDIR/test_framework.inc

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

# The script uses "su", it has to be run as root
if [[ `id -u` != 0 ]] ; then
  echo "  /!\\ This script must be run as root"
  exit 1 
fi


######################## DEFINE TEST LIST HERE ####################

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>
for m in  $MODULES ; do
  .  $CURDIR/$MODULES/testsuite.inc
  RUN_CMD="run_$m"
  eval $RUN_CMD
done

