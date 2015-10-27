#include "Program.h"

CProgram::CProgram( IMainClass* _mainClass, IClassDeclList* _classDeclList ) :
	mainClass( _mainClass ), classDeclList( _classDeclList )
{
}

void CProgram::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IMainClass* CProgram::MainClass() const
{
	return mainClass;
}

const IClassDeclList* CProgram::ClassDeclList() const
{
	return classDeclList;
}
