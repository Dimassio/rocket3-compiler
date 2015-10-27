#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CVarDeclList : public IVarDeclList {
public:
	CVarDeclList( IVarDecl* _varDecl, IVarDeclList* _varDeclList );

	void Accept( IVisitor* visitor ) const;

	const IVarDecl* VarDecl() const;

	const IVarDeclList* VarDeclList() const;

private:
	IVarDecl* varDecl;
	IVarDeclList* varDeclList;
};