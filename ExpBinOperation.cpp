#include "ExpBinOperation.h"

CExpBinOperation::CExpBinOperation( const std::string &_expName, IExp* _firstExp, IExp* _secondExp )
	: expName(_expName),
	firstExp(_firstExp),
	secondExp(_secondExp)
{
}

void CExpBinOperation::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExp* CExpBinOperation::FirstExp() const
{
	return firstExp;
}

const IExp* CExpBinOperation::SecondExp() const
{
	return secondExp;
}

const std::string& CExpBinOperation::ExpName() const
{
	return expName;
}
