#include "ClassDeclList.h"

CClassDeclList::CClassDeclList( IClassDecl* _classDecl, IClassDeclList* _classDeclList, int _yylineno ) :
	classDecl( _classDecl ), classDeclList( _classDeclList ), yylineno(_yylineno )
{
}

void CClassDeclList::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IClassDecl* CClassDeclList::ClassDecl() const
{
	return classDecl;
}

const IClassDeclList* CClassDeclList::ClassDeclList() const
{
	return classDeclList;
}
