#pragma once
#include <vector>
#include "Symbols.h"

namespace Frame
{

	class IAccess {
	public:
		virtual ~IAccess()
		{
		}
	};

	class CFrame {
	public:
		CFrame( const Symbols::CSymbol* name, int formalCount );
		
		int FormalCount() const
		{
			return formals.size();
		}

		// Получение аргументна под номером index
		const IAccess* Formal( size_t index ) const;

	private:
		std::vector<Symbols::CSymbol*> formals; // аргументы функции
	};

}