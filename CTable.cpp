#include "StaticVariables.h"
#include "CTable.h"

bool CTable::AddClass(const std::string &classId, const std::string &extendedClassId) {
	const Symbols::CSymbol* classSymbol = symbolStorage.Get(classId);

	const Symbols::CSymbol* extendedClassSymbol;
	if (extendedClassId == "") {
		extendedClassSymbol = nullptr;
	} else {
		extendedClassSymbol = symbolStorage.Get(extendedClassId);
	}

	if (classes.find(classSymbol) != classes.end()) {
		return false;
	}
	else {
		classes[classSymbol] = CClassInfo(classSymbol, extendedClassSymbol);
		return true;
	}
}

CClassInfo* CTable::GetClass(const std::string &classId) {
	const Symbols::CSymbol* classSymbol = symbolStorage.Get( classId );

	if (classes.find(classSymbol) == classes.end()) {
		return nullptr; 
	}
	else {
		return &classes[classSymbol];
	}
}

const CClassInfo* CTable::GetClass(const std::string &classId) const {
	const Symbols::CSymbol* classSymbol = symbolStorage.Get( classId );

	if (classes.find(classSymbol) == classes.end()) {
		return nullptr;
	}
	else {
		return &classes.find(classSymbol)->second;
	}
}