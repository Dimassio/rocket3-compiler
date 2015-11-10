#include "ExpNumber.h"

CExpNumber::CExpNumber(int _number, int _yylineno )
	: number(_number), yylineno(_yylineno )
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
