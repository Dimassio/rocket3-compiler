#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpSingle : public IExpSingle {
public:
	CExpSingle( const std::string &_expName, int yylineno );

	void Accept(IVisitor* visitor) const;

	const std::string& ExpName() const;

	int yylineno;
private:
	const std::string expName;
	
};
