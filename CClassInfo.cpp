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

bool CClassInfo::AddVariable(const Symbols::CSymbol* variableSymbol, CType* type) {
	if (variables.find(variableSymbol) != variables.end()) {
		return false;
	} else {
		variables[variableSymbol] = CVarInfo(variableSymbol, type);
	}

	return true;
}

CVarInfo* CClassInfo::GetVariable(const Symbols::CSymbol* variableSymbol) {
	if (variables.find(variableSymbol) == variables.end()) {
		return nullptr;
	} else {
		return &variables[variableSymbol];
	}
}

bool CClassInfo::AddMethod(const Symbols::CSymbol* methodSymbol, CType* type) {
	if (methods.find(methodSymbol) != methods.end()) {
		return false;
	} else {
		methods[methodSymbol] = CMethodInfo(methodSymbol, type);
	}

	return true;
}

CMethodInfo* CClassInfo::GetMethod(const Symbols::CSymbol* methodSymbol) {
	if (methods.find(methodSymbol) == methods.end()) {
		return nullptr;
	} else {
		return &methods[methodSymbol];
	}
}
