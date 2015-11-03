#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpRestList : public  IExpRestList {
public:
	CExpRestList( IExpRest* _expRest, IExpRestList* _expRestList );
	
	void Accept( IVisitor* visitor ) const;

	const IExpRest* Exp() const;

	const IExpRestList* ExpRestList() const;

private:
	IExpRest* expRest;
	IExpRestList* expRestList;
};
