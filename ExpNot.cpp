#include "ExpNot.h"

CExpNot::CExpNot( IExp* _exp )
	: exp(_exp)
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
