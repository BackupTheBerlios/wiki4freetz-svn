#
# Make GenieWiki
# Author: the
# Package dependencies: libxml2-dev libgee-dev libsoup2.4-dev
#   

VALAC_ARGS = \
	--pkg libxml-2.0 \
	--pkg gio-2.0 \
	--pkg libsoup-2.4 \
	--pkg gee-1.0

VALA_SOURCES = \
	wiki*.gs \
	wikiparse.tab.c \
	parsetree.c \
	lex.yy.c \
	wikiparse.vapi

# /trunk/toolchain/build/mips_gcc-4.6.4_uClibc-0.9.32.1/mips-linux-uclibc/bin/
MIPS_CC = mips-linux-gcc

geniewiki: wiki*.gs wikiparse
	valac -o geniewiki $(VALAC_ARGS) $(VALA_SOURCES) 
	strip -s geniewiki

wikiparse: lex.yy.c wikiparse.tab.c parsetree.c parsetree.h wikiparse.vapi
	
lex.yy.c: wikilex.l
	flex wikilex.l

wikiparse.tab.c: wikiparse.y
	bison -d wikiparse.y

wiki4freetz:  wiki*.gs wikiparse gwpasswd.gs wikiauth.gs
	valac --cc=$(MIPS_CC) -o geniewiki $(VALAC_ARGS) $(VALA_SOURCES) 
	valac --cc=$(MIPS_CC) -o gwpasswd --pkg gio-2.0 --pkg gee-1.0 gwpasswd.gs wikiauth.gs
	strip -s geniewiki
	strip -s gwpasswd

.PHONY: clean distclean all

clean:
	rm -rf *.o geniewiki gwpasswd

distclean:
	rm -rf *.o geniewiki gwpasswd lex.yy.c wikiparse.tab.c

all: geniewiki gwpasswd

gwpasswd: gwpasswd.gs wikiauth.gs
	valac -o gwpasswd --pkg gio-2.0 --pkg gee-1.0 gwpasswd.gs wikiauth.gs
	strip -s gwpasswd
