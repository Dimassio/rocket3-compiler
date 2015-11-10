#include "ExpSingle.h"

CExpSingle::CExpSingle(const std::string &_expName, int _yylineno )
	: expName(_expName), yylineno(_yylineno )
{
}

void CExpSingle::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}


const std::string& CExpSingle::ExpName() const
{
	return expName;
}
