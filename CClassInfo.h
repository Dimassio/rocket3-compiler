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
	const std::string& ClassName() const;
	const std::string& ExtendedClassName() const;

	bool AddVariable(const std::string& variableId, CType* type);
	CVarInfo* GetVariable(const std::string& variableId);
	const CVarInfo* GetVariable( const std::string& variableId ) const;
	const std::map<const Symbols::CSymbol*, CVarInfo>& GetVariables() const;

	bool AddMethod(const std::string& methodId, CType* type);
	CMethodInfo* GetMethod(const std::string& methodId);
	const CMethodInfo* GetMethod( const std::string& methodId ) const;

private:
	const Symbols::CSymbol* classSymbol;
	const Symbols::CSymbol* extendedClassSymbol;

	std::map<const Symbols::CSymbol*, CVarInfo> variables;
	std::map<const Symbols::CSymbol*, CMethodInfo> methods;
};