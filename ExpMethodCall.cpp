#include "ExpMethodCall.h"

CExpMethodCall::CExpMethodCall( IExp* _exp, std::string _id, IExpList* _expList )
	: exp(_exp),
	id(_id),
	expList(_expList)
{
}

void CExpMethodCall::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpMethodCall::Exp() const
{
	return exp;
}

const IExpList* CExpMethodCall::ExpList() const
{
	return expList;
}

const std::string CExpMethodCall::Id() const
{
	return id;
}
