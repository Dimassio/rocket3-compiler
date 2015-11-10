#include "Type.h"

CType::CType(const std::string &_typeName, int _yylineno ) :
		typeName(_typeName), yylineno(_yylineno )
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