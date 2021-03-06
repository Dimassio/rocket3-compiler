#include "CStm.h"
#include "IRTree.h"

CIRMove::CIRMove( const IIRExp* _dst, const IIRExp* _src ):
	dst( _dst ), src( _src )
{
}

CIRMove::~CIRMove()
{
}

void CIRMove::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRMove::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRExp::CIRExp( const IIRExp* _exp ):
	exp( _exp )
{
}

CIRExp::~CIRExp()
{
}

void CIRExp::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRExp::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRJump::CIRJump( const Temp::CLabel* _label ):
	label( _label )
{
}

CIRJump::~CIRJump()
{
}

void CIRJump::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRJump::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRCJump::CIRCJump( const EOperation _op, const IIRExp* _left, const IIRExp* _right, const CIRLabel* _iftrue, const CIRLabel* _iffalse ):
	op( _op ), left( _left ), right( _right ), iftrue( _iftrue ), iffalse( _iffalse )
{
}

CIRCJump::~CIRCJump()
{
}

void CIRCJump::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRCJump::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRSeq::CIRSeq( const IIRStm* _left, const IIRStm* _right ):
	left( _left ), right( _right )
{
}

CIRSeq::~CIRSeq()
{
}

void CIRSeq::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRSeq::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRLabel::CIRLabel( const Temp::CLabel* _label ):
	label( _label )
{
}

CIRLabel::~CIRLabel()
{
}

void CIRLabel::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRLabel::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}