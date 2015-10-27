%{
#include <iostream>
#include "Program.h"
#include "MainClass.h"
#include "ClassDecl.h"
#include "ClassDeclList.h"
#include "Exp.h"
#include "ExpList.h"
#include "FormalList.h"
#include "FormalRest.h"
#include "FormalRestList.h"
#include "MethodDecl.h"
#include "MethodDeclList.h"
#include "Statement.h"
#include "StatementList.h"
#include "Type.h"
#include "VarDecl.h"
#include "VarDeclList.h"

extern "C" int yylex();
extern int yylineno;

void yyerror( const char* );
%}

/* Этот код будет помещен до определения Union
Обычно используется для описания классов, реализующих синтаксическое дерево.
%code requires { #include <common.h> }*/
/* Параметры функции парсера. */

%parse-param { CProgram*& root }

/* Определение возможных типов выражения. */
%union{
	int ival;
	char sval[255];
	CProgram* program;
	CMainClass* mainClass;
	CClassDeclList* classDeclList;
	CClassDecl* classDecl;
	CVarDecl* varDecl;
	CVarDeclList* varDeclList;
	CMethodDecl* methodDecl;
	CMethodDeclList* methodDeclList;
	CFormalList* formalList;
	CFormalRest* formalRest;
	CFormalRestList* formalRestList;
	CStatement* statement;
	CStatementList* statementList;
	/*опишите свои классы здесь*/
}

/* Определение лево-ассоцитивности. Аналогично есть %right.
Порядок объявление важен - чем позже объявлен оператор, тем больше его приоритет. */
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
%type<mainClass> MainClass
%type<classDeclList> ClassDecls
%type<classDecl> ClassDecl
%type<varDeclList> VarDecls
%type<methodDecl> MethodDecl
%type<methodDeclList> MethodDecls
%type<varDecl> VarDecl
%type<varDeclList> VarDecls
%type<formalList> FormalList
%type<formalRest> FormalRest
%type<formalRestList> FormalRests
%type<statement> Statement
%type<statementList> Statements

/* Секция с описанием правил парсера. */
%%
Program:
	MainClass { root = new CProgram( $1, 0 ); }
	| MainClass ClassDecls { root = new CProgram( $1, $2 ); }
	;

ClassDecls:
	ClassDecl { $$ = new CClassDeclList( $1, 0 ); }
	| ClassDecls ClassDecl { $$ = new CCLassDeclList($2, $1); }
	;

MainClass:
	CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' ID ')' '{' Statement '}' '}' { $$ = new CMainClass( $2, $12, $15 ); }
	;

ClassDecl:
	CLASS ID '{' VarDecls MethodDecls '}' { $$ = new CClassDecl( $2, "", $4, $5 ); }
	| CLASS ID '{' MethodDecls '}' { $$ = new CClassDecl( $2, "", 0, $4); }
	| CLASS ID '{' VarDecls '}' { $$ = new CClassDecl( $2, "", $4, 0 ); }
	| CLASS ID '{'  '}' { $$ = new CClassDecl( $2, "", 0, 0 ); }
	| CLASS ID EXTENDS ID '{' VarDecls MethodDecls '}' { $$ = new CClassDecl( $2, $4, $6, $7 ); }
	| CLASS ID EXTENDS ID '{' MethodDecls '}' { $$ = new CClassDecl( $2, $4, 0, $6 ); }
	| CLASS ID EXTENDS ID '{' VarDecls '}' { $$ = new CClassDecl( $2, $4, $6, 0 ); }
	| CLASS ID EXTENDS ID '{' '}' { $$ = new CClassDecl( $2, $4, 0, 0 ); }
	;

VarDecls:
	VarDecl { $$ = new CVarDeclList( $1, 0 ); }
	| VarDecls VarDecl { $$ = new CVarDeclList( $2, $1 ); }
	;

MethodDecls:
	MethodDecl { $$ = new CMethodDeclList( $1, 0 ); }
	| MethodDecls MethodDecl { $$ = new CMethodDeclList( $2, $1 ); }
	;

/* Далее берет Саня */
VarDecl:
	Type ID ';' { $$ = new CVarDecl( $1, $2 ); }  
	;

MethodDecl:
	PUBLIC Type ID '(' FormalList ')' '{' VarDecls Statements RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, $8, $9, $11); }
	| PUBLIC Type ID '(' FormalList ')' '{' Statements RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, 0, $8, $10); }
	| PUBLIC Type ID '(' FormalList ')' '{' VarDecls RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, $8, 0, $10 ); }
	| PUBLIC Type ID '(' FormalList ')' '{' RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, 0, 0, $9 ); }
	;

FormalList:
	Type ID FormalRests { $$ = new CFormalList( $1, $2, $3 ); }
	| Type ID { $$ = new CFormalList( $1, $2, 0 ); }
	| { $$ = new CFormalList( 0, "", 0 ); }
	;

FormalRests:
	FormalRest { $$ = new CFormalRestList( $1, 0 ); }
	| FormalRests FormalRest { $$ = new CFormalRestList( $2, $1 ); }
	;

FormalRest:
	',' Type ID { $$ = new CFormalRest( $2, $3 ); }
	;

Statements:
	Statement { $$ = new CStatementList( $1, 0 ); }
	| Statements Statement { $$ = new CStatementList( $2, $1 ); }
	;

/* Далее берет Женя */
Type:
	INT '['']' { $$ = new Type("int []"); }
	| INT { $$ = new Type("int"); }
	| BOOLEAN { $$ = new Type("boolean"); }
	| STRING { $$ = new Type("string"); }
	| VOID { $$ = new Type("void"); }
	| ID { $$ = new Type($1); }
	;

Statement:
	'{' Statements '}' { $$ = new CStatement( "BlockStatement", $2, 0, 0, 0, 0, "" ); }
	| IF '(' Exp ')' Statement ELSE Statement { $$ = new CStatement( "IfStatement", 0, $5, $7, $3, 0, "" ); }
	| WHILE '(' Exp ')' Statement { $$ = new CStatement( "WhileStatement", 0, $5, 0, $3, 0, "" ); }
	| SYSTEMOUTPRINTLN '(' Exp ')' ';' { $$ = new CStatement( "PrintlnStatement", 0, 0, 0, $3, 0, "" ); }
	| ID '=' Exp ';' { $$ = new CStatement( "AssignStatement", 0, 0, 0, $3, 0, $1 ); }
	| ID '[' Exp ']' '=' Exp ';' { $$ = new CStatement( "ArrayAssignStatement", 0, 0, 0, $3, $6, $1 ); }
	;

Exp:
	Exp '<' Exp {}
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