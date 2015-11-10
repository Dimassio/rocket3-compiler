#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CType : public IType {
public:
	CType(const std::string &_typeName, int yylineno );

	void Accept(IVisitor* visitor) const;
	const std::string& GetTypeName() const;

	int yylineno;
private:
	const std::string typeName;
	
};
