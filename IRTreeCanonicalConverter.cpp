#include "IRTreeCanonicalConverter.h"
#include "CStm.h"
#include "CExp.h"

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

CIRTreeCanonicalConverter::CIRTreeCanonicalConverter( IIRExp* root )
	: frameRoot( root )
{
}

void CIRTreeCanonicalConverter::visit( const CIRMove* node )
{
	node->dst->Accept( this );
	IIRExp* dst = lastNodeExp;
	IIRExp* src = const_cast< IIRExp* >( node->src );

	if( IsInstanceOf<CIRCall>( const_cast< IIRExp* >( src ) ) ) {
		const CIRCall* call = dynamic_cast< const CIRCall* >( src );
		call->AcceptToSiftUpEseqs( this );
		src = lastNodeExp;
	}

	if( IsInstanceOf<CIRCall>( const_cast< IIRExp* >( src ) ) ) {
		const CIRCall* call = dynamic_cast< const CIRCall* >( src );

		call->exp->Accept( this );
		IIRExp* exp = lastNodeExp;
		call->expList->Accept( this );
		CIRExpList* expList = lastNodeExpList;

		lastNodeExp = nullptr;
		lastNodeStm = new CIRMove( dst, new CIRCall( exp, expList ) );
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( src ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( src );

		CIRSeq* seq = new CIRSeq( eseq->stm, new CIRMove( dst, eseq->exp ) );

		seq->Accept( this );
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( dst ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( dst );

		CIRSeq* seq = new CIRSeq( eseq->stm, new CIRMove( eseq->exp, src ) );

		seq->Accept( this );
		return;
	}

	src->Accept( this );
	src = lastNodeExp;

	lastNodeExp = nullptr;
	lastNodeStm = new CIRMove( dst, src );
}

void CIRTreeCanonicalConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );

	lastNodeStm = new CIRExp( lastNodeExp );
	lastNodeExp = nullptr;
}

void CIRTreeCanonicalConverter::visit( const CIRJump* node )
{
	lastNodeExp = nullptr;
	lastNodeStm = const_cast< CIRJump* >( node );
}

void CIRTreeCanonicalConverter::visit( const CIRCJump* node )
{
	node->right->Accept( this );
	IIRExp* right = lastNodeExp;
	node->left->Accept( this );
	IIRExp* left = lastNodeExp;

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( left ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( left );

		CIRSeq* seq = new CIRSeq( eseq->stm, new CIRCJump( node->op, left, right, node->iftrue, node->iffalse ) );

		seq->Accept( this );
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		CIRSeq* seq = new CIRSeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), left ),
								  new CIRSeq( eseq->stm,
											  new CIRCJump( node->op,
															new CIRTemp( new Temp::CTemp() ), eseq->exp, node->iftrue, node->iffalse ) ) );

		seq->Accept( this );
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		if( IsCommute( const_cast< IIRStm* >( eseq->stm ), const_cast< IIRExp* >( left ) ) ) {
			CIRSeq* seq = new CIRSeq( eseq->stm,
									  new CIRCJump( node->op, left, eseq->exp, node->iftrue, node->iffalse ) );


			seq->Accept( this );
			return;
		}
	}

	lastNodeExp = nullptr;
	lastNodeStm = new CIRCJump( node->op, left, right, node->iftrue, node->iffalse );
}

void CIRTreeCanonicalConverter::visit( const CIRSeq* node )
{
	IIRStm* left = nullptr;
	IIRStm* right = nullptr;

	if( node->left != nullptr ) {
		node->left->Accept( this );
		left = lastNodeStm;
	}

	if( node->right != nullptr ) {
		node->right->Accept( this );
		right = lastNodeStm;
	}

	if( left == nullptr && right != nullptr ) {
		CIRSeq* seq = new CIRSeq( right, nullptr );
		seq->Accept( this );
		return;
	}

	if( left != nullptr ) {
		if( IsInstanceOf<CIRSeq>( const_cast< IIRStm* >( left ) ) ) {
			if( right == nullptr ) {
				lastNodeExp = nullptr;
				lastNodeStm = left;
				return;
			}

			const CIRSeq* seq = dynamic_cast< const CIRSeq* >( left );

			CIRSeq* newSeq = new CIRSeq( seq->left, new CIRSeq( seq->right, right ) );
			newSeq->Accept( this );
			return;
		}

		if( right != nullptr && !IsInstanceOf<CIRSeq>( const_cast< IIRStm* >( right ) ) ) {
			lastNodeExp = nullptr;
			lastNodeStm = new CIRSeq( left, new CIRSeq( right, nullptr ) );
			return;
		}
	}

	lastNodeExp = nullptr;
	lastNodeStm = new CIRSeq( left, right );
}

void CIRTreeCanonicalConverter::visit( const CIRConst* node )
{
	lastNodeStm = nullptr;
	lastNodeExp = const_cast< CIRConst* >( node );
}

void CIRTreeCanonicalConverter::visit( const CIRName* node )
{
	lastNodeStm = nullptr;
	lastNodeExp = const_cast< CIRName* >( node );
}

void CIRTreeCanonicalConverter::visit( const CIRTemp* node )
{
	lastNodeStm = nullptr;
	lastNodeExp = const_cast< CIRTemp* >( node );
}

void CIRTreeCanonicalConverter::visit( const CIRBinOp* node )
{
	node->right->Accept( this );
	IIRExp* right = lastNodeExp;

	node->left->Accept( this );
	IIRExp* left = lastNodeExp;

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( left ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( left );
		CIRESeq* newEseq = new CIRESeq( eseq->stm, new CIRBinOp( node->opId, eseq->exp, right ) );

		newEseq->Accept( this );
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		CIRESeq* newEseq = new CIRESeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), left ),
										new CIRESeq( eseq->stm,
													 new CIRBinOp( node->opId,
																   new CIRTemp( new Temp::CTemp() ), eseq->exp ) ) );

		newEseq->Accept( this );
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		if( IsCommute( const_cast< IIRStm* >( eseq->stm ), const_cast< IIRExp* >( left ) ) ) {

			CIRESeq* newEseq = new CIRESeq( eseq->stm,
											new CIRBinOp( node->opId, left, eseq->exp ) );

			newEseq->Accept( this );
			return;
		}
	}

	lastNodeStm = nullptr;
	lastNodeExp = new CIRBinOp( node->opId, left, right );
}

void CIRTreeCanonicalConverter::visit( const CIRMem* node )
{
	node->exp->Accept( this );
	IIRExp* exp = lastNodeExp;

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( exp ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( exp ) );
		CIRESeq* newEseq = new CIRESeq( eseq->stm, new CIRMem( eseq->exp ) );

		newEseq->Accept( this );

		return;
	}

	lastNodeStm = nullptr;
	lastNodeExp = new CIRMem( exp );
}

void CIRTreeCanonicalConverter::siftUpEseqs( const CIRCall* node )
{
	CIRExpList* expList = const_cast< CIRExpList* >( node->expList );
	for( int i = 0; i < expList->expList.size(); ++i ) {
		if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( expList->expList[i] ) ) ) {
			const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( expList->expList[i] );
			expList->expList[i] = const_cast< IIRExp* >( eseq->exp );

			CIRCall* call = new CIRCall( node->exp, expList );
			call->AcceptToSiftUpEseqs( this );

			lastNodeExp = new CIRESeq( eseq->stm, lastNodeExp );
			lastNodeStm = nullptr;
			return;
		}
	}

	lastNodeExp = const_cast< CIRCall* >( node );
	lastNodeStm = nullptr;
}

void CIRTreeCanonicalConverter::visit( const CIRCall* node )
{
	node->expList->Accept( this );

	CIRESeq* eseq = new CIRESeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), new CIRCall( node->exp, lastNodeExpList ) ),
								 new CIRTemp( new Temp::CTemp() ) );

	eseq->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRESeq* node )
{
	IIRExp* exp = nullptr;
	IIRStm* stm = nullptr;

	if( node->stm != nullptr ) {
		node->stm->Accept( this );
		stm = lastNodeStm;
	}

	if( node->exp != nullptr ) {
		node->exp->Accept( this );
		exp = lastNodeExp;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( exp ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( exp );

		CIRSeq* seq = new CIRSeq( stm, eseq->stm );
		seq->Accept( this );

		lastNodeExp = new CIRESeq( lastNodeStm, eseq->exp );
		lastNodeStm = nullptr;
		return;
	}

	lastNodeStm = nullptr;
	lastNodeExp = new CIRESeq( stm, exp );

	if( node == frameRoot ) {
		frameRoot = lastNodeExp;
		frameCanonRoot = const_cast< IIRStm* >( dynamic_cast< CIRESeq* >( lastNodeExp )->stm );
		if( IsInstanceOf<CIRExp>( frameCanonRoot ) ) {
			CIRExp* currRoot = dynamic_cast< CIRExp* >( frameCanonRoot );
			frameCanonRoot = const_cast< IIRStm* >( dynamic_cast< const CIRESeq* >( currRoot->exp )->stm );
		}
	}
}

void CIRTreeCanonicalConverter::visit( const CIRExpList* node )
{
	std::vector<IIRExp*> expList;

	for( auto exp : node->expList ) {
		exp->Accept( this );
		expList.push_back( lastNodeExp );
	}

	lastNodeExp = nullptr;
	lastNodeStm = nullptr;
	lastNodeExpList = new CIRExpList( expList );
}

void CIRTreeCanonicalConverter::visit( const CIRLabel* node )
{
	lastNodeExp = nullptr;
	lastNodeStm = const_cast< CIRLabel* >( node );
}