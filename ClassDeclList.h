#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CClassDeclList : public IClassDeclList {
public:
	CClassDeclList( IClassDecl* _classDecl, IClassDeclList* _classDeclList );

	void Accept( IVisitor* visitor ) const;

	const IClassDecl* ClassDecl() const;

	const IClassDeclList* ClassDeclList() const;

private:
	IClassDecl* classDecl;
	IClassDeclList* classDeclList;
};