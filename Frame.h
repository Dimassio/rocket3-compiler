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
		virtual const IIRExp* GetExp( const Temp::CTemp* framePtr ) const = 0;
	};

	class CInFrame: public IAccess { // In frame: at fp + k
	public:
		CInFrame( int _offset );

		const IIRExp* CInFrame::GetExp( const Temp::CTemp* framePtr ) const;
	private:
		int offset;
	};

	class CInReg: public IAccess { // Var in reg
	public:
		CInReg( Temp::CTemp _temp );

		const IIRExp* GetExp( const Temp::CTemp* framePtr ) const;

	private:
		Temp::CTemp temp;
	};

	class CFrame {
	public:
		CFrame( const std::string& name, int formalCount );

		~CFrame();

		int FormalCount() const;

		const Temp::CTemp* GetFP() const;

		const IAccess* GetVar( const std::string& id ) const;

		bool AddLocal( const Symbols::CSymbol* symbol );

		bool AddFormal(const Symbols::CSymbol* symbol);

		bool AddTemprorary( const Symbols::CSymbol* symbol );

		void HangToRoot( IIRExp* stm );

		const std::string& GetFrameName() const;

		// Размер ячейки
		static const int wordSize = 4;

		IIRExp* root; // eseq's in roots, because statemnets + return expr

	private:
		std::map<const Symbols::CSymbol*, IAccess*> formals; // аргументы функции
		std::map<const Symbols::CSymbol*, IAccess*> locals; // локальные переменные
		std::map<const Symbols::CSymbol*, IAccess*> temproraries; // временные переменные

		Temp::CTemp* FP; // frame pointer

		int offSet; // Относительно FP

		const Symbols::CSymbol* symbol;
	};
}
