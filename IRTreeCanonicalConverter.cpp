#include "IRTreeCanonicalConverter.h"
#include "CStm.h"
#include "CExp.h"

// todo: we have to clean somehow old nodes :(

template<class T, class S>
bool IsInstanceOf( S* exp )
{
	return dynamic_cast< T* >( exp ) == 0 ? false : true;
}

bool IsNop( IIRStm* stm )
{
	// hint: if something will go wrong, check here:
	return IsInstanceOf<IIRExp>( stm ) && IsInstanceOf<CIRConst>( dynamic_cast< IIRExp* >( stm ) );
}

bool IsCommute( IIRStm* stm, IIRExp* exp )
{
	return IsNop( stm ) || IsInstanceOf<CIRName>( exp ) || IsInstanceOf<CIRConst>( exp );
}

void CIRTreeCanonicalConverter::visit( const CIRMove* node )
{
	node->dst->Accept( this );
	node->src->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRJump* node )
{
	// todo: jump(eseq(s, e1)) -> seq(s, jump(e1)) ?
}

void CIRTreeCanonicalConverter::visit( const CIRCJump* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->left ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->left ) );
		// new vertex here - seq:
		CIRSeq* newSeq = new CIRSeq( eseq->stm, new CIRCJump( node->op, node->left, node->right, node->iftrue, node->iffalse ) );
		newSeq->left->Accept( this );
		newSeq->right->Accept( this );
		return;
	}
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		// new vertex here - seq
		CIRSeq* newSeq = new CIRSeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), node->left ),
									 new CIRSeq( eseq->stm,
												 new CIRCJump( node->op,
															   new CIRTemp( new Temp::CTemp() ), eseq->exp, node->iftrue, node->iffalse ) ) );
		newSeq->left->Accept( this );
		newSeq->right->Accept( this );
		return;
	}
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		// new vertex here - seq
		CIRSeq* newSeq = new CIRSeq( eseq->stm,
									 new CIRCJump( node->op, node->left, eseq->exp, node->iftrue, node->iffalse ) );
		newSeq->left->Accept( this );
		newSeq->right->Accept( this );
		return;
	}
	node->right->Accept( this );
	node->left->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRSeq* node )
{
	if( node->left != nullptr ) {
		node->left->Accept( this );
	}
	if( node->right != nullptr ) {
		node->right->Accept( this );
	}
}

void CIRTreeCanonicalConverter::visit( const CIRConst* node )
{
}

void CIRTreeCanonicalConverter::visit( const CIRName* node )
{
}

void CIRTreeCanonicalConverter::visit( const CIRTemp* node )
{
}

void CIRTreeCanonicalConverter::visit( const CIRBinOp* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->left ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->left ) );
		// now vertex here -  eseq:
		CIRESeq* newEseq = new CIRESeq( eseq->stm, new CIRBinOp( node->opId, eseq->exp, node->right ) );
		eseq->stm->Accept( this );
		eseq->exp->Accept( this );
		return;
	}
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		// now vertex is - eseq:
		CIRESeq* newEseq = new CIRESeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), node->left ),
										new CIRESeq( eseq->stm,
													 new CIRBinOp( node->opId,
																   new CIRTemp( new Temp::CTemp() ), eseq->exp ) ) );
		newEseq->stm->Accept( this );
		newEseq->exp->Accept( this );
		return;
	}
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		if( IsCommute( const_cast< IIRStm* >( eseq->stm ), const_cast< IIRExp* >( node->left ) ) ) {
			// now vertex is - eseq
			CIRESeq* newEseq = new CIRESeq( eseq->stm,
											new CIRBinOp( node->opId, node->left, eseq->exp ) );
			newEseq->stm->Accept( this );
			newEseq->exp->Accept( this );
			return;
		}
	}
	node->left->Accept( this );
	node->right->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRMem* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->exp ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->exp ) );
		// new vertex here - eseq
		CIRESeq* newEseq = new CIRESeq( eseq->stm, new CIRMem( eseq->exp ) );
		newEseq->stm->Accept( this );
		newEseq->exp->Accept( this );
		return;
	}
	node->exp->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRCall* node )
{
	node->exp->Accept( this );
	node->expList->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRESeq* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->exp ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->exp ) );
		// new vertex here - eseq:
		CIRESeq* newEseq = new CIRESeq( new CIRSeq( node->stm, eseq->stm ), eseq->exp );
		newEseq->stm->Accept( this );
		newEseq->exp->Accept( this );
		return;
	}
	if( node->stm != nullptr ) {
		node->stm->Accept( this );
	}
	if( node->exp != nullptr ) {
		node->exp->Accept( this );
	}
}

void CIRTreeCanonicalConverter::visit( const CIRExpList* node )
{
	for( auto exp : node->expList ) {
		exp->Accept( this );
	}
}

void CIRTreeCanonicalConverter::visit( const CIRLabel* node )
{
}