#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpSingle : public IExpSingle {
public:
	CExpSingle( const std::string &_expName );

	void Accept(IVisitor* visitor) const;

	const std::string& ExpName() const;

private:
	const std::string expName;
};
