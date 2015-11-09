#pragma once

#include "grammar.h"
#include "Visitor.h"
#include <string>

class CExpBinOperation : public IExpBinOperation {
public:
	CExpBinOperation( const std::string &_expName, IExp* _firstExp, IExp* _secondExp );

	void Accept(IVisitor* visitor) const;

	const IExp* FirstExp() const;

	const IExp* SecondExp() const;

	const std::string& ExpName() const;

private:
	const std::string expName;
	IExp* firstExp;
	IExp* secondExp;
};

