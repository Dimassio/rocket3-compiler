#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CStatement : public IStatement {
public:
	CStatement(
		std::string _statementType,
		IStatementList* _statements,
		IStatement* _firstStatement,
		IStatement* _secondStatement,
		IExp* _firstExpression,
		IExp* _secondExperssion,
		std::string id
	);

	void Accept(IVisitor* visitor) const;

	const IStatementList* Statements() const;

	const IStatement* FirstStatement() const;

	const IStatement* SecondStatement() const;

	const IExp* FirstExpression() const;

	const IExp* SecondExpression() const;

	const Symbols::CSymbol* Symbol() const;

	const std::string GetStatementType() const;

private:
	std::string statementType;
	IStatementList* statements;
	IStatement* firstStatement;
	IStatement* secondStatement;
	IExp* firstExpression;
	IExp* secondExperssion;
	const Symbols::CSymbol* symbol;
};