#include "MethodDeclList.h"

CMethodDeclList::CMethodDeclList( IMethodDecl* _methodDecl, IMethodDeclList* _methodDeclList ) :
	methodDecl( _methodDecl ), methodDeclList( _methodDeclList )
{
}

void CMethodDeclList::CMethodDeclList::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IMethodDecl* CMethodDeclList::MethodDecl() const
{
	return methodDecl;
}

const IMethodDeclList* CMethodDeclList::MethodDeclList() const
{
	return methodDeclList;
}
