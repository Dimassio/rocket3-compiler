#include "CMethodInfo.h"

CMethodInfo::CMethodInfo() {
}

CMethodInfo::CMethodInfo(const Symbols::CSymbol* _methodSymbol, CType* _type) :
	methodSymbol(_methodSymbol),
	type(_type)
{
}

const Symbols::CSymbol* CMethodInfo::MethodSymbol() {
	return methodSymbol;
}

CType* CMethodInfo::Type() {
	return type;
}

bool CMethodInfo::AddArgument(const Symbols::CSymbol* argumentSymbol, CType* type) {
	if (arguments.find(argumentSymbol) != arguments.end()) {
		return false;
	}
	else {
		arguments[argumentSymbol] = CVarInfo(argumentSymbol, type);
	}
	return true;
}

CVarInfo* CMethodInfo::GetArgument(const Symbols::CSymbol* argumentSymbol) {
	if (arguments.find(argumentSymbol) == arguments.end()) {
		return nullptr;
	} else {
		return &arguments[argumentSymbol];
	}
}

bool CMethodInfo::AddLocalVariable(const Symbols::CSymbol* variableSymbol, CType* type) {
	if (localVariables.find(variableSymbol) != localVariables.end()) {
		return false;
	} else {
		localVariables[variableSymbol] = CVarInfo(variableSymbol, type);
	}
	return true;
}

CVarInfo* CMethodInfo::GetLocalVariable(const Symbols::CSymbol* variableSymbol) {
	if (localVariables.find(variableSymbol) == localVariables.end()) {
		return nullptr;
	} else {
		return &localVariables[variableSymbol];
	}
}
