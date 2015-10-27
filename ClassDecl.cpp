#include "ClassDecl.h"

CClassDecl::CClassDecl( std::string _className, std::string _extendedClassName, IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList ) :
	className( _className ), extendedClassName( _extendedClassName ), varDeclList( _varDeclList ), methodDeclList( _methodDeclList )
{
}

void CClassDecl::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IVarDeclList* CClassDecl::VarDeclList() const
{
	return varDeclList;
}

const IMethodDeclList*  CClassDecl::MethodDeclList() const
{
	return methodDeclList;
}

const std::string CClassDecl::GetClassName() const
{
	return className;
}

const std::string CClassDecl::GetExtendedClassName() const
{
	return extendedClassName;
}
