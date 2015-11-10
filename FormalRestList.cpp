#include "FormalRestList.h"

CFormalRestList::CFormalRestList( IFormalRest* _formalRest, IFormalRestList* _formalRestList, int _yylineno ) :
	formalRest(_formalRest), formalRestList(_formalRestList), yylineno(_yylineno )
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
