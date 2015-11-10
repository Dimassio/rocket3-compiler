#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CFormalRestList : public IFormalRestList {
public:
	CFormalRestList( IFormalRest* _formalRest, IFormalRestList* _formalRestList, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IFormalRest* FormalRest() const;

	const IFormalRestList* FormalRestList() const;

	int yylineno;
private:
	IFormalRest* formalRest;
	IFormalRestList* formalRestList;
	
};