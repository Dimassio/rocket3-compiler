#include "Type.h"

CType::CType(const std::string &_typeName) :
		typeName(_typeName)
{
}

void CType::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const std::string& CType::GetTypeName() const
{
	return typeName;
}