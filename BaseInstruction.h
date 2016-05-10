#pragma once
#include "Frame.h"
#include "Temp.h"

namespace Assembler {
	class CBaseInstruction {
	public:
		CBaseInstruction( const std::string& assemblerLine )
			: assemblerInstruction( assemblerLine )
		{
		}

		virtual ~CBaseInstruction() {}

		virtual Temp::CTempList* UsedVars() const = 0;
		virtual Temp::CTempList* DefindedVars() const = 0;
		virtual Temp::CLabelList* JumpTargets() const = 0;

		std::string Format( Temp::CTempList* varsMapping ) const;

		std::string GetAssemblerInstruction() const { return assemblerInstruction; }
		void SetAssemblerInstruction( const std::string& assemblerInstr ) { assemblerInstruction = assemblerInstr; }

	protected:
		std::string assemblerInstruction;

	private:
		const Temp::CTemp* getNthTemp( Temp::CTempList* list, int i );
		const Temp::CLabel* getNthLabel( Temp::CLabelList* list, int i );
	};

	class CBaseInstructionList {
	public:
		CBaseInstructionList( CBaseInstruction* _head, CBaseInstructionList* _tail )
			: head( _head )
			, tail( _tail )
		{
		}

		CBaseInstruction* head;
		CBaseInstructionList* tail;
	};

	class CLabel : public CBaseInstruction {
	public:
		CLabel( const std::string& instructLine, const Temp::CLabel* _label ) :
			CBaseInstruction( instructLine ), label( _label )
		{}

		Temp::CTempList* UsedVars() const override
		{
			return nullptr;
		}

		Temp::CTempList* DefindedVars() const override
		{
			return nullptr;
		}

		Temp::CLabelList* JumpTargets() const override
		{
			return nullptr;
		}

	private:
		const Temp::CLabel* label;
	};

	class CMove : public CBaseInstruction {
	public:
		CMove( const std::string& assemblerLine, const Temp::CTemp* dest, const Temp::CTemp* src )
			: CBaseInstruction( assemblerLine )
			, destTemp( dest )
			, srcTemp( src )
		{
		}

		Temp::CTempList* UsedVars() const override
		{
			return new Temp::CTempList( srcTemp, nullptr );
		}

		Temp::CTempList* DefindedVars() const override
		{
			return new Temp::CTempList( destTemp, nullptr );
		}

		Temp::CLabelList* JumpTargets() const override
		{
			return nullptr;
		}

	private:
		const Temp::CTemp* destTemp;
		const Temp::CTemp* srcTemp;
	};

	class COper : public CBaseInstruction {
	public:
		COper( const std::string& assemblerLine, Temp::CTempList* dest, Temp::CTempList* src, Temp::CLabelList* jump )
			: CBaseInstruction( assemblerLine )
			, destTempList( dest )
			, srcTempList( src )
			, jumpTargets( jump )
		{
		}

		COper( const std::string& assemblerLine, Temp::CTempList* dest, Temp::CTempList* src )
			: CBaseInstruction( assemblerLine )
			, destTempList( dest )
			, srcTempList( src )
		{
		}

		Temp::CTempList* UsedVars() const override
		{
			return srcTempList;
		}

		Temp::CTempList* DefindedVars() const override
		{
			return destTempList;
		}

		Temp::CLabelList* JumpTargets() const override
		{
			return jumpTargets;
		}

		std::string GetOperator() const { return assemblerInstruction.substr(0, assemblerInstruction.find(' ')); }

	private:
		Temp::CLabelList* jumpTargets;
		Temp::CTempList* destTempList;
		Temp::CTempList* srcTempList;
	};
}