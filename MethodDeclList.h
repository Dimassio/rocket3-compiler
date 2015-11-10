#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CMethodDeclList : public  IMethodDeclList {
public:
	CMethodDeclList( IMethodDecl* _methodDecl, IMethodDeclList* _methodDeclList, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IMethodDecl* MethodDecl() const;

	const IMethodDeclList* MethodDeclList() const;

	int yylineno;
private:
	IMethodDecl* methodDecl;
	IMethodDeclList* methodDeclList;

};