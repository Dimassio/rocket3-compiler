/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 11 "miniJava.y"
 #include "Common.h"
#include "CMiniJException.h"
#include <string>


/* Line 2058 of yacc.c  */
#line 52 "miniJava.tab.hpp"

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
/* Line 2058 of yacc.c  */
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


/* Line 2058 of yacc.c  */
#line 126 "miniJava.tab.hpp"
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
