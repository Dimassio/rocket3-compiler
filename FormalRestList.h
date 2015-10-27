#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CFormalRestList : public IFormalRestList {
public:
	CFormalRestList(IFormalRest* _formalRest, IFormalRestList* _formalRestList) :
		formalRest(_formalRest), formalRestList(_formalRestList)
	{
	}

	void Accept(IVisitor* visitor) const
	{
		visitor->visit(this);
	}

	const IFormalRest* FormalRest() const
	{
		return formalRest;
	}

	const IFormalRestList* FormalRestList() const
	{
		return formalRestList;
	}

private:
	IFormalRest* formalRest;
	IFormalRestList* formalRestList;
};