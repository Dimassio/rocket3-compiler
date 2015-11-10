#include "ExpNot.h"

CExpNot::CExpNot( IExp* _exp, int _yylineno )
	: exp(_exp), yylineno(_yylineno )
{
}

void CExpNot::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpNot::Exp() const
{
	return exp;
}
