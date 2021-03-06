﻿#include "CodeGeneration.h"
#include "EOperation.h"

template<class T, class S>
bool IsInstanceOf( S* exp )
{
	return dynamic_cast< T* >( exp ) == 0 ? false : true;
}

// todo: lol, smth strange here
void CCodeGeneration::SetFrame( const Frame::CFrame* currFrame )
{
	frame = currFrame;
	eaxTemp = new Temp::CTemp();
	edxTemp = new Temp::CTemp();
}

void CCodeGeneration::GenerateCode( const std::list<const IIRStm*>& statements, Assembler::CBaseInstructionList*& list )
{
	for( auto statement : statements ) {
		munchStm( statement );
	}
	list = instructList;
	// Чтобы не создавать несколько экземпляров этого класса
	instructList = last = nullptr;
}

void CCodeGeneration::GenerateCode( const std::list<const IIRStm*>& statements, std::list<const Assembler::CBaseInstruction*>& instructionList )
{
	Assembler::CBaseInstructionList* list;
	GenerateCode( statements, list );
	while( list != nullptr && list->head != nullptr ) {
		instructionList.push_back( list->head );
		list = list->tail;
	}
}

void CCodeGeneration::emit( Assembler::CBaseInstruction* instruct )
{
	if( last != nullptr ) {
		last = last->tail = new Assembler::CBaseInstructionList( instruct, nullptr );
	} else {
		last = instructList = new Assembler::CBaseInstructionList( instruct, nullptr );
	}
}

void CCodeGeneration::munchStm( const CIRSeq* stm )
{
	munchStm( stm->left );
	munchStm( stm->right );
}

void CCodeGeneration::munchStm(const CIRMove* stm)
{
	// MOVE( MEM(...) )
	if (IsInstanceOf<CIRMem>(const_cast< IIRExp* >(stm->dst))) {
		const CIRMem* destMem = dynamic_cast< const CIRMem* >(stm->dst);

		if (IsInstanceOf<CIRBinOp>(const_cast< IIRExp* >(destMem->exp))) {
			auto binOp = dynamic_cast< const CIRBinOp* >(destMem->exp);
			if (binOp->opId == EOperation::PLUS || binOp->opId == EOperation::MINUS) {
				// MOVE( MEM( BINOP(PLUS, e1, CONST(i)), e2 ) )
				if (IsInstanceOf<CIRConst>(const_cast< IIRExp* >(binOp->left)) || IsInstanceOf<CIRConst>(const_cast< IIRExp* >(binOp->right))) {
					const IIRExp* binOpExpr;
					const CIRConst* constantExpr;
					if (IsInstanceOf<CIRConst>(const_cast< IIRExp* >(binOp->left))) {
						binOpExpr = binOp->right;
						constantExpr = dynamic_cast< const CIRConst* >(binOp->left);
					}
					else {
						binOpExpr = binOp->left;
						constantExpr = dynamic_cast< const CIRConst* >(binOp->right);
					}
					const Temp::CTemp* sTemp = munchExp(stm->src);
					emit(new Assembler::COper(std::string("MOV [0] ") +
						((binOp->opId == EOperation::PLUS) ? "+ " : "-") +
						std::to_string(constantExpr->value) + std::string(", temp") +
						sTemp->Name() + std::string(" \n"),
						nullptr,
						new Temp::CTempList(munchExp(binOpExpr),
							new Temp::CTempList(sTemp, nullptr))));
				}
				else {
					// MOVE( MEM( BINOP( PLUS, e1, e2 ) ), e3 )
					const Temp::CTemp* destTemp = munchExp(binOp);
					const Temp::CTemp* srcTemp = munchExp(stm->src);
					emit(new Assembler::COper(std::string("MOV [temp") + destTemp->Name() + std::string("], temp") +
						srcTemp->Name() + std::string("\n"),
						new Temp::CTempList(destTemp, nullptr),
						new Temp::CTempList(srcTemp, nullptr)));
				}
			}
		}
		else if (IsInstanceOf<CIRConst>(const_cast< IIRExp* >(destMem->exp))) {
			// MOVE( MEM( CONST(i) ), e2 )
			const CIRConst* constantExpr = dynamic_cast< const CIRConst* >(destMem->exp);
			Temp::CTempList* srcTmpList = new Temp::CTempList(munchExp(stm->src), nullptr);
			emit(new Assembler::COper(std::string("MOV [") +
				std::to_string(constantExpr->value) +
				std::string("], temp" + srcTmpList->Head()->Name() + "\n"),
				nullptr,
				srcTmpList));
		}
		else if (IsInstanceOf<CIRTemp>(const_cast< IIRExp* >(destMem->exp))) {
			// MOVE( MEM( TEMP ), e2 )
			const Temp::CTemp* destTemp = munchExp(destMem->exp);
			const Temp::CTemp* srcTemp = munchExp(stm->src);
			emit(new Assembler::COper(std::string("MOV [temp") + destTemp->Name() + std::string("], temp") +
				srcTemp->Name() + std::string("\n"),
				new Temp::CTempList(destTemp, nullptr),
				new Temp::CTempList(srcTemp, nullptr)));
		}
		else if (IsInstanceOf<CIRMem>(const_cast< IIRExp* >(destMem->exp))) {
			if (IsInstanceOf<CIRMem>(const_cast< IIRExp* >(stm->src))) {
				// MOVE( MEM(e1), MEM(e2) )
				const Temp::CTemp* destTemp = munchExp(stm->dst);
				const Temp::CTemp* srcTemp = munchExp(stm->src);
				emit(new Assembler::COper(std::string("MOV [temp") + destTemp->Name() + std::string("], [temp") +
					srcTemp->Name() + std::string("] \n"),
					new Temp::CTempList(destTemp, nullptr),
					new Temp::CTempList(srcTemp, nullptr)));
			}
			else {
				// MOVE( MEM(e1), e2 )
				const Temp::CTemp* destTemp = munchExp(stm->dst);
				const Temp::CTemp* srcTemp = munchExp(stm->src);
				emit(new Assembler::COper(std::string("MOV [temp") + destTemp->Name() + std::string("], temp") +
					srcTemp->Name() + std::string(" \n"),
					new Temp::CTempList(destTemp, nullptr),
					new Temp::CTempList(srcTemp, nullptr)));
			}
		}
	}
	else if (IsInstanceOf<CIRTemp>(const_cast< IIRExp* >(stm->dst))) {
		// MOVE(TEMP(i), e2)
		const Temp::CTemp* destTemp = dynamic_cast< const CIRTemp* >(stm->dst)->temp;
		const Temp::CTemp* srcTemp = munchExp(stm->src);
		emit(new Assembler::COper("MOV temp" + destTemp->Name() + ", " + srcTemp->Name() + "\n",
			new Temp::CTempList(destTemp, nullptr),
			new Temp::CTempList(srcTemp, nullptr)));
	}
}

void CCodeGeneration::munchStm( const CIRLabel* stm )
{
	emit( new Assembler::CLabel( stm->label->Name() + std::string( ":\n" ), stm->label ) );
}

void CCodeGeneration::munchStm( const CIRExp* stm )
{
	munchExp( stm->exp );
}

void CCodeGeneration::munchStm( const CIRJump* stm )
{
	emit( new Assembler::COper( "JMP j" + stm->label->Name() + "\n", nullptr, nullptr, new Temp::CLabelList( stm->label, nullptr ) ) );
}

void CCodeGeneration::munchStm( const CIRCJump* stm )
{
	auto leftTemp = munchExp( stm->left );
	auto rightTemp = munchExp( stm->right );
	emit( new Assembler::COper( "CMP temp" + leftTemp->Name() + ", temp" + rightTemp->Name() 
		+ "\n", nullptr, new Temp::CTempList( leftTemp, new Temp::CTempList( rightTemp, nullptr ) ) ) );

	// TODO считаем, что CCondJump может идти только по < и >= (появляется в TraceSchedule)
	std::string oper;
	switch( stm->op ) {
		case EOperation::LE: oper = "JL"; break;
		case EOperation::GE: oper = "JGE"; break;
		case EOperation::NE: oper = "NE"; break;
		case EOperation::EQ: oper = "EQ"; break;
	}

	emit( new Assembler::COper( oper + " l" + stm->iftrue->label->Name() + "\n", nullptr, nullptr, new Temp::CLabelList( stm->iftrue->label, nullptr ) ) );
}

void CCodeGeneration::munchStm( const IIRStm* stm )
{
	if( IsInstanceOf<CIRSeq>( const_cast< IIRStm* >( stm ) ) ) {
		munchStm( dynamic_cast< const CIRSeq* >( stm ) );
	} else if( IsInstanceOf<CIRMove>( const_cast< IIRStm* >( stm ) ) ) {
		munchStm( dynamic_cast< const CIRMove* >( stm ) );
	} else if( IsInstanceOf<CIRLabel>( const_cast< IIRStm* >( stm ) ) ) {
		munchStm( dynamic_cast< const CIRLabel* >( stm ) );
	} else if( IsInstanceOf<CIRExp>( const_cast< IIRStm* >( stm ) ) ) {
		munchStm( dynamic_cast< const CIRExp* >( stm ) );
	} else if( IsInstanceOf<CIRJump>( const_cast< IIRStm* >( stm ) ) ) {
		munchStm( dynamic_cast< const CIRJump* >( stm ) );
	} else if( IsInstanceOf<CIRCJump>( const_cast< IIRStm* >( stm ) ) ) {
		munchStm( dynamic_cast< const CIRCJump* >( stm ) );
	}
}

const Temp::CTemp* CCodeGeneration::munchExp( const CIRMem* expr )
{
	auto temp = new Temp::CTemp();
	auto munchedTemp = munchExp(expr->exp);
	emit( new Assembler::CMove( "MOV temp" + temp->Name() + ", [temp" + munchedTemp->Name() + "]\n", temp, munchedTemp ) );
	return temp;
}

static bool isArithmeticOperation( int op )
{
	return op == EOperation::PLUS || op == EOperation::MINUS || op == EOperation::MUL || op == EOperation::DIV;
}

const Temp::CTemp* CCodeGeneration::munchExpJump( const CIRBinOp* binOp )
{
	auto temp = new Temp::CTemp();
	emit( new Assembler::COper( "MOV temp" + temp->Name() + ", 0\n", new Temp::CTempList( temp, nullptr ), nullptr ) );

	auto left = new Temp::CTemp();
	auto right = new Temp::CTemp();
	auto munchedLeft = munchExp(binOp->left);
	auto munchedRight = munchExp(binOp->right);
	emit( new Assembler::CMove( "MOV temp" + left->Name() + ", temp" + munchedLeft->Name() + "\n", left, munchedLeft ) );
	emit( new Assembler::CMove( "MOV temp" + right->Name() + ", temp" + munchedRight->Name() + "\n", right, munchedRight ) );

	auto source = new Temp::CTempList( left, new Temp::CTempList( right, nullptr ) );

	emit( new Assembler::COper( "CMP 0, temp" + source->Head()->Name() + "\n", nullptr, source ) );

	auto label = new Temp::CLabel();

	emit( new Assembler::COper( "JNL l" + label->Name() + "\n", nullptr, nullptr, new Temp::CLabelList( label, nullptr ) ) );
	emit( new Assembler::COper( "MOV temp" + temp->Name() + ", 1\n", new Temp::CTempList( temp, nullptr ), nullptr ) );
	emit( new Assembler::CLabel( label->Name() + ":\n", label ) );

	return temp;
}

const Temp::CTemp* CCodeGeneration::munchExp( const CIRBinOp* binOp )
{
	if( binOp->opId == EOperation::LT || binOp->opId == EOperation::GE ) {
		return munchExpJump( binOp );
	}
	
	if( IsInstanceOf<CIRConst>( const_cast< IIRExp* >( binOp->left ) ) && IsInstanceOf<CIRConst>( const_cast<IIRExp*>( binOp->right ) ) ) {
		// const-const
		int leftVal = dynamic_cast< const CIRConst* >( binOp->left )->value;
		int rightVal = dynamic_cast< const CIRConst* >( binOp->right )->value;
		auto temp = new Temp::CTemp();
		emit( new Assembler::CMove( "MOV temp" + eaxTemp->Name() + ", " + std::to_string( leftVal ) + "\n", eaxTemp, nullptr ) );
		if( binOp->opId == EOperation::MUL ) {
			emit( new Assembler::CMove( "MOV temp" + edxTemp->Name() + ", 0\n", edxTemp, nullptr ) );
		}
		if( binOp->opId == EOperation::PLUS ) {
			emit( new Assembler::COper( "ADD temp" + eaxTemp->Name() + ", " + std::to_string( rightVal ) + "\n",
										new Temp::CTempList(eaxTemp, nullptr ),
										nullptr ) );
		} else if( binOp->opId == EOperation::MINUS ) {
			emit( new Assembler::COper( "SUB temp" + eaxTemp->Name() + ", " + std::to_string( rightVal ) + "\n",
										new Temp::CTempList(eaxTemp, nullptr ),
										nullptr ) );
		} else if( binOp->opId == EOperation::MUL ) {
			emit( new Assembler::COper( "MUL temp" + edxTemp->Name() + ", " + std::to_string( rightVal ) + "\n",
										new Temp::CTempList(eaxTemp, new Temp::CTempList( edxTemp, nullptr ) ),
										nullptr ) );
		}
		emit( new Assembler::CMove( "MOV temp" + temp->Name() + ", temp" + eaxTemp->Name() + "\n\n", temp, eaxTemp) );
		return temp;
	}
	if( IsInstanceOf<CIRConst>( const_cast<IIRExp*>( binOp->left ) ) ) {
		// const-expr
		int leftVal = dynamic_cast< const CIRConst* >( binOp->left )->value;
		auto temp = new Temp::CTemp();
		auto rightTemp = munchExp( binOp->right );
		emit( new Assembler::CMove( "MOV temp" + eaxTemp->Name() + ", " + std::to_string( leftVal ) + "\n", eaxTemp, nullptr ) );
		emit( new Assembler::CMove( "MOV temp" + temp->Name() + ", temp" + rightTemp->Name() + "\n", temp, rightTemp ) );
		if( binOp->opId == EOperation::MUL ) {
			emit( new Assembler::CMove( "MOV temp" + edxTemp->Name() + ", 0\n", edxTemp, nullptr ) );
		}
		Temp::CTempList* usedRegisters = nullptr;
		if( binOp->opId == EOperation::PLUS ) {
			usedRegisters = new Temp::CTempList( eaxTemp, nullptr );
			emit( new Assembler::COper( "ADD temp" + usedRegisters->Head()->Name() + ", temp" + temp->Name() + "\n", usedRegisters,
										new Temp::CTempList( temp, nullptr ) ) );
		} else if( binOp->opId == EOperation::MINUS ) {
			usedRegisters = new Temp::CTempList(eaxTemp, nullptr );
			emit( new Assembler::COper( "SUB temp" + usedRegisters->Head()->Name() + ", temp" + temp-> Name() + "\n", usedRegisters,
										new Temp::CTempList( temp, nullptr ) ) );
		} else if( binOp->opId == EOperation::MUL ) {
			usedRegisters = new Temp::CTempList(eaxTemp, new Temp::CTempList(edxTemp, nullptr ) );
			emit( new Assembler::COper( "MUL temp" + usedRegisters->Head()->Name() + ", temp" + temp->Name() + "\n", usedRegisters,
										new Temp::CTempList( temp, nullptr ) ) );
		}
		auto temp2 = new Temp::CTemp();
		emit( new Assembler::CMove( "MOV temp" + temp2->Name() + ", temp" + usedRegisters->Head()->Name() + "\n\n", temp2, usedRegisters->Head() ) );
		return temp2;
	}
	if( IsInstanceOf<CIRConst>( const_cast<IIRExp*>( binOp->right )) ) {
		// expr-const
		int rightVal = dynamic_cast< const CIRConst* >( binOp->right )->value;
		auto leftTemp = munchExp( binOp->left );
		auto temp = new Temp::CTemp();
		emit( new Assembler::CMove( "MOV temp" + eaxTemp->Name() + ", temp" + leftTemp->Name() + "\n", eaxTemp, leftTemp ) );
		if( binOp->opId == EOperation::MUL ) {
			emit( new Assembler::CMove( "MOV temp" + edxTemp->Name() + ", 0\n", edxTemp, nullptr ) );
		}
		Temp::CTempList* usedRegisters = nullptr;
		if( binOp->opId == EOperation::PLUS ) {
			usedRegisters = new Temp::CTempList(eaxTemp, nullptr );
			emit( new Assembler::COper( "ADD temp" + usedRegisters->Head()->Name() + ", " + std::to_string( rightVal ) + "\n", usedRegisters,
										nullptr ) );
		} else if( binOp->opId == EOperation::MINUS ) {
			usedRegisters = new Temp::CTempList(eaxTemp, nullptr );
			emit( new Assembler::COper( "SUB temp" + usedRegisters->Head()->Name()+ ", " + std::to_string( rightVal ) + "\n", usedRegisters,
										nullptr ) );
		} else if( binOp->opId == EOperation::MUL ) {
			usedRegisters = new Temp::CTempList(eaxTemp, new Temp::CTempList(edxTemp, nullptr ) );
			emit( new Assembler::COper( "MUL temp" + usedRegisters->Head()->Name() + ", " + std::to_string( rightVal ) + "\n", usedRegisters,
										nullptr ) );
		}
		emit( new Assembler::CMove( "MOV temp" + temp->Name() + ", temp" + usedRegisters->Head()->Name() + "\n\n", temp, usedRegisters->Head() ) );
		return temp;
	}
	// expr-expr
	auto temp1 = new Temp::CTemp();
	auto temp2 = new Temp::CTemp();
	auto leftTemp = munchExp( binOp->left );
	auto rightTemp = munchExp( binOp->right );
	emit( new Assembler::CMove( "MOV temp" + eaxTemp->Name() + ", temp" + leftTemp->Name() + "\n", eaxTemp, leftTemp ) );
	emit( new Assembler::CMove( "MOV temp" + temp2->Name() + ", temp" + rightTemp->Name() + "\n", temp2, rightTemp ) );
	if( binOp->opId == EOperation::MUL ) {
		emit( new Assembler::CMove( "MOV temp" + edxTemp->Name() + ", 0\n", edxTemp, nullptr ) );
	}
	Temp::CTempList* usedRegisters = nullptr;
	if( binOp->opId == EOperation::PLUS ) {
		usedRegisters = new Temp::CTempList(eaxTemp, nullptr );
		emit( new Assembler::COper( "ADD temp" + usedRegisters->Head()->Name() + ", temp" + temp2->Name() + "\n", usedRegisters,
									new Temp::CTempList( temp2, nullptr ) ) );
	} else if( binOp->opId == EOperation::MINUS ) {
		usedRegisters = new Temp::CTempList(eaxTemp, nullptr );
		emit( new Assembler::COper( "SUB temp" + usedRegisters->Head()->Name() + ", temp" + temp2->Name() + "\n", usedRegisters,
									new Temp::CTempList( temp2, nullptr ) ) );
	} else if( binOp->opId == EOperation::MUL ) {
		usedRegisters = new Temp::CTempList(eaxTemp, new Temp::CTempList(edxTemp, nullptr ) );
		emit( new Assembler::COper( "MUL temp" + usedRegisters->Head()->Name() + ", temp" + temp2->Name() + "\n", usedRegisters,
									new Temp::CTempList( temp2, nullptr ) ) );
	}
	emit( new Assembler::CMove( "MOV temp" + temp1->Name() + ", temp" + usedRegisters->Head()->Name() + "\n\n", temp1, usedRegisters->Head() ) );
	return temp1;
}

const Temp::CTemp* CCodeGeneration::munchExp( const CIRConst* exp )
{
	const Temp::CTemp* temp( new Temp::CTemp );

	emit( new Assembler::COper( std::string( "MOV temp" + temp->Name() + ", " ) +
								std::to_string( exp->value ) + std::string( "\n" ),
								nullptr, new Temp::CTempList( temp, nullptr ) ) );

	return temp;
}

const Temp::CTemp* CCodeGeneration::munchExp( const CIRTemp* exp )
{
	return exp->temp;
}

const Temp::CTemp* CCodeGeneration::munchExp( const CIRName* exp )
{
	return new Temp::CTemp();
}

const Temp::CTemp* CCodeGeneration::munchExp( const CIRCall* exp )
{
	auto temporaries = munchArgs( exp->expList );
	// todo: only for debug
	std::string funcName = dynamic_cast< const CIRName* >( exp->exp )->label->Name();
	emit( new Assembler::COper( "CALL l0 from " + funcName + "\n", nullptr, nullptr,
								new Temp::CLabelList( dynamic_cast< const CIRName* >( exp->exp )->label, nullptr ) ) );

	return new Temp::CTemp();
}

const Temp::CTemp* CCodeGeneration::munchExp( const IIRExp* exp )
{
	if( IsInstanceOf<CIRMem>( const_cast< IIRExp* >( exp ) ) ) {
		return munchExp( dynamic_cast< const CIRMem* >( exp ) );
	}
	if( IsInstanceOf<CIRBinOp>( const_cast< IIRExp* >( exp ) ) ) {
		return munchExp( dynamic_cast< const CIRBinOp* >( exp ) );
	}
	if( IsInstanceOf<CIRConst>( const_cast< IIRExp* >( exp ) ) ) {
		return munchExp( dynamic_cast< const CIRConst* >( exp ) );
	}
	if( IsInstanceOf<CIRTemp>( const_cast< IIRExp* >( exp ) ) ) {
		return munchExp( dynamic_cast< const CIRTemp* >( exp ) );
	}
	if( IsInstanceOf<CIRName>( const_cast< IIRExp* >( exp ) ) ) {
		return munchExp( dynamic_cast< const CIRName* >( exp ) );
	}
	if( IsInstanceOf<CIRCall>( const_cast< IIRExp* >( exp ) ) ) {
		return munchExp( dynamic_cast< const CIRCall* >( exp ) );
	}
	// Для прогера
	assert( false );
	// Для компилятора
	return nullptr;
}

const Temp::CTempList* CCodeGeneration::munchArgs( const CIRExpList* args )
{
	if( args->expList.size() == 0 ) {
		return nullptr;
	}

	const Temp::CTempList* temporariesList = nullptr;

	for( size_t i = 0; i < args->expList.size(); ++i ) {
		const Temp::CTemp* temp( new Temp::CTemp() );
		auto munchedTemp = munchExp(args->expList[i]);
		emit( new Assembler::CMove( "put_in_args temp" + temp->Name() + ", temp" + munchedTemp->Name() + "\n", temp, munchedTemp ) );

		temporariesList = new Temp::CTempList( temp, temporariesList );
	}

	return temporariesList;
}
