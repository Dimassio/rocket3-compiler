#include "ExpSquareBrackets.h"

CExpSquareBrackets::CExpSquareBrackets(IExp* _firstExp, IExp* _secondExp, int _yylineno )
	: firstExp(_firstExp),
	secondExp(_secondExp),
	yylineno(_yylineno )
{
}

void CExpSquareBrackets::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpSquareBrackets::FirstExp() const
{
	return firstExp;
}

const IExp* CExpSquareBrackets::SecondExp() const
{
	return secondExp;
}
