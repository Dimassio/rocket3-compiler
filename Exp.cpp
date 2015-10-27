#include "Exp.h"

CExp::CExp(
	std::string _expressionType,
	std::string _expressionName,
	IExpList* _expressionList,
	IExp* _firstExpression,
	IExp* _secondExperssion,
	std::string _id
)
	: expressionType(_expressionType),
	expressionName(_expressionName),
	expressionList(_expressionList),
	firstExpression(_firstExpression),
	secondExperssion(_secondExperssion),
	id(_id)
{
}

void CExp::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IExpList* CExp::ExpressionList() const
{
	return expressionList;
}

const IExp* CExp::FirstExpression() const
{
	return firstExpression;
}

const IExp* CExp::SecondExpression() const
{
	return secondExperssion;
}

const std::string CExp::GetId() const
{
	return id;
}

const std::string CExp::GetExpressionType() const
{
	return expressionType;
}

const std::string CExp::GetExpressionName() const
{
	return expressionName;
}
