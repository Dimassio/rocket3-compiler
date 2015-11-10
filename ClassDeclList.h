#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CClassDeclList : public IClassDeclList {
public:
	CClassDeclList( IClassDecl* _classDecl, IClassDeclList* _classDeclList, int _yylineno );

	void Accept( IVisitor* visitor ) const;

	const IClassDecl* ClassDecl() const;

	const IClassDeclList* ClassDeclList() const;

	int yylineno;
private:
	IClassDecl* classDecl;
	IClassDeclList* classDeclList;
};