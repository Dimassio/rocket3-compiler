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
	// todo: нужен класс, содержащий координаты ошибки, и отнаследоваться еще от него, чтобы уметь
	// показывать пользователю адекватные ошибки
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