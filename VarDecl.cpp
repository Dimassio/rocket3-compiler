#include "StaticVariables.h"
#include "VarDecl.h"

CVarDecl::CVarDecl( IType* _type, std::string id ) :
	type( _type ),
	symbol( symbolStorage.Get(id) )
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

const Symbols::CSymbol* CVarDecl::Symbol() const
{
	return symbol;
}
