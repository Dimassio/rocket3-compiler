#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CMainClass : IMainClass {
public:
	CMainClass( std::string _className, std::string _argName, IStatement* _statement ) :
		className( _className ), argName( _argName ), statement( _statement )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IStatement* Statement() const
	{
		return statement;
	}

	const std::string GetClassName() const
	{
		return className;
	}

	const std::string GetArgName() const
	{
		return argName;
	}

private:
	std::string className;
	std::string argName;
	IStatement* statement;
};