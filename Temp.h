#pragma once
#include <string>
#include "Symbols.h"
#include <list>

namespace Temp
{
	// Метка - точка перехода в коде
	class CLabel {
	public:
		CLabel();

		explicit CLabel( const Symbols::CSymbol* symbol );

		const std::string& Name() const;

		~CLabel();

	private:
		static int nextUniqueId;
		std::string name;
	};

	// Временная переменная
	class CTemp {
	public:
		CTemp();

		CTemp( const CTemp& temp );

		explicit CTemp( const Symbols::CSymbol* symbol );

		~CTemp();

		const std::string& Name() const;

	private:
		static int nextUniqueId;
		std::string name;
	};
}