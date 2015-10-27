#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CExpRest : public  IExpRest {
public:
	CExpRest(IExp* _exp);

	void Accept(IVisitor* visitor) const;

	const IExp* Exp() const;

private:
	IExp* exp;
};
