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
BRACKETS									[\[\](){}]
OPERANDS									[-+*/!.,;:=<&|]
WHITESPACES									[ \t\n]
OTHERSYMBOLS								[\"\'_]

%%
{WHITESPACES}								{ }
{BRACKETS}									{ return *yytext; }
{OPERANDS}									{ return *yytext; }
"&&"										{ return AND; }
"void"										{ return VOID; }
"static"									{ return STATIC; }
"main"										{ return MAIN; }
"String"									{ return STRING; }
"if"										{ return IF; }
"else"										{ return ELSE; }
"boolean"									{ return BOOLEAN; }
"int"										{ return INT; }
"while"										{ return WHILE; }
"System.out.println"						{ return SYSTEMOUTPRINTLN; }
"length"									{ return LENGTH; }
"true"										{ return TRUE; }
"false"										{ return FALSE; }
"this"										{ return THIS; }
"new"										{ return NEW; }	
"class"										{ return CLASS; }
"extends"									{ return EXTENDS; }
"public"									{ return PUBLIC; }
"return"									{ return RETURN; }
"/*"({LETTER}|{DIGIT}|{OPERANDS}|{BRACKETS}|{WHITESPACES}|{OTHERSYMBOLS})*"*/"				{ /* block comment */ }
"//"({LETTER}|{DIGIT}|{OPERANDS}|{BRACKETS}|" "|\t|{OTHERSYMBOLS})*"\n"						{ /* line comment */ }
{INTEGER_LITERAL}							{ return NUMBER; }  
{ID}										{ return ID; }
.											{ std::cout << "Unexpected symbol at line: " << yylineno << std::endl; }

%%
extern int YYText();
