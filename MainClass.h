#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CMainClass : public IMainClass {
public:
	CMainClass( std::string _className, std::string _argName, IStatement* _statement );

	void Accept( IVisitor* visitor ) const;

	const IStatement* Statement() const;

	const std::string GetClassName() const;

	const std::string GetArgName() const;

private:
	std::string className;
	std::string argName;
	IStatement* statement;
};