#include "StaticVariables.h"
#include "CClassInfo.h"

CClassInfo::CClassInfo() {
}

CClassInfo::CClassInfo(const Symbols::CSymbol* _classSymbol, const Symbols::CSymbol* _extendedClassSymbol) :
	classSymbol(_classSymbol),
	extendedClassSymbol(_extendedClassSymbol)
{
}

const Symbols::CSymbol* CClassInfo::ClassSymbol() const
{
	return classSymbol;
}

const Symbols::CSymbol * CClassInfo::ExtendedClassSymbol() const
{
	return extendedClassSymbol;
}

bool CClassInfo::AddVariable(const std::string& variableId, CType* type) {
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	if (variables.find(variableSymbol) != variables.end()) {
		return false;
	} else {
		variables[variableSymbol] = CVarInfo(variableSymbol, type);
	}

	return true;
}

CVarInfo* CClassInfo::GetVariable(const std::string& variableId) {
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	if (variables.find(variableSymbol) == variables.end()) {
		return nullptr;
	} else {
		return &variables[variableSymbol];
	}
}

bool CClassInfo::AddMethod(const std::string& methodId, CType* type) {
	const Symbols::CSymbol* methodSymbol = symbolStorage.Get( methodId );

	if (methods.find(methodSymbol) != methods.end()) {
		return false;
	} else {
		methods[methodSymbol] = CMethodInfo(methodSymbol, type);
	}

	return true;
}

CMethodInfo* CClassInfo::GetMethod(const std::string& methodId) {
	const Symbols::CSymbol* methodSymbol = symbolStorage.Get( methodId );

	if (methods.find(methodSymbol) == methods.end()) {
		return nullptr;
	} else {
		return &methods[methodSymbol];
	}
}
