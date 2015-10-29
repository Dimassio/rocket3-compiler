#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CFormalRestList : public IFormalRestList {
public:
	CFormalRestList(IFormalRest* _formalRest, IFormalRestList* _formalRestList);

	void Accept(IVisitor* visitor) const;

	const IFormalRest* FormalRest() const;

	const IFormalRestList* FormalRestList() const;

private:
	IFormalRest* formalRest;
	IFormalRestList* formalRestList;
};