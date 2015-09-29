%{
#include <iostream>
extern "C" int yylex();
void yyerror( int*, const char* );
%}

/* ���� ��� ����� ������� �� ����������� Union
������ ������������ ��� �������� �������, ����������� �������������� ������.
%code requires { #include <common.h> }*/
/* ��������� ������� �������. */
%parse-param { int* hasError }

/* ����������� ��������� ����� ���������. */
%union{
	int ival;
	char sval[255];
}

/* ����������� ����-��������������. ���������� ���� %right.
������� ���������� ����� - ��� ����� �������� ��������, ��� ������ ��� ���������.
� ������ ������ ��� ��������� ����-�������������, �� - ����� ����� ������� ���������, ��� & � |. */
%left '&' '|'
%left '-' '+'
%left '*' '/'

/* ����������� �������. ����� ������ ������������� � ������� ��� �� Union. */
%token <ival> NUMBER
%token <sval> ID
%token CLASS
%token EXTENDS
%token PRIVATE
%token PUBLIC
%token RETURN
%token BLOCK_COMMENT
%token LINE_COMMENT
%token IF
%token ELSE
%token BOOLEAN
%token INT
%token WHILE
%token FOR
%token SYSTEMOUTPRINTLN
%token LENGTH
%token TRUE
%token FALSE
%token THIS
%token NEW

/* ��������� ��� �� union � ������ �������. */
%type<program> Program


/* ������ � ��������� ������ �������. */
%%
Program:
	MainClass
	| MainClass ClassDecls { /* ����� ����������� � ������ ���������� ��� */ }

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
	Type ID ';'

MethodDecl:
	PUBLIC Type ID '(' FormalList ')' '{' VarDecls Statements RETURN Exp ';' '}'
	| PUBLIC Type ID '(' FormalList ')' '{' Statements RETURN Exp ';' '}'
	| PUBLIC Type ID '(' FormalList ')' '{' VarDecls RETURN Exp ';' '}'
	| PUBLIC Type ID '(' FormalList ')' '{' RETURN Exp ';' '}'

FormalList:
	Type ID FormalRests
	| Type ID
	| 

FormalRests:
	FormalRest
	| FormalRests FormalRest

FormalRest:
	',' Type ID 

Statements:
	Statement
	| Statements Statement

Type:
	INT '['']'
	| INT
	| BOOLEAN
	| ID { /* coding */}

Statement:
	'{' Statements '}'
	| IF '(' Exp ')' Statement ELSE Statement
	| WHILE '(' Exp ')' Statement
	| SYSTEMOUTPRINTLN '(' Exp ')' ';'
	| ID = Exp ';'
	| ID '['Exp']' '=' Exp;

Exp:
	Exp OP Exp
	| Exp '['Exp']'
	| Exp '.'LENGTH
	| Exp '.'ID '('ExpList')'
	| NUMBER
	| TRUE
	| FALSE
	| ID
	| THIS
	| NEW INT '['Exp']'
	| NEW ID '('')'
	| '!' Exp
	| '(' Exp ')'

ExpList:
	Exp ExpRests
	| Exp
	|

ExpRests:
	ExpRest
	| ExpRests Exprest

ExpRest:
	',' Exp 

%%

/* ������� ��������� ������. */
void yyerror( int*, const char* str )
{
	std::cout << str << std::endl;
}