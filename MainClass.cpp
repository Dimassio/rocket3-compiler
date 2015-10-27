#include "MainClass.h"

CMainClass::CMainClass( std::string _className, std::string _argName, IStatement* _statement ) :
	className( _className ), argName( _argName ), statement( _statement )
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

const std::string CMainClass::GetClassName() const
{
	return className;
}

const std::string CMainClass::GetArgName() const
{
	return argName;
}
