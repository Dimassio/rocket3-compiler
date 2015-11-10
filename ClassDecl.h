#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CClassDecl : public IClassDecl {
public:
	CClassDecl( const std::string &_classId, const std::string &_extendedClassId,
		IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList, int _yylineno );
	
	void Accept( IVisitor* visitor ) const;

	const IVarDeclList* VarDeclList() const;

	const IMethodDeclList* MethodDeclList() const;

	const std::string& ClassId() const;

	const std::string& ExtendedClassId() const;
	
	int yylineno;

private:
	const std::string classId;
	const std::string  extendedClassId;
	IVarDeclList* varDeclList;
	IMethodDeclList* methodDeclList;
};