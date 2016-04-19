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
	node->dst->Accept(this);

	IIRExp* dst = lastNodeExp;

	if (IsInstanceOf<CIRCall>( const_cast<IIRExp*>( node->src ))) {
		lastNodeExp = nullptr;
		lastNodeStm = new CIRMove(dst, node->src);
		return;
	}

	node->src->Accept(this);
	IIRExp* src = lastNodeExp;

	lastNodeExp = nullptr;
	lastNodeStm = new CIRMove( dst, src );
}

void CIRTreeCanonicalConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );

	lastNodeStm = new CIRExp(lastNodeExp);
	lastNodeExp = nullptr;
}

void CIRTreeCanonicalConverter::visit( const CIRJump* node )
{
	lastNodeExp = nullptr;
	lastNodeStm = const_cast< CIRJump* >( node );

	// todo: jump(eseq(s, e1)) -> seq(s, jump(e1)) ?
}

void CIRTreeCanonicalConverter::visit( const CIRCJump* node )
{
	node->right->Accept(this);
	IIRExp* right = lastNodeExp;
	node->left->Accept(this);
	IIRExp* left = lastNodeExp;

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( left ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( left );

		lastNodeStm = new CIRSeq(eseq->stm, new CIRCJump(node->op, left, right, node->iftrue, node->iffalse));

		lastNodeExp = nullptr;
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		lastNodeStm = new CIRSeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), left ),
									 new CIRSeq( eseq->stm,
												 new CIRCJump( node->op,
															   new CIRTemp( new Temp::CTemp() ), eseq->exp, node->iftrue, node->iffalse ) ) );

		lastNodeExp = nullptr;
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		if (IsCommute(const_cast<IIRStm*>(eseq->stm), const_cast<IIRExp*>( left )))
		{
			lastNodeStm = new CIRSeq(eseq->stm,
				new CIRCJump(node->op, left, eseq->exp, node->iftrue, node->iffalse));


			lastNodeExp = nullptr;
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

	if (node->left != nullptr) {
		node->left->Accept(this);
		left = lastNodeStm;
	}

	if (node->right != nullptr) {
		node->right->Accept(this);
		right = lastNodeStm;
	}
	
	if( node->left != nullptr ) {
		if (IsInstanceOf<CIRSeq>(const_cast< IIRStm* >( left ))) {
			const CIRSeq* seq = dynamic_cast< const CIRSeq* >( left );

			lastNodeStm = new CIRSeq(seq->left, new CIRSeq(seq->right, right));

			lastNodeExp = nullptr;
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
	node->right->Accept(this);
	IIRExp* right = lastNodeExp;
	node->left->Accept(this);
	IIRExp* left = lastNodeExp;

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( left ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( left );

		lastNodeExp = new CIRESeq( eseq->stm, new CIRBinOp( node->opId, eseq->exp, right ) );
		lastNodeStm = nullptr;
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		lastNodeExp = new CIRESeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), left ),
										new CIRESeq( eseq->stm,
													 new CIRBinOp( node->opId,
																   new CIRTemp( new Temp::CTemp() ), eseq->exp ) ) );

		lastNodeStm = nullptr;

		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( right ) ) ) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq* >( right );

		if( IsCommute( const_cast< IIRStm* >( eseq->stm ), const_cast< IIRExp* >( left ) ) ) {

			lastNodeExp = new CIRESeq( eseq->stm,
											new CIRBinOp( node->opId, left, eseq->exp ) );
			
			lastNodeStm = nullptr;
			return;
		}
	}

	lastNodeStm = nullptr;
	lastNodeExp = new CIRBinOp(node->opId, left, right);
}

void CIRTreeCanonicalConverter::visit( const CIRMem* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->exp ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >(const_cast< IIRExp* >(node->exp));

		eseq->stm->Accept(this);
		IIRStm* stm = lastNodeStm;

		eseq->exp->Accept(this);

		lastNodeExp = new CIRESeq(stm, new CIRMem(lastNodeExp));
		lastNodeStm = nullptr;

		return;
	}

	node->exp->Accept( this );

	lastNodeStm = nullptr;
	lastNodeExp = new CIRMem( lastNodeExp );
}

void CIRTreeCanonicalConverter::visit( const CIRCall* node )
{
	node->exp->Accept(this);
	IIRExp* exp = lastNodeExp;
	node->expList->Accept(this);
	CIRExpList* expList = lastNodeExpList;

	lastNodeExp = new CIRESeq(new CIRMove(new CIRTemp(new Temp::CTemp()), new CIRCall(exp, expList)),
		new CIRTemp(new Temp::CTemp()));
	lastNodeStm = nullptr;
}

void CIRTreeCanonicalConverter::visit( const CIRESeq* node )
{
	IIRExp* exp = nullptr;
	IIRStm* stm = nullptr;

	if (node->stm != nullptr) {
		node->stm->Accept(this);
		stm = lastNodeStm;
	}
	if (node->exp != nullptr) {
		node->exp->Accept(this);
		exp = lastNodeExp;
	}

	if (IsInstanceOf<CIRESeq>(const_cast<IIRExp*>( exp ))) {
		const CIRESeq* eseq = dynamic_cast< const CIRESeq*>( exp );

		lastNodeExp = new CIRESeq(new CIRSeq(stm, eseq->stm), eseq->exp);
		lastNodeStm = nullptr;
		return;
	}

	lastNodeStm = nullptr;
	lastNodeExp = new CIRESeq( stm, exp );

	if( node == frameRoot ) {
		frameRoot = lastNodeExp;
	}
}

void CIRTreeCanonicalConverter::visit( const CIRExpList* node )
{
	std::list<IIRExp*> expList;

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