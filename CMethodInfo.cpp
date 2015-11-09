#include "StaticVariables.h"
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

bool CMethodInfo::AddArgument(const std::string &argumentId, CType* type) {
	const Symbols::CSymbol* argumentSymbol = symbolStorage.Get( argumentId );

	if (arguments.find(argumentSymbol) != arguments.end()) {
		return false;
	}
	else {
		arguments[argumentSymbol] = CVarInfo(argumentSymbol, type);
	}
	return true;
}

CVarInfo* CMethodInfo::GetArgument(const std::string &argumentId) {
	const Symbols::CSymbol* argumentSymbol = symbolStorage.Get( argumentId );

	if (arguments.find(argumentSymbol) == arguments.end()) {
		return nullptr;
	} else {
		return &arguments[argumentSymbol];
	}
}

bool CMethodInfo::AddLocalVariable(const std::string &variableId, CType* type) {
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	if (localVariables.find(variableSymbol) != localVariables.end()) {
		return false;
	} else {
		localVariables[variableSymbol] = CVarInfo(variableSymbol, type);
	}
	return true;
}

CVarInfo* CMethodInfo::GetLocalVariable(const std::string &variableId) {
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	if (localVariables.find(variableSymbol) == localVariables.end()) {
		return nullptr;
	} else {
		return &localVariables[variableSymbol];
	}
}
