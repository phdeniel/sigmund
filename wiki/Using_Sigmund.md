= Using the Sigmund Test Suite = 

Sigmund is an export about regresssions ;-) 
It has been designed to detect regression in filesystems in order to help locating them and curing them.

Sigmund is modular and fully written in bash to ease extensibility.

== Configuring sigmund ==

In order to run Sigmund, you'll need a few programs. They are well known products and no part of sigmund, so I don not integrate them in the repository. There may be license conflict as well.

=== Getting the prerequiste ===

The prerequisite are:
* the cthon04 test suite from Oracle
* the pynfs test suite

=== Setting Up Sigmund ===

There are 2 steps
* Configuring run_test.tc
* building the tests

==== Write the configuration file ====
In sigmund's root directory, edit the run_test.rc file
It will look like this:

 ##### Root of test  #####
 TEST_DIR=/mnt/sigmund
 BUILD_TEST_DIR=/tmp/sigmund
 
 ##### Variables to be used by module allfs #####
 # Path to cthon04 test's suite
 CTHON04_DIR=/opt/cthon04
 GIT_CLONE_URL=/opt/GANESHA/.git
 
 # Non-root user that will run part of the test
 TEST_USER=phil
  
 # Primary group for the TEST_USER
 GROUP1=users
 
 # One of the alternate group for TEST_USER
 GROUP2=ganesha
 
Important variables are
* '''TEST_USER''': the user whose identity will be used to run the tests 
* '''GROUP1''': Primary group for TEST_USER
* '''GROUP2''': one of the secondary groups (or alternate groups) for TEST_USER
* '''TEST_DIR''': the directory, inside the mount point to be tested, were Sigmund will be run. Make sure that '''TEST_USER''' can read and write in it
* '''BUILD_TEST_DIR''': a temporary directory where a few C programs will be generated. Make sure that '''TEST_USER''' can read and write in it
* '''CTHON04_DIR''': the directory where ctho04 was installed. '''TEST_USER''' must be abe to read/execute in it.
* '''GIT_CLONE_URL''' : a git repository that '''TEST_USER''' can read (even in a read-only way). I recommend a local repo for generating a bigger stress to the filesystem

==== Build the tests ====

The procedure is quite simple

 # ./build_test.sh 
 test_mmap_read compiled and moved to  /tmp/sigmund
 test_mmap_write compiled and moved to  /tmp/sigmund

=== Running Sigmund ===

==== Behaviours ====
Sigmund is designed to be run on top of various filesystems. Each type of FS to be tested is a '''behavior'''. Behavior can be easily added to Sigmund by adding a file in the behavior/ directory in Sigmund's source tree.
Currently supported behaviors currently are: 
* 9p 
* ext4  
* lustre  
* nfs
Regarding the chose behavior, some tests will be run of not. For example, xattr tests won't run on '''nfs''' but will on '''9p''' and '''lustre'''. 

==== Running tests ====
The default way of running sigmund will starts all of the tests. Please not that, even if TEST_USER is not root, the tests are to be run as root (there will be later calls to "su").
You can do it in three way:
* running it in verbose mode : use '''./sigmund.sh behavior'''
* running it in verbose mode with extra JUnit report. This is designed for integration in jenkins : '''./sigmund.sh behavior -j'''
* running it in quiet mode : use '''./sigmund.sh behavior -q'''

When run in quiet mode, ouput will look like this:

 # ./sigmund.sh ext4 -q
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [  OK  ]
 test2r :  ALLFS: rm -rf of wide namespace            [  OK  ]
 test3b :  ALLFS: cthon04's basic tests               [  OK  ]
 test3g :  ALLFS: cthon04's general tests             [  OK  ]
 test3s :  ALLFS: cthon04's special tests             [  OK  ]
 test3l :  ALLFS: cthon04's lock tests                [  OK  ]
 test4g :  ALLFS: git clone a local repository        [  OK  ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test4w :  ALLFS: Use mmap() to write a file          [  OK  ]
 test21f : XATTR: simple xattr set/get : file         [  OK  ]
 test21d : XATTR: simple xattr set/get : directory    [  OK  ]
 test21s : XATTR: simple xattr set/get : symlink      [  OK  ]
 test22f : XATTR: xattr creation/deletion : file      [  OK  ]
 test22d : XATTR: xattr creation/deletion : directory [  OK  ]
 test22s : XATTR: xattr creation/deletion : symlink   [  OK  ]
 test23f : XATTR: mulitple sets + 1 check : file      [  OK  ]
 test23d : XATTR: mulitple sets + 1 check : directory [  OK  ]
 test23s : XATTR: mulitple sets + 1 check : symlink   [  OK  ]
 All tests passed (20 successful, 0 skipped)

You can restrict t a subset of the tests by setting the '''ONLY''' variable.

 # ONLY=4 ./sigmund.sh ext4 -q
 test4g :  ALLFS: git clone a local repository        [  OK  ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test4w :  ALLFS: Use mmap() to write a file          [  OK  ]
 All tests passed (4 successful, 0 skipped)

or (a more sophiticated example)

 # ONLY=1,3,4s ./sigmund.sh ext4 -q
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [  OK  ]
 test3b :  ALLFS: cthon04's basic tests               [  OK  ]
 test3g :  ALLFS: cthon04's general tests             [  OK  ]
 test3s :  ALLFS: cthon04's special tests             [  OK  ]
 test3l :  ALLFS: cthon04's lock tests                [  OK  ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 All tests passed (7 successful, 0 skipped)

The '''EXCLUDE''' variable can be used to selct tests as well. '''EXCLUDE''' is kind of "negative '''ONLY'''". 
Tests listed in '''EXCLUDE''' won't be run.

Example : do not run test2r

 # EXCLUDE=2  ./sigmund.sh ext4 -q
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [  OK  ]
 test3b :  ALLFS: cthon04's basic tests               [  OK  ]
 test3g :  ALLFS: cthon04's general tests             [  OK  ]
 test3s :  ALLFS: cthon04's special tests             [  OK  ]
 test3l :  ALLFS: cthon04's lock tests                [  OK  ]
 test4g :  ALLFS: git clone a local repository        [  OK  ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test4w :  ALLFS: Use mmap() to write a file          [  OK  ]
 test21f : XATTR: simple xattr set/get : file         [  OK  ]
 test21d : XATTR: simple xattr set/get : directory    [  OK  ]
 test21s : XATTR: simple xattr set/get : symlink      [  OK  ]
 test22f : XATTR: xattr creation/deletion : file      [  OK  ]
 test22d : XATTR: xattr creation/deletion : directory [  OK  ]
 test22s : XATTR: xattr creation/deletion : symlink   [  OK  ]
 test23f : XATTR: mulitple sets + 1 check : file      [  OK  ]
 test23d : XATTR: mulitple sets + 1 check : directory [  OK  ]
 test23s : XATTR: mulitple sets + 1 check : symlink   [  OK  ]
 0 tests FAILED, 19 successful, 0 skipped

Other example : do not run test2 and test4w

 # EXCLUDE=2,4w  ./sigmund.sh ext4 -q
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [  OK  ]
 test3b :  ALLFS: cthon04's basic tests               [  OK  ]
 test3g :  ALLFS: cthon04's general tests             [  OK  ]
 test3s :  ALLFS: cthon04's special tests             [  OK  ]
 test3l :  ALLFS: cthon04's lock tests                [  OK  ]
 test4g :  ALLFS: git clone a local repository        [  OK  ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test21f : XATTR: simple xattr set/get : file         [  OK  ]
 test21d : XATTR: simple xattr set/get : directory    [  OK  ]
 test21s : XATTR: simple xattr set/get : symlink      [  OK  ]
 test22f : XATTR: xattr creation/deletion : file      [  OK  ]
 test22d : XATTR: xattr creation/deletion : directory [  OK  ]
 test22s : XATTR: xattr creation/deletion : symlink   [  OK  ]
 test23f : XATTR: mulitple sets + 1 check : file      [  OK  ]
 test23d : XATTR: mulitple sets + 1 check : directory [  OK  ]
 test23s : XATTR: mulitple sets + 1 check : symlink   [  OK  ]
 0 tests FAILED, 18 successful, 0 skipped

==== Running Sigmund wihout the behavior ====

You may want to choose the subset of tests to be run. Basically, behaviors are just combination of those sets.
Currently available sets are:
* allfs : tests features that all POSIX filesystems should have.
* xattr : tests extended attributes support
* pynfs40 and pynfs41 (to be coming soon) : runs pynfs for testing NFSv4.0 and NFSv4.1

You choose modules by setting the '''MODULES''' environment variable. This is a space separated list or a comma separated list (both syntax are OK).
Sets will be used in the order in which they are listed in '''MODULES'''. 

 ## Use xattr and allfs
 export MODULES=xattr,allfs

If no MODULES is set, default will be "allfs" alone.
You then run the tests invoking '''run_test.sh''', with almost the same command line option than the sigmund.sh script. Just get rid off the 
behavior argument.

Example : run allfs and xattr, but exclude test2

 # export MODULES=xattr,allfs
 # EXCLUDE=2 ./run_test.sh -q 
 EXCLUDE=2 ./run_test.sh -q 
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [  OK  ]
 test3b :  ALLFS: cthon04's basic tests               [  OK  ]
 test3g :  ALLFS: cthon04's general tests             [  OK  ]
 test3s :  ALLFS: cthon04's special tests             [  OK  ]
 test3l :  ALLFS: cthon04's lock tests                [  OK  ]
 test4g :  ALLFS: git clone a local repository        [  OK  ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test4w :  ALLFS: Use mmap() to write a file          [  OK  ]
 test21f : XATTR: simple xattr set/get : file         [  OK  ]
 test21d : XATTR: simple xattr set/get : directory    [  OK  ]
 test21s : XATTR: simple xattr set/get : symlink      [  OK  ]
 test22f : XATTR: xattr creation/deletion : file      [  OK  ]
 test22d : XATTR: xattr creation/deletion : directory [  OK  ]
 test22s : XATTR: xattr creation/deletion : symlink   [  OK  ]
 test23f : XATTR: mulitple sets + 1 check : file      [  OK  ]
 test23d : XATTR: mulitple sets + 1 check : directory [  OK  ]
 test23s : XATTR: mulitple sets + 1 check : symlink   [  OK  ]
 0 tests FAILED, 19 successful, 0 skipped

==== Running Sigmund wihout the speed tag ====

Each test has a speed tag on it. Possible speeds are ''fast, medium, slow, very_slow''.
By running sigmund with the '''-s <speed>''' option, you can choose to skip the test slowe than the required speed.
This feature is fully compatible with the ONLY/EXCLUDE logic depicted above.

Example: run only the "fast" tests:

 # ./sigmund.sh 9p -s fast -q
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [ SKIP ]
 test1w :  ALLFS: writes a 1GB file                   [ SKIP ]
 test2r :  ALLFS: rm -rf of wide namespace            [ SKIP ]
 test3b :  ALLFS: cthon04's basic tests               [ SKIP ]
 test3g :  ALLFS: cthon04's general tests             [ SKIP ]
 test3s :  ALLFS: cthon04's special tests             [ SKIP ]
 test3l :  ALLFS: cthon04's lock tests                [ SKIP ]
 test4g :  ALLFS: git clone a local repository        [ SKIP ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test4w :  ALLFS: Use mmap() to write a file          [  OK  ]
 test21f : XATTR: simple xattr set/get : file         [  OK  ]
 test21d : XATTR: simple xattr set/get : directory    [  OK  ]
 test21s : XATTR: simple xattr set/get : symlink      [  OK  ]
 test22f : XATTR: xattr creation/deletion : file      [  OK  ]
 test22d : XATTR: xattr creation/deletion : directory [  OK  ]
 test22s : XATTR: xattr creation/deletion : symlink   [  OK  ]
 test23f : XATTR: mulitple sets + 1 check : file      [  OK  ]
 test23d : XATTR: mulitple sets + 1 check : directory [  OK  ]
 test23s : XATTR: mulitple sets + 1 check : symlink   [  OK  ]
 All tests passed (13 successful, 8 skipped)

Another example, with the ONLY logic

 # ONLY=1,2,3,4 ./sigmund.sh 9p -s medium -q
 test1m :  ALLFS: copy file with 444 mode             [  OK  ]
 test1g :  ALLFS: traverse 700 dirs with altgroups    [NOROOT]
 test1w :  ALLFS: writes a 1GB file                   [ SKIP ]
 test2r :  ALLFS: rm -rf of wide namespace            [ SKIP ]
 test3b :  ALLFS: cthon04's basic tests               [  OK  ]
 test3g :  ALLFS: cthon04's general tests             [  OK  ]
 test3s :  ALLFS: cthon04's special tests             [  OK  ]
 test3l :  ALLFS: cthon04's lock tests                [ SKIP ]
 test4g :  ALLFS: git clone a local repository        [ SKIP ]
 test4s :  ALLFS: Tar calls utimes on symlink         [  OK  ]
 test4r :  ALLFS: Use mmap() to read a file           [  OK  ]
 test4w :  ALLFS: Use mmap() to write a file          [  OK  ]
 All tests passed (7 successful, 5 skipped)



