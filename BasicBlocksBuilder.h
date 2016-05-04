#pragma once

#include "IRTree.h"
#include "BasicBlock.h"
#include "Temp.h"
#include <vector>
#include <map>

class CBasicBlocksBuilder {
public:
	CBasicBlocksBuilder();

	void BuildBlocks( const IIRStm* node );

	void SortBlocks();

	std::vector<CBasicBlock> GetBasicBlocks() const;

	std::vector<CBasicBlock> GetSortedBlocks() const;

private:
	std::vector<CBasicBlock> blocks;
	std::vector<CBasicBlock> sortedBlocks;
	std::map<const Temp::CLabel*, int> labelToBlock;
	// � �������� ������ ������, ����� L ����� ����������� ������ � 1 �����
	//std::map<const Temp::CLabel*, int> blockToPosition;
	const CIRLabel* firstLabel;

	// �������� ����� -> �������� ����� �� ����� DONE
	IIRStm* getDoneLabel() const;
	const CIRLabel* getLabel( int numBlock ) const;
	const Temp::CLabel* getNextLabel( const IIRStm* stm ) const;
	const Temp::CLabel* getNextConditionalLabel( const IIRStm* stm ) const;
};