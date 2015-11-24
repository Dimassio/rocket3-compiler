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

	class CInFrame: public IAccess {
	public:
		CInFrame( int k );
	};

	class CInReg: public IAccess {
		CInReg( Temp::CTemp temp);
	};


	class CFrame {
	public:
		CFrame( const Symbols::CSymbol* name, int formalCount );

		~CFrame();

		int FormalCount() const
		{
			return formals.size();
		}

		// Получение аргументна под номером index
		const IAccess* Formal( size_t index ) const;
		const Temp::CTemp* FP() const;

	private:
		std::vector<CInFrame*> formals; // аргументы функции
		static const int wordSize = 4;
		Temp::CTemp* FP;
		int offSet; // Относительно FramePointer/ offSet += WordSize
	};

}