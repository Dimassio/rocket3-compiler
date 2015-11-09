#pragma once

#include "Common.h"
#include "Symbols.h"
#include "CClassInfo.h"

class CTable {
public:
	bool AddClass(const Symbols::CSymbol* classSymbol, const Symbols::CSymbol* extendedClassSymbol);
	CClassInfo* GetClass(const Symbols::CSymbol* classSymbol);
	const CClassInfo* GetClass(const Symbols::CSymbol* classSymbol) const;

private:
	std::map<const Symbols::CSymbol*, CClassInfo> classes;
};

