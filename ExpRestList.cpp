#include "ExpRestList.h"

CExpRestList::CExpRestList(IExpRest* _expRest, IExpRestList* _expRestList) :
	expRest(_expRest), expRestList(_expRestList)
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
