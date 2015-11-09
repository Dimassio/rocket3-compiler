#include "VarDecl.h"

CVarDecl::CVarDecl( IType* _type, const std::string &_id ) :
	type( _type ),
	id( _id )
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

const std::string& CVarDecl::Id() const
{
	return id;
}
