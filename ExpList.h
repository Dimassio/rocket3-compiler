#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpList : public IExpList {
public:
	CExpList( IExp* _exp, IExpRestList* _expRestList, int _yylineno );

	void Accept( IVisitor* visitor ) const;

	const IExp* Exp() const;

	const IExpRestList* ExpRestList() const;

	int yylineno;
private:
	IExp* exp;
	IExpRestList* expRestList;
	
};
