#!/bin/bash

CURDIR=$(dirname $(readlink -m $0))

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

su $TEST_USER -c "$CURDIR/core_test.sh $*"
