#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpRestList : public  IExpRestList {
public:
	CExpRestList( IExpRest* _expRest, IExpRestList* _expRestList, int yylineno );
	
	void Accept( IVisitor* visitor ) const;

	const IExpRest* ExpRest() const;

	const IExpRestList* ExpRestList() const;

	int yylineno;
private:
	IExpRest* expRest;
	IExpRestList* expRestList;
	
};
