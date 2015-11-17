#pragma once
#include "Temp.h"
#include "IRTree.h"

namespace Translate
{
	class ISubtreeWrapper {
	public:
		virtual ~ISubtreeWrapper()
		{
		}
		virtual const IRTree::IExp* ToExp() const = 0; // как Expr
		virtual const IRTree::IStm* ToStm() const = 0; // как Stm
		virtual const IRTree::IStm* ToConditional( const Temp::CLabel* t, const Temp::CLabel* f ) const = 0; // как if/jump
	}
}