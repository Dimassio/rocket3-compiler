#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpSquareBrackets : public IExpSquareBrackets {
public:
	CExpSquareBrackets( IExp* _firstExp, IExp* _secondExp, int yylineno );

	void Accept(IVisitor* visitor) const;

	const IExp* FirstExp() const;

	const IExp* SecondExp() const;

	int yylineno;
private:
	IExp* firstExp;
	IExp* secondExp;
	
};