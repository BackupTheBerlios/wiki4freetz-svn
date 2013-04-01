/* 
 * Scanner for Wikipedia language.  Built with flex.  
 * reference: http://www.mediawiki.org/wiki/Markup_spec/flex
 * 
 * Generate scanner: 
 * flex -o mediawiki.c mediawiki.l
 * 
 * rework: the, march 2013
 */

%{
#include "mediawiki.tab.h"  // to get the token types that we return
%}


VALIDURLCHARS	[a-z0-9\%\/\?\:\@\=\&\$\_\-\+\!\*\'\(\)\,\.]
GENERICLINK		[a-z]+:\/\/{VALIDURLCHARS}+

%%

%{
/* State variable positions (int state[10]):
0 = pre
1 = h1
2 = h2
3 = h3
4 = h4
5 = h5
6 = h6
7 = emphasis
8 = strong emphasis
9 = very strong emphasis */
int state[10];

/* Temporary variables. */
int i;

/* Set all state variables to 0. */
for (i=0; i<10; i++) { state[i] = 0; }

%}


\r												{ return CR; }
\r\n\r											{ return CR_DOUBLE; }
\n\n											{ return LF_DOUBLE; }
\n												{ return LF; }
"<math>"										{ return MATH; }
"<\/math>"										{ return MATH_END; }
"<nowiki>"										{ return NOWIKI; }
"<\/nowiki>"			 						{ return NOWIKI_END; }
[a-z]+:\/\/{VALIDURLCHARS}+						{ return GENERICLINK; }
\133{GENERICLINK}\ [^\133]*\135					{ return TITLEDLINK; }
\133{2}[^\135]+\135{2}							{ return WIKILINK; }
\{\{CURRENTDAY\}\}								{ return CURRENTDAY; }
\{\{CURRENTMONTH\}\}							{ return CURRENTMONTH; }
\{\{CURRENTTIME\}\}								{ return CURRENTTIME; }
\{\{CURRENTYEAR\}\}								{ return CURRENTYEAR; }
\n[\:\#\;\*]									{ return LIST; }
^\040											{ return PRE; }
\n[^\040]										{ return PRE_END; }
^----											{ return HR; }
={1}											{ return H1; }
={2}											{ return H2; }
={3}											{ return H3; }
={4}											{ return H4; }
={5}											{ return H5; }
={6}											{ return H6; }
'{2}											{ return EMPHASIZE; }
'{3}											{ return SEMPHASIZE; }
'{5}											{ return VSEMPHASIZE; }
"<"												{ return LESSERTHAN; }
">"												{ return GREATERTHAN; }
[a-zA-Z0-9?_]+									{ return TEXT; }
[ \t]   										{ /* ignore white space */ }

%%
