#include "FormalRestList.h"

CFormalRestList::CFormalRestList( IFormalRest* _formalRest, IFormalRestList* _formalRestList ) :
	formalRest(_formalRest), formalRestList(_formalRestList)
{
}

void CFormalRestList::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IFormalRest* CFormalRestList::FormalRest() const
{
	return formalRest;
}

const IFormalRestList* CFormalRestList::FormalRestList() const
{
	return formalRestList;
}
