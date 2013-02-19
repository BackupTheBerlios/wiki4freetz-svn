#!/bin/sh
echo "Run in Console - Return your inet address"
str=`ifconfig`
str=${str#*inet adr:}
echo your inet address is ${str%% *}
echo "Enter to exit"
read a
