#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CVarDecl : public  IVarDecl {
public:
	CVarDecl( IType* _type, std::string id );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const Symbols::CSymbol* Symbol() const;

private:
	IType* type;
	const Symbols::CSymbol* symbol;
};
