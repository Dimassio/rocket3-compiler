#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNewCustomType : public IExpNewCustomType {
public:
	CExpNewCustomType( std::string _type );

	void Accept( IVisitor* visitor ) const;

	const std::string Type() const;

private:
	std::string type;
};
