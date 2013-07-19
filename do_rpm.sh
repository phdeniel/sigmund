#!/bin/sh -x 
here=`basename $PWD`
cd ..
ln -s $here sigmund-1
tar cvfz sigmund.tar.gz sigmund-1/* && rpmbuild -ta sigmund.tar.gz
cd $here

