%{
#include <iostream>
extern "C" int yylex();
extern int yylineno;

void yyerror( const char* );
%}

/* Этот код будет помещен до определения Union
Обычно используется для описания классов, реализующих синтаксическое дерево.
%code requires { #include <common.h> }*/
/* Параметры функции парсера. */

/*%parse-param { int* hasError} */

/* Определение возможных типов выражения. */
%union{
	int ival;
	char sval[255];
}

/* Определение лево-ассоцитивности. Аналогично есть %right.
Порядок объявление важен - чем позже объявлен оператор, тем больше его приоритет.
В данном случае оба оператора лево-ассоциативные, но - имеет более высокий приоритет, чем & и |. */
%right '='
%left '+''-' 
%left '*''/' 
%left '['']' 
%left '('')' 
%left '.' 
%left '!''&''<''|'AND

/* Определение токенов. Можно задать ассоциируемый с токеном тип из Union. */
%token <ival> NUMBER
%token <sval> ID
%token CLASS
%token EXTENDS
%token PUBLIC
%token RETURN
%token IF
%token ELSE
%token AND
%token BOOLEAN
%token INT
%token WHILE
%token SYSTEMOUTPRINTLN
%token LENGTH
%token TRUE
%token FALSE
%token THIS
%token NEW
%token VOID
%token STATIC 
%token MAIN 
%token STRING

/* Связываем тип из union и символ парсера. */
%type<program> Program

/* Секция с описанием правил парсера. */
%%
Program:
	MainClass {}
	| MainClass ClassDecls { /* Здесь выполняемый в случае совпадения код */ }
	;

ClassDecls:
	ClassDecl {}
	| ClassDecls ClassDecl {}
	;

MainClass:
	CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' ID ')' '{' Statement '}' '}' {}
	| CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' ID ')' '{'  '}' '}' {}
	;

ClassDecl:
	CLASS ID '{' VarDecls MethodDecls '}' {}
	| CLASS ID '{' MethodDecls '}' {}
	| CLASS ID '{' VarDecls '}' {}
	| CLASS ID '{'  '}' {}
	| CLASS ID EXTENDS ID '{' VarDecls MethodDecls '}' {}
	| CLASS ID EXTENDS ID '{' MethodDecls '}' {}
	| CLASS ID EXTENDS ID '{' VarDecls '}' {}
	| CLASS ID EXTENDS ID '{' '}' {}
	;

VarDecls:
	VarDecl {}
	| VarDecls VarDecl {}
	;

MethodDecls:
	MethodDecl {}
	| MethodDecls MethodDecl {}
	;

VarDecl:
	Type ID ';' {}
	;

MethodDecl:
	PUBLIC Type ID '(' FormalList ')' '{' VarDecls Statements RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' Statements RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' VarDecls RETURN Exp ';' '}' {}
	| PUBLIC Type ID '(' FormalList ')' '{' RETURN Exp ';' '}' {}
	;

FormalList:
	Type ID FormalRests {}
	| Type ID {}
	|  {}
	;

FormalRests:
	FormalRest {}
	| FormalRests FormalRest {}
	;

FormalRest:
	',' Type ID {}
	;

Statements:
	Statement {}
	| Statements Statement {}
	;

Type:
	INT '['']' {}
	| INT {}
	| BOOLEAN {}
	| STRING {}
	| VOID {}
	| ID { /* coding */}
	;

Statement:
	'{' Statements '}' {}
	| IF '(' Exp ')' Statement ELSE Statement {}
	| WHILE '(' Exp ')' Statement {}
	| SYSTEMOUTPRINTLN '(' Exp ')' ';' {}
	| ID '=' Exp ';' {}
	| ID '['Exp']' '=' Exp ';' {}
	;

Exp:
	Exp '=' Exp {}
	| Exp '<' Exp {}
	| Exp AND Exp {}
	| Exp '|' Exp {}
	| Exp '&' Exp {}
	| Exp '-' Exp {}
	| Exp '+' Exp {}
	| Exp '/' Exp {}
	| Exp '*' Exp {}
	| Exp '['Exp']' {}
	| Exp '.'LENGTH {}
	| Exp '.'ID '('ExpList')' {}
	| NUMBER {}
	| TRUE {}
	| FALSE {}
	| ID {}
	| THIS {}
	| NEW INT '['Exp']' {}
	| NEW ID '('')' {}
	| '!' Exp {}
	| '(' Exp ')' {}
	;

ExpList:
	Exp ExpRests {}
	| Exp {}
	| {}
	;

ExpRests:
	ExpRest {}
	| ExpRests ExpRest {}
	;

ExpRest:
	',' Exp {}
	;

%%

/* Функция обработки ошибки. */
void yyerror( const char* str )
{
	std::cout << str << " in " << yylineno << " line" << std::endl;
}