#include "CStm.h"
#include "IRTree.h"

using namespace IRTree;

CIRMove::CIRMove( const IIRExp* _dst, const IIRExp* _src ):
	dst( _dst ), src( _src )
{
}

CIRMove::~CIRMove()
{
}

CIRExp::CIRExp( const IIRExp* _exp ):
	exp( _exp )
{
}

CIRExp::~CIRExp()
{
}

CIRJump::CIRJump( const Temp::CLabel* _target ):
	target( _target )
{
}

CIRJump::~CIRJump()
{
}

CIRCJump::CIRCJump( const EOperation _op, const IIRExp* _left, const IIRExp* _right, const CIRLabel* _iftrue, const CIRLabel* _iffalse ):
	op( _op ), left( _left ), right( _right ), iftrue( _iftrue ), iffalse( _iffalse )
{
}

CIRCJump::~CIRCJump()
{
}

CIRSeq::CIRSeq( const IIRStm* _left, const IIRStm* _right ):
	left( _left ), right( _right )
{
}

CIRSeq::~CIRSeq()
{
}

CIRLabel::CIRLabel( const Temp::CLabel* _label ):
	label( _label )
{
}

CIRLabel::~CIRLabel()
{
}