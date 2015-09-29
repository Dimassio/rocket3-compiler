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
%token CLASS
%token EXTENDS
%token PRIVATE
%token PUBLIC
%token RETURN
%token BLOCK_COMMENT
%token LINE_COMMENT
%token <sval> ID

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

/* ������� ��������� ������. */
void yyerror( int*, const char* str )
{
	std::cout << str << std::endl;
}