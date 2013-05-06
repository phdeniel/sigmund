#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))

# The script uses "su", it has to be run as root
if [[ `id -u` != 0 ]] ; then
  echo "  /!\\ This script must be run as root"
  exit 1 
fi

if [[ $# = 0 ]] ; then
  echo >&2 "Usage: $0 <behavior> [-s speed] [-jq] [rcfile]"
  echo >&2 "For running a subset of tests:  ONLY=2,5 $0 <behavior> [-s speed] [-jq] [rcfile]"
fi

# Get the behavior
BEHAVIOR=$1
shift 

if [[ ! -x $CURDIR/behavior/$BEHAVIOR ]] ; then
  echo >&2 "Unknown behavior $BEHAVIOR"
  exit 1
fi

# Source the behavior
.  $CURDIR/behavior/$BEHAVIOR

# run the test
. $CURDIR/run_test.sh $*
