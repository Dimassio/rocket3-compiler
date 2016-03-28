#include "Temp.h"

using namespace Temp;

int CTemp::nextUniqueId = 0;
int CLabel::nextUniqueId = 0;

CLabel::CLabel():
	name(std::to_string(nextUniqueId))
{
	++nextUniqueId;
}

CLabel::~CLabel()
{
}

CLabel::CLabel( const Symbols::CSymbol* symbol )
	: name( symbol->String() )
{
}

const std::string& CLabel::Name() const
{
	return name;
}

CTemp::CTemp() :
	name(std::to_string(nextUniqueId))
{
	++nextUniqueId;
}

CTemp::~CTemp()
{
}

CTemp::CTemp( const CTemp& temp ):
	name( temp.Name() )
{
}

CTemp::CTemp( const Symbols::CSymbol* symbol ) :
	name( symbol->String() )
{
}

const std::string& CTemp::Name() const
{
	return name;
}
