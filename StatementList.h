#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CStatementList : public  IStatementList {
public:
	CStatementList( IStatement* _statement, CStatementList* _statementList, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IStatement* Statement() const;

	const CStatementList* StatementList() const;

private:
	IStatement* statement;
	CStatementList* statementList;
	int yylineno;
};
