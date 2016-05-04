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
		// �������� ����� ����
		blocks.push_back( CBasicBlock() );
		numCurrBlock = blocks.size() - 1;
		// Block -> Position
		//blockToPosition[blocks.back()] = numCurrBlock;
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
			// ����� ����� � ������ ����� ��������
			firstLabel = dynamic_cast< const CIRLabel* >( blocks[numCurrBlock].First() );
		}
		bool endOfBlock = false;
		while( !endOfBlock ) {
			if( currStm != nullptr && ( IsInstanceOf<CIRJump>( const_cast< IIRStm* >( currStm->left ) ) || IsInstanceOf<CIRCJump>( const_cast< IIRStm* >( currStm->left ) ) ) ) {
				blocks[numCurrBlock].Add( currStm->left );
				endOfBlock = true;
				currStm = dynamic_cast< const CIRSeq* >( currStm->right );
			} else if( currStm != nullptr && IsInstanceOf<CIRLabel>( const_cast< IIRStm* >( currStm->left ) ) ) {
				// ����������� "�����" ����, � ������ ���� �� ������ ����������
				blocks[numCurrBlock].Add( new CIRJump( dynamic_cast< const CIRLabel* >( currStm->left )->label ) );
				endOfBlock = true;
			} else if( currStm == nullptr || currStm->left == nullptr ) {
				// ������ �����������
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
	std::vector<CBasicBlock> sortedBlocks;
	/*// 1 label L in 1 block
	// 1 jump to label L may be in N blocks*/
	// TODO: � ���� ������������� ����� ����� ����� ysed?
	//std::vector<bool> used( blocks.size(), false );
	CBasicBlock currBlock = blocks[labelToBlock[firstLabel->label]];
	sortedBlocks.push_back( currBlock );
	//used[position] = true;
	const IIRStm* jump = currBlock.Last();
	while( true ) {
		if( IsInstanceOf<CIRJump>( const_cast< IIRStm* >( jump ) ) ) {
			// �� ��� ������ ������ ���� ���� � ������, ���� �������
			const Temp::CLabel* nextLabel = getNextLabel( jump );
			if( nextLabel->Name() == "done_label" ) {
				break;
			}
			currBlock = blocks[labelToBlock[nextLabel]];
			sortedBlocks.push_back( currBlock );
		} else if( IsInstanceOf<CIRCJump>( const_cast< IIRStm* >( jump ) ) ) {
			// �� ��� ������ ���� ���� � ��������� ������ �� false
			const Temp::CLabel* nextLabel = getNextConditionalLabel( jump );
			if( nextLabel->Name() == "done_label" ) {
				break;
			}
			currBlock = blocks[labelToBlock[nextLabel]];
			sortedBlocks.push_back( currBlock );
		} else {
			assert( false );
		}
		jump = currBlock.Last();
	}
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