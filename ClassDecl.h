#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CClassDecl : public IClassDecl {
public:
	CClassDecl( std::string _className, std::string _extendedClassName, IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList ) :
		className( _className ), extendedClassName(_extendedClassName), varDeclList( _varDeclList ), methodDeclList( _methodDeclList )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IVarDeclList* VarDeclList() const
	{
		return varDeclList;
	}

	const IMethodDeclList* MethodDeclList() const
	{
		return methodDeclList;
	}

	const std::string GetClassName() const
	{
		return className;
	}

	const std::string GetExtendedClassName() const
	{
		return extendedClassName;
	}

private:
	std::string className;
	std::string extendedClassName;
	IVarDeclList* varDeclList;
	IMethodDeclList* methodDeclList;
};