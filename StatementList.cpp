#include "StatementList.h"

CStatementList::CStatementList(IStatement* _statement, CStatementList* _statementList) :
	statement(_statement), statementList(_statementList)
{
}

void CStatementList::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IStatement* CStatementList::Statement() const
{
	return statement;
}

const CStatementList* CStatementList::StatementList() const
{
	return statementList;
}
