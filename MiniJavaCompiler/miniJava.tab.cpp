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
extern "C" int yylex();
void yyerror( int*, const char* );

/* Line 371 of yacc.c  */
#line 74 "miniJava.tab.cpp"

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     CLASS = 260,
     EXTENDS = 261,
     PRIVATE = 262,
     PUBLIC = 263,
     RETURN = 264,
     BLOCK_COMMENT = 265,
     LINE_COMMENT = 266,
     IF = 267,
     ELSE = 268,
     BOOLEAN = 269,
     INT = 270,
     WHILE = 271,
     FOR = 272,
     SYSTEMOUTPRINTLN = 273,
     LENGTH = 274,
     TRUE = 275,
     FALSE = 276,
     THIS = 277,
     NEW = 278,
     VOID = 279,
     STATIC = 280,
     MAIN = 281,
     STRING = 282
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "miniJava.y"

	int ival;
	char sval[255];


/* Line 387 of yacc.c  */
#line 150 "miniJava.tab.cpp"
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
int yyparse (int* hasError);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MINIJAVA_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 178 "miniJava.tab.cpp"

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
#define YYLAST   503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,     2,     3,     2,
      35,    38,     7,     6,    41,     5,    44,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      43,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     4,    39,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    30,    37,    43,
      49,    54,    63,    71,    79,    86,    88,    91,    93,    96,
     100,   114,   127,   140,   152,   156,   159,   160,   162,   165,
     169,   171,   174,   178,   180,   182,   184,   186,   188,   192,
     200,   206,   212,   217,   225,   229,   233,   237,   241,   245,
     249,   253,   257,   262,   266,   273,   275,   277,   279,   281,
     283,   289,   294,   297,   301,   304,   306,   307,   309,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    49,    -1,    49,    48,    -1,    50,    -1,
      48,    50,    -1,    11,    10,    34,    14,    31,    30,    32,
      35,    33,    36,    37,    38,    34,    60,    39,    39,    -1,
      11,    10,    34,    51,    52,    39,    -1,    11,    10,    34,
      52,    39,    -1,    11,    10,    34,    51,    39,    -1,    11,
      10,    34,    39,    -1,    11,    10,    12,    10,    34,    51,
      52,    39,    -1,    11,    10,    12,    10,    34,    52,    39,
      -1,    11,    10,    12,    10,    34,    51,    39,    -1,    11,
      10,    12,    10,    34,    39,    -1,    53,    -1,    51,    53,
      -1,    54,    -1,    52,    54,    -1,    59,    10,    40,    -1,
      14,    59,    10,    35,    55,    38,    34,    51,    58,    15,
      61,    40,    39,    -1,    14,    59,    10,    35,    55,    38,
      34,    58,    15,    61,    40,    39,    -1,    14,    59,    10,
      35,    55,    38,    34,    51,    15,    61,    40,    39,    -1,
      14,    59,    10,    35,    55,    38,    34,    15,    61,    40,
      39,    -1,    59,    10,    56,    -1,    59,    10,    -1,    -1,
      57,    -1,    56,    57,    -1,    41,    59,    10,    -1,    60,
      -1,    58,    60,    -1,    21,    36,    37,    -1,    21,    -1,
      20,    -1,    33,    -1,    30,    -1,    10,    -1,    34,    58,
      39,    -1,    18,    35,    61,    38,    60,    19,    60,    -1,
      22,    35,    61,    38,    60,    -1,    24,    35,    61,    38,
      40,    -1,    10,    42,    61,    40,    -1,    10,    36,    61,
      37,    42,    61,    40,    -1,    61,    42,    61,    -1,    61,
      43,    61,    -1,    61,     4,    61,    -1,    61,     3,    61,
      -1,    61,     5,    61,    -1,    61,     6,    61,    -1,    61,
       8,    61,    -1,    61,     7,    61,    -1,    61,    36,    61,
      37,    -1,    61,    44,    25,    -1,    61,    44,    10,    35,
      62,    38,    -1,     9,    -1,    26,    -1,    27,    -1,    10,
      -1,    28,    -1,    29,    21,    36,    61,    37,    -1,    29,
      10,    35,    38,    -1,    45,    61,    -1,    35,    61,    38,
      -1,    61,    63,    -1,    61,    -1,    -1,    64,    -1,    63,
      64,    -1,    41,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    61,    65,    66,    70,    74,    75,    76,
      77,    78,    79,    80,    81,    85,    86,    90,    91,    95,
      99,   100,   101,   102,   106,   107,   108,   112,   113,   117,
     121,   122,   126,   127,   128,   129,   130,   131,   135,   136,
     137,   138,   139,   140,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   167,   168,   169,   173,   174,   178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'&'", "'|'", "'-'", "'+'", "'*'", "'/'",
  "NUMBER", "ID", "CLASS", "EXTENDS", "PRIVATE", "PUBLIC", "RETURN",
  "BLOCK_COMMENT", "LINE_COMMENT", "IF", "ELSE", "BOOLEAN", "INT", "WHILE",
  "FOR", "SYSTEMOUTPRINTLN", "LENGTH", "TRUE", "FALSE", "THIS", "NEW",
  "VOID", "STATIC", "MAIN", "STRING", "'{'", "'('", "'['", "']'", "')'",
  "'}'", "';'", "','", "'='", "'<'", "'.'", "'!'", "$accept", "Program",
  "ClassDecls", "MainClass", "ClassDecl", "VarDecls", "MethodDecls",
  "VarDecl", "MethodDecl", "FormalList", "FormalRests", "FormalRest",
  "Statements", "Type", "Statement", "Exp", "ExpList", "ExpRests",
  "ExpRest", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    38,   124,    45,    43,    42,    47,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   123,    40,    91,    93,    41,   125,
      59,    44,    61,    60,    46,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    54,    54,    55,    55,    55,    56,    56,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    63,    63,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,    16,     6,     5,     5,
       4,     8,     7,     7,     6,     1,     2,     1,     2,     3,
      13,    12,    12,    11,     3,     2,     0,     1,     2,     3,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     7,
       5,     5,     4,     7,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     6,     1,     1,     1,     1,     1,
       5,     4,     2,     3,     2,     1,     0,     1,     2,     2
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
       0,     0,     0,    30,     0,    28,     0,     0,     0,    55,
      58,    56,    57,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    29,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,    42,     0,     0,    63,    47,
      46,    48,    49,    51,    50,     0,    23,    44,    45,     0,
      53,     0,     0,     0,     0,     0,     0,     6,     0,    61,
       0,    52,    66,     0,    40,    41,    22,     0,    21,     0,
      60,    65,     0,     0,    20,    43,     0,    64,    67,    54,
      39,    69,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     3,     8,    24,    25,    26,    27,    54,
      62,    63,    72,    28,    73,    87,   162,   167,   168
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
       5,    16,    21,    17,     8,   -77,    34,    17,   -77,    47,
      -7,   -77,    31,    61,   366,    45,    50,   -77,   465,   -77,
      53,   -77,   -77,   -77,   371,     1,   -77,   -77,    76,    71,
     388,    95,    67,   -77,     4,   -77,   -77,   -77,    68,    72,
     -77,   393,    10,    80,   -77,   -77,   -77,    92,   -77,    11,
     -77,   465,    73,   -77,    88,   117,    91,    97,   104,   108,
     426,   465,   104,   -77,    98,    51,    38,   100,   112,   113,
     415,   443,   456,   -77,   119,   -77,   415,    38,    38,   -77,
     -77,   -77,   -77,   -77,    42,    38,    38,    52,    38,    38,
      38,    51,   406,    38,   469,    38,   -77,   -77,   110,    74,
      94,   115,   120,   116,   346,    38,    38,    38,    38,    38,
      38,    38,   114,    38,    38,    29,   136,   158,   178,   -77,
     200,    38,   220,   118,   109,   -77,   129,    38,   -77,   330,
     330,   335,   335,    70,    70,   242,   -77,   346,   346,   133,
     -77,   415,   415,    93,   130,   262,   131,   -77,    38,   -77,
     284,   -77,    38,   152,   -77,   -77,   -77,   134,   -77,   304,
     -77,   326,   137,   415,   -77,   -77,    38,   135,   -77,   -77,
     -77,   346,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   148,   -19,    44,   -18,   447,   -77,
     -77,   125,   -63,   -15,   -72,   -76,   -77,   -77,    22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      96,    99,   100,    31,    98,    13,    35,    92,    94,   103,
     104,    41,   116,   117,   118,    18,     1,   120,    18,   122,
      96,     5,    96,    35,    18,    18,     4,    14,     6,   129,
     130,   131,   132,   133,   134,   135,    55,   137,   138,   139,
      36,    71,     9,    45,    10,   145,    74,    79,    80,    50,
      53,   150,   101,    35,   140,   105,   106,   107,   108,   109,
     110,    12,    15,   102,    81,    82,    83,    84,    34,   153,
     154,    16,   159,    85,    42,    29,   161,   105,   106,   107,
     108,   109,   110,    86,    30,    49,    38,    77,   111,    32,
     171,   170,   112,    78,   113,   114,   115,   105,   106,   107,
     108,   109,   110,    39,    44,    43,   111,    47,    46,    56,
     111,   124,   113,   114,   115,    51,   113,   114,   115,   105,
     106,   107,   108,   109,   110,    52,    57,    58,    59,    97,
     111,    60,    76,   155,   125,    88,   113,   114,   115,   105,
     106,   107,   108,   109,   110,    61,    64,    89,    90,   123,
     126,   148,   111,   136,   128,    11,   127,   147,   113,   114,
     115,   105,   106,   107,   108,   109,   110,   149,   152,   156,
     158,   163,   111,   164,   141,   169,   166,     0,   113,   114,
     115,   105,   106,   107,   108,   109,   110,    75,     0,   172,
       0,     0,     0,     0,   111,     0,   142,     0,     0,     0,
     113,   114,   115,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,   111,     0,   143,     0,     0,     0,
     113,   114,   115,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
     144,     0,   113,   114,   115,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,   111,     0,     0,     0,
     146,     0,   113,   114,   115,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,   151,
       0,     0,     0,     0,   113,   114,   115,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,   111,     0,
       0,     0,   157,     0,   113,   114,   115,   105,   106,   107,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,   160,     0,     0,     0,     0,   113,   114,   115,   105,
     106,   107,   108,   109,   110,   107,   108,   109,   110,     0,
     111,     0,   109,   110,   165,     0,   113,   114,   115,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,   111,   166,   113,   114,
     115,   111,   113,   114,   115,     0,    17,   113,   114,   115,
      18,    17,   111,     0,     0,    18,    19,    20,   113,   114,
     115,    19,    20,     0,     0,     0,    21,     0,    17,    22,
       0,    21,    18,    17,    22,    23,     0,    18,    19,    20,
      33,     0,     0,    19,    20,     0,    91,     0,    21,     0,
       0,    22,     0,    21,    67,    91,    22,    40,    68,     0,
      69,     0,    48,    67,     0,     0,    65,    68,     0,    69,
      70,    66,     0,     0,    67,   119,    19,    20,    68,    70,
      69,     0,     0,    65,     0,     0,    21,     0,    93,    22,
      70,    67,     0,    19,    20,    68,    91,    69,     0,     0,
       0,    95,    37,    21,    67,    17,    22,    70,    68,    91,
      69,    37,     0,     0,   121,    19,    20,    67,     0,    37,
      70,    68,     0,    69,     0,    21,    37,     0,    22,     0,
       0,     0,     0,    70
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      72,    77,    78,    18,    76,    12,    24,    70,    71,    85,
      86,    30,    88,    89,    90,    14,    11,    93,    14,    95,
      92,     0,    94,    41,    14,    14,    10,    34,    11,   105,
     106,   107,   108,   109,   110,   111,    51,   113,   114,    10,
      39,    60,    34,    39,    10,   121,    61,     9,    10,    39,
      39,   127,    10,    71,    25,     3,     4,     5,     6,     7,
       8,    14,    31,    21,    26,    27,    28,    29,    24,   141,
     142,    10,   148,    35,    30,    30,   152,     3,     4,     5,
       6,     7,     8,    45,    34,    41,    10,    36,    36,    36,
     166,   163,    40,    42,    42,    43,    44,     3,     4,     5,
       6,     7,     8,    32,    37,    10,    36,    35,    40,    36,
      36,    37,    42,    43,    44,    35,    42,    43,    44,     3,
       4,     5,     6,     7,     8,    33,    38,    10,    37,    10,
      36,    34,    34,    40,    40,    35,    42,    43,    44,     3,
       4,     5,     6,     7,     8,    41,    38,    35,    35,    39,
      35,    42,    36,    39,    38,     7,    36,    39,    42,    43,
      44,     3,     4,     5,     6,     7,     8,    38,    35,    39,
      39,    19,    36,    39,    38,    38,    41,    -1,    42,    43,
      44,     3,     4,     5,     6,     7,     8,    62,    -1,   167,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    43,    44,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    43,    44,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    44,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,     3,
       4,     5,     6,     7,     8,     5,     6,     7,     8,    -1,
      36,    -1,     7,     8,    40,    -1,    42,    43,    44,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    36,    41,    42,    43,
      44,    36,    42,    43,    44,    -1,    10,    42,    43,    44,
      14,    10,    36,    -1,    -1,    14,    20,    21,    42,    43,
      44,    20,    21,    -1,    -1,    -1,    30,    -1,    10,    33,
      -1,    30,    14,    10,    33,    39,    -1,    14,    20,    21,
      39,    -1,    -1,    20,    21,    -1,    10,    -1,    30,    -1,
      -1,    33,    -1,    30,    18,    10,    33,    39,    22,    -1,
      24,    -1,    39,    18,    -1,    -1,    10,    22,    -1,    24,
      34,    15,    -1,    -1,    18,    39,    20,    21,    22,    34,
      24,    -1,    -1,    10,    -1,    -1,    30,    -1,    15,    33,
      34,    18,    -1,    20,    21,    22,    10,    24,    -1,    -1,
      -1,    15,    25,    30,    18,    10,    33,    34,    22,    10,
      24,    34,    -1,    -1,    15,    20,    21,    18,    -1,    42,
      34,    22,    -1,    24,    -1,    30,    49,    -1,    33,    -1,
      -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    47,    49,    10,     0,    11,    48,    50,    34,
      10,    50,    14,    12,    34,    31,    10,    10,    14,    20,
      21,    30,    33,    39,    51,    52,    53,    54,    59,    30,
      34,    59,    36,    39,    52,    53,    39,    54,    10,    32,
      39,    51,    52,    10,    37,    39,    40,    35,    39,    52,
      39,    35,    33,    39,    55,    59,    36,    38,    10,    37,
      34,    41,    56,    57,    38,    10,    15,    18,    22,    24,
      34,    51,    58,    60,    59,    57,    34,    36,    42,     9,
      10,    26,    27,    28,    29,    35,    45,    61,    35,    35,
      35,    10,    58,    15,    58,    15,    60,    10,    60,    61,
      61,    10,    21,    61,    61,     3,     4,     5,     6,     7,
       8,    36,    40,    42,    43,    44,    61,    61,    61,    39,
      61,    15,    61,    39,    37,    40,    35,    36,    38,    61,
      61,    61,    61,    61,    61,    61,    39,    61,    61,    10,
      25,    38,    38,    38,    40,    61,    40,    39,    42,    38,
      61,    37,    35,    60,    60,    40,    39,    40,    39,    61,
      37,    61,    62,    19,    39,    40,    41,    63,    64,    38,
      60,    61,    64
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
      yyerror (hasError, YY_("syntax error: cannot back up")); \
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
		  Type, Value, hasError); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, int* hasError)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, hasError)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    int* hasError;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (hasError);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, int* hasError)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, hasError)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    int* hasError;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, hasError);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, int* hasError)
#else
static void
yy_reduce_print (yyvsp, yyrule, hasError)
    YYSTYPE *yyvsp;
    int yyrule;
    int* hasError;
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
		       		       , hasError);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, hasError); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, int* hasError)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, hasError)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    int* hasError;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (hasError);

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
yyparse (int* hasError)
#else
int
yyparse (hasError)
    int* hasError;
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
#line 60 "miniJava.y"
    {}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 61 "miniJava.y"
    { /* Здесь выполняемый в случае совпадения код */ }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 65 "miniJava.y"
    {}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 66 "miniJava.y"
    {}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 70 "miniJava.y"
    {}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 74 "miniJava.y"
    {}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 75 "miniJava.y"
    {}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 76 "miniJava.y"
    {}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 77 "miniJava.y"
    {}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 78 "miniJava.y"
    {}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 79 "miniJava.y"
    {}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 80 "miniJava.y"
    {}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 81 "miniJava.y"
    {}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 85 "miniJava.y"
    {}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 86 "miniJava.y"
    {}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 90 "miniJava.y"
    {}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 91 "miniJava.y"
    {}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 95 "miniJava.y"
    {}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 99 "miniJava.y"
    {}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 100 "miniJava.y"
    {}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 101 "miniJava.y"
    {}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 102 "miniJava.y"
    {}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 106 "miniJava.y"
    {}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 107 "miniJava.y"
    {}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 108 "miniJava.y"
    {}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 112 "miniJava.y"
    {}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 113 "miniJava.y"
    {}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 117 "miniJava.y"
    {}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 121 "miniJava.y"
    {}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 122 "miniJava.y"
    {}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 126 "miniJava.y"
    {}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 127 "miniJava.y"
    {}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 128 "miniJava.y"
    {}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 129 "miniJava.y"
    {}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 130 "miniJava.y"
    {}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 131 "miniJava.y"
    { /* coding */}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 135 "miniJava.y"
    {}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 136 "miniJava.y"
    {}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 137 "miniJava.y"
    {}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 138 "miniJava.y"
    {}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 139 "miniJava.y"
    {}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 140 "miniJava.y"
    {}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 144 "miniJava.y"
    {}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 145 "miniJava.y"
    {}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 146 "miniJava.y"
    {}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 147 "miniJava.y"
    {}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 148 "miniJava.y"
    {}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 149 "miniJava.y"
    {}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 150 "miniJava.y"
    {}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 151 "miniJava.y"
    {}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 152 "miniJava.y"
    {}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 153 "miniJava.y"
    {}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 154 "miniJava.y"
    {}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 155 "miniJava.y"
    {}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 156 "miniJava.y"
    {}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 157 "miniJava.y"
    {}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 158 "miniJava.y"
    {}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 159 "miniJava.y"
    {}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 160 "miniJava.y"
    {}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 161 "miniJava.y"
    {}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 162 "miniJava.y"
    {}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 163 "miniJava.y"
    {}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 167 "miniJava.y"
    {}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 168 "miniJava.y"
    {}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 169 "miniJava.y"
    {}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 173 "miniJava.y"
    {}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 174 "miniJava.y"
    {}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 178 "miniJava.y"
    {}
    break;


/* Line 1792 of yacc.c  */
#line 1990 "miniJava.tab.cpp"
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
      yyerror (hasError, YY_("syntax error"));
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
        yyerror (hasError, yymsgp);
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
		      yytoken, &yylval, hasError);
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
		  yystos[yystate], yyvsp, hasError);
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
  yyerror (hasError, YY_("memory exhausted"));
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
                  yytoken, &yylval, hasError);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, hasError);
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
#line 181 "miniJava.y"


/* Функция обработки ошибки. */
void yyerror( int*, const char* str )
{
	std::cout << str << std::endl;
}