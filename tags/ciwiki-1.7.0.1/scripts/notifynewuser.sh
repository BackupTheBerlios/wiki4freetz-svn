#!/bin/sh
# This simple bash script will send the validation code to the new users
# Require ssmtp (relay email to your smtp)
# if newwikiusers.txt exists, then it's renamed.
# Email, name,pwd and code are extracted and sent with ssmtp
# The result file newusersnotified.txt is updated
# JP Redonnet May 2010 - inphilly@gmail.com
# Rev 1.1 August 2010
# newwikiusers.txt should be in the home dir
file1=~/newwikiusers.txt
# temporary file
file2=~/newwikiusers.temp
# list of users notified
file3=~/newusersnotified.txt
#wiki address, we need the ip address and the port 
#we will create a direct link to validate a new registration
str=`ifconfig`
str=${str#*inet adr:}
wikiaddr='http://'${str%% *}':7000'
# Subject, body
subject='Your CiWiki Access Code\r'
body='Hello\r\rTo validate your new account;
      Please click on the direct link below,
      or in the Wiki, click on login, choose new account,
      Reenter your username, password, and email,
      Enter your access code.\r'
thanks='\rThank you!\r'

if [ -f "$file1" ]
then
  mv -f $file1 $file2
  while read line
  do
    email=${line#*M:}
    email=${email%% *}
    usr=${line#*U:}
    usr=${usr%% *}
    pwd=${line#*P:}
    pwd=${pwd%% *}
    code=${line#*C:}
    direct=$wikiaddr'/Login?rac='$email,$code,$usr,$pwd

    date >> $file3
    echo "$line" >> $file3
    echo "Subject:$subject\r \
    $body\r \
    Your username:$usr\r \
    Your password:$pwd\r \
    Your access code:$code\r \
    Direct link: $direct\r \
    $thanks\r"|sendmail $email >> $file3
  done < $file2
fi
exit 0
