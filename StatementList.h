#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CStatementList : public  IStatementList {
public:
	CStatementList(IStatement* _statement, CStatementList* _statementList) :
		statement(_statement), statementList(_statementList)
	{
	}

	void Accept(IVisitor* visitor) const
	{
		visitor->visit(this);
	}

	const IStatement* Statement() const
	{
		return statement;
	}

	const CStatementList* StatementList() const
	{
		return statementList;
	}

private:
	IStatement* statement;
	CStatementList* statementList;
};
