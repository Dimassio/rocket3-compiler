#pragma once

#include "Symbols.h"
#include "CVarInfo.h"
#include "Type.h"

class CMethodInfo {
public:
	CMethodInfo();

	CMethodInfo(const Symbols::CSymbol* _methodSymbol, CType* _type);

	const Symbols::CSymbol* MethodSymbol();
	CType* Type();

	bool AddArgument(const Symbols::CSymbol* argumentSymbol, CType* type);
	CVarInfo* GetArgument(const Symbols::CSymbol* argumentSymbol);

	bool AddLocalVariable(const Symbols::CSymbol* variableSymbol, CType* type);
	CVarInfo* GetLocalVariable(const Symbols::CSymbol* variableSymbol);

private:
	const Symbols::CSymbol* methodSymbol;
	CType* type;

	std::map<const Symbols::CSymbol*, CVarInfo> arguments;
	std::map<const Symbols::CSymbol*, CVarInfo> localVariables;
};