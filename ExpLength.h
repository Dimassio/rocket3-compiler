#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpLength : public IExpLength {
public:
	CExpLength( IExp* _exp, int _yylineno );

	void Accept( IVisitor* visitor ) const;

	const IExp* Exp() const;

	int yylineno;
private:
	IExp* exp;
	
};