#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CExpId : public IExpId {
public:
	CExpId( std::string id );

	void Accept(IVisitor* visitor) const;

	const Symbols::CSymbol* Symbol() const;

private:
	const Symbols::CSymbol* symbol;
};
