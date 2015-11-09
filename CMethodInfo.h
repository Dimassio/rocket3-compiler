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

	bool AddArgument(const std::string &argumentId, CType* type);
	CVarInfo* GetArgument(const std::string &argumentId);

	bool AddLocalVariable(const std::string &variableId, CType* type);
	CVarInfo* GetLocalVariable(const std::string &variableId);

private:
	const Symbols::CSymbol* methodSymbol;
	CType* type;

	std::map<const Symbols::CSymbol*, CVarInfo> arguments;
	std::map<const Symbols::CSymbol*, CVarInfo> localVariables;
};