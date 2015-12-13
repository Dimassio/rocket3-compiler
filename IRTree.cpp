#include <list>
#include "IRTree.h"

using namespace IRTree;


CIRExpList::CIRExpList(IIRExp* head, CIRExpList* tail)
{
	if( tail != nullptr ) {
		expList = tail->GetExpList();
	}
	expList.push_front(head);
}

CIRExpList::~CIRExpList()
{
}

std::list<IIRExp*> CIRExpList::GetExpList()
{
	return expList;
}


void CIRExpList::Add( IIRExp* exp )
{
	expList.push_back( exp );
}


CIRStmList::CIRStmList(IIRStm * head, CIRStmList * tail)
{
	stmList = tail->GetStmList();
	stmList.push_front(head);
}

CIRStmList::~CIRStmList()
{
}

std::list<IIRStm*> CIRStmList::GetStmList()
{
	return stmList;
}


void CIRStmList::Add( IIRStm* exp )
{
	stmList.push_back( exp );
}