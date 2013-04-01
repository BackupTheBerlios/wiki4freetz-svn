#!/bin/sh
# This simple bash script searchs user registrations in newwikiusers.txt
# JP Redonnet August 2010 - inphilly@gmail.com
# newwikiusers.txt should be in the home dir
file1=~/newwikiusers.txt
file2=~/newusersnotified.txt
echo "Search user registrations in newwikiusers.txt"
echo "Enter the user name"
read a

if [ -f "$file1" ]
then
    echo "User not notified yet:"
    grep -i $a $file1
    echo "------------------------------"
fi
if [ -f "$file2" ]
then
    echo "User alread notified:"
    grep -i $a $file2
    echo "------------------------------"
fi
echo "Press Enter"
read a
