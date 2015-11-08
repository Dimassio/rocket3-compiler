#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CClassDecl : public IClassDecl {
public:
	CClassDecl( std::string className, std::string extendedClassName, IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList );
	
	void Accept( IVisitor* visitor ) const;

	const IVarDeclList* VarDeclList() const;

	const IMethodDeclList* MethodDeclList() const;

	const Symbols::CSymbol* ClassSymbol() const;

	const Symbols::CSymbol* ExtendedClassSymbol() const;

private:
	const Symbols::CSymbol* classSymbol;
	const Symbols::CSymbol*  extendedClassSymbol;
	IVarDeclList* varDeclList;
	IMethodDeclList* methodDeclList;
};