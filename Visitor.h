#pragma once

#include <iostream>
#include "Grammar.h"
#include "Common.h"

class IVisitor {
public:
	virtual ~IVisitor()
	{
	}

	void visit( const IProgram* ); // todo: заменить интерфейсы на классы-реализации
	void visit( const IMainClass* );
	void visit( const IClassDecl* );
	void visit( const IClassDeclList* );
	void visit( const IExp* );
	void visit( const IExpList* );
	void visit( const IFormalList* );
	void visit( const IFormalRest*);
	void visit( const IFormalRestList*);
	void visit( const IMethodDecl* );
	void visit( const IMethodDeclList* );
	void visit( const IStatement* );
	void visit( const IStatementList* );
	void visit( const IType* );
	void visit( const IVarDecl* );
	void visit( const IVarDeclList* );
	void visit( const IExpRest* );
	void visit( const IExpRestList* );
};