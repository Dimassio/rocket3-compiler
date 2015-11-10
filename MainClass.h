#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CMainClass : public IMainClass {
public:
	CMainClass( const std::string &_classId, const std::string &_argId, IStatement* _statement, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IStatement* Statement() const;

	const std::string& ClassId() const;

	const std::string& ArgId() const;

	int yylineno;
private:
	const std::string classId;
	const std::string argId;
	IStatement* statement;
	
};