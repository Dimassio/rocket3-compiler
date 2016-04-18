#include "BasicBlocksBuilder.h"
#include "CStm.h"
#include "CExp.h"
#include <string>

// todo: when in exp, we mush finish block, or what?

CBasicBlocksBuilder::CBasicBlocksBuilder()
{
	currBlock = nullptr;
}

std::vector<CBasicBlock> CBasicBlocksBuilder::GetBasicBlocks() const
{
	return blocks;
}

void CBasicBlocksBuilder::PutDoneLabel()
{
	blocks.back().Add( new CIRLabel( new Temp::CLabel( new Symbols::CSymbol( "done" ) ) ) );
}

void CBasicBlocksBuilder::addStm( const IIRStm* stm )
{
	if( currBlock == nullptr ) {
		currBlock = new CBasicBlock();
		// Создаем метку вида: <номер_блока label>
		currBlock->Add( new CIRLabel( new Temp::CLabel( new Symbols::CSymbol( std::to_string( blocks.size() ) + " label" ) ) ) );
	}
	currBlock->Add( stm );
}

void CBasicBlocksBuilder::finishBlock()
{
	if( currBlock != nullptr ) {
		blocks.push_back( *currBlock );
		delete currBlock;
	}
}

template<class T, class S>
bool IsInstanceOf( S* exp )
{
	return dynamic_cast< T* >( exp ) == 0 ? false : true;
}

void CBasicBlocksBuilder::visit( const CIRMove* node )
{
	addStm( node );
	node->dst->Accept( this );
	node->src->Accept( this );
}

void CBasicBlocksBuilder::visit( const CIRExp* node )
{
	addStm( node );
	node->exp->Accept( this );
}

void CBasicBlocksBuilder::visit( const CIRJump* node )
{
	addStm( node );
	finishBlock();
}

void CBasicBlocksBuilder::visit( const CIRCJump* node )
{
	addStm( node );
	finishBlock();

	node->right->Accept( this );
	node->left->Accept( this );
}

void CBasicBlocksBuilder::visit( const CIRSeq* node )
{
	addStm( node );
	if( node->left != nullptr ) {
		node->left->Accept( this );
	}
	if( node->right != nullptr ) {
		node->right->Accept( this );
	}
}

void CBasicBlocksBuilder::visit( const CIRConst* node )
{
	finishBlock();
}

void CBasicBlocksBuilder::visit( const CIRName* node )
{
	finishBlock();
}

void CBasicBlocksBuilder::visit( const CIRTemp* node )
{
	finishBlock();
}

void CBasicBlocksBuilder::visit( const CIRBinOp* node )
{
	finishBlock();
	node->left->Accept( this );
	node->right->Accept( this );
}

void CBasicBlocksBuilder::visit( const CIRMem* node )
{
	finishBlock();
	node->exp->Accept( this );
}

void CBasicBlocksBuilder::visit( const CIRCall* node )
{
	finishBlock();
	node->exp->Accept( this );
	node->expList->Accept( this );
}

void CBasicBlocksBuilder::visit( const CIRESeq* node )
{
	// Ничего не делаем, так как это корень
	if( node->stm != nullptr ) {
		node->stm->Accept( this );
	}
	if( node->exp != nullptr ) {
		node->exp->Accept( this );
	}
}

void CBasicBlocksBuilder::visit( const CIRExpList* node )
{
	finishBlock();
	for( auto exp : node->expList ) {
		exp->Accept( this );
	}
}

void CBasicBlocksBuilder::visit( const CIRLabel* node )
{
	// Нужно прерывать идущий блок, создание нового джампа на эту метку
	if( currBlock != nullptr ) {
		currBlock->Add( new CIRJump( node->label ) );
		finishBlock();
	}
	currBlock = new CBasicBlock();
	currBlock->Add( node );
}
