geniewiki: wiki.gs wikihandler.gs wikifile.gs wikitext.gs wikixml2html.gs wikiparse
	valac -o geniewiki --pkg libxml-2.0 --pkg gio-2.0 --pkg gee-1.0 \
	wiki.gs wikihandler.gs wikitext.gs wikifile.gs wikixml2html.gs \
	wikiparse.tab.c parsetree.c lex.yy.c wikiparse.vapi
	strip -s geniewiki

wikiparse: lex.yy.c wikiparse.tab.c parsetree.c parsetree.h wikiparse.vapi
	
lex.yy.c : wikilex.l
	flex wikilex.l

wikiparse.tab.c : wikiparse.y
	bison -d wikiparse.y

