#pragma once
#include <vector>
#include "IRTree.h"
#include "Temp.h"
#include "Symbols.h"

namespace Frame
{
	class IAccess {
	public:
		virtual ~IAccess();
		virtual const IRTree::IIRExp* GetExp( const Temp::CTemp* framePtr ) const = 0;
	};

	class CInFrame: public IAccess { // In frame: at fp + k
	public:
		CInFrame(int _offset);

		const IRTree::IIRExp* CInFrame::GetExp( const Temp::CTemp* framePtr ) const;
	private:
		int offset;
	};

	class CInReg: public IAccess { // Var in reg
	public:
		CInReg(Temp::CTemp _temp);

		const IRTree::IIRExp* GetExp( const Temp::CTemp* framePtr ) const;

	private:
		Temp::CTemp temp;
	};

	class CFrame {
	public:
		CFrame( const std::string& name, int formalCount );

		~CFrame();

		int FormalCount() const;

		const Temp::CTemp* GetFP() const;

		const IAccess* GetVar( const std::string& id) const;

		const bool AddLocal( const Symbols::CSymbol* symbol );

		const bool AddTemprorary( const Symbols::CSymbol* symbol );

		// Размер ячейки
		static const int wordSize = 4;
	private:
		std::map<const Symbols::CSymbol*, IAccess*> formals; // аргументы функции
		std::map<const Symbols::CSymbol*, IAccess*> locals; // локальные переменные
		std::map<const Symbols::CSymbol*, IAccess*> temproraries; // временные переменные

		Temp::CTemp* FP; // frame pointer

		int offSet; // Относительно FP
	};
}
