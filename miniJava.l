%option noyywrap
%{
#include <iostream>
#include <cmath>
#include <cstring>
#define YY_DECL extern "C" int yylex()
%}


LETTER				[A-Za-z]
DIGIT				[0-9]
ID					{LETTER}({LETTER} | {DIGIT} | _)*
INTEGER_LITERAL		{DIGIT}*
OP					(&& | < | + | - | *)

%%

{LETTER}*				{ std::cout << "TEST\n"; }


%%
extern int YYText();
