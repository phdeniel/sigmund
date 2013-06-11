#!/bin/bash

########################## TEST HELPERS ##################

############################ TEST FUNCTIONS ############################


### test90a : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test90a]=fast
NEEDS_ROOT[test90a]=no
function test90a
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ExportMgr \
             org.ganesha.nfsd.exportmgr.ShowExports || error "ERROR while calling dbus-send"
}

### test91b : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
### the difference with the former test is the input parameter in dbus-send
SPEED[test91b]=fast
NEEDS_ROOT[test91b]=no
function test91b
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ExportMgr \
             org.ganesha.nfsd.exportmgr.GetNFSv3IO int32:1 || error "ERROR while calling dbus-send"
}

### test91b : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test91c]=fast
NEEDS_ROOT[test91c]=no
function test91c
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ExportMgr \
             org.ganesha.nfsd.exportmgr.GetNFSv40IO int32:1 || error "ERROR while calling dbus-send"
}

### test91d : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test91d]=fast
NEEDS_ROOT[test91d]=no
function test91d
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ExportMgr \
             org.ganesha.nfsd.exportmgr.GetNFSv41IO int32:1 || error "ERROR while calling dbus-send"
}

### test91e : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test91e]=fast
NEEDS_ROOT[test91e]=no
function test91e
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ExportMgr \
             org.ganesha.nfsd.exportmgr.GetNFSv41Layouts int32:1 || error "ERROR while calling dbus-send"
}

### test92f : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test92f]=fast
NEEDS_ROOT[test92f]=no
function test92f
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ClientMgr \
             org.ganesha.nfsd.clientmgr.ShowClients  || error "ERROR while calling dbus-send"
}


### test92g : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test92g]=fast
NEEDS_ROOT[test92g]=no
function test92g
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ClientMgr \
             org.ganesha.nfsd.clientstats.GetNFSv3IO string:"127.0.0.1" || error "ERROR while calling dbus-send"
}

### test92h : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test92h]=fast
NEEDS_ROOT[test92h]=no
function test92h
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ClientMgr \
             org.ganesha.nfsd.clientstats.GetNFSv40IO string:"127.0.0.1" || error "ERROR while calling dbus-send"
}

### test92i : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test92i]=fast
NEEDS_ROOT[test92i]=no
function test92i
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ClientMgr \
             org.ganesha.nfsd.clientstats.GetNFSv41IO string:"127.0.0.1"  || error "ERROR while calling dbus-send"
}

### test92j : Make a simple call to D-BUS to make sure Ganesha replies to D-Bus requests
SPEED[test92j]=fast
NEEDS_ROOT[test92j]=no
function test92j
{
   dbus-send --system --print-reply --dest=org.ganesha.nfsd --type=method_call \
             /org/ganesha/nfsd/ClientMgr \
             org.ganesha.nfsd.clientstats.GetNFSv41IO string:"127.0.0.1"  || error "ERROR while calling dbus-send"
}

function run_ganesha_dbus
{
  run_test test90a  "D-BUS: call to exprt:ShowExports          "
  run_test test91b  "D-BUS: call to export:GetNFSv3IO          "
  run_test test91c  "D-BUS: call to export:GetNFSv40IO         "
  run_test test91d  "D-BUS: call to export:GetNFSv41IO         "
  run_test test91e  "D-BUS: call to export:GetNFSv41Layouts    " 
  run_test test92f  "D-BUS: call to client:ShowClients         "
  run_test test92g  "D-BUS: call to client:GetNFSv3IO          "
  run_test test92h  "D-BUS: call to client:GetNFSv40IO         "
  run_test test92i  "D-BUS: call to client:GetNFSv41IO         "
  run_test test92j  "D-BUS: call to client:GetNFSv41Layouts    "
}

