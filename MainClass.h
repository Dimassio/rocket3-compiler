#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CMainClass : public IMainClass {
public:
	CMainClass( std::string className, std::string argName, IStatement* _statement );

	void Accept( IVisitor* visitor ) const;

	const IStatement* Statement() const;

	const Symbols::CSymbol* ClassSymbol() const;

	const Symbols::CSymbol* ArgSymbol() const;

private:
	const Symbols::CSymbol* classSymbol;
	const Symbols::CSymbol* argSymbol;
	IStatement* statement;
};