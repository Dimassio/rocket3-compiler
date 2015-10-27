#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CClassDecl : public IClassDecl {
public:
	CClassDecl( std::string _className, std::string _extendedClassName, IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList );
	
	void Accept( IVisitor* visitor ) const;

	const IVarDeclList* VarDeclList() const;

	const IMethodDeclList* MethodDeclList() const;

	const std::string GetClassName() const;

	const std::string GetExtendedClassName() const;

private:
	std::string className;
	std::string extendedClassName;
	IVarDeclList* varDeclList;
	IMethodDeclList* methodDeclList;
};