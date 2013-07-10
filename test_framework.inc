#!/bin/bash

NB_CPU=$(( `grep processor /proc/cpuinfo  | tail -1 | awk '{print $(NF)}'` + 1 ))

# test framework variables
TMP_TEST_ERROR=/tmp/testerror
TEST_ERROR=0
TEST_SKIPPED=0
TEST_ERR_FILE=/tmp/test_err.$$
junit=0
quiet=0

NB_SUCCESS=0
NB_SKIPPED=0
NB_ERROR=0

BLACK='\e[0;30m'
RED='\e[0;31m'
GREEN='\e[1;32m'
NORMAL='\e[0;m'
YELLOW='\e[1;33m'
BLUE='\e[1;34m'
BROWN='\e[0;33m'

SUMMARY="/tmp/test_summary.$$"

# Set the value of the speeds
declare -A SPEED
declare -A VALSPEED
VALSPEED[fast]=4
VALSPEED[medium]=3
VALSPEED[slow]=2
VALSPEED[very_slow]=1
VALSPEED[longest]=0

# declare the test types
declare -A TEST_TYPE
export VALID_TEST_TYPES=("dev" "admin" "prod")

# declare the 'NEEDS_ROOT' array
declare -A NEEDS_ROOT

#declare the 'PRE_TEST' and 'POST_TEST' arrays
declare -A PRE_TEST
declare -A POST_TEST

# clean error status before running a test
function error_reset
{
    TEST_ERROR=0
    TEST_SKIPPED=0
    cp /dev/null $TEST_ERR_FILE
}

# set current test errorneous
function error
{
    echo "ERROR: $@"

    TEST_ERROR=`cat $TMP_TEST_ERROR`
    TEST_ERROR=$((TEST_ERROR+1))

    if (( $junit )); then
        echo "ERROR: $@" >> $TEST_ERR_FILE
    else
        # in interactive mode, exit at first error
        rm -f $TEST_ERR_FILE
        #exit 1
    fi

    echo $TEST_ERROR > $TMP_TEST_ERROR
}

######################## JUNIT HELPERS (do not modify) #####################

XML="/tmp/test_report.xml"
TMPXML_PREFIX="/tmp/report.xml.$$"

# initialize tmp files for XML report
function junit_init
{
	cp /dev/null $TMPXML_PREFIX.stderr
	cp /dev/null $TMPXML_PREFIX.stdout
	cp /dev/null $TMPXML_PREFIX.tc
}

# report a success for a test
function junit_report_success # (class, test_name, time)
{
	class="$1"
	name="$2"
	time="$3"

	# remove quotes in name
	name=`echo "$name" | sed -e 's/"//g'`

	echo "<testcase classname=\"$class\" name=\"$name\" time=\"$time\" />" >> $TMPXML_PREFIX.tc
}

# report a failure for a test
function junit_report_failure # (class, test_name, time, err_type)
{
	class="$1"
	name="$2"
	time="$3"
	err_type="$4"

	# remove quotes in name
	name=`echo "$name" | sed -e 's/"//g'`

	echo "<testcase classname=\"$class\" name=\"$name\" time=\"$time\">" >> $TMPXML_PREFIX.tc
	echo -n "<failure type=\"$err_type\"><![CDATA[" >> $TMPXML_PREFIX.tc
	cat $TEST_ERR_FILE >> $TMPXML_PREFIX.tc
	echo "]]></failure>" 	>> $TMPXML_PREFIX.tc
	echo "</testcase>" 	>> $TMPXML_PREFIX.tc
}

function junit_write_xml # (time, nb_failure, tests)
{
	time=$1
	failure=$2
	tests=$3
	
	cp /dev/null $XML
	echo "<?xml version=\"1.0\" encoding=\"ISO8859-2\" ?>" > $XML
	echo "<testsuite name=\"sigmund.tests\" errors=\"0\" failures=\"$failure\" tests=\"$tests\" time=\"$time\">" >> $XML
	cat $TMPXML_PREFIX.tc 		>> $XML
	echo -n "<system-out><![CDATA[" >> $XML
	cat $TMPXML_PREFIX.stdout 	>> $XML
	echo "]]></system-out>"		>> $XML
	echo -n "<system-err><![CDATA[" >> $XML
	cat $TMPXML_PREFIX.stderr 	>> $XML
	echo "]]></system-err>" 	>> $XML
	echo "</testsuite>"		>> $XML
}

############################# TEST FRAMEWORK (do not modify) ####################

function run_test
{
    func=$1
    descr=$2

    export -f error 
    export -f create_tree
    export -f empty_client_cache

    rm -f $TMP_TEST_ERROR
    touch $TMP_TEST_ERROR
    chmod 0666 $TMP_TEST_ERROR
    export TMP_TEST_ERROR
    export TEST_ERROR=0

    nonum_func=`echo $func | sed -e 's/[a-zA-Z]$//'`

    if [[ -z "$ONLY" || $ONLY = *",$func,"* ||  $ONLY = *",$nonum_func,"*  ]] ; then
        OK_ONLY=TRUE
    else
        OK_ONLY=FALSE
    fi

    if [[ -z "$EXCLUDE" ]] ; then
	OK_EXCLUDE=TRUE
    else
      if [[ ! $EXCLUDE =  *",$func,"* && !  $EXCLUDE = *",$nonum_func,"*  ]] ; then
	OK_EXCLUDE=TRUE
      else
	OK_EXCLUDE=FALSE
      fi
    fi

    SKIPPED=0
    NOROOT=0

    # Check speed
    test_speed=${SPEED[$func]}
    test_valspeed=${VALSPEED[$test_speed]}

    if [[ "$in_valspeed" -gt  "$test_valspeed" ]] ; then
        SKIPPED=1
    fi

    # Check "NEEDS_ROOT"
    if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
        my_id=i`id -u`
	if [[ $my_id != "0" ]] ; then 
        	NOROOT=1
		SKIPPED=1
	fi
    fi 

    # Check test type
    test_type=${TEST_TYPE[$func]}

    if [[ "$in_test_type" && ! "$test_type" =~ "$in_test_type" ]] ; then
        echo "$in_test_type is set and doesn't match $test_type, skipping"
        SKIPPED=1
    fi

    if (( $SKIPPED )); then
      if  [[ $OK_ONLY = "TRUE" && $OK_EXCLUDE = "TRUE" ]] ; then
		echo "($func : skipped)" >> $SUMMARY
		NB_SKIPPED=$(($NB_SKIPPED+1))
		 if (( $junit )); then
			if [[ $NOROOT = "1" ]] ; then
                  		junit_report_failure "sigmund" "$func: $descr" "$dur" "SKIPPED (NEEDS ROOT)"
			else
                        	junit_report_failure "sigmund" "$func: $descr" "$dur" "SKIPPED"
			fi
                elif (( $quiet )) ; then
			if [[ $NOROOT = "1" ]] ; then
                  		echo -e "$func : $descr [${BLUE}NOROOT${NORMAL}]"
			else
                        	echo -e "$func : $descr [${BROWN} SKIP ${NORMAL}]"
			fi
                fi
       fi
    fi

    if [[ $OK_ONLY = "TRUE" && $OK_EXCLUDE = "TRUE" && $SKIPPED = "0" ]] ; then

        # Check "PRE_TEST"
        if [[ ! -z ${PRE_TEST[$func]} ]] ; then
            echo "I need to run  ${PRE_TEST[$func]}"
        fi

        # export the function, so that it could be su-ed
	export -f $func 

        cleanup
        error_reset
        if  [[ $quiet == 0 ]] ; then 
        echo
        echo "======= $func: $descr ======="
	fi
        test_start=`date "+%s.%N"`
	if (($junit)); then
        	# write marks in junit log
		echo "==== $func: $descr ====" >> $TMPXML_PREFIX.stdout
		echo "==== $func: $descr ====" >> $TMPXML_PREFIX.stderr
    		if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
			$func 2>> $TMPXML_PREFIX.stderr >> $TMPXML_PREFIX.stdout
                else
			su root -c $func 2>> $TMPXML_PREFIX.stderr >> $TMPXML_PREFIX.stdout
                fi
        elif (( $quiet )) ; then
    		if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
			$func 2>> /tmp/output.$func.stderr >> /tmp/output.$func.stdout 
		else
			su root -c $func 2>> /tmp/output.$func.stderr >> /tmp/output.$func.stdout 
		fi
        else
    		if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
            		$func 
		else
            		su root -c $func 
		fi
        fi

        TEST_ERROR=`cat $TMP_TEST_ERROR`
        if [[ -z $TEST_ERROR ]] ; then TEST_ERROR=0 ; fi

        test_end=`date "+%s.%N"`
	dur=`echo "($test_end-$test_start)" | bc -l`
        if  [[ $quiet == 0 ]] ; then 
        	echo
        	echo "duration: $dur sec"
	fi

	if (( $TEST_ERROR > 0 )); then
		echo "$func : *FAILED*" >> $SUMMARY
		NB_ERROR=$(($NB_ERROR+1))
		if (( $junit )); then
			junit_report_failure "sigmund" "$func: $descr" "$dur" "ERROR"
                elif (( $quiet )) ; then
			echo -e "$func : $descr [${RED}FAILED${NORMAL}]"
		fi
	else
		echo "$func : OK" >> $SUMMARY
		NB_SUCCESS=$(($NB_SUCCESS+1))
		if (( $junit )); then
			junit_report_success "sigmund" "$func: $descr" "$dur"
		elif (( $quiet )); then
			echo -e "$func : $descr [${GREEN}  OK  ${NORMAL}]"
                fi
	fi

        # Check "POST_TEST"
        if [[ ! -z ${POST_TEST[$func]} ]] ; then
            echo "I need to run  ${POST_TEST[$func]}"
        fi

    fi

    rm -f $TMP_TEST_ERROR
}

function cleanup
{
    if  [[ $quiet == 0 ]] ; then
    	echo "test cleanup..."
    fi
    # cleaning test dir
    # TODO
}

function test_finalize
{
	########### Display test summary and generate junit output ########

    	if  [[ $quiet == 0 ]] ; then
		echo
		echo "=============== TEST SUMMARY  ==============="
		cat $SUMMARY
		echo "============================================="
	fi

	#init xml report
	if (( $junit )); then
		tfinal=`date "+%s.%N"`
		dur=`echo "($tfinal-$tinit)" | bc -l`
		echo "total test duration: $dur sec"
		junit_write_xml "$dur" $NB_ERROR $(( $NB_ERROR + $NB_SUCCESS ))
		rm -f $TMPXML_PREFIX.stderr $TMPXML_PREFIX.stdout $TMPXML_PREFIX.tc
	fi

	rm -f $SUMMARY
	if (( $NB_ERROR > 0 )); then
		echo "$NB_ERROR tests FAILED, $NB_SUCCESS successful, $NB_SKIPPED skipped"
	else
		echo "All tests passed ($NB_SUCCESS successful, $NB_SKIPPED skipped)"
	fi
	#TODO remove tmp files

	exit $NB_ERROR
}

# check backend
if [ ! -d $BK_ROOT ]; then
    mkdir -p $BK_ROOT
fi

# clear summary
cp /dev/null $SUMMARY

#init xml report
if (( $junit )); then
	junit_init
	tinit=`date "+%s.%N"`
fi


