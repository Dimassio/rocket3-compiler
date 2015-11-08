#include "StaticVariables.h"
#include "ExpId.h"

CExpId::CExpId( std::string id )
	: symbol( symbolStorage.Get(id) )
{
}

void CExpId::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const Symbols::CSymbol* CExpId::Symbol() const {
	return symbol;
}
