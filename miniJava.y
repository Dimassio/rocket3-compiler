%{
#include <iostream>
#include "Common.h"

extern "C" int yylex();
extern int yylineno;

void yyerror( CProgram*& root, const char* );
%}

%code requires { #include "Common.h"}
/* ��������� ������� �������. */

%parse-param { CProgram*& root }

/* ����������� ��������� ����� ���������. */
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
	CStatementList* statementList;
	CStatement* statement;
	CExpList* expList;
	CExp* exp;
	CType* type;
	CExpRestList* expRestList;
	CExpRest* expRest;
}

/* ����������� ����-��������������. ���������� ���� %right.
������� ���������� ����� - ��� ����� �������� ��������, ��� ������ ��� ���������. */
%right '='
%left '+''-' 
%left '*''/' 
%left '['']' 
%left '('')' 
%left '.' 
%left '!''&''<''|'AND

/* ����������� �������. ����� ������ ������������� � ������� ��� �� Union. */
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

/* ��������� ��� �� union � ������ �������. */
%type<program> Program
%type<mainClass> MainClass
%type<classDeclList> ClassDecls
%type<classDecl> ClassDecl
%type<varDeclList> VarDecls
%type<methodDecl> MethodDecl
%type<methodDeclList> MethodDecls
%type<varDecl> VarDecl
%type<formalList> FormalList
%type<formalRest> FormalRest
%type<formalRestList> FormalRests
%type<statement> Statement
%type<statementList> Statements
%type<expList> ExpList
%type<expRestList> ExpRests
%type<expRest> ExpRest
%type<exp> Exp
%type<type> Type

/* ������ � ��������� ������ �������. */
%%
Program:
	MainClass { root = new CProgram( $1, 0 ); }
	| MainClass ClassDecls { root = new CProgram( $1, $2 ); }
	;

ClassDecls:
	ClassDecl { $$ = new CClassDeclList( $1, 0 ); }
	| ClassDecls ClassDecl { $$ = new CClassDeclList($2, $1); }
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

/* ����� ����� ���� */
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

/* ����� ����� ���� */
Type:
	INT '['']' { $$ = new CType("int []"); }
	| INT { $$ = new CType("int"); }
	| BOOLEAN { $$ = new CType("boolean"); }
	| STRING { $$ = new CType("string"); }
	| VOID { $$ = new CType("void"); }
	| ID { $$ = new CType($1); }
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
	Exp '<' Exp { $$ = new CExp( "BinOp", "<", 0, $1, $3, "" ); }
	| Exp '&' Exp { $$ = new CExp( "BinOp", "&", 0, $1, $3, "" ); }
	| Exp '-' Exp { $$ = new CExp( "BinOp", "-", 0, $1, $3, "" ); }
	| Exp '+' Exp { $$ = new CExp( "BinOp", "+", 0, $1, $3, "" ); }
	| Exp '/' Exp { $$ = new CExp( "BinOp", "/", 0, $1, $3, "" ); }
	| Exp '*' Exp { $$ = new CExp( "BinOp", "*", 0, $1, $3, "" ); }
	| Exp '[' Exp ']' { $$ = new CExp( "SquareBrackets", "", 0, $1, $3, "" ); }
	| Exp '.' LENGTH { $$ = new CExp( "Length", "", 0, $1, 0, "" ); }
	| Exp '.' ID '(' ExpList ')' { $$ = new CExp( "MethodCall", "", $5, $1, 0, "" ); }
	| NUMBER { $$ = new CExp( "SingleExp", "Number", 0, 0, 0, "" ); } /* �������� - int*/
	| TRUE { $$ = new CExp( "SingleExp", "True", 0, 0, 0, "" ); }
	| FALSE { $$ = new CExp( "SingleExp", "False", 0, 0, 0, "" ); }
	| ID { $$ = new CExp( "SingleExp", "Id", 0, 0, 0, $1 ); }
	| THIS { $$ = new CExp( "SingleExp", "This", 0, 0, 0, "" ); }
	| NEW INT '[' Exp ']' { $$ = new CExp( "NewIntArray", "", 0, $4, 0, "" ); }
	| NEW ID '(' ')' { $$ = new CExp( "NewCustomType", "", 0, 0, 0, $2 ); }
	| '!' Exp { $$ = new CExp( "NotExp", "", 0, $2, 0, "" ); }
	| '(' Exp ')' { $$ = new CExp( "RoundBrackets", "", 0, $2, 0, "" ); }
	;

ExpList:
	Exp ExpRests { $$ = new CExpList($1, $2); }
	| Exp { $$ = new CExpList($1, 0); }
	| { $$ = new CExpList(0, 0); }
	;

ExpRests:
	ExpRest { $$ = new CExpRestList($1, 0); }
	| ExpRests ExpRest { $$ = new CExpRestList($2, $1); }
	;

ExpRest:
	',' Exp { $$ = new CExpRest($2); }
	;

%%

/* ������� ��������� ������. */
void yyerror( CProgram*& root, const char* str )
{
	std::cout << str << " in " << yylineno << " line" << std::endl;
}