#include "IRTreeLinearConverter.h"
#include "CStm.h"
#include "CExp.h"

template<class T, class S>
bool IsInstanceOf( S* exp )
{
	return dynamic_cast< T* >( exp ) == 0 ? false : true;
}

CIRTreeLinearConverter::CIRTreeLinearConverter( const IIRExp* _root )
{
	root = _root;
}

void CIRTreeLinearConverter::visit( const CIRMove* node )
{
	node->dst->Accept( this );
	node->src->Accept( this );
}

void CIRTreeLinearConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );
}

void CIRTreeLinearConverter::visit( const CIRJump* node )
{
}

void CIRTreeLinearConverter::visit( const CIRCJump* node )
{
	node->right->Accept( this );
	node->left->Accept( this );
}

void CIRTreeLinearConverter::visit( const CIRSeq* node )
{
	if( node->left != nullptr ) {
		if( IsInstanceOf<CIRSeq>( const_cast< IIRStm* >( node->left ) ) ) {
			CIRSeq* seq = dynamic_cast< CIRSeq* >( const_cast< IIRStm* >( node->left ) );
			// new vertex:
			CIRSeq* newSeq = new CIRSeq( seq->left, new CIRSeq( seq->right, node->right ) );
			newSeq->left->Accept( this );
			newSeq->right->Accept( this );
			return;
		}
		node->left->Accept( this );
	}
	if( node->right != nullptr ) {
		node->right->Accept( this );
	}
}

void CIRTreeLinearConverter::visit( const CIRConst* node )
{
}

void CIRTreeLinearConverter::visit( const CIRName* node )
{
}

void CIRTreeLinearConverter::visit( const CIRTemp* node )
{
}

void CIRTreeLinearConverter::visit( const CIRBinOp* node )
{
	node->left->Accept( this );
	node->right->Accept( this );
}

void CIRTreeLinearConverter::visit( const CIRMem* node )
{
	node->exp->Accept( this );
}

void CIRTreeLinearConverter::visit( const CIRCall* node )
{
	node->exp->Accept( this );
	node->expList->Accept( this );
}

void CIRTreeLinearConverter::visit( const CIRESeq* node )
{
	if( node->stm != nullptr ) {
		node->stm->Accept( this );
	}
	if( node->exp != nullptr ) {
		node->exp->Accept( this );
	}
}

void CIRTreeLinearConverter::visit( const CIRExpList* node )
{
	for( auto exp : node->expList ) {
		exp->Accept( this );
	}
}

void CIRTreeLinearConverter::visit( const CIRLabel* node )
{
}