#!/bin/bash

########################## TEST HELPERS ##################

function test_pjdfs
{
  $PROVE -v $PJDFSTEST_DIR/tests/$1 || error "ERROR: pjdfs/$1"
}


############################ TEST FUNCTIONS ############################

### testpchflags00: pjdfstest chflags/00
SPEED[testpchflags00]=fast
TEST_TYPE[testpchflags00]=dev,admin
NEEDS_ROOT[testpchflags00]=yes
function testpchflags00
{
  export -f test_pjdfs

  test_pjdfs chflags/00.t
}

### testpchflags01: pjdfstest chflags/01
SPEED[testpchflags01]=fast
TEST_TYPE[testpchflags01]=dev,admin
NEEDS_ROOT[testpchflags01]=yes
function testpchflags01
{
  export -f test_pjdfs

  test_pjdfs chflags/01.t
}

### testpchflags02: pjdfstest chflags/02
SPEED[testpchflags02]=fast
TEST_TYPE[testpchflags02]=dev,admin
NEEDS_ROOT[testpchflags02]=yes
function testpchflags02
{
  export -f test_pjdfs

  test_pjdfs chflags/02.t
}

### testpchflags03: pjdfstest chflags/03
SPEED[testpchflags03]=fast
TEST_TYPE[testpchflags03]=dev,admin
NEEDS_ROOT[testpchflags03]=yes
function testpchflags03
{
  export -f test_pjdfs

  test_pjdfs chflags/03.t
}

### testpchflags04: pjdfstest chflags/04
SPEED[testpchflags04]=fast
TEST_TYPE[testpchflags04]=dev,admin
NEEDS_ROOT[testpchflags04]=yes
function testpchflags04
{
  export -f test_pjdfs

  test_pjdfs chflags/04.t
}

### testpchflags05: pjdfstest chflags/05
SPEED[testpchflags05]=fast
TEST_TYPE[testpchflags05]=dev,admin
NEEDS_ROOT[testpchflags05]=yes
function testpchflags05
{
  export -f test_pjdfs

  test_pjdfs chflags/05.t
}

### testpchflags06: pjdfstest chflags/06
SPEED[testpchflags06]=fast
TEST_TYPE[testpchflags06]=dev,admin
NEEDS_ROOT[testpchflags06]=yes
function testpchflags06
{
  export -f test_pjdfs

  test_pjdfs chflags/06.t
}

### testpchflags07: pjdfstest chflags/07
SPEED[testpchflags07]=fast
TEST_TYPE[testpchflags07]=dev,admin
NEEDS_ROOT[testpchflags07]=yes
function testpchflags07
{
  export -f test_pjdfs

  test_pjdfs chflags/07.t
}

### testpchflags08: pjdfstest chflags/08
SPEED[testpchflags08]=fast
TEST_TYPE[testpchflags08]=dev,admin
NEEDS_ROOT[testpchflags08]=yes
function testpchflags08
{
  export -f test_pjdfs

  test_pjdfs chflags/08.t
}

### testpchflags09: pjdfstest chflags/09
SPEED[testpchflags09]=fast
TEST_TYPE[testpchflags09]=dev,admin
NEEDS_ROOT[testpchflags09]=yes
function testpchflags09
{
  export -f test_pjdfs

  test_pjdfs chflags/09.t
}

### testpchflags10: pjdfstest chflags/10
SPEED[testpchflags10]=fast
TEST_TYPE[testpchflags10]=dev,admin
NEEDS_ROOT[testpchflags10]=yes
function testpchflags10
{
  export -f test_pjdfs

  test_pjdfs chflags/10.t
}

### testpchflags11: pjdfstest chflags/11
SPEED[testpchflags11]=fast
TEST_TYPE[testpchflags11]=dev,admin
NEEDS_ROOT[testpchflags11]=yes
function testpchflags11
{
  export -f test_pjdfs

  test_pjdfs chflags/11.t
}

### testpchflags12: pjdfstest chflags/12
SPEED[testpchflags12]=fast
TEST_TYPE[testpchflags12]=dev,admin
NEEDS_ROOT[testpchflags12]=yes
function testpchflags12
{
  export -f test_pjdfs

  test_pjdfs chflags/12.t
}

### testpchflags13: pjdfstest chflags/13
SPEED[testpchflags13]=fast
TEST_TYPE[testpchflags13]=dev,admin
NEEDS_ROOT[testpchflags13]=yes
function testpchflags13
{
  export -f test_pjdfs

  test_pjdfs chflags/13.t
}

### testpchmod00: pjdfstest chmod/00
SPEED[testpchmod00]=medium
TEST_TYPE[testpchmod00]=dev,admin
NEEDS_ROOT[testpchmod00]=yes
function testpchmod00
{
  export -f test_pjdfs

  test_pjdfs chmod/00.t
}

### testpchmod01: pjdfstest chmod/01
SPEED[testpchmod01]=fast
TEST_TYPE[testpchmod01]=dev,admin
NEEDS_ROOT[testpchmod01]=yes
function testpchmod01
{
  export -f test_pjdfs

  test_pjdfs chmod/01.t
}

### testpchmod02: pjdfstest chmod/02
SPEED[testpchmod02]=fast
TEST_TYPE[testpchmod02]=dev,admin
NEEDS_ROOT[testpchmod02]=yes
function testpchmod02
{
  export -f test_pjdfs

  test_pjdfs chmod/02.t
}

### testpchmod03: pjdfstest chmod/03
SPEED[testpchmod03]=fast
TEST_TYPE[testpchmod03]=dev,admin
NEEDS_ROOT[testpchmod03]=yes
function testpchmod03
{
  export -f test_pjdfs

  test_pjdfs chmod/03.t
}

### testpchmod04: pjdfstest chmod/04
SPEED[testpchmod04]=fast
TEST_TYPE[testpchmod04]=dev,admin
NEEDS_ROOT[testpchmod04]=yes
function testpchmod04
{
  export -f test_pjdfs

  test_pjdfs chmod/04.t
}

### testpchmod05: pjdfstest chmod/05
SPEED[testpchmod05]=fast
TEST_TYPE[testpchmod05]=dev,admin
NEEDS_ROOT[testpchmod05]=yes
function testpchmod05
{
  export -f test_pjdfs

  test_pjdfs chmod/05.t
}

### testpchmod06: pjdfstest chmod/06
SPEED[testpchmod06]=fast
TEST_TYPE[testpchmod06]=dev,admin
NEEDS_ROOT[testpchmod06]=yes
function testpchmod06
{
  export -f test_pjdfs

  test_pjdfs chmod/06.t
}

### testpchmod07: pjdfstest chmod/07
SPEED[testpchmod07]=fast
TEST_TYPE[testpchmod07]=dev,admin
NEEDS_ROOT[testpchmod07]=yes
function testpchmod07
{
  export -f test_pjdfs

  test_pjdfs chmod/07.t
}

### testpchmod08: pjdfstest chmod/08
SPEED[testpchmod08]=fast
TEST_TYPE[testpchmod08]=dev,admin
NEEDS_ROOT[testpchmod08]=yes
function testpchmod08
{
  export -f test_pjdfs

  test_pjdfs chmod/08.t
}

### testpchmod09: pjdfstest chmod/09
SPEED[testpchmod09]=fast
TEST_TYPE[testpchmod09]=dev,admin
NEEDS_ROOT[testpchmod09]=yes
function testpchmod09
{
  export -f test_pjdfs

  test_pjdfs chmod/09.t
}

### testpchmod10: pjdfstest chmod/10
SPEED[testpchmod10]=fast
TEST_TYPE[testpchmod10]=dev,admin
NEEDS_ROOT[testpchmod10]=yes
function testpchmod10
{
  export -f test_pjdfs

  test_pjdfs chmod/10.t
}

### testpchmod11: pjdfstest chmod/11
SPEED[testpchmod11]=fast
TEST_TYPE[testpchmod11]=dev,admin
NEEDS_ROOT[testpchmod11]=yes
function testpchmod11
{
  export -f test_pjdfs

  test_pjdfs chmod/11.t
}

### testpchmod12: pjdfstest chmod/12
SPEED[testpchmod12]=fast
TEST_TYPE[testpchmod12]=dev,admin
NEEDS_ROOT[testpchmod12]=yes
function testpchmod12
{
  export -f test_pjdfs

  test_pjdfs chmod/12.t
}

### testpchown00: pjdfstest chown/00
SPEED[testpchown00]=medium
TEST_TYPE[testpchown00]=dev,admin,skip
NEEDS_ROOT[testpchown00]=yes
function testpchown00
{
  export -f test_pjdfs

  test_pjdfs chown/00.t
}

### testpchown01: pjdfstest chown/01
SPEED[testpchown01]=fast
TEST_TYPE[testpchown01]=dev,admin
NEEDS_ROOT[testpchown01]=yes
function testpchown01
{
  export -f test_pjdfs

  test_pjdfs chown/01.t
}

### testpchown02: pjdfstest chown/02
SPEED[testpchown02]=fast
TEST_TYPE[testpchown02]=dev,admin
NEEDS_ROOT[testpchown02]=yes
function testpchown02
{
  export -f test_pjdfs

  test_pjdfs chown/02.t
}

### testpchown03: pjdfstest chown/03
SPEED[testpchown03]=fast
TEST_TYPE[testpchown03]=dev,admin
NEEDS_ROOT[testpchown03]=yes
function testpchown03
{
  export -f test_pjdfs

  test_pjdfs chown/03.t
}

### testpchown04: pjdfstest chown/04
SPEED[testpchown04]=fast
TEST_TYPE[testpchown04]=dev,admin
NEEDS_ROOT[testpchown04]=yes
function testpchown04
{
  export -f test_pjdfs

  test_pjdfs chown/04.t
}

### testpchown05: pjdfstest chown/05
SPEED[testpchown05]=fast
TEST_TYPE[testpchown05]=dev,admin
NEEDS_ROOT[testpchown05]=yes
function testpchown05
{
  export -f test_pjdfs

  test_pjdfs chown/05.t
}

### testpchown06: pjdfstest chown/06
SPEED[testpchown06]=fast
TEST_TYPE[testpchown06]=dev,admin
NEEDS_ROOT[testpchown06]=yes
function testpchown06
{
  export -f test_pjdfs

  test_pjdfs chown/06.t
}

### testpchown07: pjdfstest chown/07
SPEED[testpchown07]=fast
TEST_TYPE[testpchown07]=dev,admin
NEEDS_ROOT[testpchown07]=yes
function testpchown07
{
  export -f test_pjdfs

  test_pjdfs chown/07.t
}

### testpchown08: pjdfstest chown/08
SPEED[testpchown08]=fast
TEST_TYPE[testpchown08]=dev,admin
NEEDS_ROOT[testpchown08]=yes
function testpchown08
{
  export -f test_pjdfs

  test_pjdfs chown/08.t
}

### testpchown09: pjdfstest chown/09
SPEED[testpchown09]=fast
TEST_TYPE[testpchown09]=dev,admin
NEEDS_ROOT[testpchown09]=yes
function testpchown09
{
  export -f test_pjdfs

  test_pjdfs chown/09.t
}

### testpchown10: pjdfstest chown/10
SPEED[testpchown10]=fast
TEST_TYPE[testpchown10]=dev,admin
NEEDS_ROOT[testpchown10]=yes
function testpchown10
{
  export -f test_pjdfs

  test_pjdfs chown/10.t
}

### testpftruncate00: pjdfstest ftruncate/00
SPEED[testpftruncate00]=fast
TEST_TYPE[testpftruncate00]=dev,admin
NEEDS_ROOT[testpftruncate00]=yes
function testpftruncate00
{
  export -f test_pjdfs

  test_pjdfs ftruncate/00.t
}

### testpftruncate01: pjdfstest ftruncate/01
SPEED[testpftruncate01]=fast
TEST_TYPE[testpftruncate01]=dev,admin
NEEDS_ROOT[testpftruncate01]=yes
function testpftruncate01
{
  export -f test_pjdfs

  test_pjdfs ftruncate/01.t
}

### testpftruncate02: pjdfstest ftruncate/02
SPEED[testpftruncate02]=fast
TEST_TYPE[testpftruncate02]=dev,admin
NEEDS_ROOT[testpftruncate02]=yes
function testpftruncate02
{
  export -f test_pjdfs

  test_pjdfs ftruncate/02.t
}

### testpftruncate03: pjdfstest ftruncate/03
SPEED[testpftruncate03]=fast
TEST_TYPE[testpftruncate03]=dev,admin
NEEDS_ROOT[testpftruncate03]=yes
function testpftruncate03
{
  export -f test_pjdfs

  test_pjdfs ftruncate/03.t
}

### testpftruncate04: pjdfstest ftruncate/04
SPEED[testpftruncate04]=fast
TEST_TYPE[testpftruncate04]=dev,admin
NEEDS_ROOT[testpftruncate04]=yes
function testpftruncate04
{
  export -f test_pjdfs

  test_pjdfs ftruncate/04.t
}

### testpftruncate05: pjdfstest ftruncate/05
SPEED[testpftruncate05]=fast
TEST_TYPE[testpftruncate05]=dev,admin
NEEDS_ROOT[testpftruncate05]=yes
function testpftruncate05
{
  export -f test_pjdfs

  test_pjdfs ftruncate/05.t
}

### testpftruncate06: pjdfstest ftruncate/06
SPEED[testpftruncate06]=fast
TEST_TYPE[testpftruncate06]=dev,admin
NEEDS_ROOT[testpftruncate06]=yes
function testpftruncate06
{
  export -f test_pjdfs

  test_pjdfs ftruncate/06.t
}

### testpftruncate07: pjdfstest ftruncate/07
SPEED[testpftruncate07]=fast
TEST_TYPE[testpftruncate07]=dev,admin
NEEDS_ROOT[testpftruncate07]=yes
function testpftruncate07
{
  export -f test_pjdfs

  test_pjdfs ftruncate/07.t
}

### testpftruncate08: pjdfstest ftruncate/08
SPEED[testpftruncate08]=fast
TEST_TYPE[testpftruncate08]=dev,admin
NEEDS_ROOT[testpftruncate08]=yes
function testpftruncate08
{
  export -f test_pjdfs

  test_pjdfs ftruncate/08.t
}

### testpftruncate09: pjdfstest ftruncate/09
SPEED[testpftruncate09]=fast
TEST_TYPE[testpftruncate09]=dev,admin
NEEDS_ROOT[testpftruncate09]=yes
function testpftruncate09
{
  export -f test_pjdfs

  test_pjdfs ftruncate/09.t
}

### testpftruncate10: pjdfstest ftruncate/10
SPEED[testpftruncate10]=fast
TEST_TYPE[testpftruncate10]=dev,admin
NEEDS_ROOT[testpftruncate10]=yes
function testpftruncate10
{
  export -f test_pjdfs

  test_pjdfs ftruncate/10.t
}

### testpftruncate11: pjdfstest ftruncate/11
SPEED[testpftruncate11]=fast
TEST_TYPE[testpftruncate11]=dev,admin
NEEDS_ROOT[testpftruncate11]=yes
function testpftruncate11
{
  export -f test_pjdfs

  test_pjdfs ftruncate/11.t
}

### testpftruncate12: pjdfstest ftruncate/12
SPEED[testpftruncate12]=fast
TEST_TYPE[testpftruncate12]=dev,admin
NEEDS_ROOT[testpftruncate12]=yes
function testpftruncate12
{
  export -f test_pjdfs

  test_pjdfs ftruncate/12.t
}

### testpftruncate13: pjdfstest ftruncate/13
SPEED[testpftruncate13]=fast
TEST_TYPE[testpftruncate13]=dev,admin
NEEDS_ROOT[testpftruncate13]=yes
function testpftruncate13
{
  export -f test_pjdfs

  test_pjdfs ftruncate/13.t
}

### testpftruncate14: pjdfstest ftruncate/14
SPEED[testpftruncate14]=fast
TEST_TYPE[testpftruncate14]=dev,admin
NEEDS_ROOT[testpftruncate14]=yes
function testpftruncate14
{
  export -f test_pjdfs

  test_pjdfs ftruncate/14.t
}

### testpgranular00: pjdfstest granular/00
SPEED[testpgranular00]=fast
TEST_TYPE[testpgranular00]=dev,admin
NEEDS_ROOT[testpgranular00]=yes
function testpgranular00
{
  export -f test_pjdfs

  test_pjdfs granular/00.t
}

### testpgranular01: pjdfstest granular/01
SPEED[testpgranular01]=fast
TEST_TYPE[testpgranular01]=dev,admin
NEEDS_ROOT[testpgranular01]=yes
function testpgranular01
{
  export -f test_pjdfs

  test_pjdfs granular/01.t
}

### testpgranular02: pjdfstest granular/02
SPEED[testpgranular02]=fast
TEST_TYPE[testpgranular02]=dev,admin
NEEDS_ROOT[testpgranular02]=yes
function testpgranular02
{
  export -f test_pjdfs

  test_pjdfs granular/02.t
}

### testpgranular03: pjdfstest granular/03
SPEED[testpgranular03]=fast
TEST_TYPE[testpgranular03]=dev,admin
NEEDS_ROOT[testpgranular03]=yes
function testpgranular03
{
  export -f test_pjdfs

  test_pjdfs granular/03.t
}

### testpgranular04: pjdfstest granular/04
SPEED[testpgranular04]=fast
TEST_TYPE[testpgranular04]=dev,admin
NEEDS_ROOT[testpgranular04]=yes
function testpgranular04
{
  export -f test_pjdfs

  test_pjdfs granular/04.t
}

### testpgranular05: pjdfstest granular/05
SPEED[testpgranular05]=fast
TEST_TYPE[testpgranular05]=dev,admin
NEEDS_ROOT[testpgranular05]=yes
function testpgranular05
{
  export -f test_pjdfs

  test_pjdfs granular/05.t
}

### testplink00: pjdfstest link/00
SPEED[testplink00]=medium
TEST_TYPE[testplink00]=dev,admin
NEEDS_ROOT[testplink00]=yes
function testplink00
{
  export -f test_pjdfs

  test_pjdfs link/00.t
}

### testplink01: pjdfstest link/01
SPEED[testplink01]=fast
TEST_TYPE[testplink01]=dev,admin
NEEDS_ROOT[testplink01]=yes
function testplink01
{
  export -f test_pjdfs

  test_pjdfs link/01.t
}

### testplink02: pjdfstest link/02
SPEED[testplink02]=fast
TEST_TYPE[testplink02]=dev,admin
NEEDS_ROOT[testplink02]=yes
function testplink02
{
  export -f test_pjdfs

  test_pjdfs link/02.t
}

### testplink03: pjdfstest link/03
SPEED[testplink03]=fast
TEST_TYPE[testplink03]=dev,admin
NEEDS_ROOT[testplink03]=yes
function testplink03
{
  export -f test_pjdfs

  test_pjdfs link/03.t
}

### testplink04: pjdfstest link/04
SPEED[testplink04]=fast
TEST_TYPE[testplink04]=dev,admin
NEEDS_ROOT[testplink04]=yes
function testplink04
{
  export -f test_pjdfs

  test_pjdfs link/04.t
}

### testplink05: pjdfstest link/05
SPEED[testplink05]=fast
TEST_TYPE[testplink05]=dev,admin
NEEDS_ROOT[testplink05]=yes
function testplink05
{
  export -f test_pjdfs

  test_pjdfs link/05.t
}

### testplink06: pjdfstest link/06
SPEED[testplink06]=fast
TEST_TYPE[testplink06]=dev,admin
NEEDS_ROOT[testplink06]=yes
function testplink06
{
  export -f test_pjdfs

  test_pjdfs link/06.t
}

### testplink07: pjdfstest link/07
SPEED[testplink07]=fast
TEST_TYPE[testplink07]=dev,admin
NEEDS_ROOT[testplink07]=yes
function testplink07
{
  export -f test_pjdfs

  test_pjdfs link/07.t
}

### testplink08: pjdfstest link/08
SPEED[testplink08]=fast
TEST_TYPE[testplink08]=dev,admin
NEEDS_ROOT[testplink08]=yes
function testplink08
{
  export -f test_pjdfs

  test_pjdfs link/08.t
}

### testplink09: pjdfstest link/09
SPEED[testplink09]=fast
TEST_TYPE[testplink09]=dev,admin
NEEDS_ROOT[testplink09]=yes
function testplink09
{
  export -f test_pjdfs

  test_pjdfs link/09.t
}

### testplink10: pjdfstest link/10
SPEED[testplink10]=fast
TEST_TYPE[testplink10]=dev,admin
NEEDS_ROOT[testplink10]=yes
function testplink10
{
  export -f test_pjdfs

  test_pjdfs link/10.t
}

### testplink11: pjdfstest link/11
SPEED[testplink11]=fast
TEST_TYPE[testplink11]=dev,admin
NEEDS_ROOT[testplink11]=yes
function testplink11
{
  export -f test_pjdfs

  test_pjdfs link/11.t
}

### testplink12: pjdfstest link/12
SPEED[testplink12]=fast
TEST_TYPE[testplink12]=dev,admin
NEEDS_ROOT[testplink12]=yes
function testplink12
{
  export -f test_pjdfs

  test_pjdfs link/12.t
}

### testplink13: pjdfstest link/13
SPEED[testplink13]=fast
TEST_TYPE[testplink13]=dev,admin
NEEDS_ROOT[testplink13]=yes
function testplink13
{
  export -f test_pjdfs

  test_pjdfs link/13.t
}

### testplink14: pjdfstest link/14
SPEED[testplink14]=fast
TEST_TYPE[testplink14]=dev,admin
NEEDS_ROOT[testplink14]=yes
function testplink14
{
  export -f test_pjdfs

  test_pjdfs link/14.t
}

### testplink15: pjdfstest link/15
SPEED[testplink15]=fast
TEST_TYPE[testplink15]=dev,admin
NEEDS_ROOT[testplink15]=yes
function testplink15
{
  export -f test_pjdfs

  test_pjdfs link/15.t
}

### testplink16: pjdfstest link/16
SPEED[testplink16]=fast
TEST_TYPE[testplink16]=dev,admin
NEEDS_ROOT[testplink16]=yes
function testplink16
{
  export -f test_pjdfs

  test_pjdfs link/16.t
}

### testplink17: pjdfstest link/17
SPEED[testplink17]=fast
TEST_TYPE[testplink17]=dev,admin
NEEDS_ROOT[testplink17]=yes
function testplink17
{
  export -f test_pjdfs

  test_pjdfs link/17.t
}

### testpmkdir00: pjdfstest mkdir/00
SPEED[testpmkdir00]=fast
TEST_TYPE[testpmkdir00]=dev,admin
NEEDS_ROOT[testpmkdir00]=yes
function testpmkdir00
{
  export -f test_pjdfs

  test_pjdfs mkdir/00.t
}

### testpmkdir01: pjdfstest mkdir/01
SPEED[testpmkdir01]=fast
TEST_TYPE[testpmkdir01]=dev,admin
NEEDS_ROOT[testpmkdir01]=yes
function testpmkdir01
{
  export -f test_pjdfs

  test_pjdfs mkdir/01.t
}

### testpmkdir02: pjdfstest mkdir/02
SPEED[testpmkdir02]=fast
TEST_TYPE[testpmkdir02]=dev,admin
NEEDS_ROOT[testpmkdir02]=yes
function testpmkdir02
{
  export -f test_pjdfs

  test_pjdfs mkdir/02.t
}

### testpmkdir03: pjdfstest mkdir/03
SPEED[testpmkdir03]=fast
TEST_TYPE[testpmkdir03]=dev,admin
NEEDS_ROOT[testpmkdir03]=yes
function testpmkdir03
{
  export -f test_pjdfs

  test_pjdfs mkdir/03.t
}

### testpmkdir04: pjdfstest mkdir/04
SPEED[testpmkdir04]=fast
TEST_TYPE[testpmkdir04]=dev,admin
NEEDS_ROOT[testpmkdir04]=yes
function testpmkdir04
{
  export -f test_pjdfs

  test_pjdfs mkdir/04.t
}

### testpmkdir05: pjdfstest mkdir/05
SPEED[testpmkdir05]=fast
TEST_TYPE[testpmkdir05]=dev,admin
NEEDS_ROOT[testpmkdir05]=yes
function testpmkdir05
{
  export -f test_pjdfs

  test_pjdfs mkdir/05.t
}

### testpmkdir06: pjdfstest mkdir/06
SPEED[testpmkdir06]=fast
TEST_TYPE[testpmkdir06]=dev,admin
NEEDS_ROOT[testpmkdir06]=yes
function testpmkdir06
{
  export -f test_pjdfs

  test_pjdfs mkdir/06.t
}

### testpmkdir07: pjdfstest mkdir/07
SPEED[testpmkdir07]=fast
TEST_TYPE[testpmkdir07]=dev,admin
NEEDS_ROOT[testpmkdir07]=yes
function testpmkdir07
{
  export -f test_pjdfs

  test_pjdfs mkdir/07.t
}

### testpmkdir08: pjdfstest mkdir/08
SPEED[testpmkdir08]=fast
TEST_TYPE[testpmkdir08]=dev,admin
NEEDS_ROOT[testpmkdir08]=yes
function testpmkdir08
{
  export -f test_pjdfs

  test_pjdfs mkdir/08.t
}

### testpmkdir09: pjdfstest mkdir/09
SPEED[testpmkdir09]=fast
TEST_TYPE[testpmkdir09]=dev,admin
NEEDS_ROOT[testpmkdir09]=yes
function testpmkdir09
{
  export -f test_pjdfs

  test_pjdfs mkdir/09.t
}

### testpmkdir10: pjdfstest mkdir/10
SPEED[testpmkdir10]=fast
TEST_TYPE[testpmkdir10]=dev,admin
NEEDS_ROOT[testpmkdir10]=yes
function testpmkdir10
{
  export -f test_pjdfs

  test_pjdfs mkdir/10.t
}

### testpmkdir11: pjdfstest mkdir/11
SPEED[testpmkdir11]=fast
TEST_TYPE[testpmkdir11]=dev,admin
NEEDS_ROOT[testpmkdir11]=yes
function testpmkdir11
{
  export -f test_pjdfs

  test_pjdfs mkdir/11.t
}

### testpmkdir12: pjdfstest mkdir/12
SPEED[testpmkdir12]=fast
TEST_TYPE[testpmkdir12]=dev,admin
NEEDS_ROOT[testpmkdir12]=yes
function testpmkdir12
{
  export -f test_pjdfs

  test_pjdfs mkdir/12.t
}

### testpmkfifo00: pjdfstest mkfifo/00
SPEED[testpmkfifo00]=fast
TEST_TYPE[testpmkfifo00]=dev,admin
NEEDS_ROOT[testpmkfifo00]=yes
function testpmkfifo00
{
  export -f test_pjdfs

  test_pjdfs mkfifo/00.t
}

### testpmkfifo01: pjdfstest mkfifo/01
SPEED[testpmkfifo01]=fast
TEST_TYPE[testpmkfifo01]=dev,admin
NEEDS_ROOT[testpmkfifo01]=yes
function testpmkfifo01
{
  export -f test_pjdfs

  test_pjdfs mkfifo/01.t
}

### testpmkfifo02: pjdfstest mkfifo/02
SPEED[testpmkfifo02]=fast
TEST_TYPE[testpmkfifo02]=dev,admin
NEEDS_ROOT[testpmkfifo02]=yes
function testpmkfifo02
{
  export -f test_pjdfs

  test_pjdfs mkfifo/02.t
}

### testpmkfifo03: pjdfstest mkfifo/03
SPEED[testpmkfifo03]=fast
TEST_TYPE[testpmkfifo03]=dev,admin
NEEDS_ROOT[testpmkfifo03]=yes
function testpmkfifo03
{
  export -f test_pjdfs

  test_pjdfs mkfifo/03.t
}

### testpmkfifo04: pjdfstest mkfifo/04
SPEED[testpmkfifo04]=fast
TEST_TYPE[testpmkfifo04]=dev,admin
NEEDS_ROOT[testpmkfifo04]=yes
function testpmkfifo04
{
  export -f test_pjdfs

  test_pjdfs mkfifo/04.t
}

### testpmkfifo05: pjdfstest mkfifo/05
SPEED[testpmkfifo05]=fast
TEST_TYPE[testpmkfifo05]=dev,admin
NEEDS_ROOT[testpmkfifo05]=yes
function testpmkfifo05
{
  export -f test_pjdfs

  test_pjdfs mkfifo/05.t
}

### testpmkfifo06: pjdfstest mkfifo/06
SPEED[testpmkfifo06]=fast
TEST_TYPE[testpmkfifo06]=dev,admin
NEEDS_ROOT[testpmkfifo06]=yes
function testpmkfifo06
{
  export -f test_pjdfs

  test_pjdfs mkfifo/06.t
}

### testpmkfifo07: pjdfstest mkfifo/07
SPEED[testpmkfifo07]=fast
TEST_TYPE[testpmkfifo07]=dev,admin
NEEDS_ROOT[testpmkfifo07]=yes
function testpmkfifo07
{
  export -f test_pjdfs

  test_pjdfs mkfifo/07.t
}

### testpmkfifo08: pjdfstest mkfifo/08
SPEED[testpmkfifo08]=fast
TEST_TYPE[testpmkfifo08]=dev,admin
NEEDS_ROOT[testpmkfifo08]=yes
function testpmkfifo08
{
  export -f test_pjdfs

  test_pjdfs mkfifo/08.t
}

### testpmkfifo09: pjdfstest mkfifo/09
SPEED[testpmkfifo09]=fast
TEST_TYPE[testpmkfifo09]=dev,admin
NEEDS_ROOT[testpmkfifo09]=yes
function testpmkfifo09
{
  export -f test_pjdfs

  test_pjdfs mkfifo/09.t
}

### testpmkfifo10: pjdfstest mkfifo/10
SPEED[testpmkfifo10]=fast
TEST_TYPE[testpmkfifo10]=dev,admin
NEEDS_ROOT[testpmkfifo10]=yes
function testpmkfifo10
{
  export -f test_pjdfs

  test_pjdfs mkfifo/10.t
}

### testpmkfifo11: pjdfstest mkfifo/11
SPEED[testpmkfifo11]=fast
TEST_TYPE[testpmkfifo11]=dev,admin
NEEDS_ROOT[testpmkfifo11]=yes
function testpmkfifo11
{
  export -f test_pjdfs

  test_pjdfs mkfifo/11.t
}

### testpmkfifo12: pjdfstest mkfifo/12
SPEED[testpmkfifo12]=fast
TEST_TYPE[testpmkfifo12]=dev,admin
NEEDS_ROOT[testpmkfifo12]=yes
function testpmkfifo12
{
  export -f test_pjdfs

  test_pjdfs mkfifo/12.t
}

### testpmknod00: pjdfstest mknod/00
SPEED[testpmknod00]=fast
TEST_TYPE[testpmknod00]=dev,admin
NEEDS_ROOT[testpmknod00]=yes
function testpmknod00
{
  export -f test_pjdfs

  test_pjdfs mknod/00.t
}

### testpmknod01: pjdfstest mknod/01
SPEED[testpmknod01]=fast
TEST_TYPE[testpmknod01]=dev,admin
NEEDS_ROOT[testpmknod01]=yes
function testpmknod01
{
  export -f test_pjdfs

  test_pjdfs mknod/01.t
}

### testpmknod02: pjdfstest mknod/02
SPEED[testpmknod02]=fast
TEST_TYPE[testpmknod02]=dev,admin
NEEDS_ROOT[testpmknod02]=yes
function testpmknod02
{
  export -f test_pjdfs

  test_pjdfs mknod/02.t
}

### testpmknod03: pjdfstest mknod/03
SPEED[testpmknod03]=fast
TEST_TYPE[testpmknod03]=dev,admin
NEEDS_ROOT[testpmknod03]=yes
function testpmknod03
{
  export -f test_pjdfs

  test_pjdfs mknod/03.t
}

### testpmknod04: pjdfstest mknod/04
SPEED[testpmknod04]=fast
TEST_TYPE[testpmknod04]=dev,admin
NEEDS_ROOT[testpmknod04]=yes
function testpmknod04
{
  export -f test_pjdfs

  test_pjdfs mknod/04.t
}

### testpmknod05: pjdfstest mknod/05
SPEED[testpmknod05]=fast
TEST_TYPE[testpmknod05]=dev,admin
NEEDS_ROOT[testpmknod05]=yes
function testpmknod05
{
  export -f test_pjdfs

  test_pjdfs mknod/05.t
}

### testpmknod06: pjdfstest mknod/06
SPEED[testpmknod06]=fast
TEST_TYPE[testpmknod06]=dev,admin
NEEDS_ROOT[testpmknod06]=yes
function testpmknod06
{
  export -f test_pjdfs

  test_pjdfs mknod/06.t
}

### testpmknod07: pjdfstest mknod/07
SPEED[testpmknod07]=fast
TEST_TYPE[testpmknod07]=dev,admin
NEEDS_ROOT[testpmknod07]=yes
function testpmknod07
{
  export -f test_pjdfs

  test_pjdfs mknod/07.t
}

### testpmknod08: pjdfstest mknod/08
SPEED[testpmknod08]=fast
TEST_TYPE[testpmknod08]=dev,admin
NEEDS_ROOT[testpmknod08]=yes
function testpmknod08
{
  export -f test_pjdfs

  test_pjdfs mknod/08.t
}

### testpmknod09: pjdfstest mknod/09
SPEED[testpmknod09]=fast
TEST_TYPE[testpmknod09]=dev,admin
NEEDS_ROOT[testpmknod09]=yes
function testpmknod09
{
  export -f test_pjdfs

  test_pjdfs mknod/09.t
}

### testpmknod10: pjdfstest mknod/10
SPEED[testpmknod10]=fast
TEST_TYPE[testpmknod10]=dev,admin
NEEDS_ROOT[testpmknod10]=yes
function testpmknod10
{
  export -f test_pjdfs

  test_pjdfs mknod/10.t
}

### testpmknod11: pjdfstest mknod/11
SPEED[testpmknod11]=fast
TEST_TYPE[testpmknod11]=dev,admin
NEEDS_ROOT[testpmknod11]=yes
function testpmknod11
{
  export -f test_pjdfs

  test_pjdfs mknod/11.t
}

### testpopen00: pjdfstest open/00
SPEED[testpopen00]=fast
TEST_TYPE[testpopen00]=dev,admin
NEEDS_ROOT[testpopen00]=yes
function testpopen00
{
  export -f test_pjdfs

  test_pjdfs open/00.t
}

### testpopen01: pjdfstest open/01
SPEED[testpopen01]=fast
TEST_TYPE[testpopen01]=dev,admin
NEEDS_ROOT[testpopen01]=yes
function testpopen01
{
  export -f test_pjdfs

  test_pjdfs open/01.t
}

### testpopen02: pjdfstest open/02
SPEED[testpopen02]=fast
TEST_TYPE[testpopen02]=dev,admin
NEEDS_ROOT[testpopen02]=yes
function testpopen02
{
  export -f test_pjdfs

  test_pjdfs open/02.t
}

### testpopen03: pjdfstest open/03
SPEED[testpopen03]=fast
TEST_TYPE[testpopen03]=dev,admin
NEEDS_ROOT[testpopen03]=yes
function testpopen03
{
  export -f test_pjdfs

  test_pjdfs open/03.t
}

### testpopen04: pjdfstest open/04
SPEED[testpopen04]=fast
TEST_TYPE[testpopen04]=dev,admin
NEEDS_ROOT[testpopen04]=yes
function testpopen04
{
  export -f test_pjdfs

  test_pjdfs open/04.t
}

### testpopen05: pjdfstest open/05
SPEED[testpopen05]=fast
TEST_TYPE[testpopen05]=dev,admin
NEEDS_ROOT[testpopen05]=yes
function testpopen05
{
  export -f test_pjdfs

  test_pjdfs open/05.t
}

### testpopen06: pjdfstest open/06
SPEED[testpopen06]=fast
TEST_TYPE[testpopen06]=dev,admin
NEEDS_ROOT[testpopen06]=yes
function testpopen06
{
  export -f test_pjdfs

  test_pjdfs open/06.t
}

### testpopen07: pjdfstest open/07
SPEED[testpopen07]=fast
TEST_TYPE[testpopen07]=dev,admin
NEEDS_ROOT[testpopen07]=yes
function testpopen07
{
  export -f test_pjdfs

  test_pjdfs open/07.t
}

### testpopen08: pjdfstest open/08
SPEED[testpopen08]=fast
TEST_TYPE[testpopen08]=dev,admin
NEEDS_ROOT[testpopen08]=yes
function testpopen08
{
  export -f test_pjdfs

  test_pjdfs open/08.t
}

### testpopen09: pjdfstest open/09
SPEED[testpopen09]=fast
TEST_TYPE[testpopen09]=dev,admin
NEEDS_ROOT[testpopen09]=yes
function testpopen09
{
  export -f test_pjdfs

  test_pjdfs open/09.t
}

### testpopen10: pjdfstest open/10
SPEED[testpopen10]=fast
TEST_TYPE[testpopen10]=dev,admin
NEEDS_ROOT[testpopen10]=yes
function testpopen10
{
  export -f test_pjdfs

  test_pjdfs open/10.t
}

### testpopen11: pjdfstest open/11
SPEED[testpopen11]=fast
TEST_TYPE[testpopen11]=dev,admin
NEEDS_ROOT[testpopen11]=yes
function testpopen11
{
  export -f test_pjdfs

  test_pjdfs open/11.t
}

### testpopen12: pjdfstest open/12
SPEED[testpopen12]=fast
TEST_TYPE[testpopen12]=dev,admin
NEEDS_ROOT[testpopen12]=yes
function testpopen12
{
  export -f test_pjdfs

  test_pjdfs open/12.t
}

### testpopen13: pjdfstest open/13
SPEED[testpopen13]=fast
TEST_TYPE[testpopen13]=dev,admin
NEEDS_ROOT[testpopen13]=yes
function testpopen13
{
  export -f test_pjdfs

  test_pjdfs open/13.t
}

### testpopen14: pjdfstest open/14
SPEED[testpopen14]=fast
TEST_TYPE[testpopen14]=dev,admin
NEEDS_ROOT[testpopen14]=yes
function testpopen14
{
  export -f test_pjdfs

  test_pjdfs open/14.t
}

### testpopen15: pjdfstest open/15
SPEED[testpopen15]=fast
TEST_TYPE[testpopen15]=dev,admin
NEEDS_ROOT[testpopen15]=yes
function testpopen15
{
  export -f test_pjdfs

  test_pjdfs open/15.t
}

### testpopen16: pjdfstest open/16
SPEED[testpopen16]=fast
TEST_TYPE[testpopen16]=dev,admin
NEEDS_ROOT[testpopen16]=yes
function testpopen16
{
  export -f test_pjdfs

  test_pjdfs open/16.t
}

### testpopen17: pjdfstest open/17
SPEED[testpopen17]=fast
TEST_TYPE[testpopen17]=dev,admin
NEEDS_ROOT[testpopen17]=yes
function testpopen17
{
  export -f test_pjdfs

  test_pjdfs open/17.t
}

### testpopen18: pjdfstest open/18
SPEED[testpopen18]=fast
TEST_TYPE[testpopen18]=dev,admin
NEEDS_ROOT[testpopen18]=yes
function testpopen18
{
  export -f test_pjdfs

  test_pjdfs open/18.t
}

### testpopen19: pjdfstest open/19
SPEED[testpopen19]=fast
TEST_TYPE[testpopen19]=dev,admin
NEEDS_ROOT[testpopen19]=yes
function testpopen19
{
  export -f test_pjdfs

  test_pjdfs open/19.t
}

### testpopen20: pjdfstest open/20
SPEED[testpopen20]=fast
TEST_TYPE[testpopen20]=dev,admin
NEEDS_ROOT[testpopen20]=yes
function testpopen20
{
  export -f test_pjdfs

  test_pjdfs open/20.t
}

### testpopen21: pjdfstest open/21
SPEED[testpopen21]=fast
TEST_TYPE[testpopen21]=dev,admin
NEEDS_ROOT[testpopen21]=yes
function testpopen21
{
  export -f test_pjdfs

  test_pjdfs open/21.t
}

### testpopen22: pjdfstest open/22
SPEED[testpopen22]=fast
TEST_TYPE[testpopen22]=dev,admin
NEEDS_ROOT[testpopen22]=yes
function testpopen22
{
  export -f test_pjdfs

  test_pjdfs open/22.t
}

### testpopen23: pjdfstest open/23
SPEED[testpopen23]=fast
TEST_TYPE[testpopen23]=dev,admin
NEEDS_ROOT[testpopen23]=yes
function testpopen23
{
  export -f test_pjdfs

  test_pjdfs open/23.t
}

### testpopen24: pjdfstest open/24
SPEED[testpopen24]=fast
TEST_TYPE[testpopen24]=dev,admin
NEEDS_ROOT[testpopen24]=yes
function testpopen24
{
  export -f test_pjdfs

  test_pjdfs open/24.t
}

### testprename00: pjdfstest rename/00
SPEED[testprename00]=medium
TEST_TYPE[testprename00]=dev,admin
NEEDS_ROOT[testprename00]=yes
function testprename00
{
  export -f test_pjdfs

  test_pjdfs rename/00.t
}

### testprename01: pjdfstest rename/01
SPEED[testprename01]=fast
TEST_TYPE[testprename01]=dev,admin
NEEDS_ROOT[testprename01]=yes
function testprename01
{
  export -f test_pjdfs

  test_pjdfs rename/01.t
}

### testprename02: pjdfstest rename/02
SPEED[testprename02]=fast
TEST_TYPE[testprename02]=dev,admin
NEEDS_ROOT[testprename02]=yes
function testprename02
{
  export -f test_pjdfs

  test_pjdfs rename/02.t
}

### testprename03: pjdfstest rename/03
SPEED[testprename03]=fast
TEST_TYPE[testprename03]=dev,admin
NEEDS_ROOT[testprename03]=yes
function testprename03
{
  export -f test_pjdfs

  test_pjdfs rename/03.t
}

### testprename04: pjdfstest rename/04
SPEED[testprename04]=fast
TEST_TYPE[testprename04]=dev,admin
NEEDS_ROOT[testprename04]=yes
function testprename04
{
  export -f test_pjdfs

  test_pjdfs rename/04.t
}

### testprename05: pjdfstest rename/05
SPEED[testprename05]=fast
TEST_TYPE[testprename05]=dev,admin
NEEDS_ROOT[testprename05]=yes
function testprename05
{
  export -f test_pjdfs

  test_pjdfs rename/05.t
}

### testprename06: pjdfstest rename/06
SPEED[testprename06]=fast
TEST_TYPE[testprename06]=dev,admin
NEEDS_ROOT[testprename06]=yes
function testprename06
{
  export -f test_pjdfs

  test_pjdfs rename/06.t
}

### testprename07: pjdfstest rename/07
SPEED[testprename07]=fast
TEST_TYPE[testprename07]=dev,admin
NEEDS_ROOT[testprename07]=yes
function testprename07
{
  export -f test_pjdfs

  test_pjdfs rename/07.t
}

### testprename08: pjdfstest rename/08
SPEED[testprename08]=fast
TEST_TYPE[testprename08]=dev,admin
NEEDS_ROOT[testprename08]=yes
function testprename08
{
  export -f test_pjdfs

  test_pjdfs rename/08.t
}

### testprename09: pjdfstest rename/09
SPEED[testprename09]=fast
TEST_TYPE[testprename09]=dev,admin
NEEDS_ROOT[testprename09]=yes
function testprename09
{
  export -f test_pjdfs

  test_pjdfs rename/09.t
}

### testprename10: pjdfstest rename/10
SPEED[testprename10]=fast
TEST_TYPE[testprename10]=dev,admin
NEEDS_ROOT[testprename10]=yes
function testprename10
{
  export -f test_pjdfs

  test_pjdfs rename/10.t
}

### testprename11: pjdfstest rename/11
SPEED[testprename11]=fast
TEST_TYPE[testprename11]=dev,admin
NEEDS_ROOT[testprename11]=yes
function testprename11
{
  export -f test_pjdfs

  test_pjdfs rename/11.t
}

### testprename12: pjdfstest rename/12
SPEED[testprename12]=fast
TEST_TYPE[testprename12]=dev,admin
NEEDS_ROOT[testprename12]=yes
function testprename12
{
  export -f test_pjdfs

  test_pjdfs rename/12.t
}

### testprename13: pjdfstest rename/13
SPEED[testprename13]=fast
TEST_TYPE[testprename13]=dev,admin
NEEDS_ROOT[testprename13]=yes
function testprename13
{
  export -f test_pjdfs

  test_pjdfs rename/13.t
}

### testprename14: pjdfstest rename/14
SPEED[testprename14]=fast
TEST_TYPE[testprename14]=dev,admin
NEEDS_ROOT[testprename14]=yes
function testprename14
{
  export -f test_pjdfs

  test_pjdfs rename/14.t
}

### testprename15: pjdfstest rename/15
SPEED[testprename15]=fast
TEST_TYPE[testprename15]=dev,admin
NEEDS_ROOT[testprename15]=yes
function testprename15
{
  export -f test_pjdfs

  test_pjdfs rename/15.t
}

### testprename16: pjdfstest rename/16
SPEED[testprename16]=fast
TEST_TYPE[testprename16]=dev,admin
NEEDS_ROOT[testprename16]=yes
function testprename16
{
  export -f test_pjdfs

  test_pjdfs rename/16.t
}

### testprename17: pjdfstest rename/17
SPEED[testprename17]=fast
TEST_TYPE[testprename17]=dev,admin
NEEDS_ROOT[testprename17]=yes
function testprename17
{
  export -f test_pjdfs

  test_pjdfs rename/17.t
}

### testprename18: pjdfstest rename/18
SPEED[testprename18]=fast
TEST_TYPE[testprename18]=dev,admin
NEEDS_ROOT[testprename18]=yes
function testprename18
{
  export -f test_pjdfs

  test_pjdfs rename/18.t
}

### testprename19: pjdfstest rename/19
SPEED[testprename19]=fast
TEST_TYPE[testprename19]=dev,admin
NEEDS_ROOT[testprename19]=yes
function testprename19
{
  export -f test_pjdfs

  test_pjdfs rename/19.t
}

### testprename20: pjdfstest rename/20
SPEED[testprename20]=fast
TEST_TYPE[testprename20]=dev,admin
NEEDS_ROOT[testprename20]=yes
function testprename20
{
  export -f test_pjdfs

  test_pjdfs rename/20.t
}

### testprename21: pjdfstest rename/21
SPEED[testprename21]=fast
TEST_TYPE[testprename21]=dev,admin
NEEDS_ROOT[testprename21]=yes
function testprename21
{
  export -f test_pjdfs

  test_pjdfs rename/21.t
}

### testprmdir00: pjdfstest rmdir/00
SPEED[testprmdir00]=fast
TEST_TYPE[testprmdir00]=dev,admin
NEEDS_ROOT[testprmdir00]=yes
function testprmdir00
{
  export -f test_pjdfs

  test_pjdfs rmdir/00.t
}

### testprmdir01: pjdfstest rmdir/01
SPEED[testprmdir01]=fast
TEST_TYPE[testprmdir01]=dev,admin
NEEDS_ROOT[testprmdir01]=yes
function testprmdir01
{
  export -f test_pjdfs

  test_pjdfs rmdir/01.t
}

### testprmdir02: pjdfstest rmdir/02
SPEED[testprmdir02]=fast
TEST_TYPE[testprmdir02]=dev,admin
NEEDS_ROOT[testprmdir02]=yes
function testprmdir02
{
  export -f test_pjdfs

  test_pjdfs rmdir/02.t
}

### testprmdir03: pjdfstest rmdir/03
SPEED[testprmdir03]=fast
TEST_TYPE[testprmdir03]=dev,admin
NEEDS_ROOT[testprmdir03]=yes
function testprmdir03
{
  export -f test_pjdfs

  test_pjdfs rmdir/03.t
}

### testprmdir04: pjdfstest rmdir/04
SPEED[testprmdir04]=fast
TEST_TYPE[testprmdir04]=dev,admin
NEEDS_ROOT[testprmdir04]=yes
function testprmdir04
{
  export -f test_pjdfs

  test_pjdfs rmdir/04.t
}

### testprmdir05: pjdfstest rmdir/05
SPEED[testprmdir05]=fast
TEST_TYPE[testprmdir05]=dev,admin
NEEDS_ROOT[testprmdir05]=yes
function testprmdir05
{
  export -f test_pjdfs

  test_pjdfs rmdir/05.t
}

### testprmdir06: pjdfstest rmdir/06
SPEED[testprmdir06]=fast
TEST_TYPE[testprmdir06]=dev,admin
NEEDS_ROOT[testprmdir06]=yes
function testprmdir06
{
  export -f test_pjdfs

  test_pjdfs rmdir/06.t
}

### testprmdir07: pjdfstest rmdir/07
SPEED[testprmdir07]=fast
TEST_TYPE[testprmdir07]=dev,admin
NEEDS_ROOT[testprmdir07]=yes
function testprmdir07
{
  export -f test_pjdfs

  test_pjdfs rmdir/07.t
}

### testprmdir08: pjdfstest rmdir/08
SPEED[testprmdir08]=fast
TEST_TYPE[testprmdir08]=dev,admin
NEEDS_ROOT[testprmdir08]=yes
function testprmdir08
{
  export -f test_pjdfs

  test_pjdfs rmdir/08.t
}

### testprmdir09: pjdfstest rmdir/09
SPEED[testprmdir09]=fast
TEST_TYPE[testprmdir09]=dev,admin
NEEDS_ROOT[testprmdir09]=yes
function testprmdir09
{
  export -f test_pjdfs

  test_pjdfs rmdir/09.t
}

### testprmdir10: pjdfstest rmdir/10
SPEED[testprmdir10]=fast
TEST_TYPE[testprmdir10]=dev,admin
NEEDS_ROOT[testprmdir10]=yes
function testprmdir10
{
  export -f test_pjdfs

  test_pjdfs rmdir/10.t
}

### testprmdir11: pjdfstest rmdir/11
SPEED[testprmdir11]=fast
TEST_TYPE[testprmdir11]=dev,admin
NEEDS_ROOT[testprmdir11]=yes
function testprmdir11
{
  export -f test_pjdfs

  test_pjdfs rmdir/11.t
}

### testprmdir12: pjdfstest rmdir/12
SPEED[testprmdir12]=fast
TEST_TYPE[testprmdir12]=dev,admin
NEEDS_ROOT[testprmdir12]=yes
function testprmdir12
{
  export -f test_pjdfs

  test_pjdfs rmdir/12.t
}

### testprmdir13: pjdfstest rmdir/13
SPEED[testprmdir13]=fast
TEST_TYPE[testprmdir13]=dev,admin
NEEDS_ROOT[testprmdir13]=yes
function testprmdir13
{
  export -f test_pjdfs

  test_pjdfs rmdir/13.t
}

### testprmdir14: pjdfstest rmdir/14
SPEED[testprmdir14]=fast
TEST_TYPE[testprmdir14]=dev,admin
NEEDS_ROOT[testprmdir14]=yes
function testprmdir14
{
  export -f test_pjdfs

  test_pjdfs rmdir/14.t
}

### testprmdir15: pjdfstest rmdir/15
SPEED[testprmdir15]=fast
TEST_TYPE[testprmdir15]=dev,admin
NEEDS_ROOT[testprmdir15]=yes
function testprmdir15
{
  export -f test_pjdfs

  test_pjdfs rmdir/15.t
}

### testpsymlink00: pjdfstest symlink/00
SPEED[testpsymlink00]=fast
TEST_TYPE[testpsymlink00]=dev,admin
NEEDS_ROOT[testpsymlink00]=yes
function testpsymlink00
{
  export -f test_pjdfs

  test_pjdfs symlink/00.t
}

### testpsymlink01: pjdfstest symlink/01
SPEED[testpsymlink01]=fast
TEST_TYPE[testpsymlink01]=dev,admin
NEEDS_ROOT[testpsymlink01]=yes
function testpsymlink01
{
  export -f test_pjdfs

  test_pjdfs symlink/01.t
}

### testpsymlink02: pjdfstest symlink/02
SPEED[testpsymlink02]=fast
TEST_TYPE[testpsymlink02]=dev,admin
NEEDS_ROOT[testpsymlink02]=yes
function testpsymlink02
{
  export -f test_pjdfs

  test_pjdfs symlink/02.t
}

### testpsymlink03: pjdfstest symlink/03
SPEED[testpsymlink03]=fast
TEST_TYPE[testpsymlink03]=dev,admin
NEEDS_ROOT[testpsymlink03]=yes
function testpsymlink03
{
  export -f test_pjdfs

  test_pjdfs symlink/03.t
}

### testpsymlink04: pjdfstest symlink/04
SPEED[testpsymlink04]=fast
TEST_TYPE[testpsymlink04]=dev,admin
NEEDS_ROOT[testpsymlink04]=yes
function testpsymlink04
{
  export -f test_pjdfs

  test_pjdfs symlink/04.t
}

### testpsymlink05: pjdfstest symlink/05
SPEED[testpsymlink05]=fast
TEST_TYPE[testpsymlink05]=dev,admin
NEEDS_ROOT[testpsymlink05]=yes
function testpsymlink05
{
  export -f test_pjdfs

  test_pjdfs symlink/05.t
}

### testpsymlink06: pjdfstest symlink/06
SPEED[testpsymlink06]=fast
TEST_TYPE[testpsymlink06]=dev,admin
NEEDS_ROOT[testpsymlink06]=yes
function testpsymlink06
{
  export -f test_pjdfs

  test_pjdfs symlink/06.t
}

### testpsymlink07: pjdfstest symlink/07
SPEED[testpsymlink07]=fast
TEST_TYPE[testpsymlink07]=dev,admin
NEEDS_ROOT[testpsymlink07]=yes
function testpsymlink07
{
  export -f test_pjdfs

  test_pjdfs symlink/07.t
}

### testpsymlink08: pjdfstest symlink/08
SPEED[testpsymlink08]=fast
TEST_TYPE[testpsymlink08]=dev,admin
NEEDS_ROOT[testpsymlink08]=yes
function testpsymlink08
{
  export -f test_pjdfs

  test_pjdfs symlink/08.t
}

### testpsymlink09: pjdfstest symlink/09
SPEED[testpsymlink09]=fast
TEST_TYPE[testpsymlink09]=dev,admin
NEEDS_ROOT[testpsymlink09]=yes
function testpsymlink09
{
  export -f test_pjdfs

  test_pjdfs symlink/09.t
}

### testpsymlink10: pjdfstest symlink/10
SPEED[testpsymlink10]=fast
TEST_TYPE[testpsymlink10]=dev,admin
NEEDS_ROOT[testpsymlink10]=yes
function testpsymlink10
{
  export -f test_pjdfs

  test_pjdfs symlink/10.t
}

### testpsymlink11: pjdfstest symlink/11
SPEED[testpsymlink11]=fast
TEST_TYPE[testpsymlink11]=dev,admin
NEEDS_ROOT[testpsymlink11]=yes
function testpsymlink11
{
  export -f test_pjdfs

  test_pjdfs symlink/11.t
}

### testpsymlink12: pjdfstest symlink/12
SPEED[testpsymlink12]=fast
TEST_TYPE[testpsymlink12]=dev,admin
NEEDS_ROOT[testpsymlink12]=yes
function testpsymlink12
{
  export -f test_pjdfs

  test_pjdfs symlink/12.t
}

### testptruncate00: pjdfstest truncate/00
SPEED[testptruncate00]=fast
TEST_TYPE[testptruncate00]=dev,admin
NEEDS_ROOT[testptruncate00]=yes
function testptruncate00
{
  export -f test_pjdfs

  test_pjdfs truncate/00.t
}

### testptruncate01: pjdfstest truncate/01
SPEED[testptruncate01]=fast
TEST_TYPE[testptruncate01]=dev,admin
NEEDS_ROOT[testptruncate01]=yes
function testptruncate01
{
  export -f test_pjdfs

  test_pjdfs truncate/01.t
}

### testptruncate02: pjdfstest truncate/02
SPEED[testptruncate02]=fast
TEST_TYPE[testptruncate02]=dev,admin
NEEDS_ROOT[testptruncate02]=yes
function testptruncate02
{
  export -f test_pjdfs

  test_pjdfs truncate/02.t
}

### testptruncate03: pjdfstest truncate/03
SPEED[testptruncate03]=fast
TEST_TYPE[testptruncate03]=dev,admin
NEEDS_ROOT[testptruncate03]=yes
function testptruncate03
{
  export -f test_pjdfs

  test_pjdfs truncate/03.t
}

### testptruncate04: pjdfstest truncate/04
SPEED[testptruncate04]=fast
TEST_TYPE[testptruncate04]=dev,admin
NEEDS_ROOT[testptruncate04]=yes
function testptruncate04
{
  export -f test_pjdfs

  test_pjdfs truncate/04.t
}

### testptruncate05: pjdfstest truncate/05
SPEED[testptruncate05]=fast
TEST_TYPE[testptruncate05]=dev,admin
NEEDS_ROOT[testptruncate05]=yes
function testptruncate05
{
  export -f test_pjdfs

  test_pjdfs truncate/05.t
}

### testptruncate06: pjdfstest truncate/06
SPEED[testptruncate06]=fast
TEST_TYPE[testptruncate06]=dev,admin
NEEDS_ROOT[testptruncate06]=yes
function testptruncate06
{
  export -f test_pjdfs

  test_pjdfs truncate/06.t
}

### testptruncate07: pjdfstest truncate/07
SPEED[testptruncate07]=fast
TEST_TYPE[testptruncate07]=dev,admin
NEEDS_ROOT[testptruncate07]=yes
function testptruncate07
{
  export -f test_pjdfs

  test_pjdfs truncate/07.t
}

### testptruncate08: pjdfstest truncate/08
SPEED[testptruncate08]=fast
TEST_TYPE[testptruncate08]=dev,admin
NEEDS_ROOT[testptruncate08]=yes
function testptruncate08
{
  export -f test_pjdfs

  test_pjdfs truncate/08.t
}

### testptruncate09: pjdfstest truncate/09
SPEED[testptruncate09]=fast
TEST_TYPE[testptruncate09]=dev,admin
NEEDS_ROOT[testptruncate09]=yes
function testptruncate09
{
  export -f test_pjdfs

  test_pjdfs truncate/09.t
}

### testptruncate10: pjdfstest truncate/10
SPEED[testptruncate10]=fast
TEST_TYPE[testptruncate10]=dev,admin
NEEDS_ROOT[testptruncate10]=yes
function testptruncate10
{
  export -f test_pjdfs

  test_pjdfs truncate/10.t
}

### testptruncate11: pjdfstest truncate/11
SPEED[testptruncate11]=fast
TEST_TYPE[testptruncate11]=dev,admin
NEEDS_ROOT[testptruncate11]=yes
function testptruncate11
{
  export -f test_pjdfs

  test_pjdfs truncate/11.t
}

### testptruncate12: pjdfstest truncate/12
SPEED[testptruncate12]=fast
TEST_TYPE[testptruncate12]=dev,admin
NEEDS_ROOT[testptruncate12]=yes
function testptruncate12
{
  export -f test_pjdfs

  test_pjdfs truncate/12.t
}

### testptruncate13: pjdfstest truncate/13
SPEED[testptruncate13]=fast
TEST_TYPE[testptruncate13]=dev,admin
NEEDS_ROOT[testptruncate13]=yes
function testptruncate13
{
  export -f test_pjdfs

  test_pjdfs truncate/13.t
}

### testptruncate14: pjdfstest truncate/14
SPEED[testptruncate14]=fast
TEST_TYPE[testptruncate14]=dev,admin
NEEDS_ROOT[testptruncate14]=yes
function testptruncate14
{
  export -f test_pjdfs

  test_pjdfs truncate/14.t
}

### testpunlink00: pjdfstest unlink/00
SPEED[testpunlink00]=medium
TEST_TYPE[testpunlink00]=dev,admin
NEEDS_ROOT[testpunlink00]=yes
function testpunlink00
{
  export -f test_pjdfs

  test_pjdfs unlink/00.t
}

### testpunlink01: pjdfstest unlink/01
SPEED[testpunlink01]=fast
TEST_TYPE[testpunlink01]=dev,admin
NEEDS_ROOT[testpunlink01]=yes
function testpunlink01
{
  export -f test_pjdfs

  test_pjdfs unlink/01.t
}

### testpunlink02: pjdfstest unlink/02
SPEED[testpunlink02]=fast
TEST_TYPE[testpunlink02]=dev,admin
NEEDS_ROOT[testpunlink02]=yes
function testpunlink02
{
  export -f test_pjdfs

  test_pjdfs unlink/02.t
}

### testpunlink03: pjdfstest unlink/03
SPEED[testpunlink03]=fast
TEST_TYPE[testpunlink03]=dev,admin
NEEDS_ROOT[testpunlink03]=yes
function testpunlink03
{
  export -f test_pjdfs

  test_pjdfs unlink/03.t
}

### testpunlink04: pjdfstest unlink/04
SPEED[testpunlink04]=fast
TEST_TYPE[testpunlink04]=dev,admin
NEEDS_ROOT[testpunlink04]=yes
function testpunlink04
{
  export -f test_pjdfs

  test_pjdfs unlink/04.t
}

### testpunlink05: pjdfstest unlink/05
SPEED[testpunlink05]=fast
TEST_TYPE[testpunlink05]=dev,admin
NEEDS_ROOT[testpunlink05]=yes
function testpunlink05
{
  export -f test_pjdfs

  test_pjdfs unlink/05.t
}

### testpunlink06: pjdfstest unlink/06
SPEED[testpunlink06]=fast
TEST_TYPE[testpunlink06]=dev,admin
NEEDS_ROOT[testpunlink06]=yes
function testpunlink06
{
  export -f test_pjdfs

  test_pjdfs unlink/06.t
}

### testpunlink07: pjdfstest unlink/07
SPEED[testpunlink07]=fast
TEST_TYPE[testpunlink07]=dev,admin
NEEDS_ROOT[testpunlink07]=yes
function testpunlink07
{
  export -f test_pjdfs

  test_pjdfs unlink/07.t
}

### testpunlink08: pjdfstest unlink/08
SPEED[testpunlink08]=fast
TEST_TYPE[testpunlink08]=dev,admin
NEEDS_ROOT[testpunlink08]=yes
function testpunlink08
{
  export -f test_pjdfs

  test_pjdfs unlink/08.t
}

### testpunlink09: pjdfstest unlink/09
SPEED[testpunlink09]=fast
TEST_TYPE[testpunlink09]=dev,admin
NEEDS_ROOT[testpunlink09]=yes
function testpunlink09
{
  export -f test_pjdfs

  test_pjdfs unlink/09.t
}

### testpunlink10: pjdfstest unlink/10
SPEED[testpunlink10]=fast
TEST_TYPE[testpunlink10]=dev,admin
NEEDS_ROOT[testpunlink10]=yes
function testpunlink10
{
  export -f test_pjdfs

  test_pjdfs unlink/10.t
}

### testpunlink11: pjdfstest unlink/11
SPEED[testpunlink11]=fast
TEST_TYPE[testpunlink11]=dev,admin
NEEDS_ROOT[testpunlink11]=yes
function testpunlink11
{
  export -f test_pjdfs

  test_pjdfs unlink/11.t
}

### testpunlink12: pjdfstest unlink/12
SPEED[testpunlink12]=fast
TEST_TYPE[testpunlink12]=dev,admin
NEEDS_ROOT[testpunlink12]=yes
function testpunlink12
{
  export -f test_pjdfs

  test_pjdfs unlink/12.t
}

### testpunlink13: pjdfstest unlink/13
SPEED[testpunlink13]=fast
TEST_TYPE[testpunlink13]=dev,admin
NEEDS_ROOT[testpunlink13]=yes
function testpunlink13
{
  export -f test_pjdfs

  test_pjdfs unlink/13.t
}


######################## DEFINE TEST LIST HERE ####################

function run_pjdfs
{
  export -f test_pjdfs

  # display test summary / generate outputs

  run_test testpchflags00 "pjdfs/chflags/00"
  run_test testpchflags01 "pjdfs/chflags/01"
  run_test testpchflags02 "pjdfs/chflags/02"
  run_test testpchflags03 "pjdfs/chflags/03"
  run_test testpchflags04 "pjdfs/chflags/04"
  run_test testpchflags05 "pjdfs/chflags/05"
  run_test testpchflags06 "pjdfs/chflags/06"
  run_test testpchflags07 "pjdfs/chflags/07"
  run_test testpchflags08 "pjdfs/chflags/08"
  run_test testpchflags09 "pjdfs/chflags/09"
  run_test testpchflags10 "pjdfs/chflags/10"
  run_test testpchflags11 "pjdfs/chflags/11"
  run_test testpchflags12 "pjdfs/chflags/12"
  run_test testpchflags13 "pjdfs/chflags/13"
  run_test testpchmod00 "pjdfs/chmod/00"
  run_test testpchmod01 "pjdfs/chmod/01"
  run_test testpchmod02 "pjdfs/chmod/02"
  run_test testpchmod03 "pjdfs/chmod/03"
  run_test testpchmod04 "pjdfs/chmod/04"
  run_test testpchmod05 "pjdfs/chmod/05"
  run_test testpchmod06 "pjdfs/chmod/06"
  run_test testpchmod07 "pjdfs/chmod/07"
  run_test testpchmod08 "pjdfs/chmod/08"
  run_test testpchmod09 "pjdfs/chmod/09"
  run_test testpchmod10 "pjdfs/chmod/10"
  run_test testpchmod11 "pjdfs/chmod/11"
  run_test testpchmod12 "pjdfs/chmod/12"
  run_test testpchown00 "pjdfs/chown/00"
  run_test testpchown01 "pjdfs/chown/01"
  run_test testpchown02 "pjdfs/chown/02"
  run_test testpchown03 "pjdfs/chown/03"
  run_test testpchown04 "pjdfs/chown/04"
  run_test testpchown05 "pjdfs/chown/05"
  run_test testpchown06 "pjdfs/chown/06"
  run_test testpchown07 "pjdfs/chown/07"
  run_test testpchown08 "pjdfs/chown/08"
  run_test testpchown09 "pjdfs/chown/09"
  run_test testpchown10 "pjdfs/chown/10"
  run_test testpftruncate00 "pjdfs/ftruncate/00"
  run_test testpftruncate01 "pjdfs/ftruncate/01"
  run_test testpftruncate02 "pjdfs/ftruncate/02"
  run_test testpftruncate03 "pjdfs/ftruncate/03"
  run_test testpftruncate04 "pjdfs/ftruncate/04"
  run_test testpftruncate05 "pjdfs/ftruncate/05"
  run_test testpftruncate06 "pjdfs/ftruncate/06"
  run_test testpftruncate07 "pjdfs/ftruncate/07"
  run_test testpftruncate08 "pjdfs/ftruncate/08"
  run_test testpftruncate09 "pjdfs/ftruncate/09"
  run_test testpftruncate10 "pjdfs/ftruncate/10"
  run_test testpftruncate11 "pjdfs/ftruncate/11"
  run_test testpftruncate12 "pjdfs/ftruncate/12"
  run_test testpftruncate13 "pjdfs/ftruncate/13"
  run_test testpftruncate14 "pjdfs/ftruncate/14"
  run_test testpgranular00 "pjdfs/granular/00"
  run_test testpgranular01 "pjdfs/granular/01"
  run_test testpgranular02 "pjdfs/granular/02"
  run_test testpgranular03 "pjdfs/granular/03"
  run_test testpgranular04 "pjdfs/granular/04"
  run_test testpgranular05 "pjdfs/granular/05"
  run_test testplink00 "pjdfs/link/00"
  run_test testplink01 "pjdfs/link/01"
  run_test testplink02 "pjdfs/link/02"
  run_test testplink03 "pjdfs/link/03"
  run_test testplink04 "pjdfs/link/04"
  run_test testplink05 "pjdfs/link/05"
  run_test testplink06 "pjdfs/link/06"
  run_test testplink07 "pjdfs/link/07"
  run_test testplink08 "pjdfs/link/08"
  run_test testplink09 "pjdfs/link/09"
  run_test testplink10 "pjdfs/link/10"
  run_test testplink11 "pjdfs/link/11"
  run_test testplink12 "pjdfs/link/12"
  run_test testplink13 "pjdfs/link/13"
  run_test testplink14 "pjdfs/link/14"
  run_test testplink15 "pjdfs/link/15"
  run_test testplink16 "pjdfs/link/16"
  run_test testplink17 "pjdfs/link/17"
  run_test testpmkdir00 "pjdfs/mkdir/00"
  run_test testpmkdir01 "pjdfs/mkdir/01"
  run_test testpmkdir02 "pjdfs/mkdir/02"
  run_test testpmkdir03 "pjdfs/mkdir/03"
  run_test testpmkdir04 "pjdfs/mkdir/04"
  run_test testpmkdir05 "pjdfs/mkdir/05"
  run_test testpmkdir06 "pjdfs/mkdir/06"
  run_test testpmkdir07 "pjdfs/mkdir/07"
  run_test testpmkdir08 "pjdfs/mkdir/08"
  run_test testpmkdir09 "pjdfs/mkdir/09"
  run_test testpmkdir10 "pjdfs/mkdir/10"
  run_test testpmkdir11 "pjdfs/mkdir/11"
  run_test testpmkdir12 "pjdfs/mkdir/12"
  run_test testpmkfifo00 "pjdfs/mkfifo/00"
  run_test testpmkfifo01 "pjdfs/mkfifo/01"
  run_test testpmkfifo02 "pjdfs/mkfifo/02"
  run_test testpmkfifo03 "pjdfs/mkfifo/03"
  run_test testpmkfifo04 "pjdfs/mkfifo/04"
  run_test testpmkfifo05 "pjdfs/mkfifo/05"
  run_test testpmkfifo06 "pjdfs/mkfifo/06"
  run_test testpmkfifo07 "pjdfs/mkfifo/07"
  run_test testpmkfifo08 "pjdfs/mkfifo/08"
  run_test testpmkfifo09 "pjdfs/mkfifo/09"
  run_test testpmkfifo10 "pjdfs/mkfifo/10"
  run_test testpmkfifo11 "pjdfs/mkfifo/11"
  run_test testpmkfifo12 "pjdfs/mkfifo/12"
  run_test testpmknod00 "pjdfs/mknod/00"
  run_test testpmknod01 "pjdfs/mknod/01"
  run_test testpmknod02 "pjdfs/mknod/02"
  run_test testpmknod03 "pjdfs/mknod/03"
  run_test testpmknod04 "pjdfs/mknod/04"
  run_test testpmknod05 "pjdfs/mknod/05"
  run_test testpmknod06 "pjdfs/mknod/06"
  run_test testpmknod07 "pjdfs/mknod/07"
  run_test testpmknod08 "pjdfs/mknod/08"
  run_test testpmknod09 "pjdfs/mknod/09"
  run_test testpmknod10 "pjdfs/mknod/10"
  run_test testpmknod11 "pjdfs/mknod/11"
  run_test testpopen00 "pjdfs/open/00"
  run_test testpopen01 "pjdfs/open/01"
  run_test testpopen02 "pjdfs/open/02"
  run_test testpopen03 "pjdfs/open/03"
  run_test testpopen04 "pjdfs/open/04"
  run_test testpopen05 "pjdfs/open/05"
  run_test testpopen06 "pjdfs/open/06"
  run_test testpopen07 "pjdfs/open/07"
  run_test testpopen08 "pjdfs/open/08"
  run_test testpopen09 "pjdfs/open/09"
  run_test testpopen10 "pjdfs/open/10"
  run_test testpopen11 "pjdfs/open/11"
  run_test testpopen12 "pjdfs/open/12"
  run_test testpopen13 "pjdfs/open/13"
  run_test testpopen14 "pjdfs/open/14"
  run_test testpopen15 "pjdfs/open/15"
  run_test testpopen16 "pjdfs/open/16"
  run_test testpopen17 "pjdfs/open/17"
  run_test testpopen18 "pjdfs/open/18"
  run_test testpopen19 "pjdfs/open/19"
  run_test testpopen20 "pjdfs/open/20"
  run_test testpopen21 "pjdfs/open/21"
  run_test testpopen22 "pjdfs/open/22"
  run_test testpopen23 "pjdfs/open/23"
  run_test testpopen24 "pjdfs/open/24"
  run_test testprename00 "pjdfs/rename/00"
  run_test testprename01 "pjdfs/rename/01"
  run_test testprename02 "pjdfs/rename/02"
  run_test testprename03 "pjdfs/rename/03"
  run_test testprename04 "pjdfs/rename/04"
  run_test testprename05 "pjdfs/rename/05"
  run_test testprename06 "pjdfs/rename/06"
  run_test testprename07 "pjdfs/rename/07"
  run_test testprename08 "pjdfs/rename/08"
  run_test testprename09 "pjdfs/rename/09"
  run_test testprename10 "pjdfs/rename/10"
  run_test testprename11 "pjdfs/rename/11"
  run_test testprename12 "pjdfs/rename/12"
  run_test testprename13 "pjdfs/rename/13"
  run_test testprename14 "pjdfs/rename/14"
  run_test testprename15 "pjdfs/rename/15"
  run_test testprename16 "pjdfs/rename/16"
  run_test testprename17 "pjdfs/rename/17"
  run_test testprename18 "pjdfs/rename/18"
  run_test testprename19 "pjdfs/rename/19"
  run_test testprename20 "pjdfs/rename/20"
  run_test testprename21 "pjdfs/rename/21"
  run_test testprmdir00 "pjdfs/rmdir/00"
  run_test testprmdir01 "pjdfs/rmdir/01"
  run_test testprmdir02 "pjdfs/rmdir/02"
  run_test testprmdir03 "pjdfs/rmdir/03"
  run_test testprmdir04 "pjdfs/rmdir/04"
  run_test testprmdir05 "pjdfs/rmdir/05"
  run_test testprmdir06 "pjdfs/rmdir/06"
  run_test testprmdir07 "pjdfs/rmdir/07"
  run_test testprmdir08 "pjdfs/rmdir/08"
  run_test testprmdir09 "pjdfs/rmdir/09"
  run_test testprmdir10 "pjdfs/rmdir/10"
  run_test testprmdir11 "pjdfs/rmdir/11"
  run_test testprmdir12 "pjdfs/rmdir/12"
  run_test testprmdir13 "pjdfs/rmdir/13"
  run_test testprmdir14 "pjdfs/rmdir/14"
  run_test testprmdir15 "pjdfs/rmdir/15"
  run_test testpsymlink00 "pjdfs/symlink/00"
  run_test testpsymlink01 "pjdfs/symlink/01"
  run_test testpsymlink02 "pjdfs/symlink/02"
  run_test testpsymlink03 "pjdfs/symlink/03"
  run_test testpsymlink04 "pjdfs/symlink/04"
  run_test testpsymlink05 "pjdfs/symlink/05"
  run_test testpsymlink06 "pjdfs/symlink/06"
  run_test testpsymlink07 "pjdfs/symlink/07"
  run_test testpsymlink08 "pjdfs/symlink/08"
  run_test testpsymlink09 "pjdfs/symlink/09"
  run_test testpsymlink10 "pjdfs/symlink/10"
  run_test testpsymlink11 "pjdfs/symlink/11"
  run_test testpsymlink12 "pjdfs/symlink/12"
  run_test testptruncate00 "pjdfs/truncate/00"
  run_test testptruncate01 "pjdfs/truncate/01"
  run_test testptruncate02 "pjdfs/truncate/02"
  run_test testptruncate03 "pjdfs/truncate/03"
  run_test testptruncate04 "pjdfs/truncate/04"
  run_test testptruncate05 "pjdfs/truncate/05"
  run_test testptruncate06 "pjdfs/truncate/06"
  run_test testptruncate07 "pjdfs/truncate/07"
  run_test testptruncate08 "pjdfs/truncate/08"
  run_test testptruncate09 "pjdfs/truncate/09"
  run_test testptruncate10 "pjdfs/truncate/10"
  run_test testptruncate11 "pjdfs/truncate/11"
  run_test testptruncate12 "pjdfs/truncate/12"
  run_test testptruncate13 "pjdfs/truncate/13"
  run_test testptruncate14 "pjdfs/truncate/14"
  run_test testpunlink00 "pjdfs/unlink/00"
  run_test testpunlink01 "pjdfs/unlink/01"
  run_test testpunlink02 "pjdfs/unlink/02"
  run_test testpunlink03 "pjdfs/unlink/03"
  run_test testpunlink04 "pjdfs/unlink/04"
  run_test testpunlink05 "pjdfs/unlink/05"
  run_test testpunlink06 "pjdfs/unlink/06"
  run_test testpunlink07 "pjdfs/unlink/07"
  run_test testpunlink08 "pjdfs/unlink/08"
  run_test testpunlink09 "pjdfs/unlink/09"
  run_test testpunlink10 "pjdfs/unlink/10"
  run_test testpunlink11 "pjdfs/unlink/11"
  run_test testpunlink12 "pjdfs/unlink/12"
  run_test testpunlink13 "pjdfs/unlink/13"

  test_finalize
}


