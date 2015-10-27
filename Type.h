#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CType : public IType {
public:
	CType(std::string _typeName);

	void Accept(IVisitor* visitor) const;
	const std::string GetTypeName() const;

private:
	std::string typeName;

};
