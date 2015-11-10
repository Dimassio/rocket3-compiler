#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CFormalRest : public IFormalRest {
public:
	CFormalRest( IType* _type, const std::string &_id, int yylineno );

	void Accept( IVisitor* visitor ) const;

	const IType* Type() const;

	const std::string& Id() const;

	int yylineno;
private:
	IType* type;
	const std::string id;
	
};

