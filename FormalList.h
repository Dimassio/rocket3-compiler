#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CFormalList : public  IFormalList {
public:
	CFormalList( IType* _type, std::string _id, IFormalRestList* _formalRestList );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const IFormalRestList* FormalRestList() const;

	const std::string Id() const;

private:
	IType* type;
	IFormalRestList* formalRestList;
	std::string id;
};
