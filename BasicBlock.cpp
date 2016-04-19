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
