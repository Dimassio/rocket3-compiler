#include "ExpNewCustomType.h"

CExpNewCustomType::CExpNewCustomType( std::string _type )
	: 
	type( _type )
{
}

void CExpNewCustomType::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const std::string CExpNewCustomType::Type() const
{
	return type;
}
