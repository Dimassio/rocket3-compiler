#include <list>
#include "IRTree.h"

CIRExpList::~CIRExpList()
{
}

CIRExpList::CIRExpList(IIRExp* head, CIRExpList* tail)
{
	if (tail != nullptr) {
		expList = tail->expList;
	}

	expList.insert(expList.begin(), head);
}

void CIRExpList::Add( IIRExp* exp )
{
	expList.push_back( exp );
}

CIRExpList::CIRExpList( const std::vector<IIRExp*>& _expList ):
	expList( _expList )
{
}

void CIRExpList::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}