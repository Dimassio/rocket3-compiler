#include "ExpRoundBrackets.h"

CExpRoundBrackets::CExpRoundBrackets( IExp* _exp, int _yylineno )
	: exp(_exp), yylineno(_yylineno )
{
}

void CExpRoundBrackets::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpRoundBrackets::Exp() const
{
	return exp;
}