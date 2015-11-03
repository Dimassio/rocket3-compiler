#include "ExpLength.h"

CExpLength::CExpLength( IExp* _exp)
	: exp(_exp)
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
