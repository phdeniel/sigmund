#!/bin/bash

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################


### test91b : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test91b]=fast
NEEDS_ROOT[test91b]=no
function test91b
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ExportMgr \
             org.ganesha.nfsd.exportmgr.ShowExports || error "ERROR while calling dbus-send"
}

function run_ganesha_dbus
{
  run_test test91b  "D-BUS: call to ShowExports method         "
}

