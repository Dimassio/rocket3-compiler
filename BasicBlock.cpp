#include "BasicBlock.h"

CBasicBlock::CBasicBlock()
{
}

CBasicBlock::CBasicBlock( const std::list<const IIRStm*>& _stms ):
	statements( _stms )
{
}

CBasicBlock::~CBasicBlock()
{
}

void CBasicBlock::Add( const IIRStm* stm )
{
	statements.push_back( stm );
}

const IIRStm* CBasicBlock::First() const
{
	return statements.front();
}

const IIRStm* CBasicBlock::Last() const
{
	return statements.back();
}

const std::list<const IIRStm*> CBasicBlock::GetStatements() const
{
	return statements;
}
