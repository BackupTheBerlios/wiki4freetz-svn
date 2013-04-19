#
# Make GenieWiki
#

geniewiki: wiki*.gs wikiparse
	valac -o geniewiki --pkg libxml-2.0 --pkg gio-2.0 --pkg  libsoup-2.4 --pkg gee-1.0 \
	wiki*.gs wikiparse.tab.c parsetree.c lex.yy.c wikiparse.vapi
	strip -s geniewiki

wikiparse: lex.yy.c wikiparse.tab.c parsetree.c parsetree.h wikiparse.vapi
	
lex.yy.c : wikilex.l
	flex wikilex.l

wikiparse.tab.c : wikiparse.y
	bison -d wikiparse.y

.PHONY: clean distclean all

clean:
	rm -rf *.o geniewiki gwpasswd

distclean:
	rm -rf *.o geniewiki gwpasswd lex.yy.c wikiparse.tab.c

all: geniewiki gwpasswd

gwpasswd: gwpasswd.gs wikiauth.gs
	valac -o gwpasswd --pkg gio-2.0 --pkg gee-1.0 gwpasswd.gs wikiauth.gs
