#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CType : public IType {
public:
	CType(const std::string &_typeName);

	void Accept(IVisitor* visitor) const;
	const std::string& GetTypeName() const;

private:
	const std::string typeName;
};
