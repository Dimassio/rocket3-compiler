%{
#include <iostream>
#include "Common.h"

extern "C" int yylex();
extern int yylineno;

void yyerror( CProgram*& root, const char* );
%}

%code requires { #include "Common.h"}

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
	CStatementList* statementList;
	CStatement* statement;
	CExpList* expList;
	CExp* exp;
	CExpMethodCall* expMethodCall;
	CExpBinOperation* expBinOperation;
	CExpNewIntArray* expNewIntArray;
	CExpNewCustomType* expNewCustomType;
	CExpSquareBrackets* expSquareBrackets;
	CExpRoundBrackets* expRoundBrackets;
	CExpNot* expNot;
	CExpNumber* expNumber;
	CExpId* expId;
	CExpSingle* expSingle;
	CExpLength* expLength;
	CType* type;
	CExpRestList* expRestList;
	CExpRest* expRest;
}

/* Определение ассоцитивности.
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
%type<formalList> FormalList
%type<formalRest> FormalRest
%type<formalRestList> FormalRests
%type<statement> Statement
%type<statementList> Statements
%type<expList> ExpList
%type<expRestList> ExpRests
%type<expRest> ExpRest
%type<exp> Exp
%type<expMethodCall> ExpMethodCall
%type<expBinOperation> ExpBinOperation
%type<expNewIntArray> ExpNewIntArray
%type<expNewCustomType> ExpNewCustomType
%type<expSquareBrackets> ExpSquareBrackets
%type<expRoundBrackets> ExpRoundBrackets
%type<expNot> ExpNot
%type<expNumber> ExpNumber
%type<expId> ExpId
%type<expSingle> ExpSingle
%type<expLength> ExpLength
%type<type> Type

/* Секция с описанием правил парсера. */
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
	ExpLength { $$ = new CExp( $1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ); }
	| ExpMethodCall { $$ = new CExp( 0, $1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ); }
	| ExpNewIntArray { $$ = new CExp( 0, 0, $1, 0, 0, 0, 0, 0, 0, 0, 0 ); }
	| ExpNewCustomType { $$ = new CExp( 0, 0, 0, $1, 0, 0, 0, 0, 0, 0, 0 ); }
	| ExpSquareBrackets { $$ = new CExp( 0, 0, 0, 0, $1, 0, 0, 0, 0, 0, 0 ); }
	| ExpRoundBrackets { $$ = new CExp( 0, 0, 0, 0, 0, $1, 0, 0, 0, 0, 0 ); }
	| ExpNot { $$ = new CExp( 0, 0, 0, 0, 0, 0, $1, 0, 0, 0, 0 ); }
	| ExpNumber { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, $1, 0, 0, 0 ); }
	| ExpId { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, $1, 0, 0 ); }
	| ExpSingle { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, $1, 0 ); }
	| ExpBinOperation { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, $1 ); }
	;

ExpLength:
	Exp '.' LENGTH { $$ = new CExpLength( $1 ); }
	;

ExpMethodCall:
	Exp '.' ID '(' ExpList ')' { $$ = new CExpMethodCall( $1, $3, $5 ); }
	;

ExpNewIntArray:
	NEW INT '[' Exp ']' { $$ = new CExpNewIntArray( $4 ); }
	;

ExpNewCustomType:
	NEW ID '(' ')' { $$ = new CExpNewCustomType( $2 ); }
	;

ExpSquareBrackets:
	Exp '[' Exp ']' { $$ = new CExpSquareBrackets( $1, $3 ); }
	;

ExpRoundBrackets:
	'(' Exp ')' { $$ = new CExpRoundBrackets( $2 ); }
	;

ExpNot:
	'!' Exp { $$ = new CExpNot( $2 ); }
	;

ExpBinOperation:
	Exp '<' Exp { $$ = new CExpBinOperation( "<", $1, $3 ); }
	| Exp AND Exp { $$ = new CExpBinOperation( "&&", $1, $3 ); }
	| Exp '-' Exp { $$ = new CExpBinOperation( "-", $1, $3 ); }
	| Exp '+' Exp { $$ = new CExpBinOperation( "+", $1, $3 ); }
	| Exp '/' Exp { $$ = new CExpBinOperation( "/", $1, $3 ); }
	| Exp '*' Exp { $$ = new CExpBinOperation( "*", $1, $3 ); }
	;

ExpNumber:
	NUMBER { $$ = new CExpNumber( $1 ); }
	;

ExpId:	
	ID { $$ = new CExpId( $1 ); }
	;

ExpSingle:
	TRUE { $$ = new CExpSingle( "True" ); }
	| FALSE { $$ = new CExpSingle( "False" ); }
	| THIS { $$ = new CExpSingle( "this" ); }
	;

ExpList:
	Exp ExpRests { $$ = new CExpList( $1, $2 ); }
	| Exp { $$ = new CExpList( $1, 0 ); }
	| { $$ = new CExpList( 0, 0 ); }
	;

ExpRests:
	ExpRest { $$ = new CExpRestList( $1, 0 ); }
	| ExpRests ExpRest { $$ = new CExpRestList( $2, $1 ); }
	;

ExpRest:
	',' Exp { $$ = new CExpRest($2); }
	;

%%

/* Функция обработки ошибки. */
void yyerror( CProgram*& root, const char* str )
{
	std::cout << str << " in " << yylineno << " line" << std::endl;
}