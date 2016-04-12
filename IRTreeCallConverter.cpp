#include "IRTreeCallConverter.h"
#include "CStm.h"
#include "CExp.h"

template<class T, class S>
bool IsInstanceOf( S* exp )
{
	return dynamic_cast< T* >( exp ) == 0 ? false : true;
}

CIRTreeCallConverter::CIRTreeCallConverter( const IIRExp* _root )
{
	root = _root;
}

void CIRTreeCallConverter::visit( const CIRMove* node )
{
	node->dst->Accept( this );
	node->src->Accept( this );
}

void CIRTreeCallConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );
}

void CIRTreeCallConverter::visit( const CIRJump* node )
{
}

void CIRTreeCallConverter::visit( const CIRCJump* node )
{
	node->right->Accept( this );
	node->left->Accept( this );
}

void CIRTreeCallConverter::visit( const CIRSeq* node )
{
	if( node->left != nullptr ) {
		node->left->Accept( this );
	}
	if( node->right != nullptr ) {
		node->right->Accept( this );
	}
}

void CIRTreeCallConverter::visit( const CIRConst* node )
{
}

void CIRTreeCallConverter::visit( const CIRName* node )
{
}

void CIRTreeCallConverter::visit( const CIRTemp* node )
{
}

void CIRTreeCallConverter::visit( const CIRBinOp* node )
{
	node->left->Accept( this );
	node->right->Accept( this );
}

void CIRTreeCallConverter::visit( const CIRMem* node )
{
	node->exp->Accept( this );
}

void CIRTreeCallConverter::visit( const CIRCall* node )
{
	CIRESeq* eseq = new CIRESeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), node ),
								 new CIRTemp( new Temp::CTemp() ) );
	node->exp->Accept( this );
	node->expList->Accept( this );
}

void CIRTreeCallConverter::visit( const CIRESeq* node )
{
	if( node->stm != nullptr ) {
		node->stm->Accept( this );
	}
	if( node->exp != nullptr ) {
		node->exp->Accept( this );
	}
}

void CIRTreeCallConverter::visit( const CIRExpList* node )
{
	for( auto exp : node->expList ) {
		exp->Accept( this );
	}
}

void CIRTreeCallConverter::visit( const CIRLabel* node )
{
}