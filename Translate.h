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
		virtual const IIRExp* ToExp() const = 0; // как Expr
		virtual const IIRStm* ToStm() const = 0; // как Stm
		virtual const IIRStm* ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const = 0; // как if/jump
	};

	class CExpConverter: public ISubtreeWrapper {
	public:
		CExpConverter( const IIRExp* _exp );

		~CExpConverter();

		const IIRExp* ToExp() const;

		const IIRStm* ToStm() const;

		const IIRStm* ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const;

	private:
		const IIRExp* exp;
	};

	class CStmConverter: public ISubtreeWrapper {
	public:
		CStmConverter( const IIRStm* _stm );

		~CStmConverter();

		const IIRExp* ToExp() const;

		const IIRStm* ToStm() const;

		const IIRStm* ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const;

	private:
		const IIRStm* stm;
	};
}