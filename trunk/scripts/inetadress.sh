#!/bin/sh
str=`ifconfig`
str=${str#*inet adr:}
echo ${str%% *}
