#include <list>
#include "IRTree.h"

using namespace IRTree;


CIRExpList::CIRExpList(IIRExp* head, CIRExpList* tail)
{
	expList = tail->GetExpList();
	expList.push_front(*head);
}

CIRExpList::~CIRExpList()
{
}

std::list<IIRExp> CIRExpList::GetExpList()
{
	return expList;
}


CIRStmList::CIRStmList(IIRStm * head, CIRStmList * tail)
{
	stmList = tail->GetStmList();
	stmList.push_front(*head);
}

CIRStmList::~CIRStmList()
{
}

std::list<IIRStm> CIRStmList::GetStmList()
{
	return stmList;
}