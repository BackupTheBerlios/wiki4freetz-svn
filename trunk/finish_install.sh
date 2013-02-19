#!/bin/sh
# 
# File	     : finish_install.sh
# Author     : Jean-Pierre Redonnét
# Description: install CiWiki files
# ------------------------------------
# ChangeLog:
# JPR version 1.1 August 8 2010
# the - 02/15/2013 - removed usage of xterm
# the - 02/17/2013 - the script refactoring
# ------------------------------------

usage () {
	cat <<-EOF
	Usage: $(basename $0) [-s] [-d <targetDir>]
	Installation of additional files and folders for CiWiki.
    
	Optional arguments:
	    -s        silent mode, no user interaction
	    -d <dir>  target directory path
EOF
	exit 1
}

# get command line options
set -- $(getopt "shd:" "$@")

# handle command line options
while :
do
	case "$1" in 
		-s) silent=1 ;;
		-d) shift; datadir=$1 ;;
		-h) usage ;;
		--) break ;;
	esac
	shift
done

# check user's yes/ no answer
yesno () {
	read -p "$1 ([y]/n) "  doit
	if [ "$doit" = n ]; then
		return 1 
	fi
	return 0
}

mkfolder() {
	if [ ! -d $1 ]; then
		echo "Create folder $1"
        mkdir -v -p $1
	fi
}

interactive() {

	cat <<-EOF
	------------------------------------------------
	Installation of extra CiWiki files
    ------------------------------------------------
	
EOF

	if ! [ -d "src" ]; then 
	  echo "Please run this script from ciwiki-xxx directory."
	  exit 0
	fi

	# Define CiWiki working directory
	datadir=~/.didiwiki
	while :
	do
		read -p "Please entry working directory [$datadir]: " datadir
		if yesno "Is this correct?"; then
			break
		fi
		datadir=~/.didiwiki
	done
}

if [ $silent=1 ]; then
	if [ -z $datadir ]; then
		echo
		echo "Missing option -d <directory>!"
		echo
		usage
	fi
else
	echo "Calling interactive setup"
	interactive
fi

# init further install locations
scripts=$datadir/scripts
images=$datadir/images
zipped=$datadir/files
permission=$datadir/permission
login=$datadir/.login.txt
styles=$datadir/styles.css


# Silent or interactive execution

if [ ! $silent=1 ]; then

	cat <<-EOF
	---------------------
	Installation summary:
	---------------------
	Folder
	    CiWiki working directory      : $datadir
	    Script directory              : $scripts
	    Image directory               : $images
	    Zipped file directory         : $zipped
	    Permission directory          : $permission
	Files
	    Install styles.css to $datadir if not exits.
	    Move .login.txt to $permission 
	    (for previous version < 1.7)

EOF
	if ! yesno "Do you like to proceed these settings?"; then
		exit 0
	fi
fi

# create target dir
mkfolder $datadir

# Install css styles
if [ -f "$styles" ]; then 
	echo "styles.css already exists in $datadir."
	if yesno "Would you like to see differences between both files?"; then
		echo "-------- DIFF --------"
		diff -s styles.css $styles
		echo "-------- EOF DIFF --------"
		read -p "Continue with any key ..."
	fi
else
	echo -n "Copy styles.css to $datadir :"
	cp -v styles.css $datadir/
fi

#Install scripts
mkfolder $scripts
echo "Copy scripts" 
cp -v scripts/*.sh $scripts/

#Install images
mkfolder $images 
if [ -f "images/ciwiki.png" ]; then
    echo "Copy pictures " 
	cp -v images/*.png $images/
fi

#Install zip 
mkfolder $zipped
if [ -f "files/index.zip" ]; then
	echo "Copy zip files " 
	cp -v files/*.zip $zipped/
fi

#Move .login.txt for version < 1.7
mkfolder $permission 
if [ -f "$datadir/.login.txt" ]; then
	echo "Move .login.txt to $permission" 
	mv $datadir/.login.txt $permission/.login.txt
fi

echo
echo "You will need sSMTP to notify new users by email."

sstmp=$(which ssmtp)
if [ -z "$ssmtp" ]; then
	echo "You will have to install sSMTP  (sudo apt-get install ssmtp for Debian)."
fi
echo "You will also need to check configuration of sSMTP (e.g. /etc/ssmtp/ssmtp.conf)!"

echo
echo "Installation finished"

