#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CMethodDecl : public IMethodDecl {
public:
	CMethodDecl( IType* _type, const std::string &_id, IFormalList* _formalList, 
		IVarDeclList* _varDeclList, IStatementList* _statementList, IExp* _exp, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const std::string& Id() const;

	const IFormalList* FormalList() const;

	const IVarDeclList* VarDeclList() const;

	const IStatementList* StatementList() const;

	const IExp* Exp() const;

	int yylineno;
private:
	const std::string id;
	

	IType* type;
	IFormalList* formalList;
	IVarDeclList* varDeclList;
	IStatementList* statementList;
	IExp* exp;
};