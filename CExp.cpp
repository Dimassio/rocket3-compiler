#include "CExp.h"
#include "IRTree.h"

CIRCall::CIRCall( const  IIRExp* _exp, const CIRExpList* _expList ):
	exp( _exp ), expList( _expList )
{
}

CIRCall::~CIRCall()
{
}

void CIRCall::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRCall::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

void CIRCall::AcceptToSiftUpEseqs(CIRTreeCanonicalConverter* visitor) const {
	visitor->siftUpEseqs(this);
}

CIRConst::CIRConst( const int _value ):
	value( _value )
{
}

CIRConst::~CIRConst()
{
}

void CIRConst::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRConst::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRBinOp::CIRBinOp( const EOperation binop, const IIRExp* _left, const IIRExp* _right ):
	opId( binop ), left( _left ), right( _right )
{
}

CIRBinOp::~CIRBinOp()
{
}

void CIRBinOp::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRBinOp::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRESeq::CIRESeq( const IIRStm* _stm, const IIRExp* _exp ):
	exp( _exp ), stm( _stm )
{
}

CIRESeq::~CIRESeq()
{
}

void CIRESeq::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRESeq::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRMem::CIRMem( const IIRExp* _exp ):
	exp( _exp )
{
}

CIRMem::~CIRMem()
{
}

void CIRMem::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRMem::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRName::CIRName( const Temp::CLabel* _label ):
	label( _label )
{
}

CIRName::~CIRName()
{
}

void CIRName::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRName::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

CIRTemp::CIRTemp( const Temp::CTemp* _temp ):
	temp( _temp )
{
}

CIRTemp::~CIRTemp()
{
}

void CIRTemp::Accept( IIRTreeVisitor* visitor ) const
{
	visitor->visit( this );
}

void CIRTemp::Accept( IIRTreeConvertVisitor* visitor )
{
	visitor->visit( this );
}

