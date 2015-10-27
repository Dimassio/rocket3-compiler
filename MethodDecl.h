#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CMethodDecl : public IMethodDecl {
public:
	CMethodDecl( IType* _type, std::string _id, IFormalList* _formalList, IVarDeclList* _varDeclList, IStatementList* _statementList, IExp* _exp ) :
		type( _type ), id( _id ), formalList( _formalList ), varDeclList( _varDeclList ), statementList( _statementList ), exp( _exp )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IType* Type() const
	{
		return type;
	}

	const std::string Id() const
	{
		return id;
	}

	const IFormalList* FormalList() const
	{
		return formalList;
	}

	const IVarDeclList* VarDeclList() const
	{
		return varDeclList;
	}

	const IStatementList* StatementList() const
	{
		return statementList;
	}

	const IExp* Exp() const
	{
		return exp;
	}

private:
	IType* type;
	std::string id;
	IFormalList* formalList;
	IVarDeclList* varDeclList;
	IStatementList* statementList;
	IExp* exp;
};