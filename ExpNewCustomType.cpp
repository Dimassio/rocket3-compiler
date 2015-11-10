#include "ExpNewCustomType.h"

CExpNewCustomType::CExpNewCustomType( IType* _type, int _yylineno )
	: 
	type( _type ),
	yylineno(_yylineno )
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
