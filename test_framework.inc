#!/bin/bash

NB_CPU=$(grep -c "processor" /proc/cpuinfo)

# test framework variables
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

# set current test errorneous
function error
{
    echo "ERROR: $@" 1>&2

    if (( $junit )); then
        test_end=$(date "+%s.%N")
	dur=`echo "($test_end-$test_start)" | bc -l`
	junit_report_failure "sigmund" "$MODULE: $func: $descr" "$dur" "ERROR" "$@"
    fi

    return 1
}

######################## JUNIT HELPERS (do not modify) #####################

XML="/tmp/test_report.xml"
export TMPXML_PREFIX="/tmp/report.xml.$$"
export junit

# initialize tmp files for XML report
function junit_init
{
	export -f junit_report_failure
	cp -f /dev/null $TMPXML_PREFIX.stderr
	cp -f /dev/null $TMPXML_PREFIX.stdout
	cp -f /dev/null $TMPXML_PREFIX.tc
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
function junit_report_failure # (class, test_name, time, err_type, text)
{
	class="$1"
	name="$2"
	time="$3"
	err_type="$4"
	shift 4
	error_text="$@"

	# remove quotes in name
	name=`echo "$name" | sed -e 's/"//g'`

	# skip this if already reported
	grep -q "name=\"$name\"" $TMPXML_PREFIX.tc && return 0

	echo "<testcase classname=\"$class\" name=\"$name\" time=\"$time\">" >> $TMPXML_PREFIX.tc
	echo -n "<failure type=\"$err_type\"><![CDATA[" >> $TMPXML_PREFIX.tc
	echo -n "$error_text" >> $TMPXML_PREFIX.tc
	echo "]]></failure>" 	>> $TMPXML_PREFIX.tc
	echo "</testcase>" 	>> $TMPXML_PREFIX.tc
}

# report a failure for a test
function junit_report_skipped # (class, test_name, time, text)
{
	class="$1"
	name="$2"
	time="$3"
	shift 4
	error_text="$@"

	# remove quotes in name
	name=`echo "$name" | sed -e 's/"//g'`

	# skip this if already reported
	grep -q "name=\"$name\"" $TMPXML_PREFIX.tc && return 0

	echo "<testcase classname=\"$class\" name=\"$name\" time=\"$time\">" >> $TMPXML_PREFIX.tc
	echo -n "<skipped><![CDATA[" >> $TMPXML_PREFIX.tc
	echo -n "$error_text" >> $TMPXML_PREFIX.tc
	echo "]]></skipped>" 	>> $TMPXML_PREFIX.tc
	echo "</testcase>" 	>> $TMPXML_PREFIX.tc
}

function junit_write_xml # (time, nb_failure, nb_skipped, tests)
{
	time=$1
	failure=$2
	skipped=$3
	tests=$4
	
	cp /dev/null $XML
	echo "<?xml version=\"1.0\" encoding=\"ISO8859-2\" ?>" > $XML
	echo "<testsuite name=\"sigmund.tests\" errors=\"0\" failures=\"$failure\" skipped=\"$skipped\"  tests=\"$tests\" time=\"$time\">" >> $XML
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
    export func=$1
    export descr=$2

    TEST_ERROR=0

    nonum_func=`echo $func | sed -e 's/[a-zA-Z]$//'`

    my_id=`id -u`
    outputdir=/tmp/sigmund.$$.$my_id

    mkdir -p $outputdir

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
       	if [[ "$my_id" != "0" ]] ; then 
        	NOROOT=1
		SKIPPED=1
	fi
    fi 

    # Check test type
    test_type=${TEST_TYPE[$func]}

    if [[ "$in_test_type" && ! "$test_type" =~ "$in_test_type" ]] ; then
        if  [[ $quiet == 0 ]] ; then 
        	echo "$in_test_type is set and doesn't match $test_type, skipping"
        fi
        SKIPPED=1
    fi

    if (( $SKIPPED )); then
      if  [[ $OK_ONLY = "TRUE" && $OK_EXCLUDE = "TRUE" ]] ; then
		echo "($func : skipped)" >> $SUMMARY
		NB_SKIPPED=$(($NB_SKIPPED+1))
		 if (( $junit )); then
			if [[ $NOROOT = "1" ]] ; then
                                junit_report_skipped "sigmund" "$MODULE: $func: $descr" "$dur" "SKIPPED (NEEDS ROOT)"
			else
                                junit_report_skipped "sigmund" "$MODULE: $func: $descr" "$dur" "SKIPPED"
			fi
                fi
		if (( $quiet )) ; then
			if [[ $NOROOT = "1" ]] ; then
                                printf "%-9s %-9s %-51s [${BLUE}NOROOT${NORMAL}]\n:" "$func:" "${descr:0:51}"
			else
                                printf "%-9s %-9s %-51s [${BROWN} SKIP ${NORMAL}]\n" "$MODULE:" "$func:" "${descr:0:51}"
			fi
                fi
       fi
    fi

    if [[ $OK_ONLY = "TRUE" && $OK_EXCLUDE = "TRUE" && $SKIPPED = "0" ]] ; then
        mkdir -p "$TEST_DIR"
        RUN_DIR=$(mktemp -d "$TEST_DIR/$func.XXXXXXX")
        cleanup

        mkdir -p "$RUN_DIR"
        if [[ ${NEEDS_ROOT[$func]} != "yes" && "$my_id" == 0 ]] ; then
                chown $TEST_USER: "$RUN_DIR"
        fi

        cd "$RUN_DIR"
        # Check "PRE_TEST"
        if [[ -n ${PRE_TEST[$func]} ]] ; then
            if  [[ $quiet == 0 ]] ; then 
                echo "Running ${PRE_TEST[$func]}"
	    fi
            ${PRE_TEST[$func]} 

	    # put the user in the right directory again.
	    cd "$RUN_DIR"
        fi

        # export the function, so that it could be su-ed
	export -f $func 
        if  [[ $quiet == 0 ]] ; then 
        echo
        echo "======= $func: $descr ======="
	fi
        export test_start=`date "+%s.%N"`
	if (($junit)); then
        	# write marks in junit log
		echo "==== $func: $descr ====" >> $TMPXML_PREFIX.stdout
		echo "==== $func: $descr ====" >> $TMPXML_PREFIX.stderr
    		if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
			bash -e -u -c $func 2>> $TMPXML_PREFIX.stderr >> $TMPXML_PREFIX.stdout
                else
                        if [[ "$my_id" != 0 ]] ; then
				bash -e -u -c $func 2>> $TMPXML_PREFIX.stderr >> $TMPXML_PREFIX.stdout
                        else
				su $TEST_USER -c "bash -e -u -c $func" 2>> $TMPXML_PREFIX.stderr >> $TMPXML_PREFIX.stdout
                        fi
                fi
        elif (( $quiet )) ; then
    		if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
			bash -e -u -c $func 2>> $outputdir/$func.stderr >> $outputdir/$func.stdout
		else
                        if [[ "$my_id" != 0 ]] ; then
				bash -e -u -c $func 2>> $outputdir/$func.stderr >> $outputdir/$func.stdout
			else
				su $TEST_USER -c "bash -e -u -c $func" 2>> $outputdir/$func.stderr >> $outputdir/$func.stdout
			fi
		fi
        else
    		if [[ ${NEEDS_ROOT[$func]} = "yes" ]] ; then
			bash -e -u -c $func
		else
                        if [[ "$my_id" != 0 ]] ; then
				bash -e -u -c $func
			else
				su $TEST_USER -c "bash -e -u -c $func"
			fi
		fi
        fi

        TEST_ERROR=$?
	unset -f $func

        test_end=$(date "+%s.%N")
	dur=`echo "($test_end-$test_start)" | bc -l`
        if  [[ $quiet == 0 ]] ; then 
        	echo
        	echo "duration: $dur sec"
	fi

	if (( $TEST_ERROR > 0 )); then
		echo "$func : *FAILED*" >> $SUMMARY
		NB_ERROR=$(($NB_ERROR+1))
		if (( $junit )); then
			junit_report_failure "sigmund" "$MODULE: $func: $descr" "$dur" "ERROR"
                fi
		if (( $quiet )) ; then
			printf "%-9s %-9s %-43s %6.1fs [${RED}FAILED${NORMAL}]\n" "$MODULE:" "$func:" "${descr:0:43}" "$dur"
		fi
	else
		echo "$func : OK" >> $SUMMARY
		NB_SUCCESS=$(($NB_SUCCESS+1))
		if (( $junit )); then
			junit_report_success "sigmund" "$MODULE: $func: $descr" "$dur"
		fi
		if (( $quiet )); then
			printf "%-9s %-9s %-43s %6.1fs [${GREEN}  OK  ${NORMAL}]\n" "$MODULE:" "$func:" "${descr:0:43}" "$dur"
                fi
	fi

        # Check "POST_TEST"
        if [[ ! -z ${POST_TEST[$func]} ]] ; then
	    if  [[ $quiet == 0 ]] ; then 
                echo "Running ${POST_TEST[$func]}"
	    fi
	    cd "$RUN_DIR"
            ${POST_TEST[$func]} 
        fi

        cleanup
    fi
}

function cleanup
{
    if  [[ $quiet == 0 ]] ; then
        echo "$func cleanup..."
    fi

    # cleaning test dir
    [[ -n "$RUN_DIR" ]] && rm -rf "$RUN_DIR"
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

	tfinal=`date "+%s.%N"`
	dur=`echo "($tfinal-$tinit)" | bc -l`
	echo "total test duration: $dur sec"

	#init xml report
	if (( $junit )); then
		junit_write_xml "$dur" $NB_ERROR $NB_SKIPPED $(( $NB_ERROR + $NB_SUCCESS + NB_SKIPPED ))
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

test_init()
{
	export -f error

	export tinit=`date "+%s.%N"`

	# clear summary
	cp /dev/null $SUMMARY

	#init xml report
	if (( $junit )); then
		junit_init
	fi
}
