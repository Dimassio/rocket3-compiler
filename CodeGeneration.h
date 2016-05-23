#pragma once
#include "Frame.h"
#include "CExp.h"
#include "CStm.h"
#include "BaseInstruction.h"
#include "BasicBlock.h"
#include "Frame.h"

class CCodeGeneration {
public:
	CCodeGeneration():
		instructList( nullptr ), 
		last( nullptr )
	{
	}

	void SetFrame( const Frame::CFrame* currFrame );

	void GenerateCode( const std::list<const IIRStm*>& statements, Assembler::CBaseInstructionList*& );

	void GenerateCode( const std::list<const IIRStm*>& statements, std::list<const Assembler::CBaseInstruction*>& );

private:
	Assembler::CBaseInstructionList* instructList;
	Assembler::CBaseInstructionList* last;
	const Frame::CFrame* frame;

	void emit( Assembler::CBaseInstruction* instruct );

	void munchStm( const CIRSeq* stm );
	void munchStm( const CIRMove* stm );
	void munchStm( const CIRLabel* stm );
	void munchStm( const CIRExp* stm );
	void munchStm( const CIRJump* stm );
	void munchStm( const CIRCJump* stm );
	void munchStm( const IIRStm* stm );

	const Temp::CTemp* munchExpJump( const CIRBinOp* binOp );
	const Temp::CTemp* munchExp( const CIRMem* exp );
	const Temp::CTemp* munchExp( const CIRBinOp* exp );
	const Temp::CTemp* munchExp( const CIRConst* exp );
	const Temp::CTemp* munchExp( const CIRTemp* exp );
	const Temp::CTemp* munchExp( const CIRName* exp );
	const Temp::CTemp* munchExp( const CIRCall* exp );
	const Temp::CTemp* munchExp( const IIRExp* exp );

	const Temp::CTempList* munchArgs( const CIRExpList* args );
};