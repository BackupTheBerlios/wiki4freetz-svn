# -----------------------------------
# File   : do_install.sh
# Author : the
# Desc   : install with ToolboxFlex
# -----------------------------------
cgi --id=smartreader-tool

. /mod/etc/conf/tbflex.cfg

USTOR_PATH=$TBFLEX_USTOR_PATH
WORKING_DIR=$USTOR_PATH/upload_dir

boxtype=$FREETZ_INFO_BOXTYPE

footer() {
	cgi_end
}

do_exit() {
	footer
	exit "$@"
}

cgi_begin 'Installation von Wiki4Freetz'

tbmod_pre_begin
	echo "... installiere Wiki4Freetz Service"
	cp -R $WORKING_DIR/service/wiki4freetz $USTOR_PATH/service/ 2>/dev/null
	chmod -R 755 $USTOR_PATH/service/wiki4freetz
	chown -R root:root $USTOR_PATH/service/wiki4freetz

	echo "... installiere Wiki4Freetz Arbeitsverzeichnis"
	cp -R $WORKING_DIR/tools $USTOR_PATH/ 2>/dev/null
	chmod -R 755 $USTOR_PATH/tools/wiki4freetz
	chown -R root:root $USTOR_PATH/tools/wiki4freetz

	echo "... melde Wiki4Freetz an"
	echo "Wiki4Freetz='available'" >> $USTOR_PATH/external_folder/all_data/external.cfg
	chmod -R 755 $USTOR_PATH/external_folder/all_data
	chown -R root:root $USTOR_PATH/external_folder/all_data
	echo "... schliesse Installation ab."
	rm -rf $WORKING_DIR  2>/dev/null
	rm -r $USTOR_PATH/external_folder/toolbox/mww/install/do_install.sh 2>/dev/null
tbmod_pre_end
tbmod_status "done"
do_exit 0

