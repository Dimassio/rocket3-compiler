#include "ExpRest.h"

CExpRest::CExpRest(IExp* _exp) :
	exp(_exp)
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
