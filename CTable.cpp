#include "CTable.h"

bool CTable::AddClass(const Symbols::CSymbol* classSymbol, const Symbols::CSymbol* extendedClassSymbol) {
	if (classes.find(classSymbol) != classes.end()) {
		return false;
	}
	else {
		classes[classSymbol] = CClassInfo(classSymbol, extendedClassSymbol);
	}

}

CClassInfo* CTable::GetClass(const Symbols::CSymbol * classSymbol) {
	if (classes.find(classSymbol) == classes.end()) {
		return nullptr; 
	}
	else {
		return &classes[classSymbol];
	}
}

const CClassInfo* CTable::GetClass(const Symbols::CSymbol * classSymbol) const
{
	if (classes.find(classSymbol) == classes.end()) {
		return nullptr;
	}
	else {
		return &classes[classSymbol];
	}
}