#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CFormalRest : public IFormalRest {
public:
	CFormalRest(IType* _type, std::string _id);

	void Accept(IVisitor* visitor) const;

	const IType* Type() const;

	const std::string Id() const;

private:
	IType* type;
	std::string id;
};

