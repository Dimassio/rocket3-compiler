#include "StaticVariables.h"
#include "FormalRest.h"

CFormalRest::CFormalRest( IType* _type, std::string id ) :
	type(_type), symbol( symbolStorage.Get(id) )
{
}

void CFormalRest::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IType* CFormalRest::Type() const
{
	return type;
}

const Symbols::CSymbol* CFormalRest::Symbol() const {
	return symbol;
}
