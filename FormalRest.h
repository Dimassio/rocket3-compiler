#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CFormalRest : public IFormalRest {
public:
	CFormalRest(IType* _type, std::string _id) :
		type(_type), id(_id)
	{
	}

	void Accept(IVisitor* visitor) const
	{
		visitor->visit(this);
	}

	const IType* Type() const
	{
		return type;
	}

	const std::string Id() const
	{
		return id;
	}

private:
	IType* type;
	std::string id;
};

