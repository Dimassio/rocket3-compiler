#include "StaticVariables.h"
#include "ExpMethodCall.h"

CExpMethodCall::CExpMethodCall( IExp* _exp, std::string id, IExpList* _expList )
	: exp(_exp),
	symbol( symbolStorage.Get(id) ),
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

const Symbols::CSymbol* CExpMethodCall::Symbol() const {
	return symbol;
}
