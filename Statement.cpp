#include "Statement.h"

CStatement::CStatement(
	const std::string &_statementType,
	IStatementList* _statements,
	IStatement* _firstStatement,
	IStatement* _secondStatement,
	IExp* _firstExpression,
	IExp* _secondExperssion,
	const std::string &_id,
	int _yylineno
)
	: statementType(_statementType),
	statements(_statements),
	firstStatement(_firstStatement),
	secondStatement(_secondStatement),
	firstExpression(_firstExpression),
	secondExperssion(_secondExperssion),
	id( _id ),
	yylineno(_yylineno )
{
}

void CStatement::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IStatementList* CStatement::Statements() const
{
	return statements;
}

const IStatement* CStatement::FirstStatement() const
{
	return firstStatement;
}

const IStatement* CStatement::SecondStatement() const
{
	return secondStatement;
}

const IExp* CStatement::FirstExpression() const
{
	return firstExpression;
}

const IExp* CStatement::SecondExpression() const
{
	return secondExperssion;
}

const std::string& CStatement::Id() const {
	return id;
}

const std::string& CStatement::GetStatementType() const
{
	return statementType;
}
