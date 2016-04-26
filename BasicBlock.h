#pragma once

#include "IRTree.h"

class CBasicBlock {
public:
	CBasicBlock();
	CBasicBlock( const std::list<const IIRStm*>& );
	~CBasicBlock();

	bool operator<( const CBasicBlock& other ) const;

	void Add( const IIRStm* stm );
	const IIRStm* First() const;
	const IIRStm* Last() const;

private:
	std::list<const IIRStm*> statements;
};