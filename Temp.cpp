#include "Temp.h"

using namespace Temp;

CLabel::CLabel() {

}

CLabel::~CLabel()
{
}

CLabel::CLabel(const Symbols::CSymbol* symbol) {

}

const std::string& CLabel::Name() const
{
	return name;
}

CTemp::CTemp() {
}

CTemp::~CTemp()
{
}

CTemp::CTemp(const CTemp& temp) :
	name( temp.Name() )
{
}

CTemp::CTemp(const Symbols::CSymbol* symbol) {

}

const std::string& CTemp::Name() const
{
	return name;
}
