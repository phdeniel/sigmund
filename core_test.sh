#!/bin/bash 

CURDIR=$(dirname $(readlink -m $0))
RUNDIR=$CURDIR

# include test framework
. $CURDIR/test_framework.inc

while getopts "qj" opt ; do
        case "$opt" in
                j)      export junit=1;;
                q)      export quiet=1;;
                [?])
                        echo >&2 "Usage: $0 [-jq] [rcfile]"
                        echo >&2 "For running a subset of tests:  ONLY=2,5 $0 [-jq] [rcfile]"
                        exit 1;;
        esac
done
shift $(($OPTIND-1))

if [ -z "$1" ]; then
    RCFILE=$(dirname $(readlink -m $0))/run_test.rc
    #echo >&2 "Usage: $0 [-jq] [rcfile]"
    #echo >&2 "For running a subset of tests:  ONLY=2,5 $0 [-jq] [rcfile]"
else
    RCFILE=$1
fi


if [[ -z  $RCFILE ]] ; then
	RCFILE=$(dirname $(readlink -m $0))/run_test.rc 
fi

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi

# prepare ONLY variable
# 1,2 => ,test1,test2,
if [[ -n $ONLY ]]; then
    ONLY=",$ONLY"
    ONLY=`echo $ONLY | sed -e 's/,/,test/g'`
    ONLY="$ONLY,"
fi

export BUILD_TEST_DIR
export RCFILE

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
