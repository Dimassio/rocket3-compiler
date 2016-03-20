#pragma once

#include <string>
#include <map>

namespace Symbols
{

	class CSymbol {
	public:
		CSymbol( const std::string &_id );
		const std::string& String() const;
	private:
		const std::string id;
	};

	class CStorage {
	public:
		CStorage();
		const CSymbol* Get( const std::string id );
	private:
		std::map<std::string, CSymbol*> symbols;
	};

}
