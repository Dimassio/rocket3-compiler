#pragma once
#include <string>
#include "Symbols.h"
#include <list>

namespace Temp
{
	// ����� - ����� �������� � ����
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

	class CLabelList {
	public:
		CLabelList( const CLabel* label );
		~CLabelList();

		void Add( const CLabel* label );
	private:
		std::list<const CLabel*> labels;
	};

	// ��������� ����������
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