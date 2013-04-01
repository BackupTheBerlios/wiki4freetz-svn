# Taken from CVS:phase3/extensions/wikidiff/Makefile and modified

genietest:  lex.yy.c wikiparse.tab.c parsetree.c parsetree.h wikiparse.vapi genietest.gs
	valac -o wikiparse --pkg libxml-2.0 wikiparse.tab.c parsetree.c lex.yy.c wikiparse.vapi genietest.gs

lex.yy.c : wikilex.l
	flex wikilex.l

wikiparse.tab.c : wikiparse.y
	bison -d wikiparse.y

clean :
	rm -f wikiparse.tab.c
	rm -f wikiparse.tab.h
	rm -f lex.yy.c

