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
		if( IsInstanceOf<CIRLabel>( const_cast< IIRStm* >( currStm->left ) ) ) {
			blocks[numCurrBlock].Add( dynamic_cast< const CIRLabel* >( currStm->left ) );
			// Label -> Block
			labelToBlock[getLabel( numCurrBlock )->label] = numCurrBlock;
			currStm = dynamic_cast< const CIRSeq* >( currStm->right );
		} else {
			blocks[numCurrBlock].Add( new CIRLabel( new Temp::CLabel( new Symbols::CSymbol( std::to_string( blocks.size() ) + " block_label" ) ) ) );
			// Label -> Block
			labelToBlock[getLabel( numCurrBlock )->label] = numCurrBlock;
		}
		if( firstLabel == nullptr ) {
			// чтобы знать с какого блока начинать
			firstLabel = dynamic_cast< const CIRLabel* >( blocks[numCurrBlock].First() );
		}
		bool endOfBlock = false;
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
				blocks[numCurrBlock].Add( getDoneLabel() );
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
	std::vector<bool> used( blocks.size(), false );
	CBasicBlock currBlock = blocks[labelToBlock[firstLabel->label]];
	used[labelToBlock[firstLabel->label]] = true;
	sortedBlocks.push_back( currBlock );
	const IIRStm* jump = currBlock.Last();
	size_t numOfFreeBlocks = used.size() - 1;
	while( numOfFreeBlocks > 0 ) {
		if( IsInstanceOf<CIRJump>( const_cast< IIRStm* >( jump ) ) ) {
			// За ним просто должен идти блок с меткой, куда прыгаем
			const Temp::CLabel* nextLabel = getNextLabel( jump );
			if( nextLabel->Name() == "done_label" || used[labelToBlock[nextLabel]] ) {
				// Если блок конца фрейма, или же след ведет в посещенный блок
				// Значит нужно взять непосещенный и с ним строить след
				int position = 0;
				if( getNextFreeBlock( used, currBlock, position ) ) {
					sortedBlocks.push_back( currBlock );
					used[position] = true;
					--numOfFreeBlocks;
					jump = currBlock.Last();
					continue;
				} else {
					// Свободных блоков не осталось
					break;
				}
			}
			currBlock = blocks[labelToBlock[nextLabel]];
			sortedBlocks.push_back( currBlock );
			used[labelToBlock[nextLabel]] = true;
			--numOfFreeBlocks;
		} else if( IsInstanceOf<CIRCJump>( const_cast< IIRStm* >( jump ) ) ) {
			// За ним должен идти блок с меткой на false
			const Temp::CLabel* nextLabel = getNextConditionalLabel( jump );
			if( nextLabel->Name() == "done_label" || used[labelToBlock[nextLabel]] ) {
				int position = 0;
				if( getNextFreeBlock( used, currBlock, position ) ) {
					sortedBlocks.push_back( currBlock );
					used[position] = true;
					--numOfFreeBlocks;
					jump = currBlock.Last();
					continue;
				} else {
					// Свободных блоков не осталось
					break;
				}
			}
			currBlock = blocks[labelToBlock[nextLabel]];
			sortedBlocks.push_back( currBlock );
			used[labelToBlock[nextLabel]] = true;
			--numOfFreeBlocks;
		} else {
			assert( false );
		}
		jump = currBlock.Last();
	}
}

bool CBasicBlocksBuilder::getNextFreeBlock( const std::vector<bool>& used, CBasicBlock& currBlock, int& position ) const
{
	for( size_t i = 0; i < used.size(); ++i ) {
		if( !used[i] ) {
			currBlock = blocks[i];
			position = i;
			return true;
		}
	}
	return false;
}

const Temp::CLabel* CBasicBlocksBuilder::getNextLabel( const IIRStm* stm ) const
{
	const CIRJump* jump = dynamic_cast< const CIRJump* >( stm );
	return jump->label;
}

const Temp::CLabel* CBasicBlocksBuilder::getNextConditionalLabel( const IIRStm* stm ) const
{
	const CIRCJump* jump = dynamic_cast< const CIRCJump* >( stm );
	return jump->iffalse->label;
}

IIRStm* CBasicBlocksBuilder::getDoneLabel() const
{
	return new CIRJump( new Temp::CLabel( new Symbols::CSymbol( "done_label" ) ) );
}

const CIRLabel* CBasicBlocksBuilder::getLabel( int numBlock ) const
{
	return dynamic_cast< const CIRLabel* >( blocks[numBlock].First() );
}

std::vector<CBasicBlock> CBasicBlocksBuilder::GetSortedBlocks() const
{
	return sortedBlocks;
}