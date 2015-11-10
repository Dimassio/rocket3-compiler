#include "ExpId.h"

CExpId::CExpId( const std::string &_id, int _yylineno )
	: id(_id), yylineno(_yylineno )
{
}

void CExpId::Accept(IVisitor* visitor) const
{
	visitor->visit(this);
}

const std::string& CExpId::Id() const {
	return id;
}
