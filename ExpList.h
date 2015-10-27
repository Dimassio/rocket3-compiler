#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpList : public IExpList {
public:
	CExpList( IExp* _exp, IExpRestList* _expRestList ) :
		exp( _exp ), expRestList( _expRestList )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IExp* Exp() const
	{
		return exp;
	}

	const IExpRestList* ExpRestList() const
	{
		return expRestList;
	}

private:
	IExp* exp;
	IExpRestList* expRestList;
};
