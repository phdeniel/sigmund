#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))
# include test framework
. $CURDIR/test_framework.inc

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

######################## DEFINE TEST LIST HERE ####################

# syntax: ONLY=2,3 ./run_test.sh [-j] <test_dir>
cd test_progs
for m in  $MODULES ; do
	make $m
done
cd ..
