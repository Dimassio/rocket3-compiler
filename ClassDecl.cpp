#include "StaticVariables.h"
#include "ClassDecl.h"

CClassDecl::CClassDecl( std::string className, std::string extendedClassName, IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList ) :
	classSymbol( symbolStorage.Get(className) ), 
	extendedClassSymbol( symbolStorage.Get(extendedClassName) ),
	varDeclList( _varDeclList ),
	methodDeclList( _methodDeclList )
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

const Symbols::CSymbol* CClassDecl::ClassSymbol() const
{
	return classSymbol;
}

const Symbols::CSymbol* CClassDecl::ExtendedClassSymbol() const
{
	return extendedClassSymbol;
}
