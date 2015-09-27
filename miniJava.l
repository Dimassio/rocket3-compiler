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

{INTEGER_LITERAL}							{ printf("%s - ", yytext); std::cout << "NUMBER, line=" << yylineno << std::endl; }  
{ID}										{ std::cout << "ID, line=" << yylineno << std::endl; }
{OP}										{ std::cout << "OPERATOR, line=" << yylineno << std::endl; }
"class"										{ std::cout << "CLASS, line=" << yylineno << std::endl; }
"extends"									{ std::cout << "EXTENDS, line=" << yylineno << std::endl; }
"private"									{ std::cout << "PRIVATE, line=" << yylineno << std::endl; }
"public"									{ std::cout << "PUBLIC, line=" << yylineno << std::endl; }
"return"									{ std::cout << "RETURN, line=" << yylineno << std::endl; }
"/*"({LETTER}|{DIGIT}|{OP}|" ")*"*/"		{ std::cout <<"BLOCK COMMENT, line=" << yylineno << std::endl;}
"//"({LETTER}|{DIGIT}|{OP}|" ")*"\n"		{ std::cout <<"LINE COMMENT, line=" << yylineno << std::endl;}

%%
extern int YYText();
