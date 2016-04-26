#include "BasicBlocksBuilder.h"
#include "CStm.h"
#include "CExp.h"
#include <string>

CBasicBlocksBuilder::CBasicBlocksBuilder()
{
	firstLabel = nullptr;
}

std::vector<CBasicBlock> CBasicBlocksBuilder::GetBasicBlocks() const
{
	return blocks;
}

template<class T, class S>
bool IsInstanceOf( S* exp )
{
	return dynamic_cast< T* >( exp ) == 0 ? false : true;
}

void CBasicBlocksBuilder::BuildBlocks( const IIRStm* node )
{
	const CIRSeq* currStm = dynamic_cast< const CIRSeq* >( node );
	int numCurrBlock = -1;
	while( currStm != nullptr ) {
		// Начинаем новый блок
		blocks.push_back( CBasicBlock() );
		numCurrBlock = blocks.size() - 1;
		// Block -> Position
		blockToPosition[blocks.back()] = numCurrBlock;
		if( IsInstanceOf<CIRLabel>( const_cast< IIRStm* >( currStm->left ) ) ) {
			blocks[numCurrBlock].Add( dynamic_cast< const CIRLabel* >( currStm->left ) );
			// Label -> Block
			labelToBlock[getLabel( numCurrBlock )->label] = blocks[numCurrBlock];
		} else {
			blocks[numCurrBlock].Add( new CIRLabel( new Temp::CLabel( new Symbols::CSymbol( std::to_string( blocks.size() ) + " block_label" ) ) ) );
			// Label -> Block
			labelToBlock[getLabel( numCurrBlock )->label] = blocks[numCurrBlock];
			blocks[numCurrBlock].Add( currStm->left );
		}
		if( firstLabel == nullptr ) {
			firstLabel = dynamic_cast< const CIRLabel* >( blocks[numCurrBlock].First() );
		}
		bool endOfBlock = false;
		currStm = dynamic_cast< const CIRSeq* >( currStm->right );
		while( !endOfBlock ) {
			if( currStm != nullptr && ( IsInstanceOf<CIRJump>( const_cast< IIRStm* >( currStm->left ) ) || IsInstanceOf<CIRCJump>( const_cast< IIRStm* >( currStm->left ) ) ) ) {
				blocks[numCurrBlock].Add( currStm->left );
				endOfBlock = true;
				currStm = dynamic_cast< const CIRSeq* >( currStm->right );
			} else if( currStm != nullptr && IsInstanceOf<CIRLabel>( const_cast< IIRStm* >( currStm->left ) ) ) {
				// Заканчиваем "силой" блок, и ставим Джам на начало следующего
				blocks[numCurrBlock].Add( new CIRJump( dynamic_cast< const CIRLabel* >( currStm->left )->label ) );
				endOfBlock = true;
			} else if( currStm == nullptr || currStm->left == nullptr ) {
				// Дерево закончилось
				blocks[numCurrBlock].Add( putDoneLabel() );
				endOfBlock = true;
			} else {
				blocks[numCurrBlock].Add( currStm->left );
				endOfBlock = false;
				currStm = dynamic_cast< const CIRSeq* >( currStm->right );
			}
		}
	}
}

void CBasicBlocksBuilder::SortBlocks()
{
	assert( blocks.size() > 0 );
	std::vector<CBasicBlock> sortedBlocks;
	std::vector<bool> used( blocks.size(), false );
	CBasicBlock currBlock = labelToBlock[firstLabel->label];
	int position = blockToPosition[currBlock];
	used[position] = true;
	const IIRStm* jump = currBlock.Last();
	while( true ) {
		if( IsInstanceOf<CIRJump>( const_cast< IIRStm* >( jump ) ) ) {
			sortedBlocks.push_back( currBlock );
			// todo:Temp::CLabel to = dynamic_cast< CIRJump* >( jump );

		}
	}
}

IIRStm* CBasicBlocksBuilder::putDoneLabel()
{
	return new CIRJump( new Temp::CLabel( new Symbols::CSymbol( "done" ) ) );
}

const CIRLabel* CBasicBlocksBuilder::getLabel( int numBlock )
{
	return dynamic_cast< const CIRLabel* >( blocks[numBlock].First() );
}
