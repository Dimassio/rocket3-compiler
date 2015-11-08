#pragma once

#include "Symbols.h"
#include "CVarInfo.h"
#include "CMethodInfo.h"

class CClassInfo {
public:
	CClassInfo();

	CClassInfo(const Symbols::CSymbol* _classSymbol, const Symbols::CSymbol* _extendedClassSymbol);

	const Symbols::CSymbol* ClassSymbol();

	bool AddVariable(const Symbols::CSymbol* variableSymbol, CType* type);
	CVarInfo* GetVariable(const Symbols::CSymbol* variableSymbol);

	bool AddMethod(const Symbols::CSymbol* methodSymbol, CType* type);
	CMethodInfo* GetMethod(const Symbols::CSymbol* methodSymbol);

private:
	const Symbols::CSymbol* classSymbol;
	const Symbols::CSymbol* extendedClassSymbol;

	std::map<const Symbols::CSymbol*, CVarInfo> variables;
	std::map<const Symbols::CSymbol*, CMethodInfo> methods;
};