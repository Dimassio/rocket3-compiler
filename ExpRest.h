#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpRest : public  IExpRest {
public:
	CExpRest(IExp* _exp, int yylineno );

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

	int yylineno;
private:
	IExp* exp;
	
};
