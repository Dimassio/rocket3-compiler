#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNumber : public IExpNumber {
public:
	CExpNumber( int _number, int yylineno );

	void Accept(IVisitor* visitor) const;

	const int Number() const;

	int yylineno;
private:
	int number;
	
};
