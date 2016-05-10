#pragma once

#include "IRTree.h"
#include <list>

class CBasicBlock {
public:
	CBasicBlock();
	CBasicBlock( const std::list<const IIRStm*>& );
	~CBasicBlock();

	void Add( const IIRStm* stm );
	const IIRStm* First() const;
	const IIRStm* Last() const;

	const std::list<const IIRStm*> GetStatements() const;

private:
	std::list<const IIRStm*> statements;
};