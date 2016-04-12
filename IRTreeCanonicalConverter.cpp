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

CIRTreeCanonicalConverter::CIRTreeCanonicalConverter(IIRExp* root)
	: frameRoot(root)
{
}

void CIRTreeCanonicalConverter::visit( const CIRMove* node )
{
	node->dst->Accept( this );
	IIRExp* dst = lastNodeExp;
	node->src->Accept( this );
	IIRExp* src = lastNodeExp;

	lastNodeExp = nullptr;
	lastNodeStm = new CIRMove(dst, src);
}

void CIRTreeCanonicalConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );

	lastNodeExp = nullptr;
	lastNodeStm = new CIRExp(lastNodeExp);
}

void CIRTreeCanonicalConverter::visit( const CIRJump* node )
{
	lastNodeExp = nullptr;
	lastNodeStm = const_cast<CIRJump*>(node);

	// todo: jump(eseq(s, e1)) -> seq(s, jump(e1)) ?
}

void CIRTreeCanonicalConverter::visit( const CIRCJump* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->left ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->left ) );
		// new vertex here - seq:
		CIRSeq* newSeq = new CIRSeq( eseq->stm, new CIRCJump( node->op, node->left, node->right, node->iftrue, node->iffalse ) );
		
		node->right->Accept(this);
		IIRStm* right = lastNodeStm;
		node->left->Accept(this);
		IIRStm* left = lastNodeStm;

		lastNodeExp = nullptr;
		lastNodeStm = new CIRSeq(left, right);

		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		// new vertex here - seq
		CIRSeq* newSeq = new CIRSeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), node->left ),
									 new CIRSeq( eseq->stm,
												 new CIRCJump( node->op,
															   new CIRTemp( new Temp::CTemp() ), eseq->exp, node->iftrue, node->iffalse ) ) );
		node->right->Accept(this);
		IIRStm* right = lastNodeStm;
		node->left->Accept(this);
		IIRStm* left = lastNodeStm;

		lastNodeExp = nullptr;
		lastNodeStm = new CIRSeq(left, right);
		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		// new vertex here - seq
		if (IsCommute(const_cast<IIRStm*>(eseq->stm), const_cast<IIRExp*>(node->left)))
		{
			CIRSeq* newSeq = new CIRSeq(eseq->stm,
				new CIRCJump(node->op, node->left, eseq->exp, node->iftrue, node->iffalse));

			node->right->Accept(this);
			IIRStm* right = lastNodeStm;
			node->left->Accept(this);
			IIRStm* left = lastNodeStm;

			lastNodeExp = nullptr;
			lastNodeStm = new CIRSeq(left, right);

			return;		
		}		
	}

	node->right->Accept( this );
	IIRExp* right = lastNodeExp;
	node->left->Accept( this );
	IIRExp* left = lastNodeExp;

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

	lastNodeExp = nullptr;
	lastNodeStm = new CIRSeq(left, right);
}

void CIRTreeCanonicalConverter::visit( const CIRConst* node )
{
	lastNodeStm = nullptr;
	lastNodeExp = const_cast<CIRConst*>(node);
}

void CIRTreeCanonicalConverter::visit( const CIRName* node )
{
	lastNodeStm = nullptr;
	lastNodeExp = const_cast<CIRName*>(node);
}

void CIRTreeCanonicalConverter::visit( const CIRTemp* node )
{
	lastNodeStm = nullptr;
	lastNodeExp = const_cast<CIRTemp*>(node);
}

void CIRTreeCanonicalConverter::visit( const CIRBinOp* node )
{
	IIRStm* stm = nullptr;
	IIRExp* exp = nullptr;

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->left ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->left ) );
		// now vertex here -  eseq:
		CIRESeq* newEseq = new CIRESeq( eseq->stm, new CIRBinOp( node->opId, eseq->exp, node->right ) );

		newEseq->stm->Accept(this);
		stm = lastNodeStm;
		newEseq->exp->Accept(this);
		exp = lastNodeExp;

		lastNodeStm = nullptr;
		lastNodeExp = new CIRESeq(stm, exp);


		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		// now vertex is - eseq:
		CIRESeq* newEseq = new CIRESeq( new CIRMove( new CIRTemp( new Temp::CTemp() ), node->left ),
										new CIRESeq( eseq->stm,
													 new CIRBinOp( node->opId,
																   new CIRTemp( new Temp::CTemp() ), eseq->exp ) ) );
		newEseq->stm->Accept(this);
		stm = lastNodeStm;
		newEseq->exp->Accept(this);
		exp = lastNodeExp;

		lastNodeStm = nullptr;
		lastNodeExp = new CIRESeq(stm, exp);

		return;
	}

	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->right ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->right ) );
		if( IsCommute( const_cast< IIRStm* >( eseq->stm ), const_cast< IIRExp* >( node->left ) ) ) {
			// now vertex is - eseq
			CIRESeq* newEseq = new CIRESeq( eseq->stm,
											new CIRBinOp( node->opId, node->left, eseq->exp ) );

			newEseq->stm->Accept(this);
			stm = lastNodeStm;
			newEseq->exp->Accept(this);
			exp = lastNodeExp;

			lastNodeStm = nullptr;
			lastNodeExp = new CIRESeq(stm, exp);

			return;
		}
	}

	node->left->Accept(this);
	exp = lastNodeExp;
	node->right->Accept(this);

	lastNodeStm = nullptr;
	lastNodeExp = new CIRBinOp(node->opId, exp, lastNodeExp);
}

void CIRTreeCanonicalConverter::visit( const CIRMem* node )
{
	if( IsInstanceOf<CIRESeq>( const_cast< IIRExp* >( node->exp ) ) ) {
		CIRESeq* eseq = dynamic_cast< CIRESeq* >( const_cast< IIRExp* >( node->exp ) );

		CIRESeq* newEseq = new CIRESeq( eseq->stm, new CIRMem( eseq->exp ) );
		newEseq->stm->Accept( this );
		IIRStm* stm = lastNodeStm;
		newEseq->exp->Accept( this );
		
		lastNodeStm = nullptr;
		lastNodeExp = new CIRESeq(stm, lastNodeExp);

		return;
	}

	node->exp->Accept( this );

	lastNodeStm = nullptr;
	lastNodeExp = new CIRMem(lastNodeExp);
}

void CIRTreeCanonicalConverter::visit( const CIRCall* node )
{
	node->exp->Accept( this );
	IIRExp* exp = lastNodeExp;
	node->expList->Accept( this );

	lastNodeStm = nullptr;
	lastNodeExp = new CIRCall(exp, lastNodeExpList);
}

void CIRTreeCanonicalConverter::visit( const CIRESeq* node )
{
	IIRStm* stm = nullptr;
	IIRExp* exp = nullptr;

	if (IsInstanceOf<CIRESeq>(const_cast<IIRExp*>(node->exp))) {
		CIRESeq* eseq = dynamic_cast<CIRESeq*>(const_cast<IIRExp*>(node->exp));
		// new vertex here - eseq:
		CIRESeq* newEseq = new CIRESeq(new CIRSeq(node->stm, eseq->stm), eseq->exp);

		newEseq->stm->Accept(this);
		stm = lastNodeStm;
		newEseq->exp->Accept(this);
		exp = lastNodeExp;

		lastNodeStm = nullptr;
		lastNodeExp = new CIRESeq(stm, exp);

		return;
	}

	if( node->stm != nullptr ) {
		node->stm->Accept( this );
		stm = lastNodeStm;
	}
	if( node->exp != nullptr ) {
		node->exp->Accept( this );
		exp = lastNodeExp;
	}

	lastNodeStm = nullptr;
	lastNodeExp = new CIRESeq(stm, exp);

	if (node == frameRoot) {
		frameRoot = lastNodeExp;
	}
}

void CIRTreeCanonicalConverter::visit( const CIRExpList* node )
{
	std::list<IIRExp*> expList;


	for( auto exp : node->expList ) {
		exp->Accept( this );
		expList.push_back(lastNodeExp);
	}

	lastNodeExp = nullptr;
	lastNodeStm = nullptr;
	lastNodeExpList = new CIRExpList(expList);
}

void CIRTreeCanonicalConverter::visit( const CIRLabel* node )
{
	lastNodeExp = nullptr; 
	lastNodeStm = const_cast<CIRLabel*>(node);
}