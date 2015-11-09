#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNewCustomType : public IExpNewCustomType {
public:
	CExpNewCustomType( IType* _type );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

private:
	IType* type;
};
