#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpList : public IExpList {
public:
	CExpList( IExp* _exp, IExpRestList* _expRestList );

	void Accept( IVisitor* visitor ) const;

	const IExp* Exp() const;

	const IExpRestList* ExpRestList() const;

private:
	IExp* exp;
	IExpRestList* expRestList;
};
