#!/bin/bash

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################


### test21f : Simple set/get on a xattr on a file
function test21f
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/file_xattr
   touch $dir/file_xattr

   setfattr -n user.my_attribute  -v my_value  $dir/file_xattr || error "ERROR while setting xattr on a file"

   read_value=`getfattr -n user.my_attribute --only-values $dir/file_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test21d : Simple set/get on a xattr on a directory
function test21d
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/dir_xattr
   mkdir $dir/dir_xattr

   setfattr -n user.my_attribute  -v my_value  $dir/dir_xattr || error "ERROR while setting xattr on a file"

   read_value=`getfattr -n user.my_attribute --only-values $dir/dir_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test21s : Simple set/get on a xattr on a symlink
function test21s
{
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/file_xattr  $dir/symlink_xattr
   touch $dir/file_xattr
   ln -s $dir/file_xattr $dir/symlink_xattr

   setfattr -n user.my_attribute  -v my_value  $dir/symlink_xattr || error "ERROR while setting xattr on a symlink"

   read_value=`getfattr -n user.my_attribute --only-values $dir/symlink_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test22f: Creates 100 xattr and then delete them on a file
function test22f
{ 
   MAX=10
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/file_xattr
   touch $dir/file_xattr

   for i in `seq 1 $MAX` ; do 
      setfattr -n user.attr$i  -v my_value$i  $dir/file_xattr || error "ERROR while setting xattr on a file"
   done

   # List xattr and then delete them one by one
   for i in `seq 1 $MAX` ; do 
     count=`getfattr -d  $dir/file_xattr 2>&1 | grep "user." | wc -l`
     remain=`echo "$MAX-$i+1" | bc`
     [[ $count = $remain ]] || error "ERROR bad count when deleting xattr"
     setfattr -x  user.attr$i  $dir/file_xattr 
     echo "$i xattr deleted, $remain remains"
   done

   # Make sure no xattr remain 
   count=`getfattr -d  $dir/file_xattr | grep "user." | wc -l`
   (( $count > 0 )) && error "ERROR xattr remain when they are all supposed to be deleted"
}

### test22d: Creates 100 xattr and then delete them on a directory
function test22d
{ 
   MAX=10
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/dir_xattr
   mkdir $dir/dir_xattr

   for i in `seq 1 $MAX` ; do 
      setfattr -n user.attr$i  -v my_value$i  $dir/dir_xattr || error "ERROR while setting xattr on a directory"
   done

   # List xattr and then delete them one by one
   for i in `seq 1 $MAX` ; do 
     count=`getfattr -d  $dir/dir_xattr 2>&1 | grep "user." | wc -l`
     remain=`echo "$MAX-$i+1" | bc`
     [[ $count = $remain ]] || error "ERROR bad count when deleting xattr"
     setfattr -x  user.attr$i  $dir/dir_xattr 
     echo "$i xattr deleted, $remain remains"
   done

   # Make sure no xattr remain 
   count=`getfattr -d  $dir/dir_xattr | grep "user." | wc -l`
   (( $count > 0 )) && error "ERROR xattr remain when they are all supposed to be deleted"
}

### test22s: Creates 100 xattr and then delete them on a directory
function test22s
{ 
   MAX=10
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/file_xattr  $dir/symlink_xattr
   touch $dir/file_xattr
   ln -s $dir/file_xattr $dir/symlink_xattr

   for i in `seq 1 $MAX` ; do 
      setfattr -n user.attr$i  -v my_value$i  $dir/symlink_xattr || error "ERROR while setting xattr on a symlink"
   done

   # List xattr and then delete them one by one
   for i in `seq 1 $MAX` ; do 
     count=`getfattr -d  $dir/symlink_xattr 2>&1 | grep "user." | wc -l`
     remain=`echo "$MAX-$i+1" | bc`
     [[ $count = $remain ]] || error "ERROR bad count when deleting xattr"
     setfattr -x  user.attr$i  $dir/symlink_xattr 
     echo "$i xattr deleted, $remain remains"
   done

   # Make sure no xattr remain 
   count=`getfattr -d  $dir/symlink_xattr | grep "user." | wc -l`
   (( $count > 0 )) && error "ERROR xattr remain when they are all supposed to be deleted"
}

### test23f : Set a value several times then check value
function test23f
{
   MAX=10
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/file_xattr
   touch $dir/file_xattr

   for i in `seq 1 $MAX` ; do
      setfattr -n user.my_attribute  -v my_value$i  $dir/file_xattr || error "ERROR while setting xattr on a file"
   done

   read_value=`getfattr -n user.my_attribute --only-values $dir/file_xattr`

   [[ $read_value = "my_value$MAX" ]] || error "ERROR after reading xattr. Bad value read"
}

### test23d :  Set a value several times then check value
function test23d
{
   MAX=10
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/dir_xattr
   mkdir $dir/dir_xattr

   for i in `seq 1 $MAX` ; do
     setfattr -n user.my_attribute  -v my_value$i  $dir/dir_xattr || error "ERROR while setting xattr on a file"
   done 

   read_value=`getfattr -n user.my_attribute --only-values $dir/dir_xattr`

   [[ $read_value = "my_value$MAX" ]] || error "ERROR after reading xattr. Bad value read"
}

### test23s : Set a value several times then check value
function test23s
{
   MAX=10
   dir="$TEST_DIR/dir.$$"
   mkdir -p $dir

   rm -fr $dir/file_xattr  $dir/symlink_xattr
   touch $dir/file_xattr
   ln -s $dir/file_xattr $dir/symlink_xattr

   for i in `seq 1 $MAX` ; do
     setfattr -n user.my_attribute  -v my_value$i  $dir/symlink_xattr || error "ERROR while setting xattr on a symlink"
   done 

   read_value=`getfattr -n user.my_attribute --only-values $dir/symlink_xattr`

   [[ $read_value = "my_value$MAX" ]] || error "ERROR after reading xattr. Bad value read"
}

######################## DEFINE TEST LIST HERE ####################

function run_xattr
{
  run_test test21f  "XATTR: simple xattr set/get : file        "
  run_test test21d  "XATTR: simple xattr set/get : directory   "
  run_test test21s  "XATTR: simple xattr set/get : symlink     "
  run_test test22f  "XATTR: xattr creation/deletion : file     "
  run_test test22d  "XATTR: xattr creation/deletion : directory"
  run_test test22s  "XATTR: xattr creation/deletion : symlink  "
  run_test test23f  "XATTR: mulitple sets + 1 check : file     "
  run_test test23d  "XATTR: mulitple sets + 1 check : directory"
  run_test test23s  "XATTR: mulitple sets + 1 check : symlink  "
  
}

