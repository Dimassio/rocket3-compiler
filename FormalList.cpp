#include "StaticVariables.h"
#include "FormalList.h"

CFormalList::CFormalList( IType* _type, std::string id, IFormalRestList* _formalRestList ) :
	type( _type ),
	symbol( symbolStorage.Get(id) ),
	formalRestList( _formalRestList )
{
}

void CFormalList::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IType* CFormalList::Type() const
{
	return type;
}

const IFormalRestList* CFormalList::FormalRestList() const
{
	return formalRestList;
}


const Symbols::CSymbol* CFormalList::Symbol() const {
	return symbol;
}

