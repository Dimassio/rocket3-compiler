#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CType : IType {
public:
	CType(std::string _typeName) :
		typeName(_typeName)
	{
	}

	void Accept(IVisitor* visitor) const
	{
		visitor->visit(this);
	}

	const std::string GetTypeName() const
	{
		return typeName;
	}

private:
	std::string typeName;
};
