#!/bin/sh
#--------------------------------------------
# File  : mkarchive.sh
# Desc  : Create tbflex installation package
# Author: the
#--------------------------------------------

tbflexversion=TBflex-2.4

# create tmp directory
if [ ! -d tmp ]; then
	mkdir tmp
fi
rm -rf tmp/*
mkdir -p tmp/service/wiki4freetz
mkdir -p tmp/tools/wiki4freetz
mkdir -p tmp/install-script

# copy stuff
cp -R ../images tmp/tools/wiki4freetz/
cp -R ../scripts tmp/tools/wiki4freetz/
cp -R ../files tmp/tools/wiki4freetz/
cp ../styles.css tmp/tools/wiki4freetz/

if [ ! -f ../src/didiwiki ]; then
	echo "Missing binary 'didiwiki' in src"
	exit 1
fi
cp ../src/didiwiki tmp/service/wiki4freetz/
cp do_install.sh tmp/install-script/

cd tmp
tar czvf ../Wiki4Freetz[$tbflexversion].tar.gz tools service install-script --exclude .svn
