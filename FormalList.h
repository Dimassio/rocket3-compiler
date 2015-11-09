#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CFormalList : public  IFormalList {
public:
	CFormalList( IType* _type, const std::string &_id, IFormalRestList* _formalRestList );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const IFormalRestList* FormalRestList() const;

	const std::string& Id() const;

private:
	IType* type;
	IFormalRestList* formalRestList;
	const std::string id;
};
