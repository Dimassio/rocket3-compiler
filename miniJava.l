%option noyywrap
%option yylineno

%{
#include <iostream>
#include <cmath>
#include <cstring>
#define YY_DECL extern "C" int yylex()
%}
	
LETTER										[A-Za-z]
DIGIT										[0-9]
ID											{LETTER}({LETTER}|{DIGIT}|_)*
INTEGER_LITERAL								{DIGIT}*
OP											[+-/*"/"|<"&&"]

%%

{INTEGER_LITERAL} 							{ std::cout << "NUMBER\n"; }  
{ID}										{ std::cout << "ID\n"; }
{OP}										{ std::cout << "OPERATOR\n"; }
"class"										{ std::cout << "CLASS\n"; }
"extends"									{ std::cout << "EXTENDS\n"; }
"private"									{ std::cout << "PRIVATE\n"; }
"public"									{ std::cout << "PUBLIC\n"; }
"return"									{ std::cout << "RETURN\n"; }
"/*"({LETTER}|{DIGIT}|{OP}|" ")*"*/"		{std::cout <<"BLOCK COMMENT\n";}
"//"({LETTER}|{DIGIT}|{OP}|" ")*"\n"	    {std::cout <<"LINE COMMENT\n";}

%%
extern int YYText();
