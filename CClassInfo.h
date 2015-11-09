#pragma once

#include "Symbols.h"
#include "CVarInfo.h"
#include "CMethodInfo.h"

class CClassInfo {
public:
	CClassInfo();

	CClassInfo(const Symbols::CSymbol* _classSymbol, const Symbols::CSymbol* _extendedClassSymbol);

	const Symbols::CSymbol* ClassSymbol() const;
	const Symbols::CSymbol* ExtendedClassSymbol() const;

	bool AddVariable(const std::string& variableId, CType* type);
	CVarInfo* GetVariable(const std::string& variableId);

	bool AddMethod(const std::string& methodId, CType* type);
	CMethodInfo* GetMethod(const std::string& methodId);

private:
	const Symbols::CSymbol* classSymbol;
	const Symbols::CSymbol* extendedClassSymbol;

	std::map<const Symbols::CSymbol*, CVarInfo> variables;
	std::map<const Symbols::CSymbol*, CMethodInfo> methods;
};