#include "Visitor.h"

// Он выполняет вывод того, что находится в узле дерева.
/*
void CPrettyPrinterVisiter::Visit( const CClassType* classType )
{
assert( classType->Name() != 0 );
printf( "%s", classType->Name() );
}
*/

class CPrettyPrinterVisitor : public IVisitor {
public:

	void visit( const IMainClass* )
	{

	}

	void visit( const IClassDecl* )
	{

	}

	void visit( const IClassDeclList* )
	{

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

	void visit(const IFormalRest*)
	{

	}

	void visit(const IFormalRestList*)
	{

	}

	void visit( const IMethodDecl* )
	{

	}

	void visit( const IMethodDeclList* )
	{

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

	void visit( const IVarDeclList* )
	{

	}
};
