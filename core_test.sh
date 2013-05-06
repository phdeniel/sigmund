#!/bin/bash 

CURDIR=$(dirname $(readlink -m $0))
RUNDIR=$CURDIR

# include test framework
. $CURDIR/test_framework.inc

# By default, speed allows every test
speed=longest

while getopts "qjs:" opt ; do
        case "$opt" in
                j)      export junit=1;;
                q)      export quiet=1;;
                s)	export speed=$OPTARG;;
                [?])
                        echo >&2 "Usage: $0 [-s speed] [-jq] [rcfile]"
                        echo >&2 "For running a subset of tests:  ONLY=2,5 $0i [-s speed] [-jq] [rcfile]"
                        exit 1;;
        esac
done
shift $(($OPTIND-1))

export in_valspeed=${VALSPEED[$speed]}
if [ -z "$in_valspeed" ]; then
	echo "$speed is not a valid input. Allowed speed are longest|very_slow|slow|medium|fast"
	exit 1 
fi

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

# prepare EXCLUDE variable
# 1,2 => ,test1,test2,
if [[ -n $EXCLUDE ]]; then
    EXCLUDE=",$EXCLUDE"
    EXCLUDE=`echo $EXCLUDE | sed -e 's/,/,test/g'`
    EXCLUDE="$EXCLUDE,"
fi

# Tests modules to be used
if [[ -z $MODULES ]] ; then
  MODULES="allfs"
fi

MODULES=`echo $MODULES | sed -e 's/,/ /g' | tr -s " "`


export BUILD_TEST_DIR
export RCFILE

for m in  $MODULES ; do
  .  $CURDIR/modules/$m.inc
  RUN_CMD="run_$m"
  eval $RUN_CMD
done

# display test summary / generate outputs
test_finalize
