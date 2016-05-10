#pragma once

#include "IRTree.h"
#include "BasicBlock.h"
#include "Temp.h"
#include <vector>
#include <map>

class CBasicBlocksBuilder {
public:
	CBasicBlocksBuilder( const std::string& frameName );

	void BuildBlocks( const IIRStm* node );

	void SortBlocks();

	std::vector<CBasicBlock> GetBasicBlocks() const;

	std::vector<CBasicBlock> GetSortedBlocks() const;

private:
	std::vector<CBasicBlock> blocks;
	std::vector<CBasicBlock> sortedBlocks;
	std::map<const Temp::CLabel*, int> labelToBlock;
	const CIRLabel* firstLabel;
	std::string frameName;

	// Кончился фрейм -> помещаем джамп на метку done_label
	IIRStm* getDoneLabel() const;
	const CIRLabel* getLabel( int numBlock ) const;
	const Temp::CLabel* getNextLabel( const IIRStm* stm ) const;
	const Temp::CLabel* getNextConditionalLabel( const IIRStm* stm ) const;
	bool getNextFreeBlock( const std::vector<bool>& used, CBasicBlock& currBlock, int& position ) const;
};