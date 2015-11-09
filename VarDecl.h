#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CVarDecl : public  IVarDecl {
public:
	CVarDecl( IType* _type, const std::string &_id );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const std::string& Id() const;

private:
	IType* type;
	const std::string id;
};
