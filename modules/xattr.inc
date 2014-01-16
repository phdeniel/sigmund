#!/bin/bash

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################


### test21f : Simple set/get on a xattr on a file
SPEED[test21f]=fast
TEST_TYPE[test21f]=dev,admin,prod
NEEDS_ROOT[test21f]=no
function test21f
{
   touch file_xattr

   setfattr -n user.my_attribute  -v my_value  file_xattr || error "ERROR while setting xattr on a file"

   read_value=`getfattr -n user.my_attribute --only-values file_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test21d : Simple set/get on a xattr on a directory
SPEED[test21d]=fast
TEST_TYPE[test21d]=dev,admin,prod
NEEDS_ROOT[test21d]=no
function test21d
{
   mkdir dir_xattr

   setfattr -n user.my_attribute  -v my_value  dir_xattr || error "ERROR while setting xattr on a file"

   read_value=`getfattr -n user.my_attribute --only-values dir_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test21s : Simple set/get on a xattr on a symlink
SPEED[test21s]=fast
TEST_TYPE[test21s]=dev,admin,prod
NEEDS_ROOT[test21s]=no
function test21s
{
   touch file_xattr
   ln -s file_xattr symlink_xattr

   setfattr -n user.my_attribute  -v my_value  symlink_xattr || error "ERROR while setting xattr on a symlink"

   read_value=`getfattr -n user.my_attribute --only-values symlink_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test22f: Creates 100 xattr and then delete them on a file
SPEED[test22f]=fast
TEST_TYPE[test22f]=dev,admin,prod
NEEDS_ROOT[test22f]=no
function test22f
{ 
   MAX=10
   touch file_xattr

   for i in `seq 1 $MAX` ; do 
      setfattr -n user.attr$i  -v my_value$i  file_xattr || error "ERROR while setting xattr on a file"
   done

   # List xattr and then delete them one by one
   for i in `seq 1 $MAX` ; do 
     count=`getfattr -d  file_xattr 2>&1 | grep "user." | wc -l`
     remain=`echo "$MAX-$i+1" | bc`
     [[ $count = $remain ]] || error "ERROR bad count when deleting xattr"
     setfattr -x  user.attr$i  file_xattr
     echo "$i xattr deleted, $remain remains"
   done

   # Make sure no xattr remain 
   count=`getfattr -d  file_xattr | grep "user." | wc -l`
   (( $count == 0 )) || error "ERROR xattr remain when they are all supposed to be deleted"
}

### test22d: Creates 100 xattr and then delete them on a directory
SPEED[test22d]=fast
TEST_TYPE[test22d]=dev,admin,prod
NEEDS_ROOT[test22d]=no
function test22d
{ 
   MAX=10
   mkdir dir_xattr

   for i in `seq 1 $MAX` ; do 
      setfattr -n user.attr$i  -v my_value$i  dir_xattr || error "ERROR while setting xattr on a directory"
   done

   # List xattr and then delete them one by one
   for i in `seq 1 $MAX` ; do 
     count=`getfattr -d  dir_xattr 2>&1 | grep "user." | wc -l`
     remain=`echo "$MAX-$i+1" | bc`
     [[ $count = $remain ]] || error "ERROR bad count when deleting xattr"
     setfattr -x  user.attr$i  dir_xattr
     echo "$i xattr deleted, $remain remains"
   done

   # Make sure no xattr remain 
   count=`getfattr -d  dir_xattr | grep "user." | wc -l`
   (( $count == 0 )) || error "ERROR xattr remain when they are all supposed to be deleted"
}

### test22s: Creates 100 xattr and then delete them on a directory
SPEED[test22s]=fast
TEST_TYPE[test22s]=dev,admin,prod
NEEDS_ROOT[test22s]=no
function test22s
{ 
   MAX=10
   touch file_xattr
   ln -s file_xattr symlink_xattr

   for i in `seq 1 $MAX` ; do 
      setfattr -n user.attr$i  -v my_value$i  symlink_xattr || error "ERROR while setting xattr on a symlink"
   done

   # List xattr and then delete them one by one
   for i in `seq 1 $MAX` ; do 
     count=`getfattr -d  symlink_xattr 2>&1 | grep "user." | wc -l`
     remain=`echo "$MAX-$i+1" | bc`
     [[ $count = $remain ]] || error "ERROR bad count when deleting xattr"
     setfattr -x  user.attr$i  symlink_xattr
     echo "$i xattr deleted, $remain remains"
   done

   # Make sure no xattr remain 
   count=`getfattr -d  symlink_xattr | grep "user." | wc -l`
   (( $count == 0 )) || error "ERROR xattr remain when they are all supposed to be deleted"
}

### test23f : Set a value several times then check value
SPEED[test23f]=fast
TEST_TYPE[test23f]=dev,admin,prod
NEEDS_ROOT[test23f]=no
function test23f
{
   MAX=10
   touch file_xattr

   for i in `seq 1 $MAX` ; do
      setfattr -n user.my_attribute  -v my_value$i  file_xattr || error "ERROR while setting xattr on a file"
   done

   read_value=`getfattr -n user.my_attribute --only-values file_xattr`

   [[ $read_value = "my_value$MAX" ]] || error "ERROR after reading xattr. Bad value read"
}

### test23d :  Set a value several times then check value
SPEED[test23d]=fast
TEST_TYPE[test23d]=dev,admin,prod
NEEDS_ROOT[test23d]=no
function test23d
{
   MAX=10
   mkdir dir_xattr

   for i in `seq 1 $MAX` ; do
     setfattr -n user.my_attribute  -v my_value$i  dir_xattr || error "ERROR while setting xattr on a file"
   done 

   read_value=`getfattr -n user.my_attribute --only-values dir_xattr`

   [[ $read_value = "my_value$MAX" ]] || error "ERROR after reading xattr. Bad value read"
}

### test23s : Set a value several times then check value
SPEED[test23s]=fast
TEST_TYPE[test23s]=dev,admin,prod
NEEDS_ROOT[test23s]=no
function test23s
{
   MAX=10
   touch file_xattr
   ln -s file_xattr symlink_xattr

   for i in `seq 1 $MAX` ; do
     setfattr -n user.my_attribute  -v my_value$i  symlink_xattr || error "ERROR while setting xattr on a symlink"
   done 

   read_value=`getfattr -n user.my_attribute --only-values symlink_xattr`

   [[ $read_value = "my_value$MAX" ]] || error "ERROR after reading xattr. Bad value read"
}

### test24f : Set a trusted.* xattr on a file
SPEED[test24f]=fast
TEST_TYPE[test24f]=dev,admin,prod
NEEDS_ROOT[test24f]=yes
function test24f
{
   touch file_xattr

   setfattr -n trusted.my_attribute  -v my_value  file_xattr || error "ERROR while setting xattr on a file"

   read_value=`getfattr -n trusted.my_attribute --only-values file_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}

### test25f : Set a security.* xattr on a file
SPEED[test25f]=fast
TEST_TYPE[test25f]=dev,admin,prod
NEEDS_ROOT[test25f]=yes
function test25f
{
   touch file_xattr

   setfattr -n security.my_attribute  -v my_value  file_xattr || error "ERROR while setting xattr on a file"

   read_value=`getfattr -n security.my_attribute --only-values file_xattr`

   [[ $read_value = "my_value" ]] || error "ERROR after reading xattr. Bad value read"
}


######################## DEFINE TEST LIST HERE ####################

function run_xattr
{
  run_test test21f  "simple xattr set/get: file"
  run_test test21d  "simple xattr set/get: directory"
  run_test test21s  "simple xattr set/get: symlink"
  run_test test22f  "xattr creation/deletion: file"
  run_test test22d  "xattr creation/deletion: directory"
  run_test test22s  "xattr creation/deletion: symlink"
  run_test test23f  "mulitple sets + 1 check: file"
  run_test test23d  "mulitple sets + 1 check: directory"
  run_test test23s  "mulitple sets + 1 check: symlink"
  run_test test24f  "Set a trusted.* xattr on a file"
  run_test test25f  "Set a security.* xattr on a file"
}

