#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CExpMethodCall : public IExpMethodCall {
public:
	CExpMethodCall( IExp* _exp, std::string id, IExpList* _expList);

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

	const IExpList* ExpList() const;

	const Symbols::CSymbol* Symbol() const;

private:
	IExp* exp;
	IExpList* expList;
	const Symbols::CSymbol* symbol;
};
