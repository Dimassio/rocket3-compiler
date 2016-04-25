#pragma once

#include "IRTree.h"
#include "IIRTreeVisitor.h"
#include "BasicBlock.h"
#include <vector>

class CBasicBlocksBuilder: public IIRTreeVisitor {
public:
	CBasicBlocksBuilder();

	void visit( const CIRMove* node );

	void visit( const CIRExp* node );

	void visit( const CIRJump* node );

	void visit( const CIRCJump* node );

	void visit( const CIRSeq* node );

	void visit( const CIRConst* node );

	void visit( const CIRName* node );

	void visit( const CIRTemp* node );

	void visit( const CIRBinOp* node );

	void visit( const CIRMem* node );

	void visit( const CIRCall* node );

	void visit( const CIRESeq* node );

	void visit( const CIRExpList* node );

	void visit( const CIRLabel* node );

	std::vector<CBasicBlock> GetBasicBlocks() const;

	// Нужно вызывать каждый раз, после составления блоков по функции
	void PutDoneLabel();

private:
	CBasicBlock* currBlock;
	std::vector<CBasicBlock> blocks;
	size_t numCurrBlock;

	// Добавляем Stm. Если до этого блок не был начат, то начинаем его меткой 
	// вида <номер_блока label>. И добавляем туда Stm. 
	void addStm( const IIRStm* stm );
	// Добавляем блок в массив и обнуляем текущий.
	void finishBlock();
};