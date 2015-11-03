#include "ExpNewIntArray.h"

CExpNewIntArray::CExpNewIntArray(IExp* _exp)
	: exp(_exp)
{
}

void CExpNewIntArray::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpNewIntArray::Exp() const
{
	return exp;
}
