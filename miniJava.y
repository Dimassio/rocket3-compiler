%{
#include <iostream>
extern "C" int yylex();
void yyerror( int*, const char* );
%}

/* Этот код будет помещен до определения Union
Обычно используется для описания классов, реализующих синтаксическое дерево.
%code requires { #include <common.h> }*/
/* Параметры функции парсера. */
%parse-param { int* hasError }

/* Определение возможных типов выражения. */
%union{
	int ival;
	char sval[255];
}

/* Определение лево-ассоцитивности. Аналогично есть %right.
Порядок объявление важен - чем позже объявлен оператор, тем больше его приоритет.
В данном случае оба оператора лево-ассоциативные, но - имеет более высокий приоритет, чем & и |. */
%left '&' '|'
%left '-' '+'
%left '*' '/'

/* Определение токенов. Можно задать ассоциируемый с токеном тип из Union. */
%token <ival> NUMBER
%token CLASS
%token EXTENDS
%token PRIVATE
%token PUBLIC
%token RETURN
%token BLOCK_COMMENT
%token LINE_COMMENT
%token <sval> ID

/* Связываем тип из union и символ парсера. */
%type<program> Program


/* Секция с описанием правил парсера. */
%%
Program:
	MainClass
	| MainClass ClassDecls { /* Здесь выполняемый в случае совпадения код */ }

ClassDecls:
	ClassDecl
	| ClassDecls ClassDecl

MainClass:
	CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' ')' '{' Statement '}' '}' {}

ClassDecl:
	CLASS ID '{' VarDecls MethodDecls '}' {}
	| CLASS ID '{' MethodDecls '}' {}
	| CLASS ID '{' VarDecls '}' {}
	| CLASS ID '{'  '}' {}
	| CLASS ID EXTENDS ID '{' VarDecls MethodDecls '}' {}
	| CLASS ID EXTENDS ID '{' MethodDecls '}' {}
	| CLASS ID EXTENDS ID '{' VarDecls '}' {}
	| CLASS ID EXTENDS ID '{' '}' {}

VarDecls:
	VarDecl
	| VarDecls VarDecl

MethodDecls:
	MethodDecl
	| MethodDecls MethodDecl

VarDecl:
	TYPE ID ';'

MethodDecl:
	PUBLIC TYPE ID '(' FormalList ')' '{' VarDecls Statements RETURN Exp ';' '}'
	| PUBLIC TYPE ID '(' FormalList ')' '{' Statements RETURN Exp ';' '}'
	| PUBLIC TYPE ID '(' FormalList ')' '{' VarDecls RETURN Exp ';' '}'
	| PUBLIC TYPE ID '(' FormalList ')' '{' RETURN Exp ';' '}'

FormalList:
	TYPE ID FormalRests
	| TYPE ID
	| 

FormalRests:
	FormalRest
	| FormalRests FormalRest

FormalRest:
	', ' TYPE ID 

Statements:
	Statement
	| Statements Statement

%%

/* Функция обработки ошибки. */
void yyerror( int*, const char* str )
{
	std::cout << str << std::endl;
}