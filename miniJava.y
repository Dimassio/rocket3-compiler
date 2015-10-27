%{
#include <iostream>
#include "Program.h"
#include "MainClass.h"
#include "ClassDecl.h"
#include "ClassDeclList.h"
#include "Exp.h"
#include "ExpList.h"
#include "FormalList.h"
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
	CVarDeclList* varDeclList;
	CMethodDeclList* methodDeclList;
	CStatement* statement;
	/*опишите свои классы здесь*/
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
%type<mainClass> MainClass
%type<classDeclList> ClassDecls
%type<classDecl> ClassDecl
%type<varDeclList> VarDecls
%type<methodDeclList> MethodDecls
%type<statement> Statement
/*допишите определениея своих типао символов*/

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