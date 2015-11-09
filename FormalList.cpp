#include "FormalList.h"

CFormalList::CFormalList( IType* _type, const std::string& _id, IFormalRestList* _formalRestList ) :
	type( _type ),
	id( _id ),
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


const std::string& CFormalList::Id() const {
	return id;
}

