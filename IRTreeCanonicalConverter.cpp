#include "IRTreeCanonicalConverter.h"
#include "CStm.h"
#include "CExp.h"

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
}

void CIRTreeCanonicalConverter::visit( const CIRCJump* node )
{
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
	node->left->Accept( this );

	node->right->Accept( this );
	switch( node->opId ) {
		case MUL:

			break;
		case PLUS:

			break;
		case DIV:

			break;
		case MINUS:

			break;
		case NOT:

			break;
		case EQ:

			break;
		case NE:

			break;
		case LE:

			break;
		case GE:

			break;
		case LT:

			break;
		case GT:

			break;
		case AND:

			break;
	}
}

void CIRTreeCanonicalConverter::visit( const CIRMem* node )
{
	node->exp->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRCall* node )
{
	node->exp->Accept( this );
	node->expList->Accept( this );
}

void CIRTreeCanonicalConverter::visit( const CIRESeq* node )
{
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