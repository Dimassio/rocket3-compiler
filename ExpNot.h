#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNot : public IExpNot {
public:
	CExpNot( IExp* _exp );

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

private:
	IExp* exp;
};
