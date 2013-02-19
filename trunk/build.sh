#!/bin/sh
#
# File: build.sh
# Desc: Builds didiwiki from source
# Date: 01/12/2013
#

# store old path
OLD_PATH=$PATH

export PATH=../src-freetz/trunk/7390/toolchain/target/bin:$PATH
./configure --build=i386-linux-gnu --target=mips-linux --host=mips-linux CC="mips-linux-gcc" CFLAGS="-Os -pipe -march=4kc -Wa,--trap" && make

# restore old path
export PATH=$OLD_PATH
