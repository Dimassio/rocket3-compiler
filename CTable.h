#pragma once

#include "Common.h"
#include "Symbols.h"
#include "CClassInfo.h"

class CTable {
public:
	bool AddClass(const std::string &classId, const std::string &extendedClassId);
	CClassInfo* GetClass(const std::string &classId);
	const CClassInfo* GetClass(const std::string &classId) const;

private:
	std::map<const Symbols::CSymbol*, CClassInfo> classes;
};

