#!/bin/bash 

CURDIR=$(dirname $(readlink -m $0))

if [[ -d /etc/sigmund.d ]] ; then
  CONFDIR=/etc/sigmund.d
else
  CONFDIR=$CURDIR/sigmund.d
fi

RUNDIR=$CURDIR

if [[ $# = 0 ]] ; then
  echo >&2 "Usage: $0 <behavior> [-s speed] [-t type] [-jq] [sigmund conf dir]"
  echo >&2 "For running a subset of tests:  ONLY=2,5 $0 <behavior> [-s speed] [-t type] [-jq] [sigmund conf dir]"
  exit 1
fi

# The script uses "su", it has to be run as root
if [[ `id -u` != 0 ]] ; then
  echo "  /!\\ This script must be run as root"
  exit 1 
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



# include test framework
. $CURDIR/test_framework.inc

# By default, speed allows every test
speed=longest
# so does test_type, enabling the most thorough ones
test_type=dev

while getopts "qjs:t:p:P:" opt ; do
        case "$opt" in
                j)      export junit=1;;
                q)      export quiet=1;;
                s)	export speed=$OPTARG;;
                t)	export in_test_type=$OPTARG;;
		p)	pre_script=$OPTARG ;; 
		P)	post_script=$OPTARG ;;
                [?])
                        echo >&2 "Usage: $0 [-jq] [-s speed] [-t type] [-p pre_script] [-P post_script] [rcdir]"
                        echo >&2 "For running a subset of tests:  ONLY=2,5 $0 [-jq] [rcfile]"
                        exit 1;;
        esac
done
shift $(($OPTIND-1))

export in_valspeed=${VALSPEED[$speed]}
if [ -z "$in_valspeed" ]; then
	echo "$speed is not a valid input. Allowed speed are longest|very_slow|slow|medium|fast"
	exit 1 
fi

if [[ ! ${VALID_TEST_TYPES[*]} =~ "$in_test_type" ]]; then
	echo "$in_test_type is not a valid input. Allowed types are dev|admin|prod"
	exit 1
fi



if [ -z "$1" ]; then
    RCFILE=$CONFDIR/sigmund.conf
else
    RCFILE=$1/sigmund.conf
fi


if [[ -z  $RCFILE ]] ; then
	RCFILE=$CONFDIR/sigmund.conf
fi

if [[ -r $RCFILE ]]  ; then
   .  $RCFILE
else
  echo "  /!\\ Please make test's configuration in  $RCFILE"
  exit 1 
fi
RCDIR=`dirname $RCFILE`

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
export RCDIR

if [[ ! -z $MODULES ]] ; then
  export MODULES
fi

if [[ ! -z $ONLY ]] ; then
  export ONLY
fi

if [[ ! -z $EXCLUDE ]] ; then
  export EXCLUDE
fi

# If a pre_script is set up, run it before running the test suite
if [[ -n $pre_script ]] ; then
  eval $pre_script 
  if [[ $? != 0 ]] ; then
    if [[ $quiet -eq 0 ]] ; then 
    	echo "Pre-Script was faulty, I do not start the tests"
    fi
    exit 1
  fi
fi  

for m in  $MODULES ; do
  . $RCDIR/$m.conf
  .  $CURDIR/modules/$m.inc
  RUN_CMD="run_$m"
  eval $RUN_CMD
done

# If a post_script is set up, run it after running the test suite
if [[ -n $post_script ]] ; then
  eval $post_script 
  if [[ $? != 0 ]] ; then
    if [[ $quiet -eq 0 ]] ; then 
    	echo "Post-Script was faulty"
    fi
    exit 1
  fi
fi  

# display test summary / generate outputs
test_finalize
