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

%%
"\n"
"void"										{ return VOID; }
"static"									{ return STATIC; }
"main"										{ return MAIN; }
"string"									{ return STRING; }
"if"										{ return IF; }
"else"										{ return ELSE; }
"boolean"									{ return BOOLEAN; }
"int"										{ return INT; }
"while"										{ return WHILE; }
"for"										{ return FOR; }
"System.out.println"						{ return SYSTEMOUTPRINTLN; }
"length"									{ return LENGTH; }
"true"										{ return TRUE; }
"false"										{ return FALSE; }
"this"										{ return THIS; }
"new"										{ return NEW; }	
"class"										{ return CLASS; }
"extends"									{ return EXTENDS; }
"private"									{ return PRIVATE; }
"public"									{ return PUBLIC; }
"return"									{ return RETURN; }
"/*"({LETTER}|{DIGIT}|[+-/*|<&]|" ")*"*/"		{ return BLOCK_COMMENT; }
"//"({LETTER}|{DIGIT}|[+-/*|<&]|" ")*"\n"		{ return LINE_COMMENT; }
{INTEGER_LITERAL}							{ return NUMBER; }  
{ID}										{ return ID; }

%%
extern int YYText();
