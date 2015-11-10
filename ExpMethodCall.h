#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CExpMethodCall : public IExpMethodCall {
public:
	CExpMethodCall( IExp* _exp, const std::string &_id, IExpList* _expList, int _yylineno );

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

	const IExpList* ExpList() const;

	const std::string& Id() const;

	int yylineno;
private:
	IExp* exp;
	IExpList* expList;
	const std::string id;
	
};
