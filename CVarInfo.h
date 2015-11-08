#pragma once

#include "Common.h"
#include "Symbols.h"

class CVarInfo {
public:
	CVarInfo();

	CVarInfo(const Symbols::CSymbol* _symbol, CType* _type);

	const Symbols::CSymbol* Symbol() const;

	const CType* Type() const;

private:
	const Symbols::CSymbol* symbol;
	CType* type;
};
