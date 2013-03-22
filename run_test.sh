#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))
RUNDIR=$CURDIR
# include test framework
. $CURDIR/test_framework.inc

if [ -z "$1" ]; then
    RCFILE=$(dirname $(readlink -m $0))/run_test.rc
    #echo >&2 "Usage: $0 [-jq] [rcfile]"
    #echo >&2 "For running a subset of tests:  ONLY=2,5 $0 [-jq] [rcfile]"
else
    RCFILE=$1
fi

# prepare ONLY variable
# 1,2 => ,test1,test2,
if [[ -n $ONLY ]]; then
    ONLY=",$ONLY"
    ONLY=`echo $ONLY | sed -e 's/,/,test/g'`
    ONLY="$ONLY,"
fi


if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

export BUILD_TEST_DIR

# The script uses "su", it has to be run as root
if [[ `id -u` != 0 ]] ; then
  echo "  /!\\ This script must be run as root"
  exit 1 
fi

if [[ ! -z $MODULES ]] ; then
  export MODULES
fi

if [[ ! -z $ONLY ]] ; then
  export ONLY
fi

su $TEST_USER -c "$CURDIR/core_test.sh $savedargs"
