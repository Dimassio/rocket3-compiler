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

private:
	std::vector<CBasicBlock> blocks;
	std::map<const Temp::CLabel*, CBasicBlock> labelToBlock;
	std::map<CBasicBlock, int> blockToPosition;
	const CIRLabel* firstLabel;

	// Кончился фрейм -> помещаем джамп на метку DONE
	IIRStm* putDoneLabel();
	const CIRLabel* getLabel( int numBlock );
};