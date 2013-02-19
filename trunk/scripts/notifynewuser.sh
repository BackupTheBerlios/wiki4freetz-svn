#!/bin/sh
# This simple bash script will send the validation code to the new users
# Require ssmtp (relay email to your smtp)
# if newwikiusers.txt exists, then it's renamed.
# Email, name,pwd and code are extracted and sent with ssmtp
# The result file newusersnotified.txt is updated
# JP Redonnet May 2010 - inphilly@gmail.com
# Rev 1.1 August 2010

# newwikiusers.txt should be in the home dir
file1=newuser/newwikiusers.txt

# temporary file
file2=newuser/newwikiusers.temp

# list of users notified
file3=newuser/newusersnotified.txt

#wiki address, we need the ip address and the port 
#we will create a direct link to validate a new registration
wikiaddr="http://$(hostname):8001"

# Subject, body
subject='Your CiWiki Access Code\n'
body='
    Hello\n
    To validate your new account;
    Please click on the direct link below,
    or in the Wiki, click on login, choose new account,
    Reenter your username, password, and email,
    Enter your access code.\n'
thanks='\nThank you!\n'

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

    # Sendmail
    echo "Subject: $subject\n
    $body
    Your username: $usr
    Your password: $pwd
    Your access code: $code
    Direct link: $direct
    $thanks"|sendmail $email >> $file3
  done < $file2
fi
exit 0
