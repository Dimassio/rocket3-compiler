#include "Visitor.h"

// Он выполняет вывод того, что находится в узле дерева.


class CPrettyPrinterVisitor : public IVisitor {
public:

	CPrettyPrinterVisitor()
	{
	}

	void visit( const CProgram* program )
	{
		std::cout << "Program has started:" << std::endl;
		CMainClass* mainClass = program->MainClass;
		mainClass->Accept( this );
		CClassDeclList* classDeclList = program->ClassDeclList;
		if( !classDeclList ) {
			return;
		}
		classDeclList->Accept( this );
	}

	void visit( const CMainClass* mainClass )
	{
		std::cout << "class " << mainClass->GetClassName << " public static void main(String[] "
			<< mainClass->GetArgName << " ) { " << std::endl;
		CStatement* statement = mainClass->Statement;
		statement->Accept( this );
		std::cout << "}" << std::endl;
		std::cout << "}" << std::endl;
	}

	void visit( const CClassDecl* classDecl )
	{
		std::cout << "class " << classDecl->GetClassName;
		if( classDecl->GetExtendedClassName != "" ) {
			std::cout << " extends " << classDecl->GetExtendedClassName;
		}
		std::cout << " { ";
		CVarDeclList* varDeclList = classDecl->VarDeclList;
		if( varDeclList != 0 ) {
			varDeclList->Accept( this );
		}
		CMethodDeclList* methodDeclList = classDecl->MethodDeclList;
		if( methodDeclList != 0 ) {
			methodDeclList->Accept( this );
		}
		std::cout << " } " << std::endl;
	}

	void visit( const CClassDeclList* classDeclList )
	{
		std::cout << "Class declarations:" << std::endl; // todo: или не нужен тут вывод?
		CClassDecl* classDecl = classDeclList->ClassDecl;
		classDecl->Accept( this );
		CClassDeclList* newClassDeclList = classDeclList->ClassDeclList;
		if( !newClassDeclList ) {
			return;
		}
		newClassDeclList->Accept( this );
	}

	void visit( const IExp* )
	{

	}

	void visit( const CExpList* expList )
	{
		CExp* exp = expList->Exp;
		CExpRestList* expRestList = expList->ExpRestList;
		if( exp ) {
			exp->Accept( this );
		}
		if( expRestList ) {
			expRestList->Accept( this );
		}
	}

	void visit( const CFormalList* formalList )
	{
		std::string id = formalList->Id;
		CType* type = formalList->Type;
		CFormalRestList* formalRestList = formalList->FormalRestList;
		if( !type && id = "" && !formalRestList ) {
			return;
		}
		type->Accept( this );
		std::cout << id;
		if( formalRestList ) {
			formalRestList->Accept( this );
		}
	}

	void visit( const CMethodDecl* methodDecl )
	{
		std::cout << "public ";
		( methodDecl->Type )->Accept( this );
		std::cout << methodDecl->Id << "( ";
		( methodDecl->FormalList )->Accept( this );
		std::cout << ") {";
		if( methodDecl->VarDeclList ) {
			( methodDecl->VarDeclList )->Accept( this );
		}
		if( methodDecl->StatementList ) {
			( methodDecl->StatementList )->Accept( this );
		}
		std::cout << "return ";
		( methodDecl->Exp )->Accept( this );
	}

	void visit( const CMethodDeclList* methodDeclList )
	{
		std::cout << "Methods declaration list" << std::endl; // todo: или не нужен тут вывод?
		CMethodDecl* methodDecl = methodDeclList->MethodDecl;
		methodDecl->Accept( this );
		CMethodDeclList* newMethodDeclList = methodDeclList->MethodDeclList;
		if( !newMethodDeclList ) {
			return;
		}
		newMethodDeclList->Accept( this );
	}

	void visit( const IStatement* )
	{

	}

	void visit( const CStatementList* statementList )
	{
		if( statementList->StatementList ) {
			( statementList->StatementList )->Accept( this );
		}
		( statementList->Statement )->Accept( this );
	}

	void visit( const IType* )
	{

	}

	void visit( const CVarDecl* varDecl )
	{
		( varDecl->Type )->Accept( this );
		std::cout << varDecl->VarName << ";" << std::endl;
	}

	void visit( const CVarDeclList* varDeclList )
	{
		std::cout << "Variables declaration list" << std::endl; // todo: или не нужен тут вывод?
		CVarDecl* varDecl = varDeclList->VarDecl;
		varDecl->Accept( this );
		CVarDeclList* newVarDeclList = varDeclList->VarDeclList;
		if( !newVarDeclList ) {
			return;
		}
		newVarDeclList->Accept( this );
	}

	void visit( const CFormalRestList* formalRestList )
	{
		if( formalRestList->FormalRestList ) {
			( formalRestList->FormalRestList )->Accept( this );
		}
		( formalRestList->FormalRest )->Accept( this );
	}

	void visit( const CFormalRest* formalRest )
	{
		std::cout << ", ";
		formalRest->Type->Accept( this );
		std::cout << formalRest->Id << std::endl;
	}

	void visit( const CExpRestList* expRestList )
	{
		if( expRestList->ExpRestList ) {
			( expRestList->ExpRestList )->Accept( this );
		}
		if( expRestList->Exp ) {
			( expRestList->Exp )->Accept( this );
		}
	}

	void visit( const CExpRest* expRest )
	{
		std::cout << ", ";
		( expRest->Exp )->Accept( this );
	}
};
