#pragma once

#include "IRTree.h"

class CBasicBlock {
public:
	CBasicBlock();
	CBasicBlock( const std::list<const IIRStm*>& );
	~CBasicBlock();

	void Add( const IIRStm* stm );

private:
	std::list<const IIRStm*> statements;
};