#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CFormalList : public  IFormalList {
public:
	CFormalList( IType* _type, std::string id, IFormalRestList* _formalRestList );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const IFormalRestList* FormalRestList() const;

	const Symbols::CSymbol* Symbol() const;

private:
	IType* type;
	IFormalRestList* formalRestList;
	const Symbols::CSymbol* symbol;
};
