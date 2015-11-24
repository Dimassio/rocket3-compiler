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

	class CLabelList {

	};


	// ��������� ����������
	class CTemp {
	public:
		CTemp();

		CTemp( const CTemp& temp );

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