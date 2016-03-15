#include <list>
#include "IRTree.h"

CIRExpList::CIRExpList( IIRExp* head, CIRExpList* tail )
{
	if( tail != nullptr ) {
		expList = tail->expList;
	}
	expList.push_front( head );
}

CIRExpList::~CIRExpList()
{
}

void CIRExpList::Add( IIRExp* exp )
{
	expList.push_back( exp );
}

CIRExpList::CIRExpList( const std::list<IIRExp*>& _expList ):
	expList( _expList )
{
}

void CIRExpList::Accept(IIRTreeVisitor* visitor) const {
	visitor->visit(this);
}