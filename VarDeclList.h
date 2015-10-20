#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CVarDeclList : IVarDeclList {
public:
	CVarDeclList( IVarDecl* _varDecl, IVarDeclList* _varDeclList ) :
		varDecl(_varDecl), varDeclList(_varDeclList)
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IVarDecl* VarDecl() const
	{
		return varDecl;
	}

	const IVarDeclList* VarDeclList() const
	{
		return varDeclList;
	}


private:
	IVarDecl* varDecl;
	IVarDeclList* varDeclList;
};