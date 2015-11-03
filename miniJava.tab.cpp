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

/* Line 387 of yacc.c  */
#line 113 "miniJava.tab.cpp"

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
#line 17 "miniJava.y"

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
#line 187 "miniJava.tab.cpp"
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
#line 215 "miniJava.tab.cpp"

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
#define YYLAST   367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

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
       2,     2,     2,    13,     2,     2,     2,     2,    14,     2,
      10,    11,     6,     4,    42,     5,    12,     7,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      15,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     8,     2,     9,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    16,    40,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38
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
     275,   279,   282,   286,   290,   294,   298,   302,   306,   308,
     310,   312,   314,   316,   319,   321,   322,   324,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    46,    -1,    46,    45,    -1,    47,    -1,
      45,    47,    -1,    20,    19,    39,    22,    36,    35,    37,
      10,    38,     8,     9,    19,    11,    39,    57,    40,    40,
      -1,    20,    19,    39,    48,    49,    40,    -1,    20,    19,
      39,    49,    40,    -1,    20,    19,    39,    48,    40,    -1,
      20,    19,    39,    40,    -1,    20,    19,    21,    19,    39,
      48,    49,    40,    -1,    20,    19,    21,    19,    39,    49,
      40,    -1,    20,    19,    21,    19,    39,    48,    40,    -1,
      20,    19,    21,    19,    39,    40,    -1,    50,    -1,    48,
      50,    -1,    51,    -1,    49,    51,    -1,    56,    19,    41,
      -1,    22,    56,    19,    10,    52,    11,    39,    48,    55,
      23,    58,    41,    40,    -1,    22,    56,    19,    10,    52,
      11,    39,    55,    23,    58,    41,    40,    -1,    22,    56,
      19,    10,    52,    11,    39,    48,    23,    58,    41,    40,
      -1,    22,    56,    19,    10,    52,    11,    39,    23,    58,
      41,    40,    -1,    56,    19,    53,    -1,    56,    19,    -1,
      -1,    54,    -1,    53,    54,    -1,    42,    56,    19,    -1,
      57,    -1,    55,    57,    -1,    27,     8,     9,    -1,    27,
      -1,    26,    -1,    38,    -1,    35,    -1,    19,    -1,    39,
      55,    40,    -1,    24,    10,    58,    11,    57,    25,    57,
      -1,    28,    10,    58,    11,    57,    -1,    29,    10,    58,
      11,    41,    -1,    19,     3,    58,    41,    -1,    19,     8,
      58,     9,     3,    58,    41,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      67,    -1,    68,    -1,    69,    -1,    66,    -1,    58,    12,
      30,    -1,    58,    12,    19,    10,    70,    11,    -1,    34,
      27,     8,    58,     9,    -1,    34,    19,    10,    11,    -1,
      58,     8,    58,     9,    -1,    10,    58,    11,    -1,    13,
      58,    -1,    58,    15,    58,    -1,    58,    14,    58,    -1,
      58,     5,    58,    -1,    58,     4,    58,    -1,    58,     7,
      58,    -1,    58,     6,    58,    -1,    18,    -1,    19,    -1,
      31,    -1,    32,    -1,    33,    -1,    58,    71,    -1,    58,
      -1,    -1,    72,    -1,    71,    72,    -1,    42,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   120,   124,   125,   129,   133,   134,   135,
     136,   137,   138,   139,   140,   144,   145,   149,   150,   154,
     158,   159,   160,   161,   165,   166,   167,   171,   172,   176,
     180,   181,   185,   186,   187,   188,   189,   190,   194,   195,
     196,   197,   198,   199,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   217,   221,   225,   229,   233,
     237,   241,   245,   246,   247,   248,   249,   250,   254,   258,
     262,   263,   264,   268,   269,   270,   274,   275,   279
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'+'", "'-'", "'*'", "'/'", "'['",
  "']'", "'('", "')'", "'.'", "'!'", "'&'", "'<'", "'|'", "AND", "NUMBER",
  "ID", "CLASS", "EXTENDS", "PUBLIC", "RETURN", "IF", "ELSE", "BOOLEAN",
  "INT", "WHILE", "SYSTEMOUTPRINTLN", "LENGTH", "TRUE", "FALSE", "THIS",
  "NEW", "VOID", "STATIC", "MAIN", "STRING", "'{'", "'}'", "';'", "','",
  "$accept", "Program", "ClassDecls", "MainClass", "ClassDecl", "VarDecls",
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
       0,   256,   257,    61,    43,    45,    42,    47,    91,    93,
      40,    41,    46,    33,    38,    60,   124,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   123,
     125,    59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    50,
      51,    51,    51,    51,    52,    52,    52,    53,    53,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    66,    66,    66,    66,    66,    67,    68,
      69,    69,    69,    70,    70,    70,    71,    71,    72
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
       3,     2,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     2,     1,     0,     1,     2,     2
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
       0,    68,    69,    70,    71,    72,     0,     0,    44,    45,
      46,    47,    48,    49,    50,    54,    51,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    29,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,    42,     0,    60,     0,     0,    65,    64,
      67,    66,     0,     0,    55,    63,    62,    23,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    59,    75,
       0,    40,    41,    22,     0,    21,     6,     0,    57,    74,
       0,     0,    20,    43,     0,    73,    76,    56,    39,    78,
      77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     3,     8,    24,    25,    26,    27,    54,
      62,    63,    72,    28,    73,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   170,   175,   176
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
      47,    43,    13,    55,    58,   -77,    65,    55,   -77,    68,
      -7,   -77,    70,    93,   134,    85,    91,   -77,     0,   -77,
     123,   -77,   -77,   -77,   149,    -6,   -77,   -77,   113,    97,
     159,   119,   131,   -77,    29,   -77,   -77,   -77,   101,   135,
     -77,   169,    42,   144,   -77,   -77,   -77,   125,   -77,    69,
     -77,     0,   147,   -77,   146,   151,   173,   153,   141,   171,
     192,     0,   141,   -77,   189,    45,   133,   191,   195,   196,
     120,   209,   222,   -77,   193,   -77,   178,   133,   133,   133,
     133,   -77,   -77,   -77,   -77,   -77,    41,    51,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   133,
     133,   133,    45,   174,   133,   230,   133,   -77,   -77,   120,
      66,   258,   270,   -77,   198,   202,   133,   133,   133,   133,
     133,    75,   133,   133,   182,   282,   294,   306,   -77,    81,
     133,    96,   183,   -77,   221,   -77,   214,   133,   352,   352,
     165,   165,   318,   216,   -77,   -77,   -77,   -77,   120,   120,
     188,   194,   109,   199,   200,   133,   -77,   330,   -77,   133,
     217,   -77,   -77,   -77,   203,   -77,   -77,   121,   -77,     3,
     241,   120,   -77,   -77,   133,   213,   -77,   -77,   -77,   342,
     -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   249,   -10,   117,   -19,   -13,   -77,
     -77,   206,    48,   -12,   -72,   -76,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,    82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     107,   110,   111,   112,   113,    35,    31,   116,   117,   118,
     119,   120,    37,     5,    13,   121,    18,   122,   123,    17,
      41,    37,    35,   125,   126,   127,    19,    20,   129,    37,
     131,   107,    14,   107,    36,    21,    37,   132,    22,    55,
     138,   139,   140,   141,   142,   174,   145,   146,    77,    74,
      71,    18,    35,    78,   152,   116,   117,   118,   119,   120,
     114,   157,     4,   121,    18,   122,   123,     1,   115,    45,
     116,   117,   118,   119,   120,     6,   160,   161,   121,   167,
     122,   123,    50,   169,    10,   116,   117,   118,   119,   120,
      12,    18,   124,   121,   143,   122,   123,     9,   179,   178,
     116,   117,   118,   119,   120,   144,    15,   133,   121,    53,
     122,   123,    16,   116,   117,   118,   119,   120,   103,   105,
      29,   121,   151,   122,   123,   116,   117,   118,   119,   120,
      30,    32,    38,   121,    39,   122,   123,   153,    43,   102,
      44,    34,    46,    79,    67,    47,    80,    42,    68,    69,
     164,    81,    82,    17,    51,    56,    18,    57,    49,    70,
      19,    20,   173,    52,    83,    84,    85,    86,    17,    21,
      58,    18,    22,   120,    23,    19,    20,   121,    17,   122,
     123,    18,    59,    61,    21,    19,    20,    22,    17,    33,
      64,    18,    60,   102,    21,    19,    20,    22,    67,    40,
      76,    99,    68,    69,    21,   100,   101,    22,   136,    48,
     137,    65,   108,    70,   128,    66,    67,   109,    19,    20,
      68,    69,   147,   154,   155,   156,   159,    21,    65,   162,
      22,    70,   104,    67,   163,    19,    20,    68,    69,   165,
     166,   102,   171,   172,    21,   106,    67,    22,    70,   102,
      68,    69,   177,   130,    67,   174,    11,   180,    68,    69,
       0,    70,   116,   117,   118,   119,   120,   134,    75,    70,
     121,     0,   122,   123,   116,   117,   118,   119,   120,     0,
       0,   135,   121,     0,   122,   123,   116,   117,   118,   119,
     120,     0,     0,   148,   121,     0,   122,   123,   116,   117,
     118,   119,   120,     0,     0,   149,   121,     0,   122,   123,
     116,   117,   118,   119,   120,     0,     0,   150,   121,     0,
     122,   123,   116,   117,   118,   119,   120,   158,     0,     0,
     121,     0,   122,   123,   116,   117,   118,   119,   120,   168,
       0,     0,   121,     0,   122,   123,   116,   117,   118,   119,
     120,     0,     0,     0,   121,     0,   122,   123,   118,   119,
     120,     0,     0,     0,   121,     0,   122,   123
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      72,    77,    78,    79,    80,    24,    18,     4,     5,     6,
       7,     8,    25,     0,    21,    12,    22,    14,    15,    19,
      30,    34,    41,    99,   100,   101,    26,    27,   104,    42,
     106,   103,    39,   105,    40,    35,    49,   109,    38,    51,
     116,   117,   118,   119,   120,    42,   122,   123,     3,    61,
      60,    22,    71,     8,   130,     4,     5,     6,     7,     8,
      19,   137,    19,    12,    22,    14,    15,    20,    27,    40,
       4,     5,     6,     7,     8,    20,   148,   149,    12,   155,
      14,    15,    40,   159,    19,     4,     5,     6,     7,     8,
      22,    22,    41,    12,    19,    14,    15,    39,   174,   171,
       4,     5,     6,     7,     8,    30,    36,    41,    12,    40,
      14,    15,    19,     4,     5,     6,     7,     8,    70,    71,
      35,    12,    41,    14,    15,     4,     5,     6,     7,     8,
      39,     8,    19,    12,    37,    14,    15,    41,    19,    19,
       9,    24,    41,    10,    24,    10,    13,    30,    28,    29,
      41,    18,    19,    19,    10,     8,    22,    11,    41,    39,
      26,    27,    41,    38,    31,    32,    33,    34,    19,    35,
      19,    22,    38,     8,    40,    26,    27,    12,    19,    14,
      15,    22,     9,    42,    35,    26,    27,    38,    19,    40,
      19,    22,    39,    19,    35,    26,    27,    38,    24,    40,
      11,    10,    28,    29,    35,    10,    10,    38,    10,    40,
       8,    19,    19,    39,    40,    23,    24,    39,    26,    27,
      28,    29,    40,    40,     3,    11,    10,    35,    19,    41,
      38,    39,    23,    24,    40,    26,    27,    28,    29,    40,
      40,    19,    25,    40,    35,    23,    24,    38,    39,    19,
      28,    29,    11,    23,    24,    42,     7,   175,    28,    29,
      -1,    39,     4,     5,     6,     7,     8,     9,    62,    39,
      12,    -1,    14,    15,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    -1,
      14,    15,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    15,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    14,    15,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    14,    15,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    44,    46,    19,     0,    20,    45,    47,    39,
      19,    47,    22,    21,    39,    36,    19,    19,    22,    26,
      27,    35,    38,    40,    48,    49,    50,    51,    56,    35,
      39,    56,     8,    40,    49,    50,    40,    51,    19,    37,
      40,    48,    49,    19,     9,    40,    41,    10,    40,    49,
      40,    10,    38,    40,    52,    56,     8,    11,    19,     9,
      39,    42,    53,    54,    19,    19,    23,    24,    28,    29,
      39,    48,    55,    57,    56,    54,    11,     3,     8,    10,
      13,    18,    19,    31,    32,    33,    34,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    10,
      10,    10,    19,    55,    23,    55,    23,    57,    19,    39,
      58,    58,    58,    58,    19,    27,     4,     5,     6,     7,
       8,    12,    14,    15,    41,    58,    58,    58,    40,    58,
      23,    58,    57,    41,     9,    11,    10,     8,    58,    58,
      58,    58,    58,    19,    30,    58,    58,    40,    11,    11,
      11,    41,    58,    41,    40,     3,    11,    58,     9,    10,
      57,    57,    41,    40,    41,    40,    40,    58,     9,    58,
      70,    25,    40,    41,    42,    71,    72,    11,    57,    58,
      72
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
#line 119 "miniJava.y"
    { root = new CProgram( (yyvsp[(1) - (1)].mainClass), 0 ); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 120 "miniJava.y"
    { root = new CProgram( (yyvsp[(1) - (2)].mainClass), (yyvsp[(2) - (2)].classDeclList) ); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 124 "miniJava.y"
    { (yyval.classDeclList) = new CClassDeclList( (yyvsp[(1) - (1)].classDecl), 0 ); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 125 "miniJava.y"
    { (yyval.classDeclList) = new CClassDeclList((yyvsp[(2) - (2)].classDecl), (yyvsp[(1) - (2)].classDeclList)); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 129 "miniJava.y"
    { (yyval.mainClass) = new CMainClass( (yyvsp[(2) - (17)].sval), (yyvsp[(12) - (17)].sval), (yyvsp[(15) - (17)].statement) ); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 133 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (6)].sval), "", (yyvsp[(4) - (6)].varDeclList), (yyvsp[(5) - (6)].methodDeclList) ); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 134 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (5)].sval), "", 0, (yyvsp[(4) - (5)].methodDeclList)); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 135 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (5)].sval), "", (yyvsp[(4) - (5)].varDeclList), 0 ); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 136 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (4)].sval), "", 0, 0 ); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 137 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (8)].sval), (yyvsp[(4) - (8)].sval), (yyvsp[(6) - (8)].varDeclList), (yyvsp[(7) - (8)].methodDeclList) ); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 138 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].sval), 0, (yyvsp[(6) - (7)].methodDeclList) ); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 139 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].sval), (yyvsp[(6) - (7)].varDeclList), 0 ); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 140 "miniJava.y"
    { (yyval.classDecl) = new CClassDecl( (yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].sval), 0, 0 ); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 144 "miniJava.y"
    { (yyval.varDeclList) = new CVarDeclList( (yyvsp[(1) - (1)].varDecl), 0 ); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 145 "miniJava.y"
    { (yyval.varDeclList) = new CVarDeclList( (yyvsp[(2) - (2)].varDecl), (yyvsp[(1) - (2)].varDeclList) ); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 149 "miniJava.y"
    { (yyval.methodDeclList) = new CMethodDeclList( (yyvsp[(1) - (1)].methodDecl), 0 ); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 150 "miniJava.y"
    { (yyval.methodDeclList) = new CMethodDeclList( (yyvsp[(2) - (2)].methodDecl), (yyvsp[(1) - (2)].methodDeclList) ); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 154 "miniJava.y"
    { (yyval.varDecl) = new CVarDecl( (yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].sval) ); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 158 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (13)].type), (yyvsp[(3) - (13)].sval), (yyvsp[(5) - (13)].formalList), (yyvsp[(8) - (13)].varDeclList), (yyvsp[(9) - (13)].statementList), (yyvsp[(11) - (13)].exp)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 159 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (12)].type), (yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].formalList), 0, (yyvsp[(8) - (12)].statementList), (yyvsp[(10) - (12)].exp)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 160 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (12)].type), (yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].formalList), (yyvsp[(8) - (12)].varDeclList), 0, (yyvsp[(10) - (12)].exp) ); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 161 "miniJava.y"
    { (yyval.methodDecl) = new CMethodDecl( (yyvsp[(2) - (11)].type), (yyvsp[(3) - (11)].sval), (yyvsp[(5) - (11)].formalList), 0, 0, (yyvsp[(9) - (11)].exp) ); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 165 "miniJava.y"
    { (yyval.formalList) = new CFormalList( (yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].sval), (yyvsp[(3) - (3)].formalRestList) ); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 166 "miniJava.y"
    { (yyval.formalList) = new CFormalList( (yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].sval), 0 ); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 167 "miniJava.y"
    { (yyval.formalList) = new CFormalList( 0, "", 0 ); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 171 "miniJava.y"
    { (yyval.formalRestList) = new CFormalRestList( (yyvsp[(1) - (1)].formalRest), 0 ); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 172 "miniJava.y"
    { (yyval.formalRestList) = new CFormalRestList( (yyvsp[(2) - (2)].formalRest), (yyvsp[(1) - (2)].formalRestList) ); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 176 "miniJava.y"
    { (yyval.formalRest) = new CFormalRest( (yyvsp[(2) - (3)].type), (yyvsp[(3) - (3)].sval) ); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 180 "miniJava.y"
    { (yyval.statementList) = new CStatementList( (yyvsp[(1) - (1)].statement), 0 ); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 181 "miniJava.y"
    { (yyval.statementList) = new CStatementList( (yyvsp[(2) - (2)].statement), (yyvsp[(1) - (2)].statementList) ); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 185 "miniJava.y"
    { (yyval.type) = new CType("int []"); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 186 "miniJava.y"
    { (yyval.type) = new CType("int"); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 187 "miniJava.y"
    { (yyval.type) = new CType("boolean"); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 188 "miniJava.y"
    { (yyval.type) = new CType("string"); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 189 "miniJava.y"
    { (yyval.type) = new CType("void"); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 190 "miniJava.y"
    { (yyval.type) = new CType((yyvsp[(1) - (1)].sval)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 194 "miniJava.y"
    { (yyval.statement) = new CStatement( "BlockStatement", (yyvsp[(2) - (3)].statementList), 0, 0, 0, 0, "" ); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 195 "miniJava.y"
    { (yyval.statement) = new CStatement( "IfStatement", 0, (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement), (yyvsp[(3) - (7)].exp), 0, "" ); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 196 "miniJava.y"
    { (yyval.statement) = new CStatement( "WhileStatement", 0, (yyvsp[(5) - (5)].statement), 0, (yyvsp[(3) - (5)].exp), 0, "" ); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 197 "miniJava.y"
    { (yyval.statement) = new CStatement( "PrintlnStatement", 0, 0, 0, (yyvsp[(3) - (5)].exp), 0, "" ); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 198 "miniJava.y"
    { (yyval.statement) = new CStatement( "AssignStatement", 0, 0, 0, (yyvsp[(3) - (4)].exp), 0, (yyvsp[(1) - (4)].sval) ); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 199 "miniJava.y"
    { (yyval.statement) = new CStatement( "ArrayAssignStatement", 0, 0, 0, (yyvsp[(3) - (7)].exp), (yyvsp[(6) - (7)].exp), (yyvsp[(1) - (7)].sval) ); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 203 "miniJava.y"
    { (yyval.exp) = new CExp( (yyvsp[(1) - (1)].expLength), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 204 "miniJava.y"
    { (yyval.exp) = new CExp( 0, (yyvsp[(1) - (1)].expMethodCall), 0, 0, 0, 0, 0, 0, 0, 0, 0 ); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 205 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, (yyvsp[(1) - (1)].expNewIntArray), 0, 0, 0, 0, 0, 0, 0, 0 ); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 206 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, (yyvsp[(1) - (1)].expNewCustomType), 0, 0, 0, 0, 0, 0, 0 ); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 207 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, (yyvsp[(1) - (1)].expSquareBrackets), 0, 0, 0, 0, 0, 0 ); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 208 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expRoundBrackets), 0, 0, 0, 0, 0 ); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 209 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expNot), 0, 0, 0, 0 ); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 210 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expNumber), 0, 0, 0 ); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 211 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expId), 0, 0 ); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 212 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expSingle), 0 ); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 213 "miniJava.y"
    { (yyval.exp) = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (yyvsp[(1) - (1)].expBinOperation) ); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 217 "miniJava.y"
    { (yyval.expLength) = new CExpLength( (yyvsp[(1) - (3)].exp) ); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 221 "miniJava.y"
    { (yyval.expMethodCall) = new CExpMethodCall( (yyvsp[(1) - (6)].exp), (yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].expList) ); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 225 "miniJava.y"
    { (yyval.expNewIntArray) = new CExpNewIntArray( (yyvsp[(4) - (5)].exp) ); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 229 "miniJava.y"
    { (yyval.expNewCustomType) = new CExpNewCustomType( (yyvsp[(2) - (4)].sval) ); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 233 "miniJava.y"
    { (yyval.expSquareBrackets) = new CExpSquareBrackets( (yyvsp[(1) - (4)].exp), (yyvsp[(3) - (4)].exp) ); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 237 "miniJava.y"
    { (yyval.expRoundBrackets) = new CExpRoundBrackets( (yyvsp[(2) - (3)].exp) ); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 241 "miniJava.y"
    { (yyval.expNot) = new CExpNot( (yyvsp[(2) - (2)].exp) ); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 245 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "<", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp) ); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 246 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "&", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp) ); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 247 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "-", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp) ); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 248 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "+", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp) ); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 249 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "/", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp) ); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 250 "miniJava.y"
    { (yyval.expBinOperation) = new CExpBinOperation( "*", (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp) ); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 254 "miniJava.y"
    { (yyval.expNumber) = new CExpNumber( (yyvsp[(1) - (1)].ival) ); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 258 "miniJava.y"
    { (yyval.expId) = new CExpId( (yyvsp[(1) - (1)].sval) ); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 262 "miniJava.y"
    { (yyval.expSingle) = new CExpSingle( "True" ); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 263 "miniJava.y"
    { (yyval.expSingle) = new CExpSingle( "False" ); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 264 "miniJava.y"
    { (yyval.expSingle) = new CExpSingle( "this" ); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 268 "miniJava.y"
    { (yyval.expList) = new CExpList( (yyvsp[(1) - (2)].exp), (yyvsp[(2) - (2)].expRestList) ); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 269 "miniJava.y"
    { (yyval.expList) = new CExpList( (yyvsp[(1) - (1)].exp), 0 ); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 270 "miniJava.y"
    { (yyval.expList) = new CExpList( 0, 0 ); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 274 "miniJava.y"
    { (yyval.expRestList) = new CExpRestList( (yyvsp[(1) - (1)].expRest), 0 ); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 275 "miniJava.y"
    { (yyval.expRestList) = new CExpRestList( (yyvsp[(2) - (2)].expRest), (yyvsp[(1) - (2)].expRestList) ); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 279 "miniJava.y"
    { (yyval.expRest) = new CExpRest((yyvsp[(2) - (2)].exp)); }
    break;


/* Line 1792 of yacc.c  */
#line 2063 "miniJava.tab.cpp"
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
#line 282 "miniJava.y"


/* ������� ��������� ������. */
void yyerror( CProgram*& root, const char* str )
{
	std::cout << str << " in " << yylineno << " line" << std::endl;
}