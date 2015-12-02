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
		virtual const IRTree::IIRExp* ToExp() const = 0; // как Expr
		virtual const IRTree::IIRStm* ToStm() const = 0; // как Stm
		virtual const IRTree::IIRStm* ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const = 0; // как if/jump
	};

	class CExpConverter: public ISubtreeWrapper {
	public:
		CExpConverter(const IRTree::IIRExp* _exp);

		const IRTree::IIRExp* ToExp() const;

		const IRTree::IIRStm* ToStm() const;

		const IRTree::IIRStm* ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const;

	private:
		const IRTree::IIRExp* exp;
	};

	class CStmConverter : public ISubtreeWrapper {
	public:
		CStmConverter(const IRTree::IIRStm* _stm);

		const IRTree::IIRExp* ToExp() const;

		const IRTree::IIRStm* ToStm() const;

		const IRTree::IIRStm* ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const;

	private:
		const IRTree::IIRStm* stm;
	};
}