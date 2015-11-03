#include "ExpRoundBrackets.h"

CExpRoundBrackets::CExpRoundBrackets( IExp* _exp )
	: exp(_exp)
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