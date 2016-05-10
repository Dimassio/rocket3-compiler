#pragma once
#include "Frame.h"
#include "CExp.h"
#include "CStm.h"
#include "BaseInstruction.h"

class CCodeGeneration {
public:
	CCodeGeneration( const Frame::CFrame* _frame )
		: frame( _frame )
		, instructList( nullptr )
		, last( nullptr )
	{
	}

	Assembler::CBaseInstructionList* GenerateCode( CIRStmList* stmList );

private:
	const Frame::CFrame* frame;
	Assembler::CBaseInstructionList* instructList;
	Assembler::CBaseInstructionList* last;

	void emit( Assembler::CBaseInstruction* instruct );

	void munchStm( const CIRSeq* stm );
	void munchStm( const CIRMove* stm );
	void munchStm( const CIRLabel* stm );
	void munchStm( const CIRExp* stm );
	void munchStm( const CIRJump* stm );
	void munchStm( const CIRCJump* stm );
	void munchStm( const IIRStm* stm );

	const Temp::CTemp* munchExp( const  CIRMem* exp );
	const Temp::CTemp* munchExp( const CIRBinOp* exp );
	const Temp::CTemp* munchExp( const CIRConst* exp );
	const Temp::CTemp* munchExp( const CIRTemp* exp );
	const Temp::CTemp* munchExp(  CIRName* exp );
	const Temp::CTemp* munchExp( const CIRCall* exp );
	const Temp::CTemp* munchExp( const IIRExp* exp );

	const Temp::CTempList* munchArgs( const CIRExpList* args );
};