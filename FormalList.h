#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CFormalList : public  IFormalList {
public:
	CFormalList(IType* _type, std::string _id, IFormalRestList* _formalRestList) :
		type(_type), id(_id), formalRestList(_formalRestList)
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

	const IFormalRestList* FormalRestList() const
	{
		return formalRestList;
	}

	const std::string Id() const
	{
		return id;
	}

private:
	IType* type;
	IFormalRestList* formalRestList;
	std::string id;
};
