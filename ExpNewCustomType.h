#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpNewCustomType : public IExpNewCustomType {
public:
	CExpNewCustomType( IType* _type, int _yylineno );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	int yylineno;
private:
	IType* type;
	
};
