#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CMethodDeclList : public  IMethodDeclList {
public:
	CMethodDeclList( IMethodDecl* _methodDecl, IMethodDeclList* _methodDeclList ) :
		methodDecl( _methodDecl ), methodDeclList( _methodDeclList )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IMethodDecl* MethodDecl() const
	{
		return methodDecl;
	}

	const IMethodDeclList* MethodDeclList() const
	{
		return methodDeclList;
	}

private:
	IMethodDecl* methodDecl;
	IMethodDeclList* methodDeclList;
};