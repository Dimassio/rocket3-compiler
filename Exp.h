#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExp : IExp {
public:
	CExp(
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

	void Accept(IVisitor* visitor) const
	{
		visitor->visit(this);
	}

	const IExpList* ExpressionList() const
	{
		return expressionList;
	}

	const IExp* FirstExpression() const
	{
		return firstExpression;
	}

	const IExp* SecondExpression() const
	{
		return secondExperssion;
	}

	const std::string GetId() const
	{
		return id;
	}

	const std::string GetExpressionType() const
	{
		return expressionType;
	}

	const std::string GetExpressionName() const
	{
		return expressionName;
	}

private:
	std::string expressionType;
	std::string expressionName;
	IExp* firstExpression;
	IExp* secondExperssion;
	IExpList *expressionList;
	std::string id;
};
