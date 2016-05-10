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

	class CTempList {
	public:
		CTempList(const CTemp* _head, const CTempList* _tail) :
			tail(_tail), head(_head)
		{}

		const CTemp* Head() const;
		const CTempList* Tail() const;

	private:
		const CTemp* head;
		const CTempList* tail;
	};

	class CLabelList {
	public:
		CLabelList(const CLabel* _head, const CLabelList* _tail) :
			tail(_tail), head(_head)
		{}
		const CLabel* Head() const;
		const CLabelList* Tail() const;
	private:
		const CLabel* head;
		const CLabelList* tail;
	};
}