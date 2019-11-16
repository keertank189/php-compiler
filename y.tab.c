/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_START = 258,
     T_END = 259,
     T_BRK = 260,
     T_SCLN = 261,
     T_CBOP = 262,
     T_CBCL = 263,
     T_CNTUE = 264,
     T_IF = 265,
     T_PAOP = 266,
     T_PACL = 267,
     T_ELSE = 268,
     T_ELIF = 269,
     T_WHILE = 270,
     T_CLN = 271,
     T_SWITCH = 272,
     T_CASELABEL = 273,
     T_ID = 274,
     T_EQUALS = 275,
     T_INC = 276,
     T_DEC = 277,
     T_ADDEQ = 278,
     T_SUBEQ = 279,
     T_DIVEQ = 280,
     T_MULEQ = 281,
     T_STRING = 282,
     T_LOGOR = 283,
     T_LOGAND = 284,
     T_GREQ = 285,
     T_LEEQ = 286,
     T_GR = 287,
     T_LE = 288,
     T_EQCH = 289,
     T_TRUE = 290,
     T_FALSE = 291,
     T_NOT = 292,
     T_PLUS = 293,
     T_MINUS = 294,
     T_DIVIDE = 295,
     T_MUL = 296,
     T_MOD = 297,
     T_INT = 298,
     T_FLOAT = 299,
     T_COMMA = 300,
     T_ARR = 301,
     T_SQOP = 302,
     T_SQCL = 303,
     T_LOGXOR = 304,
     T_ECHO = 305,
     T_DOT = 306
   };
#endif
/* Tokens.  */
#define T_START 258
#define T_END 259
#define T_BRK 260
#define T_SCLN 261
#define T_CBOP 262
#define T_CBCL 263
#define T_CNTUE 264
#define T_IF 265
#define T_PAOP 266
#define T_PACL 267
#define T_ELSE 268
#define T_ELIF 269
#define T_WHILE 270
#define T_CLN 271
#define T_SWITCH 272
#define T_CASELABEL 273
#define T_ID 274
#define T_EQUALS 275
#define T_INC 276
#define T_DEC 277
#define T_ADDEQ 278
#define T_SUBEQ 279
#define T_DIVEQ 280
#define T_MULEQ 281
#define T_STRING 282
#define T_LOGOR 283
#define T_LOGAND 284
#define T_GREQ 285
#define T_LEEQ 286
#define T_GR 287
#define T_LE 288
#define T_EQCH 289
#define T_TRUE 290
#define T_FALSE 291
#define T_NOT 292
#define T_PLUS 293
#define T_MINUS 294
#define T_DIVIDE 295
#define T_MUL 296
#define T_MOD 297
#define T_INT 298
#define T_FLOAT 299
#define T_COMMA 300
#define T_ARR 301
#define T_SQOP 302
#define T_SQCL 303
#define T_LOGXOR 304
#define T_ECHO 305
#define T_DOT 306




/* Copy the first part of user declarations.  */
#line 1 "n10gramunopt.y"

	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#include "header.c"
	//#include "symbol_table.c"				
	#define YYSTYPE YACC
	FILE *yyin;
	FILE *fp;
	int yylex();

	void yyerror(const char *);
	
	void printlist(DLIST *list);
	void addNode(DLIST *list,int open);

	void addVar(char *name,char *val,char *type,int scope,int occur,SYMLIST *slist);
	void printsym(SYMLIST *slist);

	SYMNODE* varsearch(char *name,SYMNODE *stemp,NODE *temp);
	SYMNODE* lookup(char *name,SYMLIST *slist, DLIST *list);
	
	FILE *yyin;
	int yylex();
	char *brlb,*contlb,*swlb,*swfal,*cslb[100],*wltr;
	int i =0;
	char* type;
	char* temp;
	char *var;
	int scope;
	int occur;
	char* newLabel(int *ln);
	char* newTemp(int *tn);
	int lbflag = 0;
	int tn = 1;
	int ln = 1;	
	DLIST *list;
	NODE *first;	
	SYMLIST *slist;
	/*typedef struct NODE
	{
		int valid;
		int dtype;
		int space;
		char name[100];
		union data_value
		{
			int i;
			float f;
			bool b;
			char string[150];
		};
		struct NODE *next;
	}NODE;
	typedef struct SYMBOL_TABLE
	{
		NODE *head;
		int entries;
	}TABLE;*/
	int scope = 0,occur = 0;
	

	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 274 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  212

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     9,    11,    13,    15,    17,    19,
      21,    23,    26,    29,    32,    35,    38,    41,    44,    45,
      46,    47,    48,    59,    62,    67,    68,    69,    76,    77,
      78,    81,    83,    84,    86,    88,    90,    91,    98,    99,
     100,   108,   109,   116,   120,   121,   122,   128,   133,   134,
     138,   139,   140,   149,   150,   151,   152,   162,   163,   166,
     167,   171,   173,   177,   179,   181,   183,   190,   194,   196,
     198,   200,   202,   204,   206,   208,   210,   212,   214,   216,
     221,   226,   227,   232,   233,   238,   243,   248,   252,   256,
     260,   264,   268,   269,   271,   273,   275,   277,   281,   285,
     287,   291,   295,   299,   301,   303,   307,   309,   311,   313,
     317,   321,   323,   327,   331,   335,   337,   339,   343,   345,
     347,   349,   351,   353,   355,   357,   359,   360,   365,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,    54,     3,    55,     4,    -1,    57,
      -1,   112,    -1,   113,    -1,    74,    -1,    69,    -1,    58,
      -1,    94,    -1,   112,    57,    -1,   110,    57,    -1,   113,
      57,    -1,    74,    57,    -1,    69,    57,    -1,    58,    57,
      -1,    94,    57,    -1,    -1,    -1,    -1,    -1,    17,    59,
      11,    62,    60,    12,     7,    61,    64,     8,    -1,    19,
      63,    -1,    47,    43,    48,    63,    -1,    -1,    -1,    18,
      68,    16,    65,    66,    64,    -1,    -1,    -1,    67,    56,
      -1,   110,    -1,    -1,    43,    -1,    27,    -1,    93,    -1,
      -1,    15,    11,    88,    12,    70,   110,    -1,    -1,    -1,
      15,    11,    88,    12,    71,    72,    56,    -1,    -1,    15,
      11,    88,    12,    73,     6,    -1,    77,   110,    78,    -1,
      -1,    -1,    77,    75,    56,    76,    78,    -1,    10,    11,
      88,    12,    -1,    -1,    79,    80,    86,    -1,    -1,    -1,
      14,    11,    88,    12,    81,   110,    82,    80,    -1,    -1,
      -1,    -1,    14,    11,    88,    12,    83,    84,    56,    85,
      80,    -1,    -1,    13,   110,    -1,    -1,    13,    87,    56,
      -1,    90,    -1,    90,    89,    88,    -1,    28,    -1,    29,
      -1,    49,    -1,    37,    11,    92,    91,    92,    12,    -1,
      92,    91,    92,    -1,    92,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    62,    -1,   101,    -1,
      93,    -1,    35,    -1,    36,    -1,    62,   109,   105,     6,
      -1,    62,    20,    27,     6,    -1,    -1,    99,    62,    95,
       6,    -1,    -1,    62,    96,   100,     6,    -1,    62,    20,
      97,     6,    -1,    46,    11,    98,    12,    -1,    43,    45,
      98,    -1,    44,    45,    98,    -1,    93,    45,    98,    -1,
      97,    45,    98,    -1,    27,    45,    98,    -1,    -1,    21,
      -1,    22,    -1,    21,    -1,    22,    -1,   101,    38,   102,
      -1,   101,    39,   102,    -1,   102,    -1,   102,    41,   103,
      -1,   102,    40,   103,    -1,   102,    42,   103,    -1,   103,
      -1,   104,    -1,    11,   101,    12,    -1,    43,    -1,    44,
      -1,    27,    -1,   105,    38,   106,    -1,   105,    39,   106,
      -1,   106,    -1,   106,    41,   107,    -1,   106,    40,   107,
      -1,   106,    42,   107,    -1,   107,    -1,   108,    -1,    11,
     105,    12,    -1,    62,    -1,    43,    -1,    44,    -1,    20,
      -1,    23,    -1,    24,    -1,    26,    -1,    25,    -1,    -1,
       7,   111,    57,     8,    -1,     5,     6,    -1,     9,     6,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    78,    82,    86,    87,    88,    89,    90,
      91,    95,    96,    97,    98,    99,   100,   101,   103,   107,
     107,   107,   107,   111,   115,   116,   120,   120,   121,   125,
     125,   126,   127,   131,   132,   133,   138,   138,   139,   139,
     139,   140,   140,   144,   145,   145,   145,   148,   152,   152,
     156,   156,   156,   157,   157,   157,   157,   158,   162,   163,
     163,   167,   168,   172,   173,   174,   179,   180,   181,   185,
     186,   187,   188,   189,   193,   194,   195,   199,   200,   204,
     205,   206,   206,   207,   207,   208,   212,   216,   217,   218,
     219,   220,   221,   225,   226,   230,   231,   236,   237,   238,
     242,   243,   244,   245,   250,   251,   256,   257,   258,   262,
     263,   264,   268,   269,   270,   271,   276,   277,   278,   283,
     284,   288,   289,   290,   291,   292,   298,   298,   302,   306
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_START", "T_END", "T_BRK", "T_SCLN",
  "T_CBOP", "T_CBCL", "T_CNTUE", "T_IF", "T_PAOP", "T_PACL", "T_ELSE",
  "T_ELIF", "T_WHILE", "T_CLN", "T_SWITCH", "T_CASELABEL", "T_ID",
  "T_EQUALS", "T_INC", "T_DEC", "T_ADDEQ", "T_SUBEQ", "T_DIVEQ", "T_MULEQ",
  "T_STRING", "T_LOGOR", "T_LOGAND", "T_GREQ", "T_LEEQ", "T_GR", "T_LE",
  "T_EQCH", "T_TRUE", "T_FALSE", "T_NOT", "T_PLUS", "T_MINUS", "T_DIVIDE",
  "T_MUL", "T_MOD", "T_INT", "T_FLOAT", "T_COMMA", "T_ARR", "T_SQOP",
  "T_SQCL", "T_LOGXOR", "T_ECHO", "T_DOT", "$accept", "phpBlock", "@1",
  "program", "singlestatement", "statement", "switch", "@2", "@3", "@4",
  "variable", "index", "cases", "@5", "insidecase", "@6", "switchconstant",
  "while", "@7", "@8", "@9", "@10", "if", "@11", "@12", "ifstmt",
  "restofif", "@13", "elseif", "@14", "@15", "@16", "@17", "@18", "else",
  "@19", "logic_expr", "logic_op", "rel_expr", "rel_op", "rel_operand",
  "boolean", "assignment", "@20", "@21", "array_declr", "in_arr_list",
  "prefix_op", "postfix_op", "rel_arith_expr", "rel_term", "rel_factor",
  "rel_const", "arith_expr", "term", "factor", "const", "assign_op",
  "block", "@22", "break", "continue", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    54,    53,    55,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    59,
      60,    61,    58,    62,    63,    63,    65,    64,    64,    67,
      66,    66,    66,    68,    68,    68,    70,    69,    71,    72,
      69,    73,    69,    74,    75,    76,    74,    77,    79,    78,
      81,    82,    80,    83,    84,    85,    80,    80,    86,    87,
      86,    88,    88,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    91,    91,    92,    92,    92,    93,    93,    94,
      94,    95,    94,    96,    94,    94,    97,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   103,   103,   104,   104,   104,   105,
     105,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   111,   110,   112,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     0,     0,
       0,     0,    10,     2,     4,     0,     0,     6,     0,     0,
       2,     1,     0,     1,     1,     1,     0,     6,     0,     0,
       7,     0,     6,     3,     0,     0,     5,     4,     0,     3,
       0,     0,     8,     0,     0,     0,     9,     0,     2,     0,
       3,     1,     3,     1,     1,     1,     6,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     0,     4,     0,     4,     4,     4,     3,     3,     3,
       3,     3,     0,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     3,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    18,     0,   126,     0,     0,     0,
      19,    25,    93,    94,     0,     4,    18,    83,    18,    18,
      44,    18,     0,    18,    18,    18,   128,    18,   129,     0,
       0,     0,     0,    23,     3,    16,   121,   122,   123,   125,
     124,     0,     0,    15,    14,     0,    48,    17,    81,    12,
      11,    13,     0,     0,   108,    77,    78,     0,   106,   107,
      74,     0,    61,    68,    76,    75,    99,   103,   104,     0,
       0,     0,     0,     0,     0,    95,    96,     0,     0,   119,
     120,   118,     0,   111,   115,   116,    45,     9,     8,     7,
      10,     5,     6,    43,    57,     0,   127,     0,     0,    47,
      63,    64,    65,     0,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,     0,    38,    20,    25,    80,    92,
      85,    84,     0,    79,     0,     0,     0,     0,     0,    48,
       0,     0,    82,   105,     0,    62,    67,    97,    98,   101,
     100,   102,     0,    39,     0,     0,    24,     0,     0,     0,
       0,     0,     0,   117,   109,   110,   113,   112,   114,    46,
       0,    59,    49,     0,    37,     0,    42,     0,    92,    92,
      92,    92,    92,    86,     0,     0,    58,     0,    40,    21,
      91,    87,    88,    89,    90,    53,    60,    66,    28,     0,
      54,     0,     0,    51,     0,    34,    33,     0,    35,    22,
      57,    55,    26,    52,    57,    29,    56,    28,     0,    31,
      27,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    86,    15,    16,    31,   145,   188,
      17,    33,   192,   205,   207,   208,   197,    18,   142,   143,
     165,   144,    19,    45,   129,    20,    93,    94,   131,   189,
     200,   190,   194,   204,   162,   175,    61,   103,    62,   109,
      63,    64,    21,    95,    41,   151,   152,    22,    77,    65,
      66,    67,    68,    82,    83,    84,    85,    42,    23,    27,
      24,    25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -171
static const yytype_int16 yypact[] =
{
    -171,    21,    15,  -171,   167,    22,  -171,    27,    31,    35,
    -171,    -9,  -171,  -171,    56,  -171,   167,    93,   167,   167,
      66,   167,    64,   167,   167,   167,  -171,   167,  -171,     0,
       0,    75,    48,  -171,  -171,  -171,   -17,  -171,  -171,  -171,
    -171,    42,     6,  -171,  -171,   182,  -171,  -171,  -171,  -171,
    -171,  -171,    88,    34,  -171,  -171,  -171,   109,  -171,  -171,
    -171,    92,    23,   128,  -171,    32,    61,  -171,  -171,   114,
      64,    51,   130,   129,   133,  -171,  -171,   136,     6,  -171,
    -171,  -171,    18,   138,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,   131,   137,  -171,    20,     4,  -171,
    -171,  -171,  -171,     0,  -171,  -171,  -171,  -171,  -171,     4,
      34,    34,    34,    34,    34,   100,  -171,    -9,  -171,    54,
    -171,  -171,    41,  -171,     6,     6,     6,     6,     6,  -171,
     135,   142,  -171,  -171,   128,  -171,  -171,    61,    61,  -171,
    -171,  -171,    66,  -171,   143,   139,  -171,   103,   118,   120,
     145,   151,   161,  -171,   138,   138,  -171,  -171,  -171,  -171,
       0,    66,  -171,     4,  -171,   182,  -171,   168,    54,    54,
      54,    54,    54,  -171,   169,   182,  -171,   171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,   191,  -171,  -171,   184,    66,
    -171,    49,   192,  -171,   182,  -171,  -171,   190,  -171,  -171,
     131,  -171,  -171,  -171,   131,    87,  -171,   184,   182,  -171,
    -171,  -171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -153,   189,   -44,  -171,  -171,  -171,
     -16,    94,     2,  -171,  -171,  -171,  -171,   -42,  -171,  -171,
    -171,  -171,   -41,  -171,  -171,  -171,    86,  -171,  -170,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,   -28,  -171,  -171,    83,
     -89,  -103,   -40,  -171,  -171,   193,    50,  -171,  -171,   173,
      19,    81,  -171,   149,   -10,    97,  -171,  -171,   -20,  -171,
     -38,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      46,    87,    69,    88,    89,    90,    48,    91,    92,   134,
      72,    53,   178,    60,    60,    53,   150,    78,     4,    11,
     136,     3,   186,    11,   123,    11,    81,    54,    26,    73,
     203,    54,   133,    28,   206,    55,    56,    57,    32,    55,
      56,   201,    29,    58,    59,    53,    30,    58,    59,    79,
      80,   100,   101,   153,   116,   211,   124,   125,   110,   111,
      34,    54,    81,    75,    76,   150,   150,   150,   150,   150,
     110,   111,   102,     6,   177,   135,   195,    58,    59,   124,
     125,   147,    60,    11,    55,    56,    70,    60,   198,    55,
      56,    71,   196,    60,     6,   -32,    96,   148,   149,   117,
      73,   112,   113,   114,    99,   -32,   -41,   -36,    81,    81,
      81,    81,    81,    36,   154,   155,    37,    38,    39,    40,
      98,    87,   164,    88,    89,    90,   115,    91,    92,   137,
     138,    87,   174,    88,    89,    90,   118,    91,    92,   120,
     119,   176,   121,   132,    60,   130,   160,    60,   168,   166,
      87,   167,    88,    89,    90,   161,    91,    92,   104,   105,
     106,   107,   108,   169,    87,   170,    88,    89,    90,   193,
      91,    92,     5,   173,     6,   179,     7,     8,   126,   127,
     128,   185,     9,   187,    10,   209,    11,     5,    12,    13,
     171,     7,     8,   139,   140,   141,   172,     9,   -50,    10,
     199,    11,   191,    12,    13,    35,   202,    43,    44,   210,
      47,   146,    49,    50,    51,   159,    52,   163,   180,   181,
     182,   183,   184,   156,   157,   158,    97,   122,     0,    74
};

static const yytype_int16 yycheck[] =
{
      20,    45,    30,    45,    45,    45,    22,    45,    45,    98,
      27,    11,   165,    29,    30,    11,   119,    11,     3,    19,
     109,     0,   175,    19,     6,    19,    42,    27,     6,    46,
     200,    27,    12,     6,   204,    35,    36,    37,    47,    35,
      36,   194,    11,    43,    44,    11,    11,    43,    44,    43,
      44,    28,    29,    12,    70,   208,    38,    39,    38,    39,
       4,    27,    78,    21,    22,   168,   169,   170,   171,   172,
      38,    39,    49,     7,   163,   103,    27,    43,    44,    38,
      39,    27,    98,    19,    35,    36,    11,   103,   191,    35,
      36,    43,    43,   109,     7,     8,     8,    43,    44,    48,
      46,    40,    41,    42,    12,    18,     6,     7,   124,   125,
     126,   127,   128,    20,   124,   125,    23,    24,    25,    26,
      11,   165,   142,   165,   165,   165,    12,   165,   165,   110,
     111,   175,   160,   175,   175,   175,     6,   175,   175,     6,
      11,   161,     6,     6,   160,    14,    11,   163,    45,     6,
     194,    12,   194,   194,   194,    13,   194,   194,    30,    31,
      32,    33,    34,    45,   208,    45,   208,   208,   208,   189,
     208,   208,     5,    12,     7,     7,     9,    10,    40,    41,
      42,    12,    15,    12,    17,   205,    19,     5,    21,    22,
      45,     9,    10,   112,   113,   114,    45,    15,     7,    17,
       8,    19,    18,    21,    22,    16,    16,    18,    19,   207,
      21,   117,    23,    24,    25,   129,    27,   134,   168,   169,
     170,   171,   172,   126,   127,   128,    53,    78,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,     5,     7,     9,    10,    15,
      17,    19,    21,    22,    55,    57,    58,    62,    69,    74,
      77,    94,    99,   110,   112,   113,     6,   111,     6,    11,
      11,    59,    47,    63,     4,    57,    20,    23,    24,    25,
      26,    96,   109,    57,    57,    75,   110,    57,    62,    57,
      57,    57,    57,    11,    27,    35,    36,    37,    43,    44,
      62,    88,    90,    92,    93,   101,   102,   103,   104,    88,
      11,    43,    27,    46,    97,    21,    22,   100,    11,    43,
      44,    62,   105,   106,   107,   108,    56,    58,    69,    74,
      94,   112,   113,    78,    79,    95,     8,   101,    11,    12,
      28,    29,    49,    89,    30,    31,    32,    33,    34,    91,
      38,    39,    40,    41,    42,    12,    62,    48,     6,    11,
       6,     6,   105,     6,    38,    39,    40,    41,    42,    76,
      14,    80,     6,    12,    92,    88,    92,   102,   102,   103,
     103,   103,    70,    71,    73,    60,    63,    27,    43,    44,
      93,    97,    98,    12,   106,   106,   107,   107,   107,    78,
      11,    13,    86,    91,   110,    72,     6,    12,    45,    45,
      45,    45,    45,    12,    88,    87,   110,    92,    56,     7,
      98,    98,    98,    98,    98,    12,    56,    12,    61,    81,
      83,    18,    64,   110,    84,    27,    43,    68,    93,     8,
      82,    56,    16,    80,    85,    65,    80,    66,    67,   110,
      64,    56
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 78 "n10gramunopt.y"
    {slist = (SYMLIST*)malloc(sizeof(SYMLIST));slist->head = NULL;list = (DLIST*)malloc(sizeof(DLIST));first= (NODE*)malloc(sizeof(NODE));first->prev = NULL;first->next = NULL;first->scope = scope;first->occur = occur;list->head = first;}
    break;

  case 3:
#line 78 "n10gramunopt.y"
    {printf("\nScoping for the whole grammar\n");printlist(list);printf("\nSYMBOL TABLE FOR THE WHOLE GRAMMAR:\n");printsym(slist);}
    break;

  case 19:
#line 107 "n10gramunopt.y"
    {(yyval).tr = newLabel(&ln); (yyval).fal = newLabel(&ln); (yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\ngo to %s",(yyval).tr);brlb = (yyval).fal;swlb = (yyval).tr;swfal = (yyval).fal;fprintf(fp,"%s",(yyval).code);}
    break;

  case 20:
#line 107 "n10gramunopt.y"
    {SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("Varible not defined");yyerror("");exit(0);}}
    break;

  case 21:
#line 107 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 22:
#line 107 "n10gramunopt.y"
    {fprintf(fp,"\n%s:\n",swfal);lbflag = 0;addNode(list,0);}
    break;

  case 23:
#line 111 "n10gramunopt.y"
    {(yyval).addr = strdup((yyvsp[(1) - (2)]).v);var = (yyval).addr;}
    break;

  case 24:
#line 115 "n10gramunopt.y"
    {(yyval).code = (char*)malloc(sizeof(char)*200);sprintf((yyval).code,"%s%s%s%s",(yyvsp[(1) - (4)]).v,(yyvsp[(2) - (4)]).v,(yyvsp[(3) - (4)]).v,(yyvsp[(4) - (4)]).code);}
    break;

  case 25:
#line 116 "n10gramunopt.y"
    {(yyval).code = strdup("");}
    break;

  case 26:
#line 120 "n10gramunopt.y"
    {(yyval).tr = newLabel(&ln);fprintf(fp,"\n%s:",(yyval).tr);cslb[i] = (yyval).tr;i++;}
    break;

  case 27:
#line 120 "n10gramunopt.y"
    {if(lbflag == 0 ){lbflag = 1;fprintf(fp,"\n%s:",swlb);}(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"\nif %s = %s go to %s\n",var,(yyvsp[(2) - (6)]).code,cslb[--i]);fprintf(fp,"%s",(yyval).code);}
    break;

  case 29:
#line 125 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 30:
#line 125 "n10gramunopt.y"
    {(yyval).code = (yyvsp[(1) - (2)]).code;addNode(list,0);}
    break;

  case 31:
#line 126 "n10gramunopt.y"
    {(yyval).code = (yyvsp[(1) - (1)]).code;}
    break;

  case 33:
#line 131 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 34:
#line 132 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 35:
#line 133 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).addr);}
    break;

  case 36:
#line 138 "n10gramunopt.y"
    {(yyval).tr = newLabel(&ln);wltr = (yyval).tr;(yyvsp[(3) - (4)]).tr = newLabel(&ln);(yyvsp[(3) - (4)]).fal = newLabel(&ln);(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code, "if %s go to %s else go to %s\n%s",(yyvsp[(3) - (4)]).addr,(yyvsp[(3) - (4)]).tr,(yyvsp[(3) - (4)]).fal,(yyvsp[(3) - (4)]).tr);fprintf(fp,"%s",(yyval).code);brlb = (yyvsp[(3) - (4)]).fal;contlb = (yyval).tr;}
    break;

  case 37:
#line 138 "n10gramunopt.y"
    {fprintf(fp,"go to %s\n%s:",wltr,(yyvsp[(3) - (6)]).fal);}
    break;

  case 38:
#line 139 "n10gramunopt.y"
    {(yyval).tr = newLabel(&ln);wltr = (yyval).tr;(yyvsp[(3) - (4)]).tr = newLabel(&ln);(yyvsp[(3) - (4)]).fal = newLabel(&ln);(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code, "if %s go to %s else go to %s\n%s",(yyvsp[(3) - (4)]).addr,(yyvsp[(3) - (4)]).tr,(yyvsp[(3) - (4)]).fal,(yyvsp[(3) - (4)]).tr);fprintf(fp,"%s",(yyval).code);brlb = (yyvsp[(3) - (4)]).fal;contlb = (yyval).tr;}
    break;

  case 39:
#line 139 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 40:
#line 139 "n10gramunopt.y"
    {fprintf(fp,"go to %s\n%s:",wltr,(yyvsp[(3) - (7)]).fal);addNode(list,0);}
    break;

  case 41:
#line 140 "n10gramunopt.y"
    {(yyval).tr = newLabel(&ln);wltr = (yyval).tr;(yyvsp[(3) - (4)]).tr = newLabel(&ln);(yyvsp[(3) - (4)]).fal = newLabel(&ln);(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code, "if %s go to %s else go to %s\n%s",(yyvsp[(3) - (4)]).addr,(yyvsp[(3) - (4)]).tr,(yyvsp[(3) - (4)]).fal,(yyvsp[(3) - (4)]).tr);fprintf(fp,"%s",(yyval).code);brlb = (yyvsp[(3) - (4)]).fal;contlb = (yyval).tr;}
    break;

  case 42:
#line 140 "n10gramunopt.y"
    {fprintf(fp,"go to %s\n%s:",wltr,(yyvsp[(3) - (6)]).fal);}
    break;

  case 44:
#line 145 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 45:
#line 145 "n10gramunopt.y"
    {addNode(list,0);}
    break;

  case 47:
#line 148 "n10gramunopt.y"
    {(yyvsp[(3) - (4)]).tr = newLabel(&ln); (yyvsp[(3) - (4)]).fal = newLabel(&ln);(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"if %s go to %s else goto %s\n%s:",(yyvsp[(3) - (4)]).addr,(yyvsp[(3) - (4)]).tr,(yyvsp[(3) - (4)]).fal,(yyvsp[(3) - (4)]).tr);printf("%s",(yyval).code);(yyval).next = (yyvsp[(3) - (4)]).fal;}
    break;

  case 48:
#line 152 "n10gramunopt.y"
    {(yyval).tr = (yyvsp[(-1) - (0)]).next;printf("\n%s:",(yyvsp[(-1) - (0)]).next);}
    break;

  case 50:
#line 156 "n10gramunopt.y"
    {(yyvsp[(3) - (4)]).tr = newLabel(&ln); (yyvsp[(3) - (4)]).fal = newLabel(&ln);(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"if %s go to %s else goto %s\n%s:",(yyvsp[(3) - (4)]).addr,(yyvsp[(3) - (4)]).tr,(yyvsp[(3) - (4)]).fal,(yyvsp[(3) - (4)]).tr);printf("%s",(yyval).code);(yyval).next = (yyvsp[(3) - (4)]).fal;}
    break;

  case 51:
#line 156 "n10gramunopt.y"
    {printf("\n%s:",(yyvsp[(3) - (6)]).fal);}
    break;

  case 53:
#line 157 "n10gramunopt.y"
    {(yyvsp[(3) - (4)]).tr = newLabel(&ln); (yyvsp[(3) - (4)]).fal = newLabel(&ln);(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"if %s go to %s else goto %s\n%s:",(yyvsp[(3) - (4)]).addr,(yyvsp[(3) - (4)]).tr,(yyvsp[(3) - (4)]).fal,(yyvsp[(3) - (4)]).tr);printf("%s",(yyval).code);(yyval).next = (yyvsp[(3) - (4)]).fal;}
    break;

  case 54:
#line 157 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 55:
#line 157 "n10gramunopt.y"
    {addNode(list,0);printf("%s:",(yyvsp[(3) - (7)]).fal);}
    break;

  case 58:
#line 162 "n10gramunopt.y"
    {(yyval).next = newLabel(&ln);printf("\n%s:",(yyval).next);}
    break;

  case 59:
#line 163 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 60:
#line 163 "n10gramunopt.y"
    {(yyval).next = newLabel(&ln);printf("\n%s:",(yyval).next);addNode(list,0);}
    break;

  case 61:
#line 167 "n10gramunopt.y"
    {(yyval).code = (yyvsp[(1) - (1)]).code;(yyval).addr = (yyvsp[(1) - (1)]).addr;}
    break;

  case 62:
#line 168 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn); (yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s %s %s\n",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(2) - (3)]).code,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 63:
#line 172 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 64:
#line 173 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 65:
#line 174 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 67:
#line 180 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn); (yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s %s %s\n",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(2) - (3)]).code,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 68:
#line 181 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;}
    break;

  case 69:
#line 185 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 70:
#line 186 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 71:
#line 187 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 72:
#line 188 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 73:
#line 189 "n10gramunopt.y"
    {(yyval).code = strdup("=");}
    break;

  case 74:
#line 193 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr; (yyval).code = strdup(" ");SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("%s : Varible not defined",var);yyerror("");exit(0);}}
    break;

  case 75:
#line 194 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr; (yyval).code = strdup(" ");}
    break;

  case 76:
#line 195 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr; (yyval).code = strdup(" ");}
    break;

  case 77:
#line 199 "n10gramunopt.y"
    {(yyval).addr = strdup("TRUE");}
    break;

  case 78:
#line 200 "n10gramunopt.y"
    {(yyval).addr = strdup("FALSE");}
    break;

  case 79:
#line 204 "n10gramunopt.y"
    {if(!strcmp((yyvsp[(2) - (4)]).code,"=")){(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s",(yyvsp[(1) - (4)]).addr,(yyvsp[(3) - (4)]).addr);if(!strcmp((yyvsp[(3) - (4)]).type,"int")){char temp[50];sprintf(temp,"%d",(yyvsp[(3) - (4)]).i);addVar((yyvsp[(1) - (4)]).addr,temp,(yyvsp[(3) - (4)]).type,list->head->scope,list->head->occur,slist);}else{char temp[50];sprintf(temp,"%f",(yyvsp[(3) - (4)]).f);addVar((yyvsp[(1) - (4)]).addr,temp,(yyvsp[(3) - (4)]).type,list->head->scope,list->head->occur,slist);}}else{(yyval).addr = newTemp(&tn); (yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s %s %s\n%s = %s",(yyval).addr,(yyvsp[(1) - (4)]).addr,(yyvsp[(2) - (4)]).code,(yyvsp[(3) - (4)]).addr,(yyvsp[(1) - (4)]).addr,(yyval).addr);fprintf(fp,"\n%s",(yyval).code);}fprintf(fp,"\n%s",(yyval).code);if(!strcmp((yyvsp[(2) - (4)]).code,"+")){}else if(!strcmp((yyvsp[(2) - (4)]).code,"-")){}else if(!strcmp((yyvsp[(2) - (4)]).code,"/")){}else if(!strcmp((yyvsp[(2) - (4)]).code,"*")){}}
    break;

  case 80:
#line 205 "n10gramunopt.y"
    {(yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s",(yyvsp[(1) - (4)]).addr,(yyvsp[(3) - (4)]).v);fprintf(fp,"\n%s",(yyval).code);char *ty = strdup("string");addVar((yyvsp[(1) - (4)]).addr,(yyvsp[(3) - (4)]).v,ty,list->head->scope,list->head->occur,slist);}
    break;

  case 81:
#line 206 "n10gramunopt.y"
    {SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("%s : Varible not defined",var);yyerror("");exit(0);}}
    break;

  case 82:
#line 206 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn); (yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s %s 1\n%s = %s",(yyval).addr,(yyvsp[(2) - (4)]).addr,(yyvsp[(1) - (4)]).code,(yyvsp[(2) - (4)]).addr,(yyval).addr);fprintf(fp,"\n%s",(yyval).code);SYMNODE *new = lookup(var,slist,list);if(!strcmp((yyvsp[(1) - (4)]).code,"+")){char temp[50];sprintf(temp,"%d",atoi(new->val)+1);addVar(var,temp,new->type,new->scope,new->occur,slist);}else{char temp[50];sprintf(temp,"%d",atoi(new->val)-1);addVar(var,temp,new->type,new->scope,new->occur,slist);}}
    break;

  case 83:
#line 207 "n10gramunopt.y"
    {SYMNODE *new = lookup(var,slist,list); if(new == NULL){printf("%s : Varible not defined",var);yyerror("");exit(0);}}
    break;

  case 84:
#line 207 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn); (yyval).code = (char*)malloc(sizeof(char)*100);sprintf((yyval).code,"%s = %s %s 1\n%s = %s",(yyval).addr,(yyvsp[(1) - (4)]).addr,(yyvsp[(2) - (4)]).code,(yyvsp[(1) - (4)]).addr,(yyval).addr);fprintf(fp,"\n%s",(yyval).code);SYMNODE *new = lookup(var,slist,list);if(!strcmp((yyvsp[(2) - (4)]).code,"+")){char temp[50];sprintf(temp,"%d",atoi(new->val)+1);addVar(var,temp,new->type,new->scope,new->occur,slist);}else{char temp[50];sprintf(temp,"%d",atoi(new->val)-1);addVar(var,temp,new->type,new->scope,new->occur,slist);}}
    break;

  case 93:
#line 225 "n10gramunopt.y"
    {(yyval).code = strdup("+");}
    break;

  case 94:
#line 226 "n10gramunopt.y"
    {(yyval).code = strdup("-");}
    break;

  case 95:
#line 230 "n10gramunopt.y"
    {(yyval).code = strdup("+");}
    break;

  case 96:
#line 231 "n10gramunopt.y"
    {(yyval).code = strdup("-");}
    break;

  case 97:
#line 236 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s + %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 98:
#line 237 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s - %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 99:
#line 238 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = (yyvsp[(1) - (1)]).code;}
    break;

  case 100:
#line 242 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s * %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 101:
#line 243 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s / %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 102:
#line 244 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s mod %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);}
    break;

  case 103:
#line 245 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = (yyvsp[(1) - (1)]).code;}
    break;

  case 104:
#line 250 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = (yyvsp[(1) - (1)]).code;}
    break;

  case 105:
#line 251 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(2) - (3)]).addr;(yyval).code = (yyvsp[(2) - (3)]).code;}
    break;

  case 106:
#line 256 "n10gramunopt.y"
    {(yyval).addr = strdup((yyvsp[(1) - (1)]).v); (yyval).code = strdup("");}
    break;

  case 107:
#line 257 "n10gramunopt.y"
    {(yyval).addr = strdup((yyvsp[(1) - (1)]).v); (yyval).code = strdup("");}
    break;

  case 108:
#line 258 "n10gramunopt.y"
    {(yyval).addr = strdup((yyvsp[(1) - (1)]).v); (yyval).code = strdup("");}
    break;

  case 109:
#line 262 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s + %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);if(!strcmp((yyvsp[(1) - (3)]).type,"int")){(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).i = (yyvsp[(1) - (3)]).i + (yyvsp[(3) - (3)]).i; }else{(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).f = (yyvsp[(1) - (3)]).f + (yyvsp[(3) - (3)]).f;}}
    break;

  case 110:
#line 263 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s - %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);if(!strcmp((yyvsp[(1) - (3)]).type,"int")){(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).i = (yyvsp[(1) - (3)]).i - (yyvsp[(3) - (3)]).i;}else{(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).f = (yyvsp[(1) - (3)]).f - (yyvsp[(3) - (3)]).f;}}
    break;

  case 111:
#line 264 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = (yyvsp[(1) - (1)]).code;if(!strcmp((yyvsp[(1) - (1)]).type,"int")){(yyval).type = (yyvsp[(1) - (1)]).type;(yyval).i = (yyvsp[(1) - (1)]).i;}else{(yyval).type = (yyvsp[(1) - (1)]).type;(yyval).f = (yyvsp[(1) - (1)]).f;}}
    break;

  case 112:
#line 268 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s * %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);if(!strcmp((yyvsp[(1) - (3)]).type,"int")){(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).i = (yyvsp[(1) - (3)]).i * (yyvsp[(3) - (3)]).i;}else{(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).f = (yyvsp[(1) - (3)]).f*(yyvsp[(1) - (3)]).f;}}
    break;

  case 113:
#line 269 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s / %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);if(!strcmp((yyvsp[(1) - (3)]).type,"int")){(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).i = (yyvsp[(1) - (3)]).i / (yyvsp[(3) - (3)]).i;}else{(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).f = (yyvsp[(1) - (3)]).f / (yyvsp[(3) - (3)]).f;}}
    break;

  case 114:
#line 270 "n10gramunopt.y"
    {(yyval).addr = newTemp(&tn);(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\n%s = %s mod %s",(yyval).addr,(yyvsp[(1) - (3)]).addr,(yyvsp[(3) - (3)]).addr);fprintf(fp,"%s",(yyval).code);if(!strcmp((yyvsp[(1) - (3)]).type,"int")){(yyval).type = (yyvsp[(1) - (3)]).type;(yyval).i = (yyvsp[(1) - (3)]).i % (yyvsp[(3) - (3)]).i;}else{printf("\nMod not allowed for floats");}}
    break;

  case 115:
#line 271 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = (yyvsp[(1) - (1)]).code;if(!strcmp((yyvsp[(1) - (1)]).type,"int")){(yyval).type = (yyvsp[(1) - (1)]).type;(yyval).i = (yyvsp[(1) - (1)]).i;}else{(yyval).type = (yyvsp[(1) - (1)]).type;(yyval).f = (yyvsp[(1) - (1)]).f;}}
    break;

  case 116:
#line 276 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = (yyvsp[(1) - (1)]).code;if(!strcmp((yyvsp[(1) - (1)]).type,"int")){(yyval).type = (yyvsp[(1) - (1)]).type;(yyval).i = (yyvsp[(1) - (1)]).i;}else{(yyval).type = (yyvsp[(1) - (1)]).type;(yyval).f = (yyvsp[(1) - (1)]).f;}}
    break;

  case 117:
#line 277 "n10gramunopt.y"
    {(yyval).addr = (yyvsp[(2) - (3)]).addr;(yyval).code = (yyvsp[(2) - (3)]).code;if(!strcmp((yyvsp[(2) - (3)]).type,"int")){(yyval).type = (yyvsp[(2) - (3)]).type;(yyval).i = (yyvsp[(2) - (3)]).i;}else{(yyval).type = (yyvsp[(2) - (3)]).type;(yyval).f = (yyvsp[(2) - (3)]).f;}}
    break;

  case 118:
#line 278 "n10gramunopt.y"
    {SYMNODE *new = lookup(var,slist,list);(yyval).addr = (yyvsp[(1) - (1)]).addr;(yyval).code = strdup("");if(new == NULL){printf("%s not defined",var);yyerror("");}if(!strcmp(new->type,"int")){(yyval).type = strdup("int");(yyval).i = atoi(new->val);}else{(yyval).type = strdup("float");(yyval).f = atof(new->val);}}
    break;

  case 119:
#line 283 "n10gramunopt.y"
    {(yyval).addr = strdup((yyvsp[(1) - (1)]).v); (yyval).code = strdup("");(yyval).type = strdup("int");(yyval).i = atoi((yyvsp[(1) - (1)]).v);}
    break;

  case 120:
#line 284 "n10gramunopt.y"
    {(yyval).addr = strdup((yyvsp[(1) - (1)]).v); (yyval).code = strdup("");(yyval).type = strdup("float");(yyval).f = atof((yyvsp[(1) - (1)]).v);}
    break;

  case 121:
#line 288 "n10gramunopt.y"
    {(yyval).code = strdup((yyvsp[(1) - (1)]).v);}
    break;

  case 122:
#line 289 "n10gramunopt.y"
    {(yyval).code = strdup("+");}
    break;

  case 123:
#line 290 "n10gramunopt.y"
    {(yyval).code = strdup("-");}
    break;

  case 124:
#line 291 "n10gramunopt.y"
    {(yyval).code = strdup("*");}
    break;

  case 125:
#line 292 "n10gramunopt.y"
    {(yyval).code = strdup("/");}
    break;

  case 126:
#line 298 "n10gramunopt.y"
    {addNode(list,1);}
    break;

  case 127:
#line 298 "n10gramunopt.y"
    {(yyval).code = (yyvsp[(1) - (4)]).code;addNode(list,0);}
    break;

  case 128:
#line 302 "n10gramunopt.y"
    {(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\ngo to %s",brlb);printf("%s",(yyval).code);}
    break;

  case 129:
#line 306 "n10gramunopt.y"
    {(yyval).code = (char*)malloc(sizeof(char)*100); sprintf((yyval).code,"\ngo to %s",contlb);printf("%s",(yyval).code);}
    break;


/* Line 1267 of yacc.c.  */
#line 2162 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 310 "n10gramunopt.y"

// if-else can switches be an empty block? switchconstant can't have empty singlestatement T_STRING strings default case
char* newLabel(int *ln)
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"L%d",*ln);
	//printf("%s",s);
	(*ln)++;
	return s;
}
char* newTemp(int *tn)
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"T%d",*tn);
	//printf("%s",s);
	(*tn)++;
	return s;
}
void addNode(DLIST *list,int open)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->next = NULL;
	temp->prev = list->head;
	
	if(open == 1)
	{
		NODE *iter = list->head;
		int flag =0; 
		temp->scope = ++scope;
		while(iter!=NULL)
		{
			if(iter->scope == scope)
			{
				temp->occur = iter->occur+1;
				flag = 1;
			}
			if(flag == 1)
				break;
			iter = iter->prev;
		}
		if(flag == 0)
		{
			temp->occur = 0 ;
		}
	}
	else
	{
		NODE *iter = list->head;
		--scope;
		int flag =0;
		temp->scope = scope;
		while(iter!=NULL)
		{
			if(iter->scope == scope)
			{
				temp->occur = iter->occur;
				flag = 1;
			}
			if(flag ==1 )
				break;
			iter = iter->prev;
		}
		if(flag == 0)
		{
			temp->occur = 0;
		}
	}
	list->head = temp;
}
void printlist(DLIST *list)
{
	NODE *temp = list->head;
	
	while(temp!=NULL)
	{
		printf("\n");
		printf("%d%d<-",temp->scope,temp->occur);
		temp = temp->prev;

	}
}
void addVar(char *name,char *val,char *type,int scope,int occur,SYMLIST *slist)
{
	SYMNODE *temp = (SYMNODE*)malloc(sizeof(SYMNODE));
	temp->next = NULL;
	temp->prev = slist->head;
	temp->name = strdup(name);
	temp->type = strdup(type);
	temp->val = strdup(val);
	temp->scope = scope;
	temp->occur = occur;
	slist->head = temp;
}
void printsym(SYMLIST *slist)
{
	SYMNODE *temp = slist->head;
	while(temp!= NULL)
	{
		printf("\n");
		printf("%s,%s,%s,%d%d<-\n",temp->name,temp->val,temp->type,temp->scope,temp->occur);
		temp = temp->prev;
	}
}
SYMNODE* varsearch(char *name,SYMNODE *stemp,NODE *temp)
{
	SYMNODE *iter = stemp;
	while(iter!=NULL)
	{
		if(!strcmp(name,iter->name) && iter->scope == temp->scope && iter->occur == temp->occur)
			return iter;
		iter = iter->prev;
	}
	return NULL;
}
SYMNODE* lookup(char *name,SYMLIST *slist, DLIST *list)
{
	NODE *temp = list->head;
	SYMNODE *stemp = slist->head;
	int errflag = 0;
	while(errflag == 0 )
	{
		SYMNODE* res = varsearch(name,stemp,temp);
		if(res != NULL)
			return res;
		if(temp->scope == 0)
		{
			errflag = 1;
			return NULL;
		}
		else
		{
			NODE *iter = temp;
			while(iter->scope!=temp->scope-1)
				iter = iter->prev;
			temp = iter;
		}
	}
}
int main(int argc, char* argv[])
{
/*TABLE *s=(TABLE*)malloc(sizeof(TABLE));
	s->head = NULL;
	s->entries = 0;*/
	yyin = fopen(argv[1], "r");
	fp = stdout;
	int flag = 1;
	if(!yyparse())
			{printf("Parsing successful \n");flag = 0;}
		else
			{printf("Unsuccessful \n");}
	return flag;
}

