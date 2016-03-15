#include <cassert>
#include "Translate.h"
#include "CStm.h"
#include "CExp.h"

using namespace Translate;

CExpConverter::CExpConverter( const IIRExp* _exp )
	: exp( _exp )
{
}

CExpConverter::~CExpConverter()
{
}

const IIRExp* CExpConverter::ToExp() const
{
	return exp;
}

const IIRStm* CExpConverter::ToStm() const
{
	return new CIRExp( exp );
}

const IIRStm* CExpConverter::ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const
{
	return new CIRCJump( NE, exp, new CIRConst( 0 ), new CIRLabel(trueLable), new CIRLabel(falseLable) );
}

CStmConverter::CStmConverter( const IIRStm * _stm ):
	stm( _stm )
{
}

CStmConverter::~CStmConverter()
{
}

const IIRExp* CStmConverter::ToExp() const
{
	// Кажется, можно обойтись и без этого
	assert( false );
	return nullptr;
}

const IIRStm* CStmConverter::ToStm() const
{
	return stm;
}

const IIRStm* CStmConverter::ToConditional( const Temp::CLabel* trueLable, const Temp::CLabel* falseLable ) const
{
	assert( false );
	return nullptr;
}