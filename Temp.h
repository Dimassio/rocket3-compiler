#pragma once
#include <string>
#include "Symbols.h"

namespace Temp
{
	// ����� - ����� �������� � ����
	class CLabel {
	public:
		CLabel();

		explicit CLabel( const Symbols::CSymbol* symbol );

		const std::string& Name() const
		{
			return name;
		}

		~CLabel();

	private:
		static int nexUniqueId;
		std::string name;
	};


	// ��������� ����������
	class CTemp {
	public:
		CTemp();

		explicit CTemp( const Symbols::CSymbol* symbol );

		~CTemp();

		const std::string& Name() const
		{
			return name;
		}

	private:
		static int nexUniqueId;
		std::string name;
	};
}