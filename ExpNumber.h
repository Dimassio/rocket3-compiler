#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNumber : public IExpNumber {
public:
	CExpNumber( int _number );

	void Accept(IVisitor* visitor) const;

	const int Number() const;

private:
	int number;
};
