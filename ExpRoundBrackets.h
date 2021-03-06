#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpRoundBrackets : public IExpRoundBrackets {
public:
	CExpRoundBrackets( IExp* _exp, int yylineno );

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

	int yylineno;
private:
	IExp* exp;
	
};
