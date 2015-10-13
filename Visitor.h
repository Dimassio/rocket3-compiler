#pragma once
#include "Grammar.h"

class IVisitor {
public:
	virtual ~IVisitor()
	{
	}

	void visit( const IProgram* );
	void visit( const IMainClass* );
	void visit( const IClassDecl* );
	void visit( const IClassDeclList* );
	void visit( const IExp* );
	void visit( const IExpList* );
	void visit( const IFormalList* );
	void visit( const IMethodDecl* );
	void visit( const IMethodDeclList* );
	void visit( const IStatement* );
	void visit( const IStatementList* );
	void visit( const IType* );
	void visit( const IVarDecl* );
	void visit( const IVarDeclList* );
};