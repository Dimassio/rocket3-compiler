#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpRest : public  IExpRest {
public:
	CExpRest( IExp* _exp ) :
		exp( _exp )
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

private:
	IExp* exp;
};
