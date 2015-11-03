#include "ExpId.h"

CExpId::CExpId( std::string _id )
	: id(_id)
{
}

void CExpId::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const std::string CExpId::Id() const
{
	return id;
}