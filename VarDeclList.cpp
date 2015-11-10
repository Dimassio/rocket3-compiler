#include "VarDeclList.h"

CVarDeclList::CVarDeclList( IVarDecl* _varDecl, IVarDeclList* _varDeclList, int _yylineno ) :
	varDecl( _varDecl ), varDeclList( _varDeclList ), yylineno(_yylineno )
{
}

void CVarDeclList::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IVarDecl* CVarDeclList::VarDecl() const
{
	return varDecl;
}

const IVarDeclList* CVarDeclList::VarDeclList() const
{
	return varDeclList;
}