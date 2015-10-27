#include "VarDeclList.h"

CVarDeclList::CVarDeclList( IVarDecl* _varDecl, IVarDeclList* _varDeclList ) :
	varDecl( _varDecl ), varDeclList( _varDeclList )
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