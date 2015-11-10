#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CStatement : public IStatement {
public:
	CStatement(
		const std::string &_statementType,
		IStatementList* _statements,
		IStatement* _firstStatement,
		IStatement* _secondStatement,
		IExp* _firstExpression,
		IExp* _secondExperssion,
		const std::string &_id,
		int yylineno
	);

	void Accept(IVisitor* visitor) const;

	const IStatementList* Statements() const;

	const IStatement* FirstStatement() const;

	const IStatement* SecondStatement() const;

	const IExp* FirstExpression() const;

	const IExp* SecondExpression() const;

	const std::string& Id() const;

	const std::string& GetStatementType() const;

	int yylineno;
private:
	const std::string statementType;
	IStatementList* statements;
	IStatement* firstStatement;
	IStatement* secondStatement;
	IExp* firstExpression;
	IExp* secondExperssion;
	const std::string id;

};