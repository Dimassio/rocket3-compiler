#include "FormalRest.h"

CFormalRest::CFormalRest( IType* _type, const std::string& _id ) :
	type(_type), id(_id)
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

const std::string& CFormalRest::Id() const {
	return id;
}
