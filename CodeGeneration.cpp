#include "CodeGeneration.h"
#include "EOperation.h"

template<class T, class S>
bool IsInstanceOf(S* exp)
{
	return dynamic_cast< T* >(exp) == 0 ? false : true;
}

Assembler::CBaseInstructionList* CCodeGeneration::GenerateCode( const std::list<const IIRStm*>& statements )
{
	Assembler::CBaseInstructionList* list;
	for( auto statement : statements ) {
		munchStm( statement );
	}
	list = instructList;
	// ����� �� ��������� ��������� ����������� ����� ������
	instructList = last = nullptr;
	return list;
}

void CCodeGeneration::emit( Assembler::CBaseInstruction* instruct )
{
	if( last != nullptr ) {
		last = last->tail = new Assembler::CBaseInstructionList( instruct, nullptr );
	} else {
		last = instructList = new Assembler::CBaseInstructionList( instruct, nullptr );
	}
}

void CCodeGeneration::munchStm(const CIRSeq* stm)
{
	munchStm( stm->left );
	munchStm( stm->right );
}

void CCodeGeneration::munchStm(const CIRMove* stm)
{
	// MOVE( MEM(...) )
	if( IsInstanceOf<CIRMem>( stm->dst ) ) {
		const CIRMem* destMem = dynamic_cast<const CIRMem*>( stm->dst );
		
		if( IsInstanceOf<CIRBinOp>( destMem->exp ) ) {
			auto binOp = dynamic_cast<const CIRBinOp*>( destMem->exp );
			if( binOp->opId == EOperation::PLUS || binOp->opId == EOperation::MINUS ) {
				// MOVE( MEM( BINOP(PLUS, e1, CONST(i)), e2 ) )
				if( IsInstanceOf<CIRConst>( binOp->left ) || IsInstanceOf<CIRConst>( binOp->right ) ) {
					const IIRExp* binOpExpr;
					const CIRConst* constantExpr;
					if( IsInstanceOf<CIRConst>( binOp->left ) ) {
						binOpExpr = binOp->right;
						constantExpr = dynamic_cast<const CIRConst*>( binOp->left );
					} else {
						binOpExpr = binOp->left;
						constantExpr = dynamic_cast<const CIRConst*>( binOp->right );
					}
					emit( new Assembler::COper( std::string( "MOV ['s0" ) +
						( ( binOp->opId == EOperation::PLUS ) ? "+" : "-" ) +
						std::to_string( constantExpr->value ) +
						std::string( "], 's1\n" ),
						nullptr,
						new Temp::CTempList( munchExp( binOpExpr ),
						new Temp::CTempList( munchExp( stm->src ), nullptr ) ) ) );
				} else {
					// MOVE( MEM( BINOP( PLUS, e1, e2 ) ), e3 )
					emit( new Assembler::COper( std::string( "MOV ['s0], 's1\n" ),
						new Temp::CTempList( munchExp( binOp ), nullptr ),
						new Temp::CTempList( munchExp( stm->src ), nullptr ) ) );
				}
			}
		} else if( IsInstanceOf<CIRConst>( destMem->exp ) ) {
			// MOVE( MEM( CONST(i) ), e2 )
			const CIRConst* constantExpr = dynamic_cast<const CIRConst*>( destMem->exp );
			emit( new Assembler::COper( std::string( "MOV ['s0+" ) +
				std::to_string( constantExpr->value ) +
				std::string( "], 's1\n" ),
				nullptr,
				new Temp::CTempList( munchExp( stm->src ), nullptr ) ) );
		} else if( IsInstanceOf<CIRTemp>( destMem->exp ) ) {
			// MOVE( MEM( TEMP ), e2 )
			emit( new Assembler::COper( std::string( "MOV ['s0], 's1\n" ),
				new Temp::CTempList( munchExp( destMem->exp ), nullptr ),
				new Temp::CTempList( munchExp( stm->src ), nullptr ) ) );
		} else if( IsInstanceOf<CIRMem>( destMem->exp ) ) {
			if( IsInstanceOf<CIRMem>( stm->src ) ) {
				// MOVE( MEM(e1), MEM(e2) )
				emit( new Assembler::COper( std::string( "MOV ['s0], ['s1]\n" ),
					nullptr,
					new Temp::CTempList( 
					munchExp( stm->src ),
					new Temp::CTempList( munchExp( stm->src ), nullptr ) ) ) );
			} else {
				// MOVE( MEM(e1), e2 )
				emit( new Assembler::COper( std::string( "MOV ['s0], 's1\n" ),
					nullptr,
					new Temp::CTempList( munchExp( stm->src ),
					new Temp::CTempList( munchExp( stm->src ), nullptr ) ) ) );
			}
		}
	} else if( IsInstanceOf<CIRTemp>( stm->dst ) ) { 
		// MOVE(TEMP(i), e2)
		const CIRTemp* temp = dynamic_cast<const CIRTemp*>( stm->dst );
		emit( new Assembler::COper( "MOV 'd0, 's0 + r0\n",
			new Temp::CTempList( temp->temp, nullptr ),
			new Temp::CTempList( munchExp( stm->src ), nullptr ) ) );
	}
}

void CCodeGeneration::munchStm(const CIRLabel* stm)
{
	emit( new Assembler::CLabel( stm->label->Name() + std::string(":\n"), stm->label ) );
}

void CCodeGeneration::munchStm(const CIRExp* stm)
{
	munchExp( stm->exp );
}

void CCodeGeneration::munchStm(const CIRJump* stm)
{
	emit( new Assembler::COper( "JMP 'j0\n", nullptr, nullptr, stm->GetTargets() ) );
}

void CCodeGeneration::munchStm(const CIRCJump* stm)
{
	emit( new Assembler::COper( "CMP 's0, 's1\n", nullptr, new Temp::CTempList( munchExp( stm->left ),
		new Temp::CTempList( munchExp( stm->right ), nullptr ) ) ) );

	// TODO �������, ��� CCondJump ����� ���� ������ �� < � >= (���������� � TraceSchedule)
	std::string oper;
	switch( stm->op ) {
		case EOperation::LE: oper = "JL"; break;
		case EOperation::GE: oper = "JGE"; break;
	}

	emit( new Assembler::COper( oper + " 'l0\n", nullptr, nullptr, new Temp::CLabel( stm->iftrue, nullptr ) ) );
}

void CCodeGeneration::munchStm(const IIRStm* stm)
{
	if( IsInstanceOf<CIRSeq>( stm ) ) {
		munchStm( dynamic_cast<const CIRSeq*>( stm ) );
	} else if( IsInstanceOf<CIRMove>( stm ) ) {
		munchStm( dynamic_cast<const CIRMove*>( stm ) );
	} else if( IsInstanceOf<CIRLabel>( stm ) ) {
		munchStm( dynamic_cast<const CIRLabel*>( stm ) );
	} else if( IsInstanceOf<CIRExp>( stm ) ) {
		munchStm( dynamic_cast<const CIRExp*>( stm ) );
	} else if( IsInstanceOf<CIRJump>( stm ) ) {
		munchStm( dynamic_cast<const CIRJump*>( stm ) );
	} else if( IsInstanceOf<CIRCJump>( stm ) ) {
		munchStm( dynamic_cast<const CIRCJump*>( stm ) );
	}
}

const Temp::CTemp* CCodeGeneration::munchExp(const  CIRMem* exp)
{
	const Temp::CTemp* temp( new Temp::CTemp );
	if( IsInstanceOf<CIRBinOp>( exp->exp ) ) {
		// MEM( BINOP(PLUS,e1,CONST(i)), e2 )
		auto binOp = dynamic_cast<const CIRBinOp*>( exp->exp ) );
		if( (binOp->opId == EOperation::PLUS || binOp->opId == EOperation::MINUS) && 
			( IsInstanceOf<CIRConst>( binOp->left ) || IsInstanceOf<CIRConst>( binOp->right ) ) )
		{
			const IIRExp* binOpExpr;
			const CIRConst* constantExpr;
			if( IsInstanceOf<CIRConst>( binOp->left ) ) {
				binOpExpr = binOp->right;
				constantExpr = dynamic_cast<const CIRConst*>( binOp->left );
			} else {
				binOpExpr = binOp->left;
				constantExpr = dynamic_cast<const CIRConst*>( binOp->right );
			}
			emit( new Assembler::COper( std::string( "MEM 'd0, ['s0" ) +
				( ( binOp->opId == EOperation::PLUS ) ? "+" : "-" ) +
				std::to_string( constantExpr->value ) +
				std::string( "]\n" ),
				new Temp::CTempList( temp, nullptr ),
				new Temp::CTempList( munchExp( binOpExpr ), nullptr ) ) );
			return temp;
		}
	} 
	if( IsInstanceOf<CIRConst>( exp->exp ) ) {
		auto constantExpr = dynamic_cast<const CIRConst*>( exp->exp ) );
		emit( new Assembler::COper( std::string( "MEM 'd0, ['r0+" ) +
			std::to_string( constantExpr->value ) +
			std::string( "]\n" ),
			new Temp::CTempList( temp, nullptr ), 
			nullptr ) );
		return temp;
	} 
	emit( new Assembler::COper( "MEM 'd0, ['s0+0]\n",
		new Temp::CTempList( temp, nullptr ),
		new Temp::CTempList( munchExp( exp->exp ), nullptr ) ) );
	return temp;
}

static bool isArithmeticOperation( int op )
{
	return op == EOperation::PLUS || op == EOperation::MINUS || op == EOperation::MUL || op == EOperation::DIV;
}

const Temp::CTemp* CCodeGeneration::munchExp(const CIRBinOp* exp)
{
	const Temp::CTemp* temp( new Temp::CTemp );

	if( isArithmeticOperation( exp->opId ) ) {
		std::string oper;
		switch( exp->opId ) {
			case EOperation::PLUS: oper = "ADD"; break;
			case EOperation::MINUS: oper = "SUB"; break;
			case EOperation::MUL: oper = "MUL"; break;
			case EOperation::DIV: oper = "DIV"; break;
		}

		if( IsInstanceOf<CIRConst>( exp->left ) || IsInstanceOf<CIRConst>( exp->right ) ) {
			const IIRExp* binOpExpr;
			const CIRConst* constantExpr;
			if( IsInstanceOf<CIRConst>( exp->left ) ) {
				binOpExpr = exp->right;
				constantExpr = dynamic_cast<const CIRConst*>( exp->left );
			} else {
				binOpExpr = exp->left;
				constantExpr = dynamic_cast<const CIRConst*>( exp->right );
			}
			emit( new Assembler::COper( std::string( oper + " 'd0, 's0+" ) +
				std::to_string( constantExpr->value ) +
				std::string( "\n" ),
				new Temp::CTempList( temp, nullptr ),
				new Temp::CTempList( munchExp( binOpExpr ), nullptr ) ) );
		} else {
			emit( new Assembler::COper( oper + " 'd0, 's0+'s1\n",
				new Temp::CTempList( temp, nullptr ),
				new Temp::CTempList( munchExp( exp->left ),
				new Temp::CTempList( munchExp( exp->right ), nullptr ) ) ) );
		}
	} else {
		// TODO ���������� ��������
	}
	return temp;
}

const Temp::CTemp* CCodeGeneration::munchExp(const CIRConst* exp)
{
	const Temp::CTemp* temp( new Temp::CTemp );
	
	emit( new Assembler::COper( std::string( "ADD 'd0, r0+" ) +
		std::to_string( exp->value ) + std::string( "\n" ),
		nullptr, new Temp::CTempList( temp, nullptr ) ) );

	return temp;
}

const Temp::CTemp* CCodeGeneration::munchExp(const CIRTemp* exp)
{
	return exp->temp;
}

const Temp::CTemp* CCodeGeneration::munchExp(CIRName* exp)
{
	return new Temp::CTemp();
}

const Temp::CTemp* CCodeGeneration::munchExp(const CIRCall* exp)
{
	auto temporaries = munchArgs( exp->expList );
	emit( new Assembler::COper( "CALL 'l0\n", nullptr, nullptr, 
		new Temp::CLabelList( new Temp::CLabel( dynamic_cast<const CIRName*>(exp->exp)->label ), nullptr ) ) );

	return new const Temp::CTemp>();
}

const Temp::CTemp* CCodeGeneration::munchExp(const IIRExp* exp)
{
	if( IsInstanceOf<CIRMem>( exp ) ) {
		return munchExp( dynamic_cast<const CIRMem*>( exp ) );
	}
	if( IsInstanceOf<CIRBinOp>( exp ) ) {
		return munchExp( dynamic_cast<const CIRBinOp*>( exp ) );
	}
	if( IsInstanceOf<CIRConst>( exp ) ) {
		return munchExp( dynamic_cast<const CIRConst*>( exp ) );
	}
	if( IsInstanceOf<CIRTemp>( exp ) ) {
		return munchExp( dynamic_cast<const CIRTemp*>( exp ) );
	}
	if( IsInstanceOf<CIRName>( exp ) ) {
		return munchExp( dynamic_cast<const CIRName*>( exp ) );
	}
	if( IsInstanceOf<CIRCall>( exp ) ) {
		return munchExp( dynamic_cast<const CIRCall*>( exp ) );
	}
}

const Temp::CTempList* CCodeGeneration::munchArgs(const CIRExpList* args)
{
	if( args == nullptr ) {
		return nullptr;
	}
	const Temp::CTempList* temporariesList;
	while( args ) {
		const Temp::CTemp* temp( new Temp::CTemp() );
		emit( new Assembler::CMove( "MOV 'd0, 's0\n", temp, munchExp( args->GetHead() ) ) );

		temporariesList = new Temp::CTempList( temp, temporariesList );
		args = args->GetTail();
	}

	return temporariesList;
}