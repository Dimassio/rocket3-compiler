#include "ExpNewCustomType.h"

CExpNewCustomType::CExpNewCustomType( std::string _id )
	: 
	id(_id)
{
}

void CExpNewCustomType::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const std::string CExpNewCustomType::Id() const
{
	return id;
}
