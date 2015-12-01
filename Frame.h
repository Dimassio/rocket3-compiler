#pragma once
#include <vector>
#include "IRTree.h"
#include "Temp.h"
#include "Symbols.h"

namespace Frame
{
	class IAccess {
	public:
		virtual ~IAccess()
		{
		}
		virtual const IRTree::IExp* GetExp( const Temp::CTemp* framePtr ) const = 0;
	};

	class CInFrame: public IAccess { // In frame: at fp + k
	public:
		CInFrame( int _offset ):
			offset( _offset )
		{
		}

		const IRTree::IExp* CInFrame::GetExp( const Temp::CTemp* framePtr ) const;
	private:
		int offset;
	};

	class CInReg: public IAccess { // Var in reg
	public:
		CInReg( Temp::CTemp _temp ):
			temp( _temp )
		{
		}

		const IRTree::IExp* GetExp( const Temp::CTemp* framePtr ) const;

	private:
		Temp::CTemp temp;
	};

	class CFrame {  // TODO:!!!!!!!
	public:
		CFrame( const Symbols::CSymbol* name, int formalCount );

		~CFrame();

		int FormalCount() const
		{
			return formals.size();
		}

		// Получение аргументна под номером index
		const IAccess* Formal( size_t index ) const;
		const Temp::CTemp* getFP() const;

	private:
		std::map<const Symbols::CSymbol*, IAccess*> formals; // аргументы функции
		std::map<const Symbols::CSymbol*, IAccess*> locals; // локальные переменные
		std::map<const Symbols::CSymbol*, IAccess*> temproraries; // временные переменны
		static const int wordSize = 4;
		Temp::CTemp* FP;
		int offSet; // Относительно FramePointer/ offSet += WordSize
	};

}