%{
/*
 * Parser for MediaWiki syntax
 * Author: the, March 2013
 */
#  include <stdio.h>
%}

/*
%union {
	int ival;
	float fval;
	char *sval;
}
*/

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
/*
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
*/
%token CR
%token CR_DOUBLE
%token LF LF_DOUBLE
%token VALIDURLCHARS
%token NEWPARAGRAPH
%token MATH MATH_END
%token NOWIKI NOWIKI_END
%token GENERICLINK TITLEDLINK WIKILINK
%token CURRENTDAY CURRENTMONTH CURRENTTIME CURRENTYEAR
%token LIST
%token PRE PRE_END
%token HR
%token H1 H2 H3 H4 H5 H6
%token EMPHASIZE SEMPHASIZE VSEMPHASIZE
%token LESSERTHAN GREATERTHAN
%token TEXT

%%

article:	/* nothing */
			| CR blocks
			| newlines blocks
			| blocks newlines
			;

newlines: 	CR_DOUBLE	{ printf("newlines: CR double\n"); }
			| LF_DOUBLE	{ printf("newlines: LF double\n"); }
			| newlines CR 	{ printf("newlines: CR\n"); }
			| newlines LF  	{ printf("newlines: LF\n"); }
			;

blocks: 	block	{ printf("block: %s\n", $1); }
			| blocks block  { printf("blocks: %s\n", $2); }
			;

block: 		paragraph	{ printf("paragraph: %s\n", $1); }
			| heading { printf("heading: %s\n", $1); }
			;

paragraph:  text LF { printf("p-1: %s\n",$1); }
			| paragraph text LF { printf("p-2: %s\n",$2); }
			| text { printf("p-3: %s\n",$1); }
			| paragraph text { printf("p-4: %s\n",$2); }
			;

heading: 	H1 text LF { printf("h1: %s\n", $2); }
			| H2 text LF { printf("h2: %s\n",$2); }
			| H3 text LF { printf("h3: %s\n", $2); }
			| H4 text LF { printf("h4: %s\n", $2); }
			| H5 text LF { printf("h5: %s\n", $2); }
			| H6 text LF { printf("h6: %s\n", $2); }
			;

text: 		TEXT { printf("text: %s\n", $$); } 
			;


%%
main() {
	yyparse();
}

void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
}
