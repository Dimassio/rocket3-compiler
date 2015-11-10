#include "ExpLength.h"

CExpLength::CExpLength( IExp* _exp, int _yylineno )
	: exp(_exp), yylineno(_yylineno )
{
}

void CExpLength::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpLength::Exp() const
{
	return exp;
}
