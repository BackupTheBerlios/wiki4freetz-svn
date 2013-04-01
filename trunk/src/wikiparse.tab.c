/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "wikiparse.y"


/**
 **
 **  This file is part of the flex/bison-based parser for MediaWiki.
 **          This is the grammar - the input file for bison.
 **  See fb_defines.h on how to make it output debugging information.
 **
 ** This source file is licensed unter the GNU General Public License
 **               http://www.gnu.org/copyleft/gpl.html
 **                 Originally written 2004 by Timwi
 **/

#include <string.h>
#include <stdio.h>
#include "parsetree.h"
#include "fb_defines.h"
int yyerror() { printf ("\n\nSYNTAX ERROR.\n\n"); }

Node articlenode;
int i;



/* Line 268 of yacc.c  */
#line 96 "wikiparse.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     EXTENSION = 258,
     BEGINCOMMENT = 259,
     TEXT = 260,
     ENDCOMMENT = 261,
     OPENLINK = 262,
     OPENDBLSQBR = 263,
     CLOSEDBLSQBR = 264,
     PIPE = 265,
     NEWLINE = 266,
     PRELINE = 267,
     LISTBULLET = 268,
     LISTNUMBERED = 269,
     LISTIDENT = 270,
     HEADING = 271,
     ENDHEADING = 272,
     APO5 = 273,
     APO3 = 274,
     APO2 = 275,
     TABLEBEGIN = 276,
     TABLECELL = 277,
     TABLEHEAD = 278,
     TABLEROW = 279,
     TABLEEND = 280,
     TABLECAPTION = 281,
     ATTRIBUTE = 282,
     EQUALS = 283,
     ATTRAPO = 284,
     ATTRQ = 285,
     OPENPENTUPLECURLY = 286,
     CLOSEPENTUPLECURLY = 287,
     OPENTEMPLATEVAR = 288,
     CLOSETEMPLATEVAR = 289,
     OPENTEMPLATE = 290,
     CLOSETEMPLATE = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 26 "wikiparse.y"

    Node node;
    char* str;
    int num;
    AttributeData ad;



/* Line 293 of yacc.c  */
#line 177 "wikiparse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 189 "wikiparse.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  193
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  330
/* YYNRULES -- Number of states.  */
#define YYNSTATES  374

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    10,    13,    15,    18,
      20,    23,    26,    29,    32,    35,    37,    40,    43,    46,
      49,    52,    56,    59,    61,    63,    66,    70,    72,    74,
      76,    78,    81,    83,    86,    88,    91,    96,   100,   105,
     109,   114,   118,   119,   121,   123,   125,   128,   131,   134,
     136,   140,   145,   150,   156,   160,   165,   170,   176,   179,
     183,   187,   192,   195,   199,   203,   208,   211,   215,   216,
     218,   222,   228,   233,   236,   240,   246,   251,   255,   258,
     262,   268,   273,   277,   283,   288,   292,   295,   299,   302,
     306,   309,   314,   318,   324,   329,   333,   336,   341,   345,
     349,   354,   358,   361,   363,   366,   370,   373,   378,   382,
     384,   388,   391,   394,   396,   398,   400,   403,   408,   411,
     416,   420,   423,   425,   430,   433,   438,   442,   445,   447,
     449,   452,   457,   461,   464,   468,   471,   473,   475,   479,
     485,   491,   496,   499,   501,   504,   506,   509,   511,   514,
     516,   519,   521,   524,   526,   529,   531,   534,   536,   539,
     541,   543,   545,   547,   549,   551,   553,   555,   557,   559,
     561,   563,   565,   567,   569,   571,   573,   575,   577,   579,
     581,   583,   585,   587,   589,   591,   593,   595,   597,   599,
     601,   603,   605,   607,   609,   611,   613,   615,   617,   619,
     621,   623,   625,   627,   629,   631,   633,   635,   637,   639,
     641,   643,   645,   647,   649,   651,   653,   655,   657,   659,
     661,   663,   665,   667,   669,   671,   673,   675,   677,   679,
     681,   683,   685,   687,   689,   691,   693,   695,   697,   699,
     701,   703,   705,   707,   709,   711,   713,   715,   717,   719,
     721,   723,   725,   727,   729,   731,   733,   735,   737,   739,
     741,   743,   745,   747,   749,   751,   753,   755,   757,   759,
     761,   763,   765,   767,   769,   771,   773,   775,   777,   779,
     781,   783,   785,   787,   789,   791,   793,   795,   797,   799,
     801,   803,   805,   807,   809,   811,   815,   821,   827,   830,
     835,   840,   844,   848,   851,   854,   855,   857,   859,   862,
     863,   865,   867,   870,   873,   877,   879,   882,   885,   889,
     892,   896,   901,   905,   907,   910,   912,   915,   919,   922,
     926
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    -1,    87,    -1,    39,    -1,    41,    -1,
      39,    41,    -1,    42,    -1,    40,    42,    -1,    44,    -1,
      43,    86,    -1,    46,    86,    -1,    90,    86,    -1,    61,
      86,    -1,    92,    86,    -1,    44,    -1,    43,    86,    -1,
      46,    86,    -1,    91,    86,    -1,    61,    86,    -1,    92,
      86,    -1,    16,    70,    17,    -1,    16,    70,    -1,    16,
      -1,    45,    -1,    44,    45,    -1,    12,    57,    88,    -1,
      47,    -1,    48,    -1,    49,    -1,    50,    -1,    47,    50,
      -1,    51,    -1,    48,    51,    -1,    52,    -1,    49,    52,
      -1,    13,    53,    57,    11,    -1,    13,    53,    57,    -1,
      14,    53,    57,    11,    -1,    14,    53,    57,    -1,    15,
      53,    57,    11,    -1,    15,    53,    57,    -1,    -1,    13,
      -1,    14,    -1,    15,    -1,    53,    13,    -1,    53,    14,
      -1,    53,    15,    -1,     9,    -1,     8,    75,    54,    -1,
       8,    75,    10,    54,    -1,     8,    75,    56,    54,    -1,
       8,    75,    56,    10,    54,    -1,     7,    75,    54,    -1,
       7,    75,    10,    54,    -1,     7,    75,    56,    54,    -1,
       7,    75,    56,    10,    54,    -1,     8,    75,    -1,     8,
      75,    10,    -1,     8,    75,    56,    -1,     8,    75,    56,
      10,    -1,     7,    75,    -1,     7,    75,    10,    -1,     7,
      75,    56,    -1,     7,    75,    56,    10,    -1,    10,    75,
      -1,    56,    10,    75,    -1,    -1,    70,    -1,    20,    71,
      20,    -1,    20,    71,    19,    73,    18,    -1,    20,    71,
      19,    73,    -1,    20,    71,    -1,    19,    72,    19,    -1,
      19,    72,    20,    73,    18,    -1,    19,    72,    20,    73,
      -1,    19,    72,    20,    -1,    19,    72,    -1,    18,    73,
      18,    -1,    18,    73,    19,    71,    20,    -1,    18,    73,
      19,    71,    -1,    18,    73,    19,    -1,    18,    73,    20,
      72,    19,    -1,    18,    73,    20,    72,    -1,    18,    73,
      20,    -1,    18,    73,    -1,    20,    73,    20,    -1,    20,
      73,    -1,    19,    73,    19,    -1,    19,    73,    -1,    21,
      69,    62,    25,    -1,    21,    69,    62,    -1,    21,    69,
      87,    62,    25,    -1,    21,    69,    87,    62,    -1,    21,
      62,    25,    -1,    21,    62,    -1,    21,    87,    62,    25,
      -1,    21,    87,    62,    -1,    21,    69,    86,    -1,    21,
      69,    70,    86,    -1,    21,    70,    86,    -1,    21,    87,
      -1,    63,    -1,    62,    63,    -1,    24,    69,    64,    -1,
      24,    64,    -1,    24,    69,    87,    64,    -1,    24,    87,
      64,    -1,    64,    -1,    24,    69,    87,    -1,    24,    69,
      -1,    24,    87,    -1,    24,    -1,    67,    -1,    65,    -1,
      64,    65,    -1,    22,    69,    10,    66,    -1,    22,    66,
      -1,    22,    69,    10,    87,    -1,    22,    69,    10,    -1,
      22,    87,    -1,    22,    -1,    23,    69,    10,    66,    -1,
      23,    66,    -1,    23,    69,    10,    87,    -1,    23,    69,
      10,    -1,    23,    87,    -1,    23,    -1,    40,    -1,    87,
      40,    -1,    26,    69,    10,    74,    -1,    26,    69,    74,
      -1,    26,    74,    -1,    26,    69,    10,    -1,    26,    69,
      -1,    26,    -1,    27,    -1,    27,    28,     5,    -1,    27,
      28,    29,    70,    29,    -1,    27,    28,    30,    70,    30,
      -1,    27,    28,    30,    30,    -1,    27,    28,    -1,    68,
      -1,    69,    68,    -1,    77,    -1,    70,    77,    -1,    78,
      -1,    71,    78,    -1,    79,    -1,    72,    79,    -1,    80,
      -1,    73,    80,    -1,    81,    -1,    74,    81,    -1,    82,
      -1,    75,    82,    -1,    83,    -1,    76,    83,    -1,     5,
      -1,     3,    -1,    10,    -1,     9,    -1,    20,    -1,    19,
      -1,    18,    -1,    28,    -1,    21,    -1,    25,    -1,    24,
      -1,    22,    -1,    23,    -1,    26,    -1,    27,    -1,    32,
      -1,    34,    -1,    36,    -1,    92,    -1,    55,    -1,    58,
      -1,    84,    -1,    85,    -1,     5,    -1,     3,    -1,    10,
      -1,     9,    -1,    21,    -1,    25,    -1,    24,    -1,    22,
      -1,    23,    -1,    26,    -1,    27,    -1,    32,    -1,    34,
      -1,    36,    -1,    92,    -1,    55,    -1,    60,    -1,    84,
      -1,    85,    -1,     5,    -1,     3,    -1,    10,    -1,     9,
      -1,    21,    -1,    25,    -1,    24,    -1,    22,    -1,    23,
      -1,    26,    -1,    27,    -1,    32,    -1,    34,    -1,    36,
      -1,    92,    -1,    55,    -1,    59,    -1,    84,    -1,    85,
      -1,     5,    -1,     3,    -1,    10,    -1,     9,    -1,    21,
      -1,    25,    -1,    24,    -1,    22,    -1,    23,    -1,    26,
      -1,    27,    -1,    32,    -1,    34,    -1,    36,    -1,    92,
      -1,    55,    -1,    84,    -1,    85,    -1,     5,    -1,     3,
      -1,    10,    -1,     9,    -1,    20,    -1,    19,    -1,    18,
      -1,    28,    -1,    32,    -1,    34,    -1,    36,    -1,    92,
      -1,    55,    -1,    58,    -1,    84,    -1,    85,    -1,     5,
      -1,     3,    -1,    20,    -1,    19,    -1,    18,    -1,    28,
      -1,    21,    -1,    25,    -1,    24,    -1,    22,    -1,    23,
      -1,    26,    -1,    27,    -1,    32,    -1,    34,    -1,    36,
      -1,    92,    -1,    55,    -1,    58,    -1,    84,    -1,    85,
      -1,     5,    -1,     3,    -1,    10,    -1,     9,    -1,    20,
      -1,    19,    -1,    18,    -1,    28,    -1,    21,    -1,    25,
      -1,    24,    -1,    22,    -1,    23,    -1,    26,    -1,    27,
      -1,    92,    -1,    55,    -1,    58,    -1,    84,    -1,    85,
      -1,    35,    76,    36,    -1,    31,    76,    34,    76,    36,
      -1,    35,    76,    33,    76,    32,    -1,    35,    76,    -1,
      31,    76,    34,    76,    -1,    35,    76,    33,    76,    -1,
      33,    76,    34,    -1,    31,    76,    32,    -1,    33,    76,
      -1,    31,    76,    -1,    -1,    87,    -1,    11,    -1,    87,
      11,    -1,    -1,    89,    -1,    11,    -1,    89,    11,    -1,
      70,    11,    -1,    90,    70,    11,    -1,    70,    -1,    90,
      70,    -1,    74,    11,    -1,    69,    74,    11,    -1,    69,
      11,    -1,    91,    74,    11,    -1,    91,    69,    74,    11,
      -1,    91,    69,    11,    -1,    74,    -1,    69,    74,    -1,
      69,    -1,    91,    74,    -1,    91,    69,    74,    -1,    91,
      69,    -1,     4,    70,     6,    -1,     4,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    71,    72,    74,    75,    77,    78,    80,
      81,    82,    83,    84,    85,    87,    88,    89,    90,    91,
      92,    94,    96,    98,   101,   102,   104,   107,   108,   109,
     111,   112,   113,   114,   115,   116,   118,   120,   122,   124,
     126,   128,   131,   132,   134,   136,   138,   139,   140,   150,
     155,   157,   159,   161,   163,   165,   167,   169,   173,   175,
     177,   179,   181,   183,   185,   187,   191,   192,   194,   195,
     197,   199,   202,   205,   207,   209,   215,   218,   221,   223,
     226,   229,   232,   235,   238,   241,   244,   248,   250,   253,
     255,   258,   260,   262,   264,   266,   268,   270,   272,   275,
     279,   283,   286,   290,   291,   293,   295,   297,   299,   302,
     305,   307,   309,   311,   313,   316,   317,   319,   321,   323,
     325,   327,   329,   331,   333,   335,   337,   339,   341,   344,
     346,   349,   351,   353,   355,   357,   359,   364,   366,   368,
     370,   372,   374,   377,   378,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   542,   544,   547,   551,   553,
     556,   560,   562,   566,   568,   571,   572,   573,   574,   576,
     577,   578,   579,   581,   583,   586,   588,   595,   597,   599,
     601,   603,   605,   608,   610,   612,   614,   616,   618,   621,
     623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EXTENSION", "BEGINCOMMENT", "TEXT",
  "ENDCOMMENT", "OPENLINK", "OPENDBLSQBR", "CLOSEDBLSQBR", "PIPE",
  "NEWLINE", "PRELINE", "LISTBULLET", "LISTNUMBERED", "LISTIDENT",
  "HEADING", "ENDHEADING", "APO5", "APO3", "APO2", "TABLEBEGIN",
  "TABLECELL", "TABLEHEAD", "TABLEROW", "TABLEEND", "TABLECAPTION",
  "ATTRIBUTE", "EQUALS", "ATTRAPO", "ATTRQ", "OPENPENTUPLECURLY",
  "CLOSEPENTUPLECURLY", "OPENTEMPLATEVAR", "CLOSETEMPLATEVAR",
  "OPENTEMPLATE", "CLOSETEMPLATE", "$accept", "article", "blocks",
  "blocksintbl", "block", "blockintbl", "heading", "preblock", "preline",
  "listblock", "bulletlistblock", "numberlistblock", "identlistblock",
  "bulletlistline", "numberlistline", "identlistline", "listseries",
  "linktrail", "linketc", "pipeseries", "textorempty", "italicsorbold",
  "italicsnobold", "boldnoitalics", "table", "tablerows", "tablerow",
  "tablecells", "tablecell", "tablecellcontents", "tablecaption",
  "attribute", "attributes", "text", "textnoital", "textnobold",
  "textnoboit", "textintbl", "textinlink", "textintmpl", "textelement",
  "textelementnoital", "textelementnobold", "textelementnoboit",
  "textelementintbl", "textelementinlink", "textelementintmpl", "template",
  "templatevar", "zeroormorenewlines", "oneormorenewlines",
  "zeroormorenewlinessave", "oneormorenewlinessave", "paragraph",
  "paragraphintbl", "comment", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    39,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    42,    42,    42,    42,    42,
      42,    43,    43,    43,    44,    44,    45,    46,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     2,     1,     2,     1,
       2,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     3,     2,     1,     1,     2,     3,     1,     1,     1,
       1,     2,     1,     2,     1,     2,     4,     3,     4,     3,
       4,     3,     0,     1,     1,     1,     2,     2,     2,     1,
       3,     4,     4,     5,     3,     4,     4,     5,     2,     3,
       3,     4,     2,     3,     3,     4,     2,     3,     0,     1,
       3,     5,     4,     2,     3,     5,     4,     3,     2,     3,
       5,     4,     3,     5,     4,     3,     2,     3,     2,     3,
       2,     4,     3,     5,     4,     3,     2,     4,     3,     3,
       4,     3,     2,     1,     2,     3,     2,     4,     3,     1,
       3,     2,     2,     1,     1,     1,     2,     4,     2,     4,
       3,     2,     1,     4,     2,     4,     3,     2,     1,     1,
       2,     4,     3,     2,     3,     2,     1,     1,     3,     5,
       5,     4,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     5,     2,     4,
       4,     3,     3,     2,     2,     0,     1,     1,     2,     0,
       1,     1,     2,     2,     3,     1,     2,     2,     3,     2,
       3,     4,     3,     1,     2,     1,     2,     3,     2,     3,
       2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,   160,     0,   159,     0,     0,   162,   161,   307,    68,
      42,    42,    42,    23,   165,   164,   163,   167,   170,   171,
     169,   168,   172,   173,   166,     0,   174,     0,   175,     0,
     176,     0,     4,     5,   305,     9,    24,   305,    27,    28,
      29,    30,    32,    34,   178,   179,   305,   315,   145,   180,
     181,     3,   305,   177,   330,   167,     0,   177,   255,   254,
     258,   257,   256,   260,   263,   264,   262,   261,   265,   266,
     259,   267,   268,   269,   271,   272,    62,   155,   273,   274,
     270,    58,   309,    69,    43,    44,    45,    68,    68,    68,
      22,   221,   220,   223,   222,   224,   227,   228,   226,   225,
     229,   230,   231,   232,   233,   235,    86,   151,   236,   237,
     234,   202,   201,   204,   203,     0,   205,   208,   209,   207,
     206,   210,   211,   212,   213,   214,   216,   217,    78,   149,
     218,   219,   215,   183,   182,   185,   184,     0,   186,   189,
     190,   188,   187,   191,   192,   193,   194,   195,   197,   198,
      73,   147,   199,   200,   196,   122,   128,   113,   136,   137,
      96,   103,   109,   115,   114,   143,   305,   305,   102,   276,
     275,   278,   277,   281,   280,   279,   283,   286,   287,   285,
     284,   288,   289,   282,   291,   292,   304,   157,   293,   294,
     290,   303,   298,     1,     6,    10,   306,    25,    11,    31,
      33,    35,    13,   313,   146,   308,   316,    12,    14,   329,
      49,    63,    54,    64,   156,    59,    50,    60,   311,    26,
     310,    46,    47,    48,    37,    39,    41,    21,    79,    82,
      85,   152,    88,    74,    77,   150,    90,     0,    70,   148,
     239,   238,   241,   240,   244,   243,   242,     0,   137,   245,
     246,   247,   248,   129,     7,   305,    15,   305,   250,   251,
     305,   118,   325,   323,   153,   252,   253,   121,   305,   249,
     124,   325,   127,   122,   128,   106,   111,   112,   135,   133,
     249,   142,   113,    95,   136,   104,   116,    92,   144,   305,
      99,   306,   101,    98,   302,     0,   158,   301,     0,   295,
     314,    55,    66,    65,    56,    51,    61,    52,   312,    36,
      38,    40,    81,    84,    87,    76,    89,    72,     8,   325,
      16,    17,    19,   120,   319,   324,   317,   154,   130,   328,
     326,    18,    20,   126,   105,   110,   108,   134,   132,   138,
       0,     0,    91,   100,    94,    97,   299,   300,    57,    67,
      53,    80,    83,    75,    71,   117,   119,   318,   322,   327,
     320,   123,   125,   107,   131,     0,   141,     0,    93,   296,
     297,   321,   139,   140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    32,   253,    33,   254,   255,   256,    36,   257,
      38,    39,    40,    41,    42,    43,    87,   212,   258,   213,
      82,   259,   127,   149,   260,   160,   161,   162,   163,   261,
     164,   165,   319,    83,   150,   128,   106,   263,   302,   186,
      48,   151,   129,   107,   264,    77,   187,   265,   266,   195,
     196,   219,   220,    52,   268,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -228
static const yytype_int16 yypact[] =
{
    1254,  -228,  1356,  -228,  1900,  1900,  -228,  -228,  -228,  1764,
      80,    80,    80,  1764,  2274,  2138,  2172,  1390,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,   449,  -228,   449,  -228,   449,
    -228,    26,  1288,  -228,    20,    29,  -228,    20,    36,    41,
      51,  -228,  -228,  -228,  -228,  -228,    20,  1424,  -228,  -228,
    -228,    63,  1458,    20,  -228,  -228,  1492,  -228,  -228,  -228,
    2274,  2138,  2172,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  1798,  -228,  -228,  -228,
    -228,  1832,    66,  1764,  -228,  -228,  -228,  1322,  1322,  1322,
    1526,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,   924,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  2274,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  1066,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  2274,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    1934,  -228,  -228,  -228,  -228,  1560,  1560,    48,  2478,    44,
     328,  -228,    57,  -228,  -228,  -228,  1390,  1458,    81,  -228,
    -228,  -228,  -228,  2274,  2138,  2172,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  2716,  -228,  -228,  -228,
    -228,  2782,   848,  -228,  -228,  -228,    63,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  1594,  -228,  -228,  -228,
    -228,  1866,  -228,    89,  -228,  1866,  -228,    92,  -228,  -228,
      74,  -228,  -228,  -228,    98,   103,   105,  -228,  -228,  2172,
    2138,  -228,  2206,  -228,  2274,  -228,  2240,  2274,  -228,  -228,
    -228,  -228,  -228,  -228,  2274,  2138,  2172,  1390,    44,  -228,
    -228,  -228,  -228,   624,  -228,    20,    29,    20,  -228,  -228,
      20,  -228,  2308,  2512,  -228,  -228,  -228,  1628,  2342,    20,
    -228,  2376,  1628,  1560,  1560,    57,    48,    97,  2546,  2682,
    -228,    39,    48,  -228,  2478,  -228,  -228,   334,  -228,  1458,
    -228,    81,  -228,   348,  -228,   449,  -228,  -228,   449,  -228,
    -228,  -228,  1900,  1866,  -228,  -228,  1866,  -228,  -228,  -228,
    -228,  -228,  1968,  2002,  -228,  2036,  -228,  2070,  -228,  2410,
    -228,  -228,  -228,  1560,  -228,  2580,  -228,  -228,   624,  2444,
    2614,  -228,  -228,  1560,    57,    97,    57,  2682,  2682,  -228,
    1764,  1662,  -228,  -228,   378,  -228,  2104,  2749,  -228,  1900,
    -228,  -228,  -228,  -228,  -228,  -228,  1628,  -228,  -228,  2648,
    -228,  -228,  1628,    57,  2682,  1696,  -228,  1730,  -228,  -228,
    -228,  -228,  -228,  -228
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,  -228,  -227,    85,  -218,    50,    54,   -17,    64,
    -228,  -228,  -228,    87,    88,    91,   100,   -75,     0,    53,
      35,   694,  -228,  -228,    65,  -138,  -136,  -121,  -154,   -98,
    -228,   119,    61,    21,   -97,   -91,  -104,   -58,    15,   -26,
       1,  -128,  -118,   -67,  -212,   -69,  -149,   249,   498,   125,
      46,  -228,  -228,  -228,  -228,   892
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      44,   191,    44,   192,    74,    74,   216,   214,   286,    44,
     235,   232,   214,    44,   105,   126,   148,    44,   197,    76,
      81,    47,   239,    56,   285,   184,   193,   184,   287,   184,
     293,     8,    44,   236,    90,   318,   275,   296,   167,   231,
     328,     9,   296,   296,   339,   328,    51,    44,   204,    10,
      34,   327,    44,    47,    35,    11,    44,   204,   270,     8,
     105,   126,   148,   168,    37,    46,    12,   327,   340,   341,
     273,   274,   281,   206,   205,   248,    74,   218,   166,   273,
     274,    74,    34,    44,   204,   308,    35,    44,    44,    44,
      44,   204,   205,    84,    85,    86,    37,    46,   210,   303,
     279,   210,   306,   273,   274,   282,   105,   284,   205,   309,
     318,    88,    89,   327,   310,   105,   311,   194,   327,   273,
     274,   286,   224,   225,   226,   199,   327,   200,   126,   328,
     315,   201,   312,   317,   217,   328,   301,   105,   304,   313,
     305,     0,   307,     0,     0,     0,     0,   327,     0,     0,
     148,   285,   327,   344,     0,   334,   336,   285,     0,     0,
       0,   275,   198,     0,     0,   231,    44,    44,   204,   231,
       0,   202,     0,   105,   126,   148,   270,   207,   208,     0,
     286,     0,   286,     0,   239,     0,   184,   289,     0,     0,
       0,   184,   184,     0,     0,   235,     0,   296,   296,     0,
       0,   267,   272,   277,   325,     0,    44,   204,   285,   286,
     330,    74,   291,   325,   363,    74,   262,   271,   276,   278,
     338,     0,     0,     0,     0,   355,   279,     0,   348,   148,
     126,   350,   105,   214,   105,   361,   105,   105,     0,   197,
       0,     0,     0,     0,   105,   126,   148,    44,   231,    49,
     231,    49,     0,    78,    78,     0,     0,     0,    49,     0,
       0,   325,    49,   108,   130,   152,    49,     0,   167,   346,
       0,   359,   347,     0,   188,     0,   188,     0,   188,   364,
     214,    49,     0,     0,     0,   288,     0,     0,     0,    44,
     204,   290,   292,   168,     0,   184,    49,     0,   184,     0,
       0,    49,    74,    74,     0,    49,    74,     0,   166,   108,
     130,   152,   148,   126,     0,   105,     0,   105,   349,   267,
     272,   349,   335,     0,     0,    78,     0,     0,   277,   329,
      78,     0,    49,     0,   262,   271,    49,    49,    49,    49,
      44,    44,     0,   276,     0,   278,   184,   184,     0,    74,
     273,   274,   282,   283,   284,   108,   273,   274,   282,   342,
     284,   365,   367,     0,   108,    44,   204,    44,   204,   356,
     273,   274,   282,   345,   284,     0,     0,   130,     0,   362,
     320,   288,   321,     0,     0,   322,   108,     0,     0,     0,
     288,     0,     0,   331,   332,   288,     0,   288,     0,   152,
     273,   274,   282,   368,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   343,    49,    49,     0,     0,     0,
       0,     0,   108,   130,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,     0,   288,     0,
     188,   188,     0,     0,     0,     0,     0,     0,   288,     0,
       0,     0,   169,     2,   170,    49,     4,     5,   171,   172,
      78,     0,     0,     0,    78,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   152,   130,
      25,   108,    27,   108,    29,   108,   108,     0,     0,     0,
       0,     0,     0,   108,   130,   152,    49,     0,    50,     0,
      50,     0,    79,    79,     0,     0,     0,    50,     0,     0,
       0,    50,   109,   131,   153,    50,     0,     0,     0,     0,
       0,     0,     0,   189,     0,   189,     0,   189,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,   188,    50,     0,   188,     0,     0,
      50,    78,    78,     0,    50,    78,     0,     0,   109,   131,
     153,   152,   130,     0,   108,     0,   108,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,    79,
       0,    50,     0,     0,     0,    50,    50,    50,    50,    49,
      49,     0,     0,     0,     0,   188,   188,     0,    78,     0,
       0,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,   109,    49,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   240,     2,   241,
       0,     4,     5,   242,   243,   109,     9,    10,    11,    12,
      13,     0,   244,   245,   246,   247,     0,     0,   153,     0,
       0,   248,   249,     0,     0,    25,   250,    27,   251,    29,
     252,     0,     0,     0,    50,    50,     0,     0,     0,     0,
       0,   109,   131,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,     0,     0,   189,
     189,     0,     0,     0,    45,     0,    45,     0,    75,    75,
       0,     0,     0,    45,    50,     0,     0,    45,     0,    79,
       0,    45,     0,    79,     0,     0,     0,     0,     0,   185,
       0,   185,     0,   185,     0,     0,    45,   153,   131,     0,
     109,     0,   109,     0,   109,   109,     0,     0,     0,     0,
       0,    45,   109,   131,   153,    50,    45,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,    75,     0,    45,     0,     0,
       0,    45,    45,    45,    45,     0,     0,    50,     0,     0,
       0,     0,     0,   189,     0,     0,   189,     0,     0,     0,
      79,    79,     0,     0,    79,     0,     0,     0,     0,     0,
     153,   131,     0,   109,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    50,
       0,     0,     0,     0,   189,   189,     0,    79,     0,     0,
       0,   169,     2,   170,     0,     4,     5,   171,   172,     0,
      45,    45,     0,    50,     0,    50,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,     0,     0,    25,
     185,   298,     0,    29,   299,   185,   185,     0,     0,     0,
       0,     0,    53,     0,     0,     0,    80,    80,     0,     0,
      45,     0,     0,     0,     0,    75,   110,   132,   154,    75,
       0,     0,     0,     0,     0,     0,     0,   190,     0,   190,
       0,   190,     0,     0,    53,     0,     0,    91,     2,    92,
       0,     4,     5,    93,    94,     0,     0,     0,     0,     0,
       0,    45,   228,   229,   230,    95,    96,    97,    98,    99,
     100,   101,   110,   132,   154,    25,   102,    27,   103,    29,
     104,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,   185,
       0,     0,   185,     0,     0,     0,    75,    75,   110,     0,
      75,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,    45,    45,     0,     0,     0,     0,
     185,   185,   154,    75,     0,     0,     0,   269,   269,     0,
     280,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,    45,     0,     0,     0,   110,   132,   154,     0,   111,
       2,   112,     0,     4,     5,   113,   114,     0,   190,     0,
       0,     0,     0,   190,   190,   233,   234,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,    25,   123,    27,
     124,    29,   125,    80,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   132,     0,   110,     0,   110,     0,   110,   110,
       0,     0,     0,     0,     0,     0,   110,   132,   154,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,     0,     0,   280,   280,     0,     0,     0,   269,
     280,     0,     0,   280,   269,   269,   269,     0,     0,     0,
     280,   280,     0,     0,     0,     0,   280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,     0,     0,
     190,     0,     0,     0,    80,    80,     0,     0,    80,     0,
       0,     0,     0,     0,   154,   132,     0,   110,     0,   110,
       0,   280,     0,     0,     0,   269,     0,   280,     0,     0,
     269,   280,   280,     0,     0,   269,     0,     0,     0,   280,
     280,     0,     0,     0,     0,     0,     0,     0,   190,   190,
       0,    80,     0,     0,     0,     0,     0,     0,   269,     0,
       0,   280,     0,     0,   269,     0,   280,     1,     2,     3,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,    25,    26,    27,    28,    29,
      30,     1,     2,     3,     0,     4,     5,     6,     7,     0,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,     0,    25,
      26,    27,    28,    29,    30,     1,     2,     3,     0,     4,
       5,     6,     7,     0,     0,   221,   222,   223,     0,     0,
      14,    15,    16,    55,    18,    19,    20,    21,    22,    23,
      24,     0,     0,    25,    26,    27,    28,    29,    30,     1,
       2,     3,    54,     4,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    55,    18,    19,
      20,    21,    22,    23,    24,     0,     0,    25,    26,    27,
      28,    29,    30,     1,     2,     3,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     0,    14,    15,
      16,    55,   155,   156,   157,    21,   158,   159,    24,     0,
       0,    25,    26,    27,    28,    29,    30,     1,     2,     3,
       0,     4,     5,     6,     7,   203,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    55,    18,    19,    20,    21,
      22,    23,    24,     0,     0,    25,    26,    27,    28,    29,
      30,     1,     2,     3,     0,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    55,
      18,    19,    20,    21,    22,    23,    24,     0,     0,    25,
      26,    27,    28,    29,    30,     1,     2,     3,   209,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,    55,    18,    19,    20,    21,    22,    23,
      24,     0,     0,    25,    26,    27,    28,    29,    30,     1,
       2,     3,     0,     4,     5,     6,     7,     0,     0,     0,
       0,     0,     0,   227,    14,    15,    16,    55,    18,    19,
      20,    21,    22,    23,    24,     0,     0,    25,    26,    27,
      28,    29,    30,   240,     2,   241,     0,     4,     5,   242,
     243,     8,     9,    10,    11,    12,    13,     0,   244,   245,
     246,   247,     0,     0,     0,     0,     0,   248,   249,     0,
       0,    25,   250,    27,   251,    29,   252,     1,     2,     3,
       0,     4,     5,     6,     7,   300,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    55,    18,    19,    20,    21,
      22,    23,    24,     0,     0,    25,    26,    27,    28,    29,
      30,   240,     2,   241,     0,     4,     5,   242,   243,   205,
       9,    10,    11,    12,    13,     0,   244,   245,   246,   247,
       0,     0,     0,     0,     0,   248,   249,     0,     0,    25,
     250,    27,   251,    29,   252,     1,     2,     3,     0,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,    55,    18,    19,    20,    21,    22,    23,
      24,     0,   366,    25,    26,    27,    28,    29,    30,     1,
       2,     3,     0,     4,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    55,    18,    19,
      20,    21,    22,    23,    24,   372,     0,    25,    26,    27,
      28,    29,    30,     1,     2,     3,     0,     4,     5,     6,
       7,     0,     0,     0,     0,     0,     0,     0,    14,    15,
      16,    55,    18,    19,    20,    21,    22,    23,    24,     0,
     373,    25,    26,    27,    28,    29,    30,     1,     2,     3,
       0,     4,     5,     6,     7,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    55,    18,    19,    20,    21,
      22,    23,    24,     0,     0,    25,    26,    27,    28,    29,
      30,    58,     2,    59,     0,     4,     5,   210,   211,     0,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,    25,
      71,    27,    72,    29,    73,    58,     2,    59,     0,     4,
       5,   210,   215,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,    25,    71,    27,    72,    29,    73,    58,
       2,    59,     0,     4,     5,   210,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,    25,    71,    27,
      72,    29,    73,    58,     2,    59,     0,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    25,    71,    27,    72,    29,    73,   133,     2,   134,
       0,     4,     5,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   138,   139,   140,   141,   142,
     143,   144,     0,     0,     0,    25,   145,    27,   146,    29,
     147,   133,     2,   134,     0,     4,     5,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   351,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,    25,
     145,    27,   146,    29,   147,   111,     2,   112,     0,     4,
       5,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,   352,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,    25,   123,    27,   124,    29,   125,    91,
       2,    92,     0,     4,     5,    93,    94,     0,     0,     0,
       0,     0,     0,     0,   353,     0,   314,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,    25,   102,    27,
     103,    29,   104,    91,     2,    92,     0,     4,     5,    93,
      94,     0,     0,     0,     0,     0,     0,     0,   354,   316,
       0,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,    25,   102,    27,   103,    29,   104,   169,     2,   170,
       0,     4,     5,   171,   172,     0,     0,     0,     0,     0,
       0,     0,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,     0,     0,    25,     0,    27,     0,    29,
     369,   111,     2,   112,     0,     4,     5,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,    25,
     123,    27,   124,    29,   125,   133,     2,   134,     0,     4,
       5,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
       0,     0,     0,    25,   145,    27,   146,    29,   147,    91,
       2,    92,     0,     4,     5,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,    95,    96,    97,
      98,    99,   100,   101,     0,     0,     0,    25,   102,    27,
     103,    29,   104,    91,     2,    92,     0,     4,     5,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,   316,
       0,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,    25,   102,    27,   103,    29,   104,    91,     2,    92,
       0,     4,     5,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,     0,     0,     0,    25,   102,    27,   103,    29,
     104,   240,     2,   241,     0,     4,     5,   242,   323,   324,
       0,     0,     0,     0,     0,     0,   244,   245,   246,     0,
       0,     0,     0,     0,     0,   248,   249,     0,     0,    25,
     250,    27,   251,    29,   252,   240,     2,   241,     0,     4,
       5,   242,   243,     8,     0,     0,     0,     0,     0,     0,
     244,   245,   246,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,    25,   250,    27,   251,    29,   252,   240,
       2,   241,     0,     4,     5,   242,   333,   324,     0,     0,
       0,     0,     0,     0,   244,   245,   246,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,    25,   250,    27,
     251,    29,   252,   240,     2,   241,     0,     4,     5,   242,
     243,   324,     0,     0,     0,     0,     0,     0,   244,   245,
     246,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,    25,   250,    27,   251,    29,   252,   240,     2,   241,
       0,     4,     5,   242,   243,   358,     0,     0,     0,     0,
       0,     0,   244,   245,   246,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,    25,   250,    27,   251,    29,
     252,   240,     2,   241,     0,     4,     5,   242,   243,     0,
       0,     0,     0,     0,     0,     0,   244,   245,   246,     0,
       0,     0,     0,     0,     0,   248,   249,     0,     0,    25,
     250,    27,   251,    29,   252,   240,     2,   241,     0,     4,
       5,   242,   243,   326,     0,     0,     0,     0,     0,     0,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,    25,   250,    27,   251,    29,   252,   240,
       2,   241,     0,     4,     5,   242,   337,     0,     0,     0,
       0,     0,     0,     0,   244,   245,   246,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,    25,   250,    27,
     251,    29,   252,   240,     2,   241,     0,     4,     5,   242,
     243,   357,     0,     0,     0,     0,     0,     0,   244,   245,
     246,     0,     0,     0,     0,     0,     0,     0,   249,     0,
       0,    25,   250,    27,   251,    29,   252,   240,     2,   241,
       0,     4,     5,   242,   243,   360,     0,     0,     0,     0,
       0,     0,   244,   245,   246,     0,     0,     0,     0,     0,
       0,     0,   249,     0,     0,    25,   250,    27,   251,    29,
     252,   240,     2,   241,     0,     4,     5,   242,   243,   371,
       0,     0,     0,     0,     0,     0,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,   249,     0,     0,    25,
     250,    27,   251,    29,   252,   240,     2,   241,     0,     4,
       5,   242,   243,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,    25,   250,    27,   251,    29,   252,   169,
       2,   170,     0,     4,     5,   171,   172,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     0,     0,    25,   294,    27,
     295,    29,   169,     2,   170,     0,     4,     5,   171,   172,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,     0,     0,
      25,   370,    27,   297,    29,   169,     2,   170,     0,     4,
       5,   171,   172,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,     0,     0,    25,     0,    27,   297,    29
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-228))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    27,     2,    29,     4,     5,    81,    76,   162,     9,
     128,   115,    81,    13,    14,    15,    16,    17,    35,     4,
       5,     0,   150,     2,   160,    25,     0,    27,   166,    29,
     168,    11,    32,   137,    13,   253,   157,   186,    17,   106,
     267,    12,   191,   192,     5,   272,     0,    47,    47,    13,
       0,   263,    52,    32,     0,    14,    56,    56,   156,    11,
      60,    61,    62,    17,     0,     0,    15,   279,    29,    30,
      22,    23,    28,    52,    11,    27,    76,    11,    17,    22,
      23,    81,    32,    83,    83,    11,    32,    87,    88,    89,
      90,    90,    11,    13,    14,    15,    32,    32,     9,    10,
     158,     9,    10,    22,    23,    24,   106,    26,    11,    11,
     328,    11,    12,   325,    11,   115,    11,    32,   330,    22,
      23,   275,    87,    88,    89,    38,   338,    39,   128,   356,
     234,    40,   229,   237,    81,   362,   211,   137,   213,   230,
     215,    -1,   217,    -1,    -1,    -1,    -1,   359,    -1,    -1,
     150,   287,   364,   291,    -1,   276,   277,   293,    -1,    -1,
      -1,   282,    37,    -1,    -1,   232,   166,   167,   167,   236,
      -1,    46,    -1,   173,   174,   175,   274,    52,    53,    -1,
     334,    -1,   336,    -1,   312,    -1,   186,   166,    -1,    -1,
      -1,   191,   192,    -1,    -1,   313,    -1,   346,   347,    -1,
      -1,   155,   156,   157,   262,    -1,   206,   206,   344,   363,
     268,   211,   166,   271,   335,   215,   155,   156,   157,   158,
     278,    -1,    -1,    -1,    -1,   323,   284,    -1,   303,   229,
     230,   306,   232,   302,   234,   333,   236,   237,    -1,   256,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,   315,     0,
     317,     2,    -1,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,   319,    13,    14,    15,    16,    17,    -1,   247,   295,
      -1,   329,   298,    -1,    25,    -1,    27,    -1,    29,   337,
     349,    32,    -1,    -1,    -1,   166,    -1,    -1,    -1,   289,
     289,   166,   167,   247,    -1,   295,    47,    -1,   298,    -1,
      -1,    52,   302,   303,    -1,    56,   306,    -1,   247,    60,
      61,    62,   312,   313,    -1,   315,    -1,   317,   303,   273,
     274,   306,   276,    -1,    -1,    76,    -1,    -1,   282,   268,
      81,    -1,    83,    -1,   273,   274,    87,    88,    89,    90,
     340,   341,    -1,   282,    -1,   284,   346,   347,    -1,   349,
      22,    23,    24,    25,    26,   106,    22,    23,    24,    25,
      26,   340,   341,    -1,   115,   365,   365,   367,   367,   323,
      22,    23,    24,    25,    26,    -1,    -1,   128,    -1,   333,
     255,   262,   257,    -1,    -1,   260,   137,    -1,    -1,    -1,
     271,    -1,    -1,   268,   269,   276,    -1,   278,    -1,   150,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   289,   166,   167,    -1,    -1,    -1,
      -1,    -1,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,   319,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   329,    -1,
      -1,    -1,     3,     4,     5,   206,     7,     8,     9,    10,
     211,    -1,    -1,    -1,   215,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   229,   230,
      31,   232,    33,   234,    35,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,   244,   245,   246,   247,    -1,     0,    -1,
       2,    -1,     4,     5,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    -1,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,    -1,
      -1,    -1,    -1,    -1,   295,    47,    -1,   298,    -1,    -1,
      52,   302,   303,    -1,    56,   306,    -1,    -1,    60,    61,
      62,   312,   313,    -1,   315,    -1,   317,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      -1,    83,    -1,    -1,    -1,    87,    88,    89,    90,   340,
     341,    -1,    -1,    -1,    -1,   346,   347,    -1,   349,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   365,    -1,   367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,     3,     4,     5,
      -1,     7,     8,     9,    10,   137,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    -1,    -1,   150,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,   166,   167,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,     0,    -1,     2,    -1,     4,     5,
      -1,    -1,    -1,     9,   206,    -1,    -1,    13,    -1,   211,
      -1,    17,    -1,   215,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    -1,    29,    -1,    -1,    32,   229,   230,    -1,
     232,    -1,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,    47,   244,   245,   246,   247,    52,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    -1,    83,    -1,    -1,
      -1,    87,    88,    89,    90,    -1,    -1,   289,    -1,    -1,
      -1,    -1,    -1,   295,    -1,    -1,   298,    -1,    -1,    -1,
     302,   303,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,
     312,   313,    -1,   315,    -1,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,   341,
      -1,    -1,    -1,    -1,   346,   347,    -1,   349,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
     166,   167,    -1,   365,    -1,   367,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
     186,    33,    -1,    35,    36,   191,   192,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,     4,     5,    -1,    -1,
     206,    -1,    -1,    -1,    -1,   211,    14,    15,    16,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,
      -1,    29,    -1,    -1,    32,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,   247,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    60,    61,    62,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,   295,
      -1,    -1,   298,    -1,    -1,    -1,   302,   303,   106,    -1,
     306,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,   340,   341,    -1,    -1,    -1,    -1,
     346,   347,   150,   349,    -1,    -1,    -1,   155,   156,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
      -1,   367,    -1,    -1,    -1,   173,   174,   175,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,   186,    -1,
      -1,    -1,    -1,   191,   192,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,   211,    -1,    -1,    -1,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,    -1,   232,    -1,   234,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,    -1,
      -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,   263,    -1,    -1,    -1,   267,
     268,    -1,    -1,   271,   272,   273,   274,    -1,    -1,    -1,
     278,   279,    -1,    -1,    -1,    -1,   284,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,
     298,    -1,    -1,    -1,   302,   303,    -1,    -1,   306,    -1,
      -1,    -1,    -1,    -1,   312,   313,    -1,   315,    -1,   317,
      -1,   319,    -1,    -1,    -1,   323,    -1,   325,    -1,    -1,
     328,   329,   330,    -1,    -1,   333,    -1,    -1,    -1,   337,
     338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,   347,
      -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,
      -1,   359,    -1,    -1,   362,    -1,   364,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,    36,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    33,    34,    35,    36,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    31,    32,    33,    34,    35,    36,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    32,    33,
      34,    35,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    33,    34,    35,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    31,    32,    33,    34,    35,
      36,    38,    39,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    55,    58,    61,    70,    77,    84,
      85,    87,    90,    92,     6,    21,    70,    92,     3,     5,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    32,    34,    36,    55,    58,    75,    82,    84,    85,
      92,    75,    57,    70,    13,    14,    15,    53,    53,    53,
      70,     3,     5,     9,    10,    21,    22,    23,    24,    25,
      26,    27,    32,    34,    36,    55,    73,    80,    84,    85,
      92,     3,     5,     9,    10,    20,    21,    22,    23,    24,
      25,    26,    27,    32,    34,    36,    55,    59,    72,    79,
      84,    85,    92,     3,     5,     9,    10,    19,    21,    22,
      23,    24,    25,    26,    27,    32,    34,    36,    55,    60,
      71,    78,    84,    85,    92,    22,    23,    24,    26,    27,
      62,    63,    64,    65,    67,    68,    69,    70,    87,     3,
       5,     9,    10,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    55,    58,    76,    83,    84,    85,
      92,    76,    76,     0,    41,    86,    87,    45,    86,    50,
      51,    52,    86,    11,    77,    11,    70,    86,    86,     6,
       9,    10,    54,    56,    82,    10,    54,    56,    11,    88,
      89,    13,    14,    15,    57,    57,    57,    17,    18,    19,
      20,    80,    73,    19,    20,    79,    73,    19,    20,    78,
       3,     5,     9,    10,    18,    19,    20,    21,    27,    28,
      32,    34,    36,    40,    42,    43,    44,    46,    55,    58,
      61,    66,    69,    74,    81,    84,    85,    87,    91,    92,
      66,    69,    87,    22,    23,    64,    69,    87,    69,    74,
      92,    28,    24,    25,    26,    63,    65,    62,    68,    70,
      86,    87,    86,    62,    32,    34,    83,    34,    33,    36,
      11,    54,    75,    10,    54,    54,    10,    54,    11,    11,
      11,    11,    71,    72,    20,    73,    19,    73,    42,    69,
      86,    86,    86,    10,    11,    74,    11,    81,    40,    69,
      74,    86,    86,    10,    64,    87,    64,    10,    74,     5,
      29,    30,    25,    86,    62,    25,    76,    76,    54,    75,
      54,    20,    19,    18,    18,    66,    87,    11,    11,    74,
      11,    66,    87,    64,    74,    70,    30,    70,    25,    36,
      32,    11,    29,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 70 "wikiparse.y"
    { debugf ("article#1 "); (yyval.node) = articlenode = newNode (Article); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 71 "wikiparse.y"
    { debugf ("article#2 "); (yyval.node) = articlenode = newNode (Article); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 72 "wikiparse.y"
    { debugf ("article#3 "); (yyval.node) = articlenode = nodeAddChild (newNode (Article), (yyvsp[(1) - (1)].node)); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 74 "wikiparse.y"
    { debugf ("blocks#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 75 "wikiparse.y"
    { debugf ("blocks#2 "); (yyval.node) = nodeAddSibling ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 77 "wikiparse.y"
    { debugf ("blocksintbl#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 78 "wikiparse.y"
    { debugf ("blocksintbl#2 "); (yyval.node) = nodeAddSibling ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 80 "wikiparse.y"
    { debugf ("block#1 "); (yyval.node) = processPreBlock ((yyvsp[(1) - (1)].node)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 81 "wikiparse.y"
    { debugf ("block#2 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 82 "wikiparse.y"
    { debugf ("block#3 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 83 "wikiparse.y"
    { debugf ("block#4 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 84 "wikiparse.y"
    { debugf ("block#5 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 85 "wikiparse.y"
    { debugf ("block#6 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 87 "wikiparse.y"
    { debugf ("blockintbl#1 "); (yyval.node) = processPreBlock ((yyvsp[(1) - (1)].node)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 88 "wikiparse.y"
    { debugf ("blockintbl#2 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 89 "wikiparse.y"
    { debugf ("blockintbl#3 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 90 "wikiparse.y"
    { debugf ("blockintbl#4 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 91 "wikiparse.y"
    { debugf ("blockintbl#5 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 92 "wikiparse.y"
    { debugf ("blockintbl#6 "); (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 95 "wikiparse.y"
    { debugf ("heading#1 "); (yyval.node) = nodeAddChild (newNodeI (Heading, (yyvsp[(1) - (3)].num)), (yyvsp[(2) - (3)].node)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 97 "wikiparse.y"
    { debugf ("heading#2 "); (yyval.node) = nodeAddChild (newNode (Paragraph), makeTextBlock (convertHeadingToText ((yyvsp[(1) - (2)].num)), (yyvsp[(2) - (2)].node))); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 99 "wikiparse.y"
    { debugf ("heading#3 "); (yyval.node) = nodeAddChild (newNode (Paragraph), convertHeadingToText ((yyvsp[(1) - (1)].num))); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 101 "wikiparse.y"
    { debugf ("preblock#1 "); (yyval.node) = nodeAddChild (newNode (PreBlock), (yyvsp[(1) - (1)].node)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 102 "wikiparse.y"
    { debugf ("preblock#2 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 105 "wikiparse.y"
    { debugf ("preline#1 "); (yyval.node) = nodeAddChild2 (newNode (PreLine), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 107 "wikiparse.y"
    { debugf ("listblock#1 "); (yyval.node) = processListBlock ((yyvsp[(1) - (1)].node)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 108 "wikiparse.y"
    { debugf ("listblock#2 "); (yyval.node) = processListBlock ((yyvsp[(1) - (1)].node)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 109 "wikiparse.y"
    { debugf ("listblock#3 "); (yyval.node) = processListBlock ((yyvsp[(1) - (1)].node)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 111 "wikiparse.y"
    { debugf ("bulletlistblock#1 "); (yyval.node) = nodeAddChild (newNode (ListBlock), (yyvsp[(1) - (1)].node)); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 112 "wikiparse.y"
    { debugf ("bulletlistblock#2 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 113 "wikiparse.y"
    { debugf ("numberlistblock#1 "); (yyval.node) = nodeAddChild (newNode (ListBlock), (yyvsp[(1) - (1)].node)); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 114 "wikiparse.y"
    { debugf ("numberlistblock#2 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 115 "wikiparse.y"
    { debugf ("identlistblock#1 "); (yyval.node) = nodeAddChild (newNode (ListBlock), (yyvsp[(1) - (1)].node)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 116 "wikiparse.y"
    { debugf ("identlistblock#2 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 119 "wikiparse.y"
    { debugf ("bulletlistline#1 "); (yyval.node) = nodeAddChild (nodePrependChild ((yyvsp[(2) - (4)].node), newNode (ListBullet)), (yyvsp[(3) - (4)].node)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 121 "wikiparse.y"
    { debugf ("bulletlistline#2 "); (yyval.node) = nodeAddChild (nodePrependChild ((yyvsp[(2) - (3)].node), newNode (ListBullet)), (yyvsp[(3) - (3)].node)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 123 "wikiparse.y"
    { debugf ("numberlistline#1 "); (yyval.node) = nodeAddChild (nodePrependChild ((yyvsp[(2) - (4)].node), newNode (ListNumbered)), (yyvsp[(3) - (4)].node)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 125 "wikiparse.y"
    { debugf ("numberlistline#2 "); (yyval.node) = nodeAddChild (nodePrependChild ((yyvsp[(2) - (3)].node), newNode (ListNumbered)), (yyvsp[(3) - (3)].node)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 127 "wikiparse.y"
    { debugf ("identlistline#1 "); (yyval.node) = nodeAddChild (nodePrependChild ((yyvsp[(2) - (4)].node), newNode (ListIdent)), (yyvsp[(3) - (4)].node)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 129 "wikiparse.y"
    { debugf ("identlistline#2 "); (yyval.node) = nodeAddChild (nodePrependChild ((yyvsp[(2) - (3)].node), newNode (ListIdent)), (yyvsp[(3) - (3)].node)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 131 "wikiparse.y"
    { debugf ("listseries#1 "); (yyval.node) = newNode (ListLine); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 133 "wikiparse.y"
    { debugf ("listseries#2 "); (yyval.node) = nodeAddChild (newNode (ListLine), newNode (ListBullet)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 135 "wikiparse.y"
    { debugf ("listseries#3 "); (yyval.node) = nodeAddChild (newNode (ListLine), newNode (ListNumbered)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 137 "wikiparse.y"
    { debugf ("listseries#4 "); (yyval.node) = nodeAddChild (newNode (ListLine), newNode (ListIdent)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 138 "wikiparse.y"
    { debugf ("listseries#5 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), newNode (ListBullet)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 139 "wikiparse.y"
    { debugf ("listseries#6 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), newNode (ListNumbered)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 140 "wikiparse.y"
    { debugf ("listseries#6 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), newNode (ListIdent)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 150 "wikiparse.y"
    {}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 156 "wikiparse.y"
    { debugf ("linketc#1 "); (yyval.node) = nodeAddChild (newNodeI (LinkEtc, 0), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (3)].node))); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 158 "wikiparse.y"
    { debugf ("linketc#2 "); (yyval.node) = nodeAddChild (newNodeI (LinkEtc, 1), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (4)].node))); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 160 "wikiparse.y"
    { debugf ("linketc#3 "); (yyval.node) = nodeAddChild2 (newNodeI (LinkEtc, 0), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (4)].node)), (yyvsp[(3) - (4)].node)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 162 "wikiparse.y"
    { debugf ("linketc#4 "); (yyval.node) = nodeAddChild2 (newNodeI (LinkEtc, 1), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (5)].node)), (yyvsp[(3) - (5)].node)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 164 "wikiparse.y"
    { debugf ("linketc#5 "); (yyval.node) = nodeAddChild (newNodeI (LinkEtc, 2), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (3)].node))); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 166 "wikiparse.y"
    { debugf ("linketc#6 "); (yyval.node) = nodeAddChild (newNodeI (LinkEtc, 3), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (4)].node))); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 168 "wikiparse.y"
    { debugf ("linketc#7 "); (yyval.node) = nodeAddChild2 (newNodeI (LinkEtc, 2), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (4)].node)), (yyvsp[(3) - (4)].node)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 170 "wikiparse.y"
    { debugf ("linketc#8 "); (yyval.node) = nodeAddChild2 (newNodeI (LinkEtc, 3), nodeAddChild (newNode (LinkTarget), (yyvsp[(2) - (5)].node)), (yyvsp[(3) - (5)].node)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 174 "wikiparse.y"
    { debugf ("linketc#9 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "[["), (yyvsp[(2) - (2)].node)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 176 "wikiparse.y"
    { debugf ("linketc#10 "); (yyval.node) = makeTextBlock2 (newNodeS (TextToken, "[["), (yyvsp[(2) - (3)].node), newNodeS (TextToken, "|")); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 178 "wikiparse.y"
    { debugf ("linketc#11 "); (yyval.node) = makeTextBlock2 (newNodeS (TextToken, "[["), (yyvsp[(2) - (3)].node), convertPipeSeriesToText ((yyvsp[(3) - (3)].node))); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 180 "wikiparse.y"
    { debugf ("linketc#12 "); (yyval.node) = makeTextBlock3 (newNodeS (TextToken, "[["), (yyvsp[(2) - (4)].node), convertPipeSeriesToText ((yyvsp[(3) - (4)].node)), newNodeS (TextToken, "|")); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 182 "wikiparse.y"
    { debugf ("linketc#13 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "[[:"), (yyvsp[(2) - (2)].node)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 184 "wikiparse.y"
    { debugf ("linketc#14 "); (yyval.node) = makeTextBlock2 (newNodeS (TextToken, "[[:"), (yyvsp[(2) - (3)].node), newNodeS (TextToken, "|")); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 186 "wikiparse.y"
    { debugf ("linketc#15 "); (yyval.node) = makeTextBlock2 (newNodeS (TextToken, "[[:"), (yyvsp[(2) - (3)].node), convertPipeSeriesToText ((yyvsp[(3) - (3)].node))); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 188 "wikiparse.y"
    { debugf ("linketc#16 "); (yyval.node) = makeTextBlock3 (newNodeS (TextToken, "[[:"), (yyvsp[(2) - (4)].node), convertPipeSeriesToText ((yyvsp[(3) - (4)].node)), newNodeS (TextToken, "|")); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 191 "wikiparse.y"
    { debugf ("pipeseries#1 "); (yyval.node) = nodeAddChild (newNode (LinkOption), (yyvsp[(2) - (2)].node)); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 192 "wikiparse.y"
    { debugf ("pipeseries#2 "); (yyval.node) = nodeAddSibling ((yyvsp[(1) - (3)].node), nodeAddChild (newNode (LinkOption), (yyvsp[(3) - (3)].node))); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 194 "wikiparse.y"
    { debugf ("textorempty#1 "); (yyval.node) = newNodeS (TextToken, ""); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 195 "wikiparse.y"
    { debugf ("textorempty#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 198 "wikiparse.y"
    { debugf ("italicsorbold#1 "); (yyval.node) = nodeAddChild (newNode (Italics), (yyvsp[(2) - (3)].node)); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 200 "wikiparse.y"
    { debugf ("italicsorbold#2 "); (yyval.node) = nodeAddChild (newNode (Italics),
                                makeTextBlock ((yyvsp[(2) - (5)].node), nodeAddChild (newNode (Bold), (yyvsp[(4) - (5)].node)))); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 203 "wikiparse.y"
    { debugf ("italicsorbold#3 "); (yyval.node) =
                        makeTextBlock2 (nodeAddChild (newNode (Italics), (yyvsp[(2) - (4)].node)), newNodeS (TextToken, "'"), (yyvsp[(4) - (4)].node)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 206 "wikiparse.y"
    { debugf ("italicsorbold#4 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "''"), (yyvsp[(2) - (2)].node)); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 208 "wikiparse.y"
    { debugf ("italicsorbold#5 "); (yyval.node) = nodeAddChild (newNode (Bold), (yyvsp[(2) - (3)].node)); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 210 "wikiparse.y"
    { debugf ("italicsorbold#6 "); (yyval.node) = nodeAddChild (newNode (Bold),
                            makeTextBlock ((yyvsp[(2) - (5)].node), nodeAddChild (newNode (Italics), (yyvsp[(4) - (5)].node)))); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 216 "wikiparse.y"
    { debugf ("italicsorbold#7 "); (yyval.node) = processNestedItalics (makeTextBlock2 (newNodeS
                            (TextToken, "'"), nodeAddChild (newNode (Italics), (yyvsp[(2) - (4)].node)), (yyvsp[(4) - (4)].node))); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 219 "wikiparse.y"
    { debugf ("italicsorbold#8 "); (yyval.node) = processNestedItalics (makeTextBlock (newNodeS
                            (TextToken, "'"), nodeAddChild (newNode (Italics), (yyvsp[(2) - (3)].node)))); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 222 "wikiparse.y"
    { debugf ("italicsorbold#9 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "'''"), (yyvsp[(2) - (2)].node)); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 224 "wikiparse.y"
    { debugf ("italicsorbold#10 "); (yyval.node) = nodeAddChild (newNode (Italics),
                            nodeAddChild (newNode (Bold), (yyvsp[(2) - (3)].node))); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 227 "wikiparse.y"
    { debugf ("italicsorbold#11 "); (yyval.node) = nodeAddChild (newNode (Italics),
                            makeTextBlock (nodeAddChild (newNode (Bold), (yyvsp[(2) - (5)].node)), (yyvsp[(4) - (5)].node))); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 230 "wikiparse.y"
    { debugf ("italicsorbold#12 "); (yyval.node) = makeTextBlock2 (newNodeS (TextToken, "''"),
                            nodeAddChild (newNode (Bold), (yyvsp[(2) - (4)].node)), (yyvsp[(4) - (4)].node)); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 233 "wikiparse.y"
    { debugf ("italicsorbold#13 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "''"),
                            nodeAddChild (newNode (Bold), (yyvsp[(2) - (3)].node))); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 236 "wikiparse.y"
    { debugf ("italicsorbold#14 "); (yyval.node) = nodeAddChild (newNode (Bold),
                            makeTextBlock (nodeAddChild (newNode (Italics), (yyvsp[(2) - (5)].node)), (yyvsp[(4) - (5)].node))); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 239 "wikiparse.y"
    { debugf ("italicsorbold#15 "); (yyval.node) = makeTextBlock2 (newNodeS (TextToken, "'''"),
                            nodeAddChild (newNode (Italics), (yyvsp[(2) - (4)].node)), (yyvsp[(4) - (4)].node)); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 242 "wikiparse.y"
    { debugf ("italicsorbold#16 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "'''"),
                            nodeAddChild (newNode (Italics), (yyvsp[(2) - (3)].node))); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 245 "wikiparse.y"
    { debugf ("italicsorbold#17 ");
                            (yyval.node) = makeTextBlock (newNodeS (TextToken, "'''''"), (yyvsp[(2) - (2)].node)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 249 "wikiparse.y"
    { debugf ("italicsnobold#1 "); (yyval.node) = nodeAddChild (newNode (Italics), (yyvsp[(2) - (3)].node)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 251 "wikiparse.y"
    { debugf ("italicsnobold#2 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "''"), (yyvsp[(2) - (2)].node)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 254 "wikiparse.y"
    { debugf ("boldnoitalics#1 "); (yyval.node) = nodeAddChild (newNode (Bold), (yyvsp[(2) - (3)].node)); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 256 "wikiparse.y"
    { debugf ("boldnoitalics#2 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "'''"), (yyvsp[(2) - (2)].node)); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 259 "wikiparse.y"
    { debugf ("table#1 "); (yyval.node) = nodeAddChild2 (newNode (Table), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 261 "wikiparse.y"
    { debugf ("table#2 "); (yyval.node) = nodeAddChild2 (newNode (Table), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 263 "wikiparse.y"
    { debugf ("table#3 "); (yyval.node) = nodeAddChild2 (newNode (Table), (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 265 "wikiparse.y"
    { debugf ("table#4 "); (yyval.node) = nodeAddChild2 (newNode (Table), (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 267 "wikiparse.y"
    { debugf ("table#5 "); (yyval.node) = nodeAddChild (newNode (Table), (yyvsp[(2) - (3)].node)); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 269 "wikiparse.y"
    { debugf ("table#6 "); (yyval.node) = nodeAddChild (newNode (Table), (yyvsp[(2) - (2)].node)); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 271 "wikiparse.y"
    { debugf ("table#7 "); (yyval.node) = nodeAddChild (newNode (Table), (yyvsp[(3) - (4)].node)); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 273 "wikiparse.y"
    { debugf ("table#8 "); (yyval.node) = nodeAddChild (newNode (Table), (yyvsp[(3) - (3)].node)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 276 "wikiparse.y"
    { debugf ("table#9 "); (yyval.node) = nodeAddChild (newNode (Paragraph),
                            makeTextBlock (newNodeS (TextToken, addSpaces ("{|", (yyvsp[(1) - (3)].num))),
                                           convertAttributesToText ((yyvsp[(2) - (3)].node)))); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 280 "wikiparse.y"
    { debugf ("table#10 "); (yyval.node) = nodeAddChild (newNode (Paragraph),
                            makeTextBlock2 (newNodeS (TextToken, addSpaces ("{|", (yyvsp[(1) - (4)].num))),
                                            convertAttributesToText ((yyvsp[(2) - (4)].node)), (yyvsp[(3) - (4)].node))); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 284 "wikiparse.y"
    { debugf ("table#11 "); (yyval.node) = nodeAddChild (newNode (Paragraph),
                            makeTextBlock (newNodeS (TextToken, addSpaces ("{|", (yyvsp[(1) - (3)].num))), (yyvsp[(3) - (3)].node))); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 287 "wikiparse.y"
    { debugf ("table#12 "); (yyval.node) = nodeAddChild (newNode (Paragraph),
                            newNodeS (TextToken, addSpaces ("{|", (yyvsp[(1) - (2)].num)))); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 290 "wikiparse.y"
    { debugf ("tablerows#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 291 "wikiparse.y"
    { debugf ("tablerows#2 "); (yyval.node) = nodeAddSibling ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 294 "wikiparse.y"
    { debugf ("tablerow#1 "); (yyval.node) = nodeAddChild2 (newNode (TableRow), (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 296 "wikiparse.y"
    { debugf ("tablerow#2 "); (yyval.node) = nodeAddChild (newNode (TableRow), (yyvsp[(2) - (2)].node)); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 298 "wikiparse.y"
    { debugf ("tablerow#3 "); (yyval.node) = nodeAddChild2 (newNode (TableRow), (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 300 "wikiparse.y"
    { debugf ("tablerow#4 "); (yyval.node) = nodeAddChild (newNode (TableRow), (yyvsp[(3) - (3)].node)); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 303 "wikiparse.y"
    { debugf ("tablerow#5 "); (yyval.node) = nodeAddChild (newNode (TableRow), (yyvsp[(1) - (1)].node)); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 306 "wikiparse.y"
    { debugf ("tablerow#6 "); freeRecursivelyWithSiblings ((yyvsp[(2) - (3)].node)); (yyval.node) = 0; }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 308 "wikiparse.y"
    { debugf ("tablerow#7 "); freeRecursivelyWithSiblings ((yyvsp[(2) - (2)].node)); (yyval.node) = 0; }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 310 "wikiparse.y"
    { debugf ("tablerow#8 "); (yyval.node) = 0; }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 312 "wikiparse.y"
    { debugf ("tablerow#9 "); (yyval.node) = 0; }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 314 "wikiparse.y"
    { debugf ("tablerow#10 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 316 "wikiparse.y"
    { debugf ("tablecells#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 317 "wikiparse.y"
    { debugf ("tablecells#2 "); (yyval.node) = nodeAddSibling ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 320 "wikiparse.y"
    { debugf ("tablecell#1 "); (yyval.node) = nodeAddChild2 (newNode (TableCell), (yyvsp[(2) - (4)].node), processTableCellContents ((yyvsp[(4) - (4)].node))); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 322 "wikiparse.y"
    { debugf ("tablecell#2 "); (yyval.node) = nodeAddChild (newNode (TableCell), processTableCellContents ((yyvsp[(2) - (2)].node))); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 324 "wikiparse.y"
    { debugf ("tablecell#3 "); (yyval.node) = nodeAddChild (newNode (TableCell), (yyvsp[(2) - (4)].node)); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 326 "wikiparse.y"
    { debugf ("tablecell#4 "); (yyval.node) = nodeAddChild (newNode (TableCell), (yyvsp[(2) - (3)].node)); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 328 "wikiparse.y"
    { debugf ("tablecell#5 "); (yyval.node) = newNode (TableCell); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 330 "wikiparse.y"
    { debugf ("tablecell#6 "); (yyval.node) = newNode (TableCell); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 332 "wikiparse.y"
    { debugf ("tablecell#7 "); (yyval.node) = nodeAddChild2 (newNode (TableHead), (yyvsp[(2) - (4)].node), processTableCellContents ((yyvsp[(4) - (4)].node))); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 334 "wikiparse.y"
    { debugf ("tablecell#8 "); (yyval.node) = nodeAddChild (newNode (TableHead), processTableCellContents ((yyvsp[(2) - (2)].node))); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 336 "wikiparse.y"
    { debugf ("tablecell#9 "); (yyval.node) = nodeAddChild (newNode (TableHead), (yyvsp[(2) - (4)].node)); }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 338 "wikiparse.y"
    { debugf ("tablecell#10 "); (yyval.node) = nodeAddChild (newNode (TableHead), (yyvsp[(2) - (3)].node)); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 340 "wikiparse.y"
    { debugf ("tablecell#11 "); (yyval.node) = newNode (TableHead); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 342 "wikiparse.y"
    { debugf ("tablecell#12 "); (yyval.node) = newNode (TableHead); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 345 "wikiparse.y"
    { debugf ("tablecellcontents#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 347 "wikiparse.y"
    { debugf ("tablecellcontents#2 "); (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 350 "wikiparse.y"
    { debugf ("tablecaption#1 "); (yyval.node) = nodeAddChild2 (newNode (TableCaption), (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 352 "wikiparse.y"
    { debugf ("tablecaption#2 "); (yyval.node) = nodeAddChild (newNode (TableCaption), makeTextBlock (convertAttributesToText ((yyvsp[(2) - (3)].node)), (yyvsp[(3) - (3)].node))); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 354 "wikiparse.y"
    { debugf ("tablecaption#3 "); (yyval.node) = nodeAddChild (newNode (TableCaption), (yyvsp[(2) - (2)].node)); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 356 "wikiparse.y"
    { debugf ("tablecaption#4 "); (yyval.node) = nodeAddChild (newNode (TableCaption), makeTextBlock (convertAttributesToText ((yyvsp[(2) - (3)].node)), newNodeS (TextToken, "|"))); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 358 "wikiparse.y"
    { debugf ("tablecaption#5 "); (yyval.node) = nodeAddChild (newNode (TableCaption), convertAttributesToText ((yyvsp[(2) - (2)].node))); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 360 "wikiparse.y"
    { debugf ("tablecaption#6 "); (yyval.node) = 0; }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 365 "wikiparse.y"
    { debugf ("attribute#1 "); (yyval.node) = newNodeA (0, (yyvsp[(1) - (1)].ad), 0, 0); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 367 "wikiparse.y"
    { debugf ("attribute#2 "); (yyval.node) = nodeAddChild (newNodeA (1, (yyvsp[(1) - (3)].ad), (yyvsp[(2) - (3)].num), strtrimNC ((yyvsp[(3) - (3)].node))), (yyvsp[(3) - (3)].node)); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 369 "wikiparse.y"
    { debugf ("attribute#3 "); (yyval.node) = nodeAddChild (newNodeA (2, (yyvsp[(1) - (5)].ad), (yyvsp[(2) - (5)].num), (yyvsp[(5) - (5)].num)), (yyvsp[(4) - (5)].node)); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 371 "wikiparse.y"
    { debugf ("attribute#4 "); (yyval.node) = nodeAddChild (newNodeA (3, (yyvsp[(1) - (5)].ad), (yyvsp[(2) - (5)].num), (yyvsp[(5) - (5)].num)), (yyvsp[(4) - (5)].node)); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 373 "wikiparse.y"
    { debugf ("attribute#5 "); (yyval.node) = newNodeA (3, (yyvsp[(1) - (4)].ad), (yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].num)); }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 375 "wikiparse.y"
    { debugf ("attribute#6 "); (yyval.node) = newNodeA (1, (yyvsp[(1) - (2)].ad), (yyvsp[(2) - (2)].num), 0); }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 377 "wikiparse.y"
    { debugf ("attributes#1 "); (yyval.node) = nodeAddChild (newNode (AttributeGroup), (yyvsp[(1) - (1)].node)); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 378 "wikiparse.y"
    { debugf ("attributes#2 "); (yyval.node) = nodeAddChild ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 380 "wikiparse.y"
    { debugf ("text#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 381 "wikiparse.y"
    { debugf ("text#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 382 "wikiparse.y"
    { debugf ("textnoital#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 383 "wikiparse.y"
    { debugf ("textnoital#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 384 "wikiparse.y"
    { debugf ("textnobold#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 385 "wikiparse.y"
    { debugf ("textnobold#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 386 "wikiparse.y"
    { debugf ("textnoboit#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 387 "wikiparse.y"
    { debugf ("textnoboit#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 388 "wikiparse.y"
    { debugf ("textintbl#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 389 "wikiparse.y"
    { debugf ("textintbl#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 390 "wikiparse.y"
    { debugf ("textinlink#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 391 "wikiparse.y"
    { debugf ("textinlink#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 392 "wikiparse.y"
    { debugf ("textintmpl#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 393 "wikiparse.y"
    { debugf ("textintmpl#2 "); (yyval.node) = makeTextBlock ((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 395 "wikiparse.y"
    { debugf ("textelement#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 396 "wikiparse.y"
    { debugf ("textelement#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 397 "wikiparse.y"
    { debugf ("textelement#3 "); (yyval.node) = newNodeS (TextToken, "|"); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 398 "wikiparse.y"
    { debugf ("textelement#4 "); (yyval.node) = newNodeS (TextToken, "]]"); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 399 "wikiparse.y"
    { debugf ("textelement#5 "); (yyval.node) = newNodeS (TextToken, "''"); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 400 "wikiparse.y"
    { debugf ("textelement#6 "); (yyval.node) = newNodeS (TextToken, "'''"); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 401 "wikiparse.y"
    { debugf ("textelement#7 "); (yyval.node) = newNodeS (TextToken, "'''''"); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 402 "wikiparse.y"
    { debugf ("textelement#8 "); (yyval.node) = newNodeS (TextToken, addSpaces ("=", (yyvsp[(1) - (1)].num))); }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 403 "wikiparse.y"
    { debugf ("textelement#9 "); (yyval.node) = newNodeS (TextToken, addSpaces ("    {|", (yyvsp[(1) - (1)].num))); }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 404 "wikiparse.y"
    { debugf ("textelement#10 "); (yyval.node) = newNodeS (TextToken, "|}"); }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 405 "wikiparse.y"
    { debugf ("textelement#11 "); (yyval.node) = convertTableRowToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 406 "wikiparse.y"
    { debugf ("textelement#12 "); (yyval.node) = convertTableCellToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 407 "wikiparse.y"
    { debugf ("textelement#13 "); (yyval.node) = convertTableHeadToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 408 "wikiparse.y"
    { debugf ("textelement#14 "); (yyval.node) = convertTableCaptionToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 409 "wikiparse.y"
    { debugf ("textelement#15 "); (yyval.node) = convertAttributeDataToText ((yyvsp[(1) - (1)].ad)); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 410 "wikiparse.y"
    { debugf ("textelement#16 "); (yyval.node) = newNodeS (TextToken, "}}}}}"); }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 411 "wikiparse.y"
    { debugf ("textelement#17 "); (yyval.node) = newNodeS (TextToken, "}}}"); }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 412 "wikiparse.y"
    { debugf ("textelement#18 "); (yyval.node) = newNodeS (TextToken, "}}"); }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 413 "wikiparse.y"
    { debugf ("textelement#19 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 414 "wikiparse.y"
    { debugf ("textelement#20 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 415 "wikiparse.y"
    { debugf ("textelement#21 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 416 "wikiparse.y"
    { debugf ("textelement#22 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 417 "wikiparse.y"
    { debugf ("textelement#23 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 420 "wikiparse.y"
    { debugf ("textelementnoital#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 421 "wikiparse.y"
    { debugf ("textelementnoital#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 422 "wikiparse.y"
    { debugf ("textelementnoital#3 "); (yyval.node) = newNodeS (TextToken, "|"); }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 423 "wikiparse.y"
    { debugf ("textelementnoital#4 "); (yyval.node) = newNodeS (TextToken, "]]"); }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 424 "wikiparse.y"
    { debugf ("textelementnoital#5 "); (yyval.node) = newNodeS (TextToken, addSpaces ("    {|", (yyvsp[(1) - (1)].num))); }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 425 "wikiparse.y"
    { debugf ("textelementnoital#6 "); (yyval.node) = newNodeS (TextToken, "|}"); }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 426 "wikiparse.y"
    { debugf ("textelementnoital#7 "); (yyval.node) = convertTableRowToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 427 "wikiparse.y"
    { debugf ("textelementnoital#8 "); (yyval.node) = convertTableCellToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 428 "wikiparse.y"
    { debugf ("textelementnoital#9 "); (yyval.node) = convertTableHeadToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 429 "wikiparse.y"
    { debugf ("textelementnoital#10 "); (yyval.node) = convertTableCaptionToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 430 "wikiparse.y"
    { debugf ("textelementnoital#11 "); (yyval.node) = convertAttributeDataToText ((yyvsp[(1) - (1)].ad)); }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 431 "wikiparse.y"
    { debugf ("textelementnoital#12 "); (yyval.node) = newNodeS (TextToken, "}}}}}"); }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 432 "wikiparse.y"
    { debugf ("textelementnoital#13 "); (yyval.node) = newNodeS (TextToken, "}}}"); }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 433 "wikiparse.y"
    { debugf ("textelementnoital#14 "); (yyval.node) = newNodeS (TextToken, "}}"); }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 434 "wikiparse.y"
    { debugf ("textelementnoital#15 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 435 "wikiparse.y"
    { debugf ("textelementnoital#16 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 436 "wikiparse.y"
    { debugf ("textelementnoital#17 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 437 "wikiparse.y"
    { debugf ("textelementnoital#18 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 438 "wikiparse.y"
    { debugf ("textelementnoital#19 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 440 "wikiparse.y"
    { debugf ("textelementnobold#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 441 "wikiparse.y"
    { debugf ("textelementnobold#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 442 "wikiparse.y"
    { debugf ("textelementnobold#3 "); (yyval.node) = newNodeS (TextToken, "|"); }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 443 "wikiparse.y"
    { debugf ("textelementnobold#4 "); (yyval.node) = newNodeS (TextToken, "]]"); }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 444 "wikiparse.y"
    { debugf ("textelementnobold#5 "); (yyval.node) = newNodeS (TextToken, addSpaces ("    {|", (yyvsp[(1) - (1)].num))); }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 445 "wikiparse.y"
    { debugf ("textelementnobold#6 "); (yyval.node) = newNodeS (TextToken, "|}"); }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 446 "wikiparse.y"
    { debugf ("textelementnobold#7 "); (yyval.node) = convertTableRowToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 447 "wikiparse.y"
    { debugf ("textelementnobold#8 "); (yyval.node) = convertTableCellToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 448 "wikiparse.y"
    { debugf ("textelementnobold#9 "); (yyval.node) = convertTableHeadToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 449 "wikiparse.y"
    { debugf ("textelementnobold#10 "); (yyval.node) = convertTableCaptionToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 450 "wikiparse.y"
    { debugf ("textelementnobold#11 "); (yyval.node) = convertAttributeDataToText ((yyvsp[(1) - (1)].ad)); }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 451 "wikiparse.y"
    { debugf ("textelementnobold#12 "); (yyval.node) = newNodeS (TextToken, "}}}}}"); }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 452 "wikiparse.y"
    { debugf ("textelementnobold#13 "); (yyval.node) = newNodeS (TextToken, "}}}"); }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 453 "wikiparse.y"
    { debugf ("textelementnobold#14 "); (yyval.node) = newNodeS (TextToken, "}}"); }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 454 "wikiparse.y"
    { debugf ("textelementnobold#15 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 455 "wikiparse.y"
    { debugf ("textelementnobold#16 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 456 "wikiparse.y"
    { debugf ("textelementnobold#17 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 457 "wikiparse.y"
    { debugf ("textelementnobold#18 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 458 "wikiparse.y"
    { debugf ("textelementnobold#19 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 460 "wikiparse.y"
    { debugf ("textelementnoboit#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 461 "wikiparse.y"
    { debugf ("textelementnoboit#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 462 "wikiparse.y"
    { debugf ("textelementnoboit#3 "); (yyval.node) = newNodeS (TextToken, "|"); }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 463 "wikiparse.y"
    { debugf ("textelementnoboit#4 "); (yyval.node) = newNodeS (TextToken, "]]"); }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 464 "wikiparse.y"
    { debugf ("textelementnoboit#5 "); (yyval.node) = newNodeS (TextToken, addSpaces ("    {|", (yyvsp[(1) - (1)].num))); }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 465 "wikiparse.y"
    { debugf ("textelementnoboit#6 "); (yyval.node) = newNodeS (TextToken, "|}"); }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 466 "wikiparse.y"
    { debugf ("textelementnoboit#7 "); (yyval.node) = convertTableRowToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 467 "wikiparse.y"
    { debugf ("textelementnoboit#8 "); (yyval.node) = convertTableCellToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 468 "wikiparse.y"
    { debugf ("textelementnoboit#9 "); (yyval.node) = convertTableHeadToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 469 "wikiparse.y"
    { debugf ("textelementnoboit#10 "); (yyval.node) = convertTableCaptionToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 470 "wikiparse.y"
    { debugf ("textelementnoboit#11 "); (yyval.node) = convertAttributeDataToText ((yyvsp[(1) - (1)].ad)); }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 471 "wikiparse.y"
    { debugf ("textelementnobold#12 "); (yyval.node) = newNodeS (TextToken, "}}}}}"); }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 472 "wikiparse.y"
    { debugf ("textelementnobold#13 "); (yyval.node) = newNodeS (TextToken, "}}}"); }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 473 "wikiparse.y"
    { debugf ("textelementnobold#14 "); (yyval.node) = newNodeS (TextToken, "}}"); }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 474 "wikiparse.y"
    { debugf ("textelementnoboit#15 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 475 "wikiparse.y"
    { debugf ("textelementnoboit#16 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 476 "wikiparse.y"
    { debugf ("textelementnoboit#17 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 477 "wikiparse.y"
    { debugf ("textelementnoboit#18 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 479 "wikiparse.y"
    { debugf ("textelementintbl#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 480 "wikiparse.y"
    { debugf ("textelementintbl#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 481 "wikiparse.y"
    { debugf ("textelementintbl#3 "); (yyval.node) = newNodeS (TextToken, "|"); }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 482 "wikiparse.y"
    { debugf ("textelementintbl#4 "); (yyval.node) = newNodeS (TextToken, "]]"); }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 483 "wikiparse.y"
    { debugf ("textelementintbl#5 "); (yyval.node) = newNodeS (TextToken, "''"); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 484 "wikiparse.y"
    { debugf ("textelementintbl#6 "); (yyval.node) = newNodeS (TextToken, "'''"); }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 485 "wikiparse.y"
    { debugf ("textelementintbl#7 "); (yyval.node) = newNodeS (TextToken, "'''''"); }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 486 "wikiparse.y"
    { debugf ("textelementintbl#8 "); (yyval.node) = newNodeS (TextToken, addSpaces ("=", (yyvsp[(1) - (1)].num))); }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 487 "wikiparse.y"
    { debugf ("textelementintbl#9 "); (yyval.node) = newNodeS (TextToken, "}}}}}"); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 488 "wikiparse.y"
    { debugf ("textelementintbl#10 "); (yyval.node) = newNodeS (TextToken, "}}}"); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 489 "wikiparse.y"
    { debugf ("textelementintbl#11 "); (yyval.node) = newNodeS (TextToken, "}}"); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 490 "wikiparse.y"
    { debugf ("textelementintbl#12 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 491 "wikiparse.y"
    { debugf ("textelementintbl#13 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 492 "wikiparse.y"
    { debugf ("textelementintbl#14 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 493 "wikiparse.y"
    { debugf ("textelementintbl#15 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 494 "wikiparse.y"
    { debugf ("textelementintbl#16 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 496 "wikiparse.y"
    { debugf ("textelementinlink#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 497 "wikiparse.y"
    { debugf ("textelementinlink#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 498 "wikiparse.y"
    { debugf ("textelementinlink#3 "); (yyval.node) = newNodeS (TextToken, "''"); }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 499 "wikiparse.y"
    { debugf ("textelementinlink#4 "); (yyval.node) = newNodeS (TextToken, "'''"); }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 500 "wikiparse.y"
    { debugf ("textelementinlink#5 "); (yyval.node) = newNodeS (TextToken, "'''''"); }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 501 "wikiparse.y"
    { debugf ("textelementinlink#6 "); (yyval.node) = newNodeS (TextToken, addSpaces ("=", (yyvsp[(1) - (1)].num))); }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 502 "wikiparse.y"
    { debugf ("textelementinlink#7 "); (yyval.node) = newNodeS (TextToken, addSpaces ("    {|", (yyvsp[(1) - (1)].num))); }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 503 "wikiparse.y"
    { debugf ("textelementinlink#8 "); (yyval.node) = newNodeS (TextToken, "|}"); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 504 "wikiparse.y"
    { debugf ("textelementinlink#9 "); (yyval.node) = convertTableRowToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 505 "wikiparse.y"
    { debugf ("textelementinlink#10 "); (yyval.node) = convertTableCellToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 506 "wikiparse.y"
    { debugf ("textelementinlink#11 "); (yyval.node) = convertTableHeadToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 507 "wikiparse.y"
    { debugf ("textelementinlink#12 "); (yyval.node) = convertTableCaptionToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 508 "wikiparse.y"
    { debugf ("textelementinlink#13 "); (yyval.node) = convertAttributeDataToText ((yyvsp[(1) - (1)].ad)); }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 509 "wikiparse.y"
    { debugf ("textelementinlink#14 "); (yyval.node) = newNodeS (TextToken, "}}}}}"); }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 510 "wikiparse.y"
    { debugf ("textelementinlink#15 "); (yyval.node) = newNodeS (TextToken, "}}}"); }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 511 "wikiparse.y"
    { debugf ("textelementinlink#16 "); (yyval.node) = newNodeS (TextToken, "}}"); }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 512 "wikiparse.y"
    { debugf ("textelementinlink#17 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 513 "wikiparse.y"
    { debugf ("textelementinlink#18 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 514 "wikiparse.y"
    { debugf ("textelementinlink#19 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 515 "wikiparse.y"
    { debugf ("textelementinlink#20 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 516 "wikiparse.y"
    { debugf ("textelementinlink#21 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 518 "wikiparse.y"
    { debugf ("textelementintmpl#1 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 519 "wikiparse.y"
    { debugf ("textelementintmpl#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 520 "wikiparse.y"
    { debugf ("textelementintmpl#3 "); (yyval.node) = newNodeS (TextToken, "|"); }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 521 "wikiparse.y"
    { debugf ("textelementintmpl#4 "); (yyval.node) = newNodeS (TextToken, "]]"); }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 522 "wikiparse.y"
    { debugf ("textelementintmpl#5 "); (yyval.node) = newNodeS (TextToken, "''"); }
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 523 "wikiparse.y"
    { debugf ("textelementintmpl#6 "); (yyval.node) = newNodeS (TextToken, "'''"); }
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 524 "wikiparse.y"
    { debugf ("textelementintmpl#7 "); (yyval.node) = newNodeS (TextToken, "'''''"); }
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 525 "wikiparse.y"
    { debugf ("textelementintmpl#8 "); (yyval.node) = newNodeS (TextToken, addSpaces ("=", (yyvsp[(1) - (1)].num))); }
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 526 "wikiparse.y"
    { debugf ("textelementintmpl#9 "); (yyval.node) = newNodeS (TextToken, addSpaces ("    {|", (yyvsp[(1) - (1)].num))); }
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 527 "wikiparse.y"
    { debugf ("textelementintmpl#10 "); (yyval.node) = newNodeS (TextToken, "|}"); }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 528 "wikiparse.y"
    { debugf ("textelementintmpl#11 "); (yyval.node) = convertTableRowToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 529 "wikiparse.y"
    { debugf ("textelementintmpl#12 "); (yyval.node) = convertTableCellToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 530 "wikiparse.y"
    { debugf ("textelementintmpl#13 "); (yyval.node) = convertTableHeadToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 531 "wikiparse.y"
    { debugf ("textelementintmpl#14 "); (yyval.node) = convertTableCaptionToText ((yyvsp[(1) - (1)].num)); }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 532 "wikiparse.y"
    { debugf ("textelementintmpl#15 "); (yyval.node) = convertAttributeDataToText ((yyvsp[(1) - (1)].ad)); }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 533 "wikiparse.y"
    { debugf ("textelementintmpl#16 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 534 "wikiparse.y"
    { debugf ("textelementintmpl#17 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 535 "wikiparse.y"
    { debugf ("textelementintmpl#18 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 536 "wikiparse.y"
    { debugf ("textelementintmpl#19 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 537 "wikiparse.y"
    { debugf ("textelementintmpl#20 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 543 "wikiparse.y"
    { debugf ("template#1 "); (yyval.node) = nodeAddChild (newNode (Template), (yyvsp[(2) - (3)].node)); }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 545 "wikiparse.y"
    { debugf ("template#2 "); (yyval.node) = nodeAddChild (newNode (Template),
                                makeTextBlock (nodeAddChild (newNode (TemplateVar), (yyvsp[(2) - (5)].node)), (yyvsp[(4) - (5)].node))); }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 548 "wikiparse.y"
    { debugf ("template#3 "); (yyval.node) = nodeAddChild (newNode (Template),
                                makeTextBlock ((yyvsp[(2) - (5)].node), nodeAddChild (newNode (TemplateVar), (yyvsp[(4) - (5)].node)))); }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 552 "wikiparse.y"
    { debugf ("template#4 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "{{"), (yyvsp[(2) - (2)].node)); }
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 554 "wikiparse.y"
    { debugf ("template#5 "); (yyval.node) = makeTextBlock3 (newNodeS (TextToken, "{{{{{"),
                                (yyvsp[(2) - (4)].node), newNodeS (TextToken, "}}}"), (yyvsp[(4) - (4)].node)); }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 557 "wikiparse.y"
    { debugf ("template#6 "); (yyval.node) = makeTextBlock3 (newNodeS (TextToken, "{{"),
                                (yyvsp[(2) - (4)].node), newNodeS (TextToken, "{{{"), (yyvsp[(4) - (4)].node)); }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 561 "wikiparse.y"
    { debugf ("templatevar#1 "); (yyval.node) = nodeAddChild (newNode (TemplateVar), (yyvsp[(2) - (3)].node)); }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 563 "wikiparse.y"
    { debugf ("templatevar#2 "); (yyval.node) =
                                nodeAddChild (newNode (Template), nodeAddChild (newNode (TemplateVar), (yyvsp[(2) - (3)].node))); }
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 567 "wikiparse.y"
    { debugf ("templatevar#1 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "{{{"), (yyvsp[(2) - (2)].node)); }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 569 "wikiparse.y"
    { debugf ("templatevar#2 "); (yyval.node) = makeTextBlock (newNodeS (TextToken, "{{{{{"), (yyvsp[(2) - (2)].node)); }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 571 "wikiparse.y"
    { debugf ("zeroormorenewlines#1 "); (yyval.node) = 0; }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 572 "wikiparse.y"
    { debugf ("zeroormorenewlines#2 "); (yyval.node) = 0; }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 573 "wikiparse.y"
    { debugf ("oneormorenewlines#1 "); (yyval.node) = 0; }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 574 "wikiparse.y"
    { debugf ("oneormorenewlines#2 "); (yyval.node) = 0; }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 576 "wikiparse.y"
    { debugf ("zeroormorenewlinessave#1 "); (yyval.node) = 0; }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 577 "wikiparse.y"
    { debugf ("zeroormorenewlinessave#2 "); (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 578 "wikiparse.y"
    { debugf ("oneormorenewlinessave#1 "); (yyval.node) = newNodeI (Newlines, 0); }
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 579 "wikiparse.y"
    { debugf ("oneormorenewlinessave#2 "); (yyvsp[(1) - (2)].node)->data.num++; (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 582 "wikiparse.y"
    { debugf ("paragraph#1 "); (yyval.node) = nodeAddChild (newNode (Paragraph), (yyvsp[(1) - (2)].node)); }
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 584 "wikiparse.y"
    { debugf ("paragraph#2 "); (yyval.node) = nodeAddChild2 ((yyvsp[(1) - (3)].node), newNodeS (TextToken, " "), (yyvsp[(2) - (3)].node)); }
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 587 "wikiparse.y"
    { debugf ("paragraph#3 "); (yyval.node) = nodeAddChild (newNode (Paragraph), (yyvsp[(1) - (1)].node)); }
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 589 "wikiparse.y"
    { debugf ("paragraph#4 "); (yyval.node) = nodeAddChild2 ((yyvsp[(1) - (2)].node), newNodeS (TextToken, " "), (yyvsp[(2) - (2)].node)); }
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 596 "wikiparse.y"
    { debugf ("paragraphintbl#1 "); (yyval.node) = nodeAddChild (newNode (Paragraph), (yyvsp[(1) - (2)].node)); }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 598 "wikiparse.y"
    { debugf ("paragraphintbl#2 "); (yyval.node) = nodeAddChild2 (newNode (Paragraph), convertAttributesToText ((yyvsp[(1) - (3)].node)), (yyvsp[(2) - (3)].node)); }
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 600 "wikiparse.y"
    { debugf ("paragraphintbl#3 "); (yyval.node) = nodeAddChild (newNode (Paragraph), convertAttributesToText ((yyvsp[(1) - (2)].node))); }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 602 "wikiparse.y"
    { debugf ("paragraphintbl#4 "); (yyval.node) = nodeAddChild2 ((yyvsp[(1) - (3)].node), newNodeS (TextToken, " "), (yyvsp[(2) - (3)].node)); }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 604 "wikiparse.y"
    { debugf ("paragraphintbl#5 "); (yyval.node) = nodeAddChild3 ((yyvsp[(1) - (4)].node), newNodeS (TextToken, " "), convertAttributesToText ((yyvsp[(2) - (4)].node)), (yyvsp[(3) - (4)].node)); }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 606 "wikiparse.y"
    { debugf ("paragraphintbl#6 "); (yyval.node) = nodeAddChild2 ((yyvsp[(1) - (3)].node), newNodeS (TextToken, " "), convertAttributesToText ((yyvsp[(2) - (3)].node))); }
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 609 "wikiparse.y"
    { debugf ("paragraphintbl#7 "); (yyval.node) = nodeAddChild (newNode (Paragraph), (yyvsp[(1) - (1)].node)); }
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 611 "wikiparse.y"
    { debugf ("paragraphintbl#8 "); (yyval.node) = nodeAddChild2 (newNode (Paragraph), convertAttributesToText ((yyvsp[(1) - (2)].node)), (yyvsp[(2) - (2)].node)); }
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 613 "wikiparse.y"
    { debugf ("paragraphintbl#9 "); (yyval.node) = nodeAddChild (newNode (Paragraph), convertAttributesToText ((yyvsp[(1) - (1)].node))); }
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 615 "wikiparse.y"
    { debugf ("paragraphintbl#10 "); (yyval.node) = nodeAddChild2 ((yyvsp[(1) - (2)].node), newNodeS (TextToken, " "), (yyvsp[(2) - (2)].node)); }
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 617 "wikiparse.y"
    { debugf ("paragraphintbl#11 "); (yyval.node) = nodeAddChild3 ((yyvsp[(1) - (3)].node), newNodeS (TextToken, " "), convertAttributesToText ((yyvsp[(2) - (3)].node)), (yyvsp[(3) - (3)].node)); }
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 619 "wikiparse.y"
    { debugf ("paragraphintbl#12 "); (yyval.node) = nodeAddChild2 ((yyvsp[(1) - (2)].node), newNodeS (TextToken, " "), convertAttributesToText ((yyvsp[(2) - (2)].node))); }
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 622 "wikiparse.y"
    { debugf ("comment#1 "); (yyval.node) = nodeAddChild (newNode (Comment), (yyvsp[(2) - (3)].node)); }
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 624 "wikiparse.y"
    { debugf ("comment#2 "); (yyval.node) = newNode (Comment); }
    break;



/* Line 1806 of yacc.c  */
#line 4658 "wikiparse.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 627 "wikiparse.y"


/* main() -- this is called whenever you invoke the parser from the command line. You probably
 * do that only to test it, which is why we are outputting some extra information. It reads
 * standard input and writes to standard output. */
/*
int main() {
    int result;
//    printf ("Parsing... ");

    result = yyparse();
    if (!result) printf ("%s", outputXML (articlenode, 1024) ) ;
//        printf ("\n\nXML output:\n\n%s\n\n", outputXML (articlenode, 1024));
    freeRecursively (articlenode);
    return result;
}
*/

/* wikiparse_do_parse() -- this is the function that is actually called by PHP. It uses an
 * input string, and returns an output string. No stdin/stdout. */
const char* wikiparse_do_parse (const char* input)
{
    int result, i;
    char* ret = "<error />";

    /* yy_scan_string copies the string into an internal buffer. During lexing, this internal
     * buffer may be modified. We don't really need the string anymore, so we probably don't mind
     * if it's modified, so we might not need for it to be copied. There is yy_scan_buffer which
     * uses the string directly as a buffer, but for some bizarre reason it expects the buffer to
     * end with *two* NULs instead of just one. Thus yy_scan_string is the easiest way for now. */
    yy_scan_string (input);

    result = yyparse();
    if (!result)
    {
        /* Start with an output buffer twice the size of the input, but at least 1 KB. This should
         * normally be plenty. If it isn't, it will grow automatically. */
        i = 2*strlen (input);
        ret = outputXML (articlenode, i < 1024 ? 1024 : i);
        freeRecursively (articlenode);
    }
    return ret;
}

