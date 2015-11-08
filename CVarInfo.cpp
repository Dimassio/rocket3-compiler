#include "CVarInfo.h"

CVarInfo::CVarInfo() {
}

CVarInfo::CVarInfo(const Symbols::CSymbol* _symbol, CType* _type) :
	type(_type),
	symbol(_symbol)
{
}

const Symbols::CSymbol* CVarInfo::Symbol() const {
	return symbol;
}

const CType* CVarInfo::Type() const {
	return type;
}