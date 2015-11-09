#include "ExpNewCustomType.h"

CExpNewCustomType::CExpNewCustomType( IType* _type )
	: 
	type( _type )
{
}

void CExpNewCustomType::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const IType* CExpNewCustomType::Type() const
{
	return type;
}
