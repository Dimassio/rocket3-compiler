#include "VarDecl.h"

CVarDecl::CVarDecl( IType* _type, std::string _varName ) :
	type( _type ), varName( _varName )
{
}

void CVarDecl::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IType* CVarDecl::Type() const
{
	return type;
}

const std::string CVarDecl::VarName() const
{
	return varName;
}
