#pragma once

#include "Grammar.h"
#include "Visitor.h"

/*
ClassDecls:
	ClassDecl {}
	| ClassDecls ClassDecl {}
	;
*/

class CClassDeclList : IClassDeclList {
public:
	CClassDeclList( IClassDecl* _classDecl, IClassDeclList* _classDeclList) :
		classDecl( _classDecl ), classDeclList(_classDeclList)
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IClassDecl* ClassDecl() const
	{
		return classDecl;
	}

	const IClassDeclList* ClassDeclList() const
	{
		return classDeclList;
	}


private:
	IClassDecl* classDecl;
	IClassDeclList* classDeclList;
};