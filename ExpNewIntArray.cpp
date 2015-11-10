#include "ExpNewIntArray.h"

CExpNewIntArray::CExpNewIntArray(IExp* _exp, int _yylineno )
	: exp(_exp), yylineno(_yylineno )
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
