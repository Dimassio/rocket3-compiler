#pragma once

#include "Grammar.h"
#include "Visitor.h"

/*
Grammar:

Program:
MainClass {}
| MainClass ClassDecls {}
;

*/

class CProgram : public IProgram { 
public:
	CProgram( IMainClass* _mainClass, IClassDeclList* _classDeclList ) :
		mainClass( _mainClass ), classDeclList( _classDeclList )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IMainClass* MainClass() const
	{
		return mainClass;
	}

	const IClassDeclList* ClassDeclList() const
	{
		return classDeclList;
	}

private:
	IMainClass* mainClass;
	IClassDeclList* classDeclList;
};