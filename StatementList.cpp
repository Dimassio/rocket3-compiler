#include "StatementList.h"

CStatementList::CStatementList( IStatement* _statement, CStatementList* _statementList, int _yylineno ) :
	statement(_statement), statementList(_statementList), yylineno(_yylineno )
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
