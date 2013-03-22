#!/bin/bash

NB_CPU=$(( `grep processor /proc/cpuinfo  | tail -1 | awk '{print $(NF)}'` + 1 ))

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

SUMMARY="/tmp/test_summary.$$"

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
    TEST_ERROR=$((TEST_ERROR+1))

    if (( $junit )); then
        echo "ERROR: $@" >> $TEST_ERR_FILE
    else
        # in interactive mode, exit at first error
        rm -f $TEST_ERR_FILE
        #exit 1
    fi
}

# set current test skipped
function skip_test
{
    TEST_SKIPPED=1
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
	echo "<testsuite name=\"thomasthon.tests\" errors=\"0\" failures=\"$failure\" tests=\"$tests\" time=\"$time\">" >> $XML
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

    nonum_func=`echo $func | sed -e 's/[a-zA-Z]$//'`

    if [[ -z "$ONLY" || $ONLY = *",$func,"* ||  $ONLY = *",$nonum_func,"*  ]]; then
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
		$func 2>> $TMPXML_PREFIX.stderr >> $TMPXML_PREFIX.stdout
        elif (( $quiet )) ; then
		$func 2>> /tmp/output.$func.stderr >> /tmp/output.$func.stdout 
        else
            $func 
        fi
        test_end=`date "+%s.%N"`
	dur=`echo "($test_end-$test_start)" | bc -l`
        if  [[ $quiet == 0 ]] ; then 
        	echo
        	echo "duration: $dur sec"
	fi

	if (( $TEST_SKIPPED )); then
		echo "($func : skipped)" >> $SUMMARY
		NB_SKIPPED=$(($NB_SKIPPED+1))
	elif (( $TEST_ERROR > 0 )); then
		echo "$func : *FAILED*" >> $SUMMARY
		NB_ERROR=$(($NB_ERROR+1))
		if (( $junit )); then
			junit_report_failure "thomasthon" "$func: $descr" "$dur" "ERROR"
                elif (( $quiet )) ; then
			echo -e "$func : $descr [${RED}FAILED${NORMAL}]"
		fi
	else
		echo "$func : OK" >> $SUMMARY
		NB_SUCCESS=$(($NB_SUCCESS+1))
		if (( $junit )); then
			junit_report_success "thomasthon" "$func: $descr" "$dur"
		elif (( $quiet )); then
			echo -e "$func : $descr [${GREEN}  OK  ${NORMAL}]"
                fi
	fi
    fi
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

savedargs=$*
while getopts "qj" opt ; do
	case "$opt" in
		j)	junit=1;;
        	q)      quiet=1;;
		[?])
        		echo >&2 "Usage: $0 [-jq] [rcfile]"
        		echo >&2 "For running a subset of tests:  ONLY=2,5 $0 [-jq] [rcfile]"
			exit 1;;
	esac
done
shift $(($OPTIND-1))

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


