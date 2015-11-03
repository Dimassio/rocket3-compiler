#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpLength : public IExpLength {
public:
	CExpLength( IExp* _exp );

	void Accept( IVisitor* visitor ) const;

	const IExp* Exp() const;

private:
	IExp* exp;
};