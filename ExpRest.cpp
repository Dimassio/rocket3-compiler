#include "ExpRest.h"

CExpRest::CExpRest(IExp* _exp, int _yylineno ) :
	exp(_exp), yylineno(_yylineno )
{
}

void CExpRest::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpRest::Exp() const
{
	return exp;
}
