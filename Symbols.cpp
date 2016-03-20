#include "Symbols.h"

Symbols::CStorage::CStorage()
{
}

Symbols::CSymbol::CSymbol(const std::string &_id) :
	id(_id)
{
}

const std::string& Symbols::CSymbol::String() const {
	return id;
}

const Symbols::CSymbol* Symbols::CStorage::Get(const std::string id) {
	if (symbols.find(id) == symbols.end()) {
		symbols[id] = new CSymbol(id);
	}

	return symbols[id];
}
