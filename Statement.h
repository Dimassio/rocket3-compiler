#pragma once


#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CStatement : public IStatement {
public:
	CStatement (
		std::string _statementType,
		IStatementList* _statements,
		IStatement* _firstStatement,
		IStatement* _secondStatement,
		IExp* _firstExpression,
		IExp* _secondExperssion,
		std::string _id )
		: statementType( _statementType ),
		statements( _statements ),
		firstStatement( _firstStatement ),
		secondStatement( _secondStatement ),
		firstExpression( _firstExpression ),
		secondExperssion( _secondExperssion ),
		id( _id )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor-> visit( this );
	}

	const IStatementList* Statements() const
	{
		return statements;
	}

	const IStatement* FirstStatement() const
	{
		return firstStatement;
	}

	const IStatement* SecondStatement() const
	{
		return secondStatement;
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

	const std::string GetStatementType() const
	{
		return statementType;
	}

private:
	std::string statementType;
	IStatementList* statements;
	IStatement* firstStatement;
	IStatement* secondStatement;
	IExp* firstExpression;
	IExp* secondExperssion;
	std::string id;
};