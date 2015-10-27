#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExp : public IExp {
public:
	CExp(
		std::string _expressionType,
		std::string _expressionName,
		IExpList* _expressionList,
		IExp* _firstExpression,
		IExp* _secondExperssion,
		std::string _id
	);

	void Accept(IVisitor* visitor) const;

	const IExpList* ExpressionList() const;

	const IExp* FirstExpression() const;

	const IExp* SecondExpression() const;

	const std::string GetId() const;

	const std::string GetExpressionType() const;

	const std::string GetExpressionName() const;

private:
	std::string expressionType;
	std::string expressionName;
	IExp* firstExpression;
	IExp* secondExperssion;
	IExpList *expressionList;
	std::string id;
};
