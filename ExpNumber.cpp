#include "ExpNumber.h"

CExpNumber::CExpNumber(int _number)
	: number(_number)
{
}

void CExpNumber::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const int CExpNumber::Number() const
{
	return number;
}
