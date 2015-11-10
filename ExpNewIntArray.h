#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNewIntArray : public IExpNewIntArray {
public:
	CExpNewIntArray( IExp* _exp, int _yylineno );

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

	int yylineno;
private:
	IExp* exp;
	
};
