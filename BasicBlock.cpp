#include "BasicBlock.h"

CBasicBlock::CBasicBlock()
{
}

CBasicBlock::CBasicBlock( const std::list<IIRStm*>& _stms ):
	statements( _stms )
{
}

CBasicBlock::~CBasicBlock()
{
}

void CBasicBlock::Add( IIRStm* stm )
{
	statements.push_back( stm );
}
