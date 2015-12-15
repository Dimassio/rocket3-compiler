/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "miniJava.y"

#include <iostream>
#include "Common.h"

extern "C" int yylex();
extern int yylineno;

void yyerror( CProgram*& root, const char* );

/* Line 371 of yacc.c  */
#line 78 "miniJava.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "miniJava.tab.hpp".  */
#ifndef YY_YY_MINIJAVA_TAB_HPP_INCLUDED
# define YY_YY_MINIJAVA_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 11 "miniJava.y"
 #include "Common.h"
#include "CMiniJException.h"
#include <string>


/* Line 387 of yacc.c  */
#line 116 "miniJava.tab.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     NUMBER = 259,
     ID = 260,
     CLASS = 261,
     EXTENDS = 262,
     PUBLIC = 263,
     RETURN = 264,
     IF = 265,
     ELSE = 266,
     BOOLEAN = 267,
     INT = 268,
     WHILE = 269,
     SYSTEMOUTPRINTLN = 270,
     LENGTH = 271,
     TRUE = 272,
     FALSE = 273,
     THIS = 274,
     NEW = 275,
     VOID = 276,
     STATIC = 277,
     MAIN = 278,
     STRING = 279
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 20 "miniJava.y"

	int ival;
	char sval[255];
	CProgram* program;
	CMainClass* mainClass;
	CClassDeclList* classDeclList;
	CClassDecl* classDecl;
	CVarDecl* varDecl;
	CVarDeclList* varDeclList;
	CMethodDecl* methodDecl;
	CMethodDeclList* methodDeclList;
	CFormalList* formalList;
	CFormalRest* formalRest;
	CFormalRestList* formalRestList;
	CStatementList* statementList;
	CStatement* statement;
	CExpList* expList;
	CExp* exp;
	CExpMethodCall* expMethodCall;
	CExpBinOperation* expBinOperation;
	CExpNewIntArray* expNewIntArray;
	CExpNewCustomType* expNewCustomType;
	CExpSquareBrackets* expSquareBrackets;
	CExpRoundBrackets* expRoundBrackets;
	CExpNot* expNot;
	CExpNumber* expNumber;
	CExpId* expId;
	CExpSingle* expSingle;
	CExpLength* expLength;
	CType* type;
	CExpRestList* expRestList;
	CExpRest* expRest;


/* Line 387 of yacc.c  */
#line 190 "miniJava.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (CProgram*& root);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MINIJAVA_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 218 "miniJava.tab.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    10,     2,     2,     2,     2,     2,     2,
      14,    15,     7,     5,    40,     6,    11,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       3,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     9,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    31,    38,    44,
      50,    55,    64,    72,    80,    87,    89,    92,    94,    97,
     101,   115,   128,   141,   153,   157,   160,   161,   163,   166,
     170,   172,   175,   179,   181,   183,   185,   187,   189,   193,
     201,   207,   213,   218,   226,   228,   230,   232,   234,   236,
     238,   240,   242,   244,   246,   248,   252,   259,   265,   270,
     275,   279,   282,   286,   290,   294,   298,   302,   304,   306,
     308,   310,   312,   315,   317,   318,   320,   323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    44,    -1,    44,    43,    -1,    45,    -1,
      43,    45,    -1,    18,    17,    37,    20,    34,    33,    35,
      14,    36,    12,    13,    17,    15,    37,    55,    38,    38,
      -1,    18,    17,    37,    46,    47,    38,    -1,    18,    17,
      37,    47,    38,    -1,    18,    17,    37,    46,    38,    -1,
      18,    17,    37,    38,    -1,    18,    17,    19,    17,    37,
      46,    47,    38,    -1,    18,    17,    19,    17,    37,    47,
      38,    -1,    18,    17,    19,    17,    37,    46,    38,    -1,
      18,    17,    19,    17,    37,    38,    -1,    48,    -1,    46,
      48,    -1,    49,    -1,    47,    49,    -1,    54,    17,    39,
      -1,    20,    54,    17,    14,    50,    15,    37,    46,    53,
      21,    56,    39,    38,    -1,    20,    54,    17,    14,    50,
      15,    37,    53,    21,    56,    39,    38,    -1,    20,    54,
      17,    14,    50,    15,    37,    46,    21,    56,    39,    38,
      -1,    20,    54,    17,    14,    50,    15,    37,    21,    56,
      39,    38,    -1,    54,    17,    51,    -1,    54,    17,    -1,
      -1,    52,    -1,    51,    52,    -1,    40,    54,    17,    -1,
      55,    -1,    53,    55,    -1,    25,    12,    13,    -1,    25,
      -1,    24,    -1,    36,    -1,    33,    -1,    17,    -1,    37,
      53,    38,    -1,    22,    14,    56,    15,    55,    23,    55,
      -1,    26,    14,    56,    15,    55,    -1,    27,    14,    56,
      15,    39,    -1,    17,     4,    56,    39,    -1,    17,    12,
      56,    13,     4,    56,    39,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      65,    -1,    66,    -1,    67,    -1,    64,    -1,    56,    11,
      28,    -1,    56,    11,    17,    14,    68,    15,    -1,    32,
      25,    12,    56,    13,    -1,    32,    17,    14,    15,    -1,
      56,    12,    56,    13,    -1,    14,    56,    15,    -1,    10,
      56,    -1,    56,     3,    56,    -1,    56,     9,    56,    -1,
      56,     6,    56,    -1,    56,     5,    56,    -1,    56,     7,
      56,    -1,    16,    -1,    17,    -1,    29,    -1,    30,    -1,
      31,    -1,    56,    69,    -1,    56,    -1,    -1,    70,    -1,
      69,    70,    -1,    40,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   124,   128,   129,   133,   137,   138,   139,
     140,   141,   142,   143,   144,   148,   149,   153,   154,   158,
     162,   163,   164,   165,   169,   170,   171,   175,   176,   180,
     184,   185,   189,   190,   191,   192,   193,   194,   198,   199,
     200,   201,   202,   203,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   221,   225,   229,   233,   237,
     241,   245,   249,   250,   251,   252,   253,   257,   261,   265,
     266,   267,   271,   272,   273,   277,   278,   282
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'<'", "'='", "'+'", "'-'", "'*'", "'/'",
  "AND", "'!'", "'.'", "'['", "']'", "'('", "')'", "NUMBER", "ID", "CLASS",
  "EXTENDS", "PUBLIC", "RETURN", "IF", "ELSE", "BOOLEAN", "INT", "WHILE",
  "SYSTEMOUTPRINTLN", "LENGTH", "TRUE", "FALSE", "THIS", "NEW", "VOID",
  "STATIC", "MAIN", "STRING", "'{'", "'}'", "';'", "','", "$accept",
  "Program", "ClassDecls", "MainClass", "ClassDecl", "VarDecls",
  "MethodDecls", "VarDecl", "MethodDecl", "FormalList", "FormalRests",
  "FormalRest", "Statements", "Type", "Statement", "Exp", "ExpLength",
  "ExpMethodCall", "ExpNewIntArray", "ExpNewCustomType",
  "ExpSquareBrackets", "ExpRoundBrackets", "ExpNot", "ExpBinOperation",
  "ExpNumber", "ExpId", "ExpSingle", "ExpList", "ExpRests", "ExpRest", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    60,    61,    43,    45,    42,    47,   258,
      33,    46,    91,    93,    40,    41,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   123,   125,    59,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    47,    47,    48,
      49,    49,    49,    49,    50,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    64,    64,    64,    64,    65,    66,    67,
      67,    67,    68,    68,    68,    69,    69,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,    17,     6,     5,     5,
       4,     8,     7,     7,     6,     1,     2,     1,     2,     3,
      13,    12,    12,    11,     3,     2,     0,     1,     2,     3,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     7,
       5,     5,     4,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     4,     4,
       3,     2,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     2,     1,     0,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     3,     4,     0,
       0,     5,     0,     0,     0,     0,     0,    37,     0,    34,
      33,    36,    35,    10,     0,     0,    15,    17,     0,     0,
       0,     0,     0,     9,     0,    16,     8,    18,     0,     0,
      14,     0,     0,     0,    32,     7,    19,     0,    13,     0,
      12,    26,     0,    11,     0,     0,     0,     0,    25,     0,
       0,     0,    24,    27,     0,    37,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    28,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,     0,    44,    45,
      46,    47,    48,    49,    50,    54,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    29,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,    42,     0,    60,     0,     0,    62,    65,    64,
      66,    63,     0,    55,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    74,    59,     0,    40,
      41,    22,     0,    21,     6,     0,    57,    73,     0,     0,
      20,    43,     0,    72,    75,    56,    39,    77,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     3,     8,    24,    25,    26,    27,    54,
      62,    63,    72,    28,    73,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   168,   173,   174
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
     -11,    -8,    13,    16,    14,   -77,    59,    16,   -77,    64,
      -1,   -77,    65,    86,   131,    35,    68,   -77,     2,   -77,
      97,   -77,   -77,   -77,   146,     9,   -77,   -77,    96,    84,
     156,   106,   112,   -77,    28,   -77,   -77,   -77,    89,   116,
     -77,   166,    34,   122,   -77,   -77,   -77,   104,   -77,    51,
     -77,     2,   135,   -77,   137,   136,   144,   125,   128,   155,
     189,     2,   128,   -77,   159,    58,   129,   161,   163,   164,
     233,   206,   219,   -77,   168,   -77,   150,   129,   129,   129,
     129,   -77,   -77,   -77,   -77,   -77,    48,    52,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   129,
     129,   129,    58,   171,   129,   227,   129,   -77,   -77,   233,
      76,   304,   130,   260,   181,   184,   129,   129,   129,   129,
     129,    39,   129,   162,   271,   282,   293,   -77,    95,   129,
     105,   165,   -77,   197,   -77,   190,   129,   337,    83,    83,
     130,   130,   193,   -77,   315,   -77,   233,   233,   173,   179,
     115,   180,   182,   129,   -77,   326,   129,   -77,   196,   -77,
     -77,   -77,   183,   -77,   -77,   126,   -77,     5,   209,   233,
     -77,   -77,   129,   194,   -77,   -77,   -77,   337,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   222,   -10,    -9,   -19,    44,   -77,
     -77,   175,    79,   -12,   -72,   -76,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,    62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     107,   110,   111,   112,   113,    35,    31,     1,   116,     4,
     117,   118,   119,     5,   120,    34,   121,   122,    13,    17,
      41,    42,    35,   124,   125,   126,    19,    20,   128,    18,
     130,   107,    49,   107,     6,    21,    14,   131,    22,    55,
     137,   138,   139,   140,   141,   172,   144,    36,    18,    74,
      71,     9,    35,   150,    18,   116,   142,   117,   118,   119,
     155,   120,    77,   121,   122,   114,    45,   143,    29,    37,
      78,    18,    50,   115,   158,   159,    10,   165,    37,   116,
     167,   117,   118,   119,    12,   120,    37,   121,   122,    53,
     119,   123,   120,    37,   121,   122,   177,   176,   116,    15,
     117,   118,   119,    16,   120,    30,   121,   122,   116,    32,
     117,   118,   119,    38,   120,   132,   121,   122,   116,    39,
     117,   118,   119,    43,   120,    44,   121,   122,    46,   116,
      47,   117,   118,   119,   149,   120,    51,   121,   122,    79,
      52,   121,   122,    80,   151,    81,    82,    56,    17,   103,
     105,    18,    57,    58,   162,    19,    20,    59,    83,    84,
      85,    86,    60,    17,    21,   171,    18,    22,    61,    23,
      19,    20,    64,    17,    76,    99,    18,   100,   101,    21,
      19,    20,    22,    17,    33,   108,    18,   109,   102,    21,
      19,    20,    22,    67,    40,   135,   136,    68,    69,    21,
     145,   153,    22,   152,    48,   154,    65,   156,    70,   127,
      66,    67,   160,    19,    20,    68,    69,   161,   163,   169,
     164,   170,    21,    65,   175,    22,    70,   104,    67,    11,
      19,    20,    68,    69,   172,   178,   102,    75,     0,    21,
     106,    67,    22,    70,   102,    68,    69,     0,   129,    67,
     102,     0,     0,    68,    69,    67,    70,     0,     0,    68,
      69,     0,     0,   116,    70,   117,   118,   119,     0,   120,
      70,   121,   122,     0,   116,   134,   117,   118,   119,     0,
     120,     0,   121,   122,     0,   116,   146,   117,   118,   119,
       0,   120,     0,   121,   122,     0,   116,   147,   117,   118,
     119,     0,   120,     0,   121,   122,     0,   116,   148,   117,
     118,   119,     0,   120,     0,   121,   122,   133,   116,     0,
     117,   118,   119,     0,   120,     0,   121,   122,   157,   116,
       0,   117,   118,   119,     0,   120,     0,   121,   122,   166,
     116,     0,   117,   118,   119,     0,   120,     0,   121,   122
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      72,    77,    78,    79,    80,    24,    18,    18,     3,    17,
       5,     6,     7,     0,     9,    24,    11,    12,    19,    17,
      30,    30,    41,    99,   100,   101,    24,    25,   104,    20,
     106,   103,    41,   105,    18,    33,    37,   109,    36,    51,
     116,   117,   118,   119,   120,    40,   122,    38,    20,    61,
      60,    37,    71,   129,    20,     3,    17,     5,     6,     7,
     136,     9,     4,    11,    12,    17,    38,    28,    33,    25,
      12,    20,    38,    25,   146,   147,    17,   153,    34,     3,
     156,     5,     6,     7,    20,     9,    42,    11,    12,    38,
       7,    39,     9,    49,    11,    12,   172,   169,     3,    34,
       5,     6,     7,    17,     9,    37,    11,    12,     3,    12,
       5,     6,     7,    17,     9,    39,    11,    12,     3,    35,
       5,     6,     7,    17,     9,    13,    11,    12,    39,     3,
      14,     5,     6,     7,    39,     9,    14,    11,    12,    10,
      36,    11,    12,    14,    39,    16,    17,    12,    17,    70,
      71,    20,    15,    17,    39,    24,    25,    13,    29,    30,
      31,    32,    37,    17,    33,    39,    20,    36,    40,    38,
      24,    25,    17,    17,    15,    14,    20,    14,    14,    33,
      24,    25,    36,    17,    38,    17,    20,    37,    17,    33,
      24,    25,    36,    22,    38,    14,    12,    26,    27,    33,
      38,     4,    36,    38,    38,    15,    17,    14,    37,    38,
      21,    22,    39,    24,    25,    26,    27,    38,    38,    23,
      38,    38,    33,    17,    15,    36,    37,    21,    22,     7,
      24,    25,    26,    27,    40,   173,    17,    62,    -1,    33,
      21,    22,    36,    37,    17,    26,    27,    -1,    21,    22,
      17,    -1,    -1,    26,    27,    22,    37,    -1,    -1,    26,
      27,    -1,    -1,     3,    37,     5,     6,     7,    -1,     9,
      37,    11,    12,    -1,     3,    15,     5,     6,     7,    -1,
       9,    -1,    11,    12,    -1,     3,    15,     5,     6,     7,
      -1,     9,    -1,    11,    12,    -1,     3,    15,     5,     6,
       7,    -1,     9,    -1,    11,    12,    -1,     3,    15,     5,
       6,     7,    -1,     9,    -1,    11,    12,    13,     3,    -1,
       5,     6,     7,    -1,     9,    -1,    11,    12,    13,     3,
      -1,     5,     6,     7,    -1,     9,    -1,    11,    12,    13,
       3,    -1,     5,     6,     7,    -1,     9,    -1,    11,    12
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    42,    44,    17,     0,    18,    43,    45,    37,
      17,    45,    20,    19,    37,    34,    17,    17,    20,    24,
      25,    33,    36,    38,    46,    47,    48,    49,    54,    33,
      37,    54,    12,    38,    47,    48,    38,    49,    17,    35,
      38,    46,    47,    17,    13,    38,    39,    14,    38,    47,
      38,    14,    36,    38,    50,    54,    12,    15,    17,    13,
      37,    40,    51,    52,    17,    17,    21,    22,    26,    27,
      37,    46,    53,    55,    54,    52,    15,     4,    12,    10,
      14,    16,    17,    29,    30,    31,    32,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    14,
      14,    14,    17,    53,    21,    53,    21,    55,    17,    37,
      56,    56,    56,    56,    17,    25,     3,     5,     6,     7,
       9,    11,    12,    39,    56,    56,    56,    38,    56,    21,
      56,    55,    39,    13,    15,    14,    12,    56,    56,    56,
      56,    56,    17,    28,    56,    38,    15,    15,    15,    39,
      56,    39,    38,     4,    15,    56,    14,    13,    55,    55,
      39,    38,    39,    38,    38,    56,    13,    56,    68,    23,
      38,    39,    40,    69,    70,    15,    55,    56,    70
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (root, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
		  Type, Value, root); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, CProgram*& root)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    CProgram*& root;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (root);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, CProgram*& root)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    CProgram*& root;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, root);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, CProgram*& root)
#else
static void
yy_reduce_print (yyvsp, yyrule, root)
    YYSTYPE *yyvsp;
    int yyrule;
    CProgram*& root;
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
		       		       , root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, root); \
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, CProgram*& root)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, root)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    CProgram*& root;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (root);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
yyparse (CProgram*& root)
#else
int
yyparse (root)
    CProgram*& root;
#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 123 "miniJava.y"
    { root = new CProgram( (yyvsp[(1) - (1)].mainClass), 0, yylineno ); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 124 "miniJava.y"
    { root = new CProgram( (yyvsp[(1) - (2)].mainClass), (yyvsp[(2) - (2)].classDeclList), yylineno ); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 128 "miniJava.y"
    { (yyval.classDeclList) = new CClassDeclList( (yyvsp[(1) - (1)].classDecl), 0, yylineno ); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 129 "miniJava.y"
    { (yyval.classDeclList) = new CClassDeclList((yyvsp[(2) - (2)].classDecl), (yyvsp[(1) - (2)].classDeclList), yylineno); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 133 "miniJava.y"
    { (yyval.mainClass) = new CMainClass( (yyvsp[(2) - (17)].sval), (yyvsp[(12) - (17)].sval), (yyvsp[(15) - (17)].statement), yylineno ); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 137 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (6)].sval), "", (yyvsp[(4) - (6)].varDeclList), (yyvsp[(5) - (6)].methodDeclList), yylineno ); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 138 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (5)].sval), "", 0, (yyvsp[(4) - (5)].methodDeclList), yylineno); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 139 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (5)].sval), "", (yyvsp[(4) - (5)].varDeclList), 0, yylineno ); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 140 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (4)].sval), "", 0, 0, yylineno ); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 141 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (8)].sval), (yyvsp[(4) - (8)].sval), (yyvsp[(6) - (8)].varDeclList), (yyvsp[(7) - (8)].methodDeclList), yylineno ); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 142 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].sval), 0, (yyvsp[(6) - (7)].methodDeclList), yylineno ); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 143 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].sval), (yyvsp[(6) - (7)].varDeclList), 0, yylineno ); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 144 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].sval), 0, 0, yylineno ); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 148 "miniJava.y"
    { (yyval.varDeclList) = new CVarDeclList( (yyvsp[(1) - (1)].varDecl), 0, yylineno ); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 149 "miniJava.y"
    { (yyval.varDeclList) = new CVarDeclList( (yyvsp[(2) - (2)].varDecl), (yyvsp[(1) - (2)].varDeclList), yylineno ); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 153 "miniJava.y"
    { (yyval.methodDeclList) = new CMethodDeclList( (yyvsp[(1) - (1)].methodDecl), 0, yylineno ); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 154 "miniJava.y"
    { (yyval.methodDeclList) = new CMethodDeclList( (yyvsp[(2) - (2)].methodDecl), (yyvsp[(1) - (2)].methodDeclList), yylineno ); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 158 "miniJava.y"
    { (yyval.varDecl) = new CVarDecl( (yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].sval), yylineno ); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 162 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (13)].type), (yyvsp[(3) - (13)].sval), (yyvsp[(5) - (13)].formalList), (yyvsp[(8) - (13)].varDeclList), (yyvsp[(9) - (13)].statementList), (yyvsp[(11) - (13)].exp), yylineno); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 163 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (12)].type), (yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].formalList), 0, (yyvsp[(8) - (12)].statementList), (yyvsp[(10) - (12)].exp), yylineno); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 164 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (12)].type), (yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].formalList), (yyvsp[(8) - (12)].varDeclList), 0, (yyvsp[(10) - (12)].exp), yylineno ); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 165 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (11)].type), (yyvsp[(3) - (11)].sval), (yyvsp[(5) - (11)].formalList), 0, 0, (yyvsp[(9) - (11)].exp), yylineno ); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 169 "miniJava.y"
    { (yyval.formalList) = new CFormalList( (yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].sval), (yyvsp[(3) - (3)].formalRestList), yylineno ); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 170 "miniJava.y"
    { (yyval.formalList) = new CFormalList( (yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].sval), 0, yylineno ); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 171 "miniJava.y"
    { (yyval.formalList) = new CFormalList( 0, "", 0, yylineno ); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 175 "miniJava.y"
    { (yyval.formalRestList) = new CFormalRestList( (yyvsp[(1) - (1)].formalRest), 0, yylineno ); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 176 "miniJava.y"
    { (yyval.formalRestList) = new CFormalRestList( (yyvsp[(2) - (2)].formalRest), (yyvsp[(1) - (2)].formalRestList), yylineno ); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 180 "miniJava.y"
    { (yyval.formalRest) = new CFormalRest( (yyvsp[(2) - (3)].type), (yyvsp[(3) - (3)].sval), yylineno ); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 184 "miniJava.y"
    { (yyval.statementList) = new CStatementList( (yyvsp[(1) - (1)].statement), 0, yylineno ); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 185 "miniJava.y"
    { (yyval.statementList) = new CStatementList( (yyvsp[(2) - (2)].statement), (yyvsp[(1) - (2)].statementList), yylineno ); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 189 "miniJava.y"
    { (yyval.type) = new CType("int []", yylineno); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 190 "miniJava.y"
    { (yyval.type) = new CType("int", yylineno); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 191 "miniJava.y"
    { (yyval.type) = new CType("boolean", yylineno); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 192 "miniJava.y"
    { (yyval.type) = new CType("string", yylineno); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 193 "miniJava.y"
    { (yyval.type) = new CType("void", yylineno); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 194 "miniJava.y"
    { (yyval.type) = new CType((yyvsp[(1) - (1)].sval), yylineno); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 198 "miniJava.y"
    { (yyval.statement) = new CStatement( "BlockStatement", (yyvsp[(2) - (3)].statementList), 0, 0, 0, 0, "", yylineno ); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 199 "miniJava.y"
    { (yyval.statement) = new CStatement( "IfStatement", 0, (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement), (yyvsp[(3) - (7)].exp), 0, "", yylineno ); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 200 "miniJava.y"
    { (yyval.statement) = new CStatement( "WhileStatement", 0, (yyvsp[(5) - (5)].statement), 0, (yyvsp[(3) - (5)].exp), 0, "", yylineno ); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 201 "miniJava.y"
    { (yyval.statement) = new CStatement( "PrintlnStatement", 0, 0, 0, (yyvsp[(3) - (5)].exp), 0, "", yylineno ); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 202 "miniJava.y"
    { (yyval.statement) = new CStatement( "AssignStatement", 0, 0, 0, (yyvsp[(3) - (4)].exp), 0, (yyvsp[(1) - (4)].sval), yylineno ); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 203 "miniJava.y"
    { (yyval.statement) = new CStatement( "ArrayAssignStatement", 0, 0, 0, (yyvsp[(3) - (7)].exp), (yyvsp[(6) - (7)].exp), (yyvsp[(1) - (7)].sval), yylineno ); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 207 "miniJava.y"
    { (yyval.exp) = new CExp( (yyvsp[(1) - (1)].expLength), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 208 "miniJava.y"
    { (yyval.exp) = new CExp( 0, (yyvsp[(1) - (1)].expMethodCall), 0, 0, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 209 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, (yyvsp[(1) - (1)].expNewIntArray), 0, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 210 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, (yyvsp[(1) - (1)].expNewCustomType), 0, 0, 0, 0, 0, 0, 0, yylineno ); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 211 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, (yyvsp[(1) - (1)].expSquareBrackets), 0, 0, 0, 0, 0, 0, yylineno ); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 212 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expRoundBrackets), 0, 0, 0, 0, 0, yylineno ); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 213 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expNot), 0, 0, 0, 0, yylineno ); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 214 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expNumber), 0, 0, 0, yylineno ); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 215 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expId), 0, 0, yylineno ); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 216 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expSingle), 0, yylineno ); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 217 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expBinOperation), yylineno ); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 221 "miniJava.y"
    { (yyval.expLength) = new CExpLength( (yyvsp[(1) - (3)].exp), yylineno ); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 225 "miniJava.y"
    { (yyval.expMethodCall) = new CExpMethodCall( (yyvsp[(1) - (6)].exp), (yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].expList), yylineno ); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 229 "miniJava.y"
    { (yyval.expNewIntArray) = new CExpNewIntArray( (yyvsp[(4) - (5)].exp), yylineno ); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 233 "miniJava.y"
    { (yyval.expNewCustomType) = new CExpNewCustomType( new CType( (yyvsp[(2) - (4)].sval), yylineno ), yylineno ); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 237 "miniJava.y"
    { (yyval.expSquareBrackets) = new CExpSquareBrackets( (yyvsp[(1) - (4)].exp), (yyvsp[(3) - (4)].exp), yylineno ); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 241 "miniJava.y"
    { (yyval.expRoundBrackets) = new CExpRoundBrackets( (yyvsp[(2) - (3)].exp), yylineno ); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 245 "miniJava.y"
    { (yyval.expNot) = new CExpNot( (yyvsp[(2) - (2)].exp), yylineno ); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 249 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "<", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), yylineno ); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 250 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "&&", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), yylineno ); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 251 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "-", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), yylineno ); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 252 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "+", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), yylineno ); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 253 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "*", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), yylineno ); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 257 "miniJava.y"
    { (yyval.expNumber) = new CExpNumber( (yyvsp[(1) - (1)].ival), yylineno ); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 261 "miniJava.y"
    { (yyval.expId) = new CExpId( (yyvsp[(1) - (1)].sval), yylineno ); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 265 "miniJava.y"
    { (yyval.expSingle) = new CExpSingle( "True", yylineno ); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 266 "miniJava.y"
    { (yyval.expSingle) = new CExpSingle( "False", yylineno ); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 267 "miniJava.y"
    { (yyval.expSingle) = new CExpSingle( "this", yylineno ); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 271 "miniJava.y"
    { (yyval.expList) = new CExpList( (yyvsp[(1) - (2)].exp), (yyvsp[(2) - (2)].expRestList), yylineno ); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 272 "miniJava.y"
    { (yyval.expList) = new CExpList( (yyvsp[(1) - (1)].exp), 0, yylineno ); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 273 "miniJava.y"
    { (yyval.expList) = new CExpList( 0, 0, yylineno ); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 277 "miniJava.y"
    { (yyval.expRestList) = new CExpRestList( (yyvsp[(1) - (1)].expRest), 0, yylineno ); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 278 "miniJava.y"
    { (yyval.expRestList) = new CExpRestList( (yyvsp[(2) - (2)].expRest), (yyvsp[(1) - (2)].expRestList), yylineno ); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 282 "miniJava.y"
    { (yyval.expRest) = new CExpRest((yyvsp[(2) - (2)].exp), yylineno); }
    break;


/* Line 1792 of yacc.c  */
#line 2053 "miniJava.tab.cpp"
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
      yyerror (root, YY_("syntax error"));
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
        yyerror (root, yymsgp);
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
		      yytoken, &yylval, root);
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
		  yystos[yystate], yyvsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
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
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, root);
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


/* Line 2055 of yacc.c  */
#line 285 "miniJava.y"


/* Функция обработки ошибки. */
void yyerror( CProgram*& root, const char* str )
{
	std::string error =  std::string(str) + " in " + std::to_string(yylineno) + " line";
	throw CMiniJException(error);
}