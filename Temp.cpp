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

const CTemp* CTempList::Head() const
{
	return head;
}

const CTempList* CTempList::Tail() const
{
	return tail;
}

const CLabel* CLabelList::Head() const
{
	return head;
}

const CLabelList* CLabelList::Tail() const
{
	return tail;
}
