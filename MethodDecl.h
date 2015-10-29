#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CMethodDecl : public IMethodDecl {
public:
	CMethodDecl( IType* _type, std::string _id, IFormalList* _formalList, IVarDeclList* _varDeclList, IStatementList* _statementList, IExp* _exp );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const std::string Id() const;

	const IFormalList* FormalList() const;

	const IVarDeclList* VarDeclList() const;

	const IStatementList* StatementList() const;

	const IExp* Exp() const;

private:
	IType* type;
	std::string id;
	IFormalList* formalList;
	IVarDeclList* varDeclList;
	IStatementList* statementList;
	IExp* exp;
};