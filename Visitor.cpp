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
		std::cout << "class " << mainClass->GetClassName << " public static void main(string[] "
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

	void visit( const IExpList* )
	{

	}

	void visit( const IFormalList* )
	{

	}

	void visit( const IMethodDecl* )
	{

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

	void visit( const IStatementList* )
	{

	}

	void visit( const IType* )
	{

	}

	void visit( const IVarDecl* )
	{

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

};
