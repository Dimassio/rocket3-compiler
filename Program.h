#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CProgram : public IProgram { 
public:
	CProgram( IMainClass* _mainClass, IClassDeclList* _classDeclList, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IMainClass* MainClass() const;

	const IClassDeclList* ClassDeclList() const;

	int yylineno;
private:
	IMainClass* mainClass;
	IClassDeclList* classDeclList;
	
};