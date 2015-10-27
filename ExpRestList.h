#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpRestList : public  IExpRestList {
public:
	CExpRestList( IExpRest* _expRest, IExpRestList* _expRestList ) :
		expRest( _expRest ), expRestList( _expRestList )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IExpRest* Exp() const
	{
		return expRest;
	}

	const IExpRestList* ExpRestList() const
	{
		return expRestList;
	}

private:
	IExpRest* expRest;
	IExpRestList* expRestList;
};
