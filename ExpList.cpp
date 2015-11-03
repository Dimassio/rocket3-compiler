#include "ExpList.h"

CExpList::CExpList( IExp* _exp, IExpRestList* _expRestList ) :
	exp(_exp), expRestList(_expRestList)
{
}

void CExpList::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpList::Exp() const
{
	return exp;
}

const IExpRestList* CExpList::ExpRestList() const
{
	return expRestList;
}
