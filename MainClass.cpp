#include "StaticVariables.h"
#include "MainClass.h"

CMainClass::CMainClass( std::string className, std::string argName, IStatement* _statement ) :
	classSymbol( symbolStorage.Get(className) ),
	argSymbol( symbolStorage.Get(argName) ),
	statement( _statement )
{
}

void CMainClass::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IStatement* CMainClass::Statement() const
{
	return statement;
}

const Symbols::CSymbol* CMainClass::ClassSymbol() const {
	return classSymbol;
}

const Symbols::CSymbol* CMainClass::ArgSymbol() const {
	return argSymbol;
}
