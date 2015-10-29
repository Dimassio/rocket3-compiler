#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CVarDecl : public  IVarDecl {
public:
	CVarDecl( IType* _type, std::string _varName );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const std::string VarName() const;

private:
	IType* type;
	std::string varName;
};
