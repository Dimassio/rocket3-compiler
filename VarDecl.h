#pragma once

#include "Grammar.h"
#include "Visitor.h"

class CVarDecl : IVarDecl {
public:
	CVarDecl( IType* _type, std::string _varName ) :
		type( _type ), varName( _varName )
	{
	}

	void Accept( IVisitor* visitor ) const
	{
		visitor->visit( this );
	}

	const IType* Type() const
	{
		return type;
	}

	const std::string VarName() const
	{
		return varName;
	}

private:
	IType* type;
	std::string varName;
};
