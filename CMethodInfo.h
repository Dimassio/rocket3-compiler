#pragma once

#include "Symbols.h"
#include "CVarInfo.h"
#include "Type.h"
#include <vector>

class CMethodInfo {
public:
	CMethodInfo();

	CMethodInfo(const Symbols::CSymbol* _methodSymbol, CType* _type);

	const Symbols::CSymbol* MethodSymbol() const;
	CType* Type();

	bool AddArgument(const std::string &argumentId, CType* type);
	CVarInfo* GetArgument(const std::string &argumentId);
	const CVarInfo* GetArgument( int number ) const;

	bool AddLocalVariable(const std::string &variableId, CType* type);
	CVarInfo* GetLocalVariable(const std::string &variableId);
	const CVarInfo* GetLocalVariable( const std::string &variableId ) const;

private:
	const Symbols::CSymbol* methodSymbol;
	CType* type;

	std::vector< std::pair<const Symbols::CSymbol*, CVarInfo> > arguments;
	std::vector< std::pair<const Symbols::CSymbol*, CVarInfo> > localVariables;
};