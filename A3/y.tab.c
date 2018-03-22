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
     IF = 258,
     ELSE = 259,
     INT = 260,
     RETURN = 261,
     VOID = 262,
     WHILE = 263,
     ID = 264,
     NUM = 265,
     LET = 266,
     GET = 267,
     EQ = 268,
     NQ = 269,
     ASSIGN = 270,
     LT = 271,
     GT = 272,
     PLUS = 273,
     MINUS = 274,
     TIMES = 275,
     OVER = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRKT = 279,
     RBRKT = 280,
     LBRC = 281,
     RBRC = 282,
     SEMI = 283,
     COMMA = 284,
     ERROR = 285
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define INT 260
#define RETURN 261
#define VOID 262
#define WHILE 263
#define ID 264
#define NUM 265
#define LET 266
#define GET 267
#define EQ 268
#define NQ 269
#define ASSIGN 270
#define LT 271
#define GT 272
#define PLUS 273
#define MINUS 274
#define TIMES 275
#define OVER 276
#define LPAREN 277
#define RPAREN 278
#define LBRKT 279
#define RBRKT 280
#define LBRC 281
#define RBRC 282
#define SEMI 283
#define COMMA 284
#define ERROR 285




/* Copy the first part of user declarations.  */
#line 6 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName;
static int savedLineNo;
static TreeNode * savedTree; /* stores syntax tree for later return */
static int savedNumber;
static char * savedName;
static char * type;

extern int yychar;

extern int yyparse ();

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);

  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void) {
  yyparse();
  return savedTree;
}



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      22,    29,    30,    38,    40,    42,    44,    46,    50,    52,
      55,    60,    65,    68,    69,    72,    73,    75,    77,    79,
      81,    83,    86,    88,    94,   102,   108,   111,   115,   119,
     123,   127,   131,   135,   139,   143,   147,   151,   155,   159,
     163,   165,   167,   169,   171,   172,   178,   179,   185,   187,
     188,   192
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    -1,    33,    34,    -1,    34,    -1,
      37,    -1,    38,    -1,     9,    -1,    10,    -1,    40,    35,
      28,    -1,    40,    35,    24,    36,    25,    28,    -1,    -1,
      40,    35,    39,    22,    41,    23,    44,    -1,     5,    -1,
       7,    -1,    42,    -1,     7,    -1,    42,    29,    43,    -1,
      43,    -1,    40,    35,    -1,    40,    35,    24,    25,    -1,
      26,    45,    46,    27,    -1,    45,    37,    -1,    -1,    46,
      47,    -1,    -1,    48,    -1,    44,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    28,    -1,    28,    -1,     3,    22,
      52,    23,    47,    -1,     3,    22,    52,    23,    47,     4,
      47,    -1,     8,    22,    52,    23,    47,    -1,     6,    28,
      -1,     6,    52,    28,    -1,    52,    15,    52,    -1,    52,
      11,    52,    -1,    52,    16,    52,    -1,    52,    17,    52,
      -1,    52,    12,    52,    -1,    52,    13,    52,    -1,    52,
      14,    52,    -1,    52,    18,    52,    -1,    52,    19,    52,
      -1,    52,    20,    52,    -1,    52,    21,    52,    -1,    22,
      52,    23,    -1,    55,    -1,    53,    -1,    36,    -1,    35,
      -1,    -1,    35,    54,    24,    52,    25,    -1,    -1,    35,
      56,    22,    57,    23,    -1,    58,    -1,    -1,    58,    29,
      52,    -1,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    61,    73,    75,    76,    78,    84,    89,
      95,   104,   103,   115,   120,   126,   127,   129,   138,   139,
     148,   158,   164,   173,   175,   185,   187,   188,   189,   190,
     191,   193,   194,   196,   202,   209,   215,   219,   224,   230,
     236,   242,   248,   254,   260,   266,   272,   278,   284,   290,
     291,   292,   293,   298,   303,   302,   313,   312,   322,   323,
     325,   334
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "INT", "RETURN", "VOID",
  "WHILE", "ID", "NUM", "LET", "GET", "EQ", "NQ", "ASSIGN", "LT", "GT",
  "PLUS", "MINUS", "TIMES", "OVER", "LPAREN", "RPAREN", "LBRKT", "RBRKT",
  "LBRC", "RBRC", "SEMI", "COMMA", "ERROR", "$accept", "program",
  "dec_list", "dec", "saveName", "saveNumber", "var_dec", "fun_dec", "@1",
  "type_spec", "params", "param_list", "param", "comp_stmt", "local_decs",
  "stmt_list", "stmt", "exp_stmt", "sel_stmt", "iter_stmt", "ret_stmt",
  "exp", "var", "@2", "call", "@3", "args", "arg_list", 0
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
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    36,    37,
      37,    39,    38,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    54,    53,    56,    55,    57,    57,
      58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       6,     0,     7,     1,     1,     1,     1,     3,     1,     2,
       4,     4,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     0,     5,     0,     5,     1,     0,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    14,     0,     2,     4,     5,     6,     0,     1,
       3,     7,    11,     0,     9,     0,     8,     0,     0,     0,
      14,     0,     0,    15,    18,    10,    19,     0,     0,     0,
      23,    12,    17,    20,    25,    22,     0,     0,     0,     0,
       0,     0,     0,    21,    32,    53,    52,    27,    24,    26,
      28,    29,    30,     0,    51,    50,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    37,     0,    49,     0,
      59,    39,    42,    43,    44,    38,    40,    41,    45,    46,
      47,    48,     0,     0,     0,    61,     0,    58,    33,    35,
      55,    57,     0,     0,    60,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    45,    46,     6,     7,    15,     8,
      22,    23,    24,    47,    34,    37,    48,    49,    50,    51,
      52,    53,    54,    61,    55,    62,    96,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -90
static const yytype_int16 yypact[] =
{
       8,   -90,   -90,     9,     8,   -90,   -90,   -90,     1,   -90,
     -90,   -90,   -16,    11,   -90,     0,   -90,    13,    29,    17,
      30,     1,    44,    32,   -90,   -90,    34,    45,     8,    48,
     -90,   -90,   -90,   -90,     8,   -90,     1,    38,   -16,    65,
      41,    66,    -4,   -90,   -90,    35,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,    64,   -90,   -90,    -4,   -90,    82,    -4,
     115,    62,    67,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,   -90,   128,   -90,   141,   -90,    -4,
      -4,   154,   154,   154,   154,   165,   154,   154,    22,    22,
      55,    55,    46,    46,   100,   165,    68,    61,   101,   -90,
     -90,   -90,    -4,    46,   165,   -90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   102,    -1,    91,    73,   -90,   -90,   -17,
     -90,   -90,    80,    95,   -90,   -90,   -89,   -90,   -90,   -90,
     -90,   -40,   -90,   -90,   -90,   -90,   -90,   -90
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int8 yytable[] =
{
      58,    21,    60,    98,    99,    11,    16,    12,    13,     9,
      11,    21,    14,     1,   105,     2,    75,    36,    42,    77,
      26,    16,    18,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     1,    38,    20,    67,    19,    94,
      95,    39,    72,    73,    40,    25,    41,    11,    16,    39,
      11,    16,    40,   -16,    41,    11,    16,   -56,    29,   -54,
      42,    28,   104,    42,    30,    43,    44,    27,    42,    57,
      67,    30,    30,    33,    44,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    79,    56,    59,    80,
     102,   101,    74,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    17,   103,    10,    35,    32,     0,
      76,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    31,     0,     0,   100,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    78,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    92,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    93,   -57,   -57,   -57,   -57,    67,
     -57,   -57,    70,    71,    72,    73,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73
};

static const yytype_int8 yycheck[] =
{
      40,    18,    42,    92,    93,     9,    10,     8,    24,     0,
       9,    28,    28,     5,   103,     7,    56,    34,    22,    59,
      21,    10,    22,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     5,    36,     7,    15,    25,    79,
      80,     3,    20,    21,     6,    28,     8,     9,    10,     3,
       9,    10,     6,    23,     8,     9,    10,    22,    24,    24,
      22,    29,   102,    22,    26,    27,    28,    23,    22,    28,
      15,    26,    26,    25,    28,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    24,    22,    22,    22,
      29,    23,    28,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    13,     4,     4,    34,    28,    -1,
      28,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    27,    -1,    -1,    25,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    32,    33,    34,    37,    38,    40,     0,
      34,     9,    35,    24,    28,    39,    10,    36,    22,    25,
       7,    40,    41,    42,    43,    28,    35,    23,    29,    24,
      26,    44,    43,    25,    45,    37,    40,    46,    35,     3,
       6,     8,    22,    27,    28,    35,    36,    44,    47,    48,
      49,    50,    51,    52,    53,    55,    22,    28,    52,    22,
      52,    54,    56,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    28,    52,    28,    52,    23,    24,
      22,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    23,    23,    52,    52,    57,    58,    47,    47,
      25,    23,    29,     4,    52,    47
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
#line 59 "cminus.y"
    { savedTree = (yyvsp[(1) - (1)]);}
    break;

  case 3:
#line 62 "cminus.y"
    { YYSTYPE tree = (yyvsp[(1) - (2)]);
                   if(tree != NULL){
                     while(tree->sibling != NULL){
                       tree = tree->sibling;
                     }
                     tree->sibling = (yyvsp[(2) - (2)]);
                     (yyval) = (yyvsp[(1) - (2)]);
                   }else{
                      (yyval) = (yyvsp[(2) - (2)]);
                   }
                 }
    break;

  case 4:
#line 73 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 5:
#line 75 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 6:
#line 76 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 7:
#line 79 "cminus.y"
    { (yyval) = newExpNode(IdK);
                    savedName = copyString(tokenString);
                    (yyval)->attr.name = savedName;
                  }
    break;

  case 8:
#line 85 "cminus.y"
    {savedNumber = atoi(tokenString);
                    savedLineNo = lineno;
                  }
    break;

  case 9:
#line 90 "cminus.y"
    {   (yyval) = newDecNode(VarK);
                      (yyval)->child[0] = (yyvsp[(1) - (3)]);
                      (yyval)->lineno = lineno;
                      (yyval)->attr.name = savedName;
                  }
    break;

  case 10:
#line 96 "cminus.y"
    {   (yyval) = newDecNode(ArrK);
                      (yyval)->child[0] = (yyvsp[(1) - (6)]);
                      (yyval)->lineno = lineno;
                      (yyval)->attr.arr.name = savedName;
                      (yyval)->attr.arr.size = savedNumber;
                  }
    break;

  case 11:
#line 104 "cminus.y"
    { (yyval) = newDecNode(FuncK);
                    (yyval)->lineno = lineno;
                    (yyval)->child[0]=(yyvsp[(1) - (2)]);
                    (yyval)->attr.name = savedName;
                  }
    break;

  case 12:
#line 110 "cminus.y"
    { (yyval) = (yyvsp[(3) - (7)]);
                   (yyval)->child[1] = (yyvsp[(5) - (7)]);
                   (yyval)->child[2] = (yyvsp[(7) - (7)]);
                  }
    break;

  case 13:
#line 116 "cminus.y"
    {   (yyval) = newTypeNode(TypeNameK);
                    (yyval)->attr.type = INT;
                    savedLineNo = lineno;
                }
    break;

  case 14:
#line 121 "cminus.y"
    {   (yyval) = newTypeNode(TypeNameK);
                    (yyval)->attr.type = VOID;
                    savedLineNo = lineno;
                }
    break;

  case 15:
#line 126 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 17:
#line 130 "cminus.y"
    { YYSTYPE tree = (yyvsp[(1) - (3)]);
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree->sibling = (yyvsp[(3) - (3)]);
                     (yyval) = (yyvsp[(1) - (3)]); }
                    else (yyval) = (yyvsp[(3) - (3)]);
                 }
    break;

  case 18:
#line 138 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 19:
#line 140 "cminus.y"
    { if(type == "void"){
                     yyerror("declare variable as void");
                   }else{
                     (yyval) = newParamNode(NonArrParamK);
                     (yyval)->child[0] = (yyvsp[(1) - (2)]);
                     (yyval)->attr.name = savedName;
                   }
                 }
    break;

  case 20:
#line 149 "cminus.y"
    { if(type == "void"){
                     yyerror("declare parameter as void");
                   }else{
                     (yyval) = newParamNode(ArrParamK);
                     (yyval)->child[0] = (yyvsp[(1) - (4)]);
                     (yyval)->attr.name = savedName;
                   }
                 }
    break;

  case 21:
#line 159 "cminus.y"
    { (yyval) = newStmtNode(CompK);
                   (yyval)->child[0] = (yyvsp[(2) - (4)]);
                   (yyval)->child[1] = (yyvsp[(3) - (4)]);
                 }
    break;

  case 22:
#line 165 "cminus.y"
    { YYSTYPE tree = (yyvsp[(1) - (2)]);
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree->sibling = (yyvsp[(2) - (2)]);
                     (yyval) = (yyvsp[(1) - (2)]); }
                     else (yyval) = (yyvsp[(2) - (2)]);
                 }
    break;

  case 23:
#line 173 "cminus.y"
    { (yyval) = NULL; }
    break;

  case 24:
#line 176 "cminus.y"
    { YYSTYPE tree = (yyvsp[(1) - (2)]);
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree->sibling = (yyvsp[(2) - (2)]);
                     (yyval) = (yyvsp[(1) - (2)]);
                    }
                     else (yyval) = (yyvsp[(2) - (2)]);
                  }
    break;

  case 25:
#line 185 "cminus.y"
    { (yyval) = NULL; }
    break;

  case 26:
#line 187 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 27:
#line 188 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 28:
#line 189 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 29:
#line 190 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 30:
#line 191 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 31:
#line 193 "cminus.y"
    { (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 32:
#line 194 "cminus.y"
    { (yyval) = NULL; }
    break;

  case 33:
#line 197 "cminus.y"
    { (yyval) = newStmtNode(IfK);
                   (yyval)->child[0] = (yyvsp[(3) - (5)]);
                   (yyval)->child[1] = (yyvsp[(5) - (5)]);
                   (yyval)->child[2] = NULL;
                 }
    break;

  case 34:
#line 203 "cminus.y"
    { (yyval) = newStmtNode(IfK);
                   (yyval)->child[0] = (yyvsp[(3) - (7)]);
                   (yyval)->child[1] = (yyvsp[(5) - (7)]);
                   (yyval)->child[2] = (yyvsp[(7) - (7)]);
                 }
    break;

  case 35:
#line 210 "cminus.y"
    { (yyval) = newStmtNode(WhileK);
                   (yyval)->child[0] = (yyvsp[(3) - (5)]);
                   (yyval)->child[1] = (yyvsp[(5) - (5)]);
                 }
    break;

  case 36:
#line 216 "cminus.y"
    { (yyval) = newStmtNode(ReturnK);
                   (yyval)->child[0] = NULL;
                 }
    break;

  case 37:
#line 220 "cminus.y"
    { (yyval) = newStmtNode(ReturnK);
                   (yyval)->child[0] = (yyvsp[(2) - (3)]);
                 }
    break;

  case 38:
#line 225 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = ASSIGN;
                 }
    break;

  case 39:
#line 231 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = LET;
                 }
    break;

  case 40:
#line 237 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = LT;
                 }
    break;

  case 41:
#line 243 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = GT;
                 }
    break;

  case 42:
#line 249 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = GET;
                 }
    break;

  case 43:
#line 255 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = EQ;
                 }
    break;

  case 44:
#line 261 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = NQ;
                 }
    break;

  case 45:
#line 267 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = PLUS;
                 }
    break;

  case 46:
#line 273 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = MINUS;
                 }
    break;

  case 47:
#line 279 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = TIMES;
                 }
    break;

  case 48:
#line 285 "cminus.y"
    { (yyval) = newExpNode(OpK);
                   (yyval)->child[0] = (yyvsp[(1) - (3)]);
                   (yyval)->child[1] = (yyvsp[(3) - (3)]);
                   (yyval)->attr.op = OVER;
                 }
    break;

  case 49:
#line 290 "cminus.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 50:
#line 291 "cminus.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 51:
#line 292 "cminus.y"
    {(yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 52:
#line 294 "cminus.y"
    { (yyval) = newExpNode(ConstK);
                   (yyval)->attr.val = atoi(tokenString);
                 }
    break;

  case 53:
#line 299 "cminus.y"
    { //printf("in saveName\n");
                   (yyval)->attr.name = savedName;
                 }
    break;

  case 54:
#line 303 "cminus.y"
    { (yyval) = newExpNode(ArrIdK);
                 //printf("after new ArrIdK\n");
                   (yyval)->attr.name = savedName;
                 }
    break;

  case 55:
#line 308 "cminus.y"
    { (yyval)->child[0] = (yyvsp[(4) - (5)]);
                 //printf("back here\n");
                 }
    break;

  case 56:
#line 313 "cminus.y"
    {
                  (yyval) = newExpNode(CallK);
                    (yyval)->attr.name = savedName;
                  }
    break;

  case 57:
#line 318 "cminus.y"
    {(yyval)=(yyvsp[(2) - (5)]);
                 (yyval)->child[0] = (yyvsp[(4) - (5)]);
                 }
    break;

  case 58:
#line 322 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 59:
#line 323 "cminus.y"
    { (yyval) = NULL; }
    break;

  case 60:
#line 326 "cminus.y"
    { YYSTYPE tree = (yyvsp[(1) - (3)]);
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree-> sibling = (yyvsp[(3) - (3)]);
                     (yyval) = (yyvsp[(1) - (3)]); }
                     else (yyval) = (yyvsp[(3) - (3)]);
                 }
    break;

  case 61:
#line 334 "cminus.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;


/* Line 1267 of yacc.c.  */
#line 1962 "y.tab.c"
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


#line 336 "cminus.y"

