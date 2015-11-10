#pragma once

#include "Grammar.h"
#include "Symbols.h"
#include "Visitor.h"
#include <string>

class CExpId : public IExpId {
public:
	CExpId( const std::string &_id, int _yylineno );

	void Accept(IVisitor* visitor) const;

	const std::string& Id() const;

	int yylineno;
private:
	const std::string id;
	
};
