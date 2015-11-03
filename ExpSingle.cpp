#include "ExpSingle.h"

CExpSingle::CExpSingle(std::string _expName)
	: expName(_expName)
{
}

void CExpSingle::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}


const std::string CExpSingle::ExpName() const
{
	return expName;
}
