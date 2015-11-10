#include "ExpRestList.h"

CExpRestList::CExpRestList( IExpRest* _expRest, IExpRestList* _expRestList, int _yylineno ) :
	expRest(_expRest), expRestList(_expRestList), yylineno(_yylineno )
{
}

void CExpRestList::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExpRest* CExpRestList::Exp() const
{
	return expRest;
}

const IExpRestList* CExpRestList::ExpRestList() const
{
	return expRestList;
}
