#include <cassert>
#include "Translate.h"
#include "CStm.h"

using namespace Translate;

CExpConverter::CExpConverter( const IRTree::IIRExp* _exp )
	: exp( _exp )
{
}

CExpConverter::~CExpConverter()
{
}

const IRTree::IIRExp* CExpConverter::ToExp() const
{
	return exp;
}

const IRTree::IIRStm* CExpConverter::ToStm() const
{
	return new CIRExp( exp );
}

const IRTree::IIRStm* CExpConverter::ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const
{
	// todo
	assert( false );
	return nullptr;
}

CStmConverter::CStmConverter( const IRTree::IIRStm * _stm ):
	stm( _stm )
{
}

CStmConverter::~CStmConverter()
{
}

const IRTree::IIRExp* CStmConverter::ToExp() const
{
	// Кажется, можно обойтись и без этого
	assert( false );
	return nullptr;
}

const IRTree::IIRStm* CStmConverter::ToStm() const
{
	return stm;
}

const IRTree::IIRStm* CStmConverter::ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const
{
	// todo
	assert( false );
	return nullptr;
}
