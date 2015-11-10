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
	MainClass { root = new CProgram( $1, 0, yylineno ); }
	| MainClass ClassDecls { root = new CProgram( $1, $2, yylineno ); }
	;

ClassDecls:
	ClassDecl { $$ = new CClassDeclList( $1, 0, yylineno ); }
	| ClassDecls ClassDecl { $$ = new CClassDeclList($2, $1, yylineno); }
	;

MainClass:
	CLASS ID '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' ID ')' '{' Statement '}' '}' { $$ = new CMainClass( $2, $12, $15, yylineno ); }
	;

ClassDecl:
	CLASS ID '{' VarDecls MethodDecls '}' { $$ = new CClassDecl( $2, "", $4, $5, yylineno ); }
	| CLASS ID '{' MethodDecls '}' { $$ = new CClassDecl( $2, "", 0, $4, yylineno); }
	| CLASS ID '{' VarDecls '}' { $$ = new CClassDecl( $2, "", $4, 0, yylineno ); }
	| CLASS ID '{'  '}' { $$ = new CClassDecl( $2, "", 0, 0, yylineno ); }
	| CLASS ID EXTENDS ID '{' VarDecls MethodDecls '}' { $$ = new CClassDecl( $2, $4, $6, $7, yylineno ); }
	| CLASS ID EXTENDS ID '{' MethodDecls '}' { $$ = new CClassDecl( $2, $4, 0, $6, yylineno ); }
	| CLASS ID EXTENDS ID '{' VarDecls '}' { $$ = new CClassDecl( $2, $4, $6, 0, yylineno ); }
	| CLASS ID EXTENDS ID '{' '}' { $$ = new CClassDecl( $2, $4, 0, 0, yylineno ); }
	;

VarDecls:
	VarDecl { $$ = new CVarDeclList( $1, 0, yylineno ); }
	| VarDecls VarDecl { $$ = new CVarDeclList( $2, $1, yylineno ); }
	;

MethodDecls:
	MethodDecl { $$ = new CMethodDeclList( $1, 0, yylineno ); }
	| MethodDecls MethodDecl { $$ = new CMethodDeclList( $2, $1, yylineno ); }
	;

VarDecl:
	Type ID ';' { $$ = new CVarDecl( $1, $2, yylineno ); }  
	;

MethodDecl:
	PUBLIC Type ID '(' FormalList ')' '{' VarDecls Statements RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, $8, $9, $11, yylineno); }
	| PUBLIC Type ID '(' FormalList ')' '{' Statements RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, 0, $8, $10, yylineno); }
	| PUBLIC Type ID '(' FormalList ')' '{' VarDecls RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, $8, 0, $10, yylineno ); }
	| PUBLIC Type ID '(' FormalList ')' '{' RETURN Exp ';' '}' { $$ = new CMethodDecl( $2, $3, $5, 0, 0, $9, yylineno ); }
	;

FormalList:
	Type ID FormalRests { $$ = new CFormalList( $1, $2, $3, yylineno ); }
	| Type ID { $$ = new CFormalList( $1, $2, 0, yylineno ); }
	| { $$ = new CFormalList( 0, "", 0, yylineno ); }
	;

FormalRests:
	FormalRest { $$ = new CFormalRestList( $1, 0, yylineno ); }
	| FormalRests FormalRest { $$ = new CFormalRestList( $2, $1, yylineno ); }
	;

FormalRest:
	',' Type ID { $$ = new CFormalRest( $2, $3, yylineno ); }
	;

Statements:
	Statement { $$ = new CStatementList( $1, 0, yylineno ); }
	| Statements Statement { $$ = new CStatementList( $2, $1, yylineno ); }
	;

Type:
	INT '['']' { $$ = new CType("int []", yylineno); }
	| INT { $$ = new CType("int", yylineno); }
	| BOOLEAN { $$ = new CType("boolean", yylineno); }
	| STRING { $$ = new CType("string", yylineno); }
	| VOID { $$ = new CType("void", yylineno); }
	| ID { $$ = new CType($1, yylineno); }
	;

Statement:
	'{' Statements '}' { $$ = new CStatement( "BlockStatement", $2, 0, 0, 0, 0, "", yylineno ); }
	| IF '(' Exp ')' Statement ELSE Statement { $$ = new CStatement( "IfStatement", 0, $5, $7, $3, 0, "", yylineno ); }
	| WHILE '(' Exp ')' Statement { $$ = new CStatement( "WhileStatement", 0, $5, 0, $3, 0, "", yylineno ); }
	| SYSTEMOUTPRINTLN '(' Exp ')' ';' { $$ = new CStatement( "PrintlnStatement", 0, 0, 0, $3, 0, "", yylineno ); }
	| ID '=' Exp ';' { $$ = new CStatement( "AssignStatement", 0, 0, 0, $3, 0, $1, yylineno ); }
	| ID '[' Exp ']' '=' Exp ';' { $$ = new CStatement( "ArrayAssignStatement", 0, 0, 0, $3, $6, $1, yylineno ); }
	;

Exp:
	ExpLength { $$ = new CExp( $1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
	| ExpMethodCall { $$ = new CExp( 0, $1, 0, 0, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
	| ExpNewIntArray { $$ = new CExp( 0, 0, $1, 0, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
	| ExpNewCustomType { $$ = new CExp( 0, 0, 0, $1, 0, 0, 0, 0, 0, 0, 0, yylineno ); }
	| ExpSquareBrackets { $$ = new CExp( 0, 0, 0, 0, $1, 0, 0, 0, 0, 0, 0, yylineno ); }
	| ExpRoundBrackets { $$ = new CExp( 0, 0, 0, 0, 0, $1, 0, 0, 0, 0, 0, yylineno ); }
	| ExpNot { $$ = new CExp( 0, 0, 0, 0, 0, 0, $1, 0, 0, 0, 0, yylineno ); }
	| ExpNumber { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, $1, 0, 0, 0, yylineno ); }
	| ExpId { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, $1, 0, 0, yylineno ); }
	| ExpSingle { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, $1, 0, yylineno ); }
	| ExpBinOperation { $$ = new CExp( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, $1, yylineno ); }
	;

ExpLength:
	Exp '.' LENGTH { $$ = new CExpLength( $1, yylineno ); }
	;

ExpMethodCall:
	Exp '.' ID '(' ExpList ')' { $$ = new CExpMethodCall( $1, $3, $5, yylineno ); }
	;

ExpNewIntArray:
	NEW INT '[' Exp ']' { $$ = new CExpNewIntArray( $4, yylineno ); }
	;

ExpNewCustomType:
	NEW ID '(' ')' { $$ = new CExpNewCustomType( new CType( $2, yylineno ), yylineno ) }
	;

ExpSquareBrackets:
	Exp '[' Exp ']' { $$ = new CExpSquareBrackets( $1, $3, yylineno ); }
	;

ExpRoundBrackets:
	'(' Exp ')' { $$ = new CExpRoundBrackets( $2, yylineno ); }
	;

ExpNot:
	'!' Exp { $$ = new CExpNot( $2, yylineno ); }
	;

ExpBinOperation:
	Exp '<' Exp { $$ = new CExpBinOperation( "<", $1, $3, yylineno ); }
	| Exp AND Exp { $$ = new CExpBinOperation( "&&", $1, $3, yylineno ); }
	| Exp '-' Exp { $$ = new CExpBinOperation( "-", $1, $3, yylineno ); }
	| Exp '+' Exp { $$ = new CExpBinOperation( "+", $1, $3, yylineno ); }
	| Exp '/' Exp { $$ = new CExpBinOperation( "/", $1, $3, yylineno ); }
	| Exp '*' Exp { $$ = new CExpBinOperation( "*", $1, $3, yylineno ); }
	;

ExpNumber:
	NUMBER { $$ = new CExpNumber( $1, yylineno ); }
	;

ExpId:	
	ID { $$ = new CExpId( $1, yylineno ); }
	;

ExpSingle:
	TRUE { $$ = new CExpSingle( "True", yylineno ); }
	| FALSE { $$ = new CExpSingle( "False", yylineno ); }
	| THIS { $$ = new CExpSingle( "this", yylineno ); }
	;

ExpList:
	Exp ExpRests { $$ = new CExpList( $1, $2, yylineno ); }
	| Exp { $$ = new CExpList( $1, 0, yylineno ); }
	| { $$ = new CExpList( 0, 0, yylineno ); }
	;

ExpRests:
	ExpRest { $$ = new CExpRestList( $1, 0, yylineno ); }
	| ExpRests ExpRest { $$ = new CExpRestList( $2, $1, yylineno ); }
	;

ExpRest:
	',' Exp { $$ = new CExpRest($2, yylineno); }
	;

%%

/* Функция обработки ошибки. */
void yyerror( CProgram*& root, const char* str )
{
	std::cout << str << " in " << yylineno << " line" << std::endl;
}