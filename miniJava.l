%option noyywrap
%option yylineno

%{
#include <iostream>
#include <cmath>
#include <cstring>
#include "miniJava.tab.hpp"
#define YY_DECL extern "C" int yylex()
%}
	
LETTER										[A-Za-z]
DIGIT										[0-9]
ID											{LETTER}({LETTER}|{DIGIT}|_)*
INTEGER_LITERAL								{DIGIT}*
OP											[+-/*"/"|<&]

%%
"\n"
"class"										{ return CLASS; }
"extends"									{ return EXTENDS; }
"private"									{ return PRIVATE; }
"public"									{ return PUBLIC; }
"return"									{ return RETURN; }
"/*"({LETTER}|{DIGIT}|{OP}|" ")*"*/"		{ return BLOCK_COMMENT; }
"//"({LETTER}|{DIGIT}|{OP}|" ")*"\n"		{ return LINE_COMMENT; }
{INTEGER_LITERAL}							{ return NUMBER; }  
{ID}										{ return ID; }
{OP}										{ return yytext[0]; }

%%
extern int YYText();
