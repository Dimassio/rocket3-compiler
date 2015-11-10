#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CVarDeclList : public IVarDeclList {
public:
	CVarDeclList( IVarDecl* _varDecl, IVarDeclList* _varDeclList, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IVarDecl* VarDecl() const;

	const IVarDeclList* VarDeclList() const;

	int yylineno;
private:
	IVarDecl* varDecl;
	IVarDeclList* varDeclList;

};