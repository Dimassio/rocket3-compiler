#include "CIRTreeToGraphConverter.h"
#include "CStm.h"
#include "CExp.h"

using namespace std;

void CIRTreeToGraphConverter::visit( const CIRMove* node )
{
	node->dst->Accept( this );
	string destString = lastNodeName;

	node->src->Accept( this );
	string srcString = lastNodeName;

	nextNameWithId( "move" );

	treeRepresentation.AddEdge( lastNodeName, destString, "dest" );
	treeRepresentation.AddEdge( lastNodeName, srcString, "src" );
}

void CIRTreeToGraphConverter::visit( const CIRExp* node )
{
	node->exp->Accept( this );
	string prevString = lastNodeName;

	nextNameWithId( "exp" );
	treeRepresentation.AddEdge( lastNodeName, prevString );
}

void CIRTreeToGraphConverter::visit( const CIRJump* node )
{
	nextNameWithId( "jump" );
	treeRepresentation.AddEdge( lastNodeName, node->label->Name(), "to_label" );
}

void CIRTreeToGraphConverter::visit( const CIRCJump* node )
{
	node->right->Accept( this );
	string rightString = lastNodeName;
	node->left->Accept( this );
	string leftString = lastNodeName;

	nextNameWithId( "Cjump" );

	treeRepresentation.AddEdge( lastNodeName, rightString, "right" );
	treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
	treeRepresentation.AddEdge( lastNodeName, node->iftrue->label->Name(), "iftrue" );
	treeRepresentation.AddEdge( lastNodeName, node->iffalse->label->Name(), "iffalse" );
}

void CIRTreeToGraphConverter::visit( const CIRSeq* node )
{
	if( node->left != nullptr ) {
		node->left->Accept( this );
		string leftString = lastNodeName;
		if( node->right != nullptr ) {
			node->right->Accept( this );
			string rightString = lastNodeName;
			nextNameWithId( "seq" );
			treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
			treeRepresentation.AddEdge( lastNodeName, rightString, "right" );
		} else {
			nextNameWithId( "seq" );
			treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
		}
	} else {
		nextNameWithId( "seq" );
	}
}

void CIRTreeToGraphConverter::visit( const CIRConst* node )
{
	nextNameWithId( string( "const_" ) + to_string( node->value ) );
}

void CIRTreeToGraphConverter::visit( const CIRName* node )
{
	nextNameWithId( string( "name_" ) + node->label->Name() );
}

void CIRTreeToGraphConverter::visit( const CIRTemp* node )
{
	nextNameWithId( string( "temp_" ) + node->temp->Name() );
}

void CIRTreeToGraphConverter::visit( const CIRBinOp* node )
{
	node->left->Accept( this );
	string leftString = lastNodeName;
	node->right->Accept( this );
	string rightString = lastNodeName;
	//graphviz отказывается работать с символами типа + *
	switch( node->opId ) {
		case MUL:
			nextNameWithId( "binop__mul" );
			break;
		case PLUS:
			nextNameWithId( "binop__plus" );
			break;
		case DIV:
			nextNameWithId( "binop__div" );
			break;
		case MINUS:
			nextNameWithId( "binop__minus" );
			break;
		case NOT:
			nextNameWithId( "binop__not" );
			break;
		case EQ:
			nextNameWithId( "binop__eq" );
			break;
		case NE:
			nextNameWithId( "binop__ne" );
			break;
		case LE:
			nextNameWithId( "binop__le" );
			break;
		case GE:
			nextNameWithId( "binop__ge" );
			break;
		case LT:
			nextNameWithId( "binop__lt" );
			break;
		case GT:
			nextNameWithId( "binop__gt" );
			break;
		case AND:
			nextNameWithId( "binop__and" );
			break;
	}
	treeRepresentation.AddEdge( lastNodeName, rightString, "right" );
	treeRepresentation.AddEdge( lastNodeName, leftString, "left" );
}

void CIRTreeToGraphConverter::visit( const CIRMem* node )
{
	node->exp->Accept( this );
	string prevString = lastNodeName;
	nextNameWithId( "mem" );
	treeRepresentation.AddEdge( lastNodeName, prevString );
}

void CIRTreeToGraphConverter::visit( const CIRCall* node )
{
	node->exp->Accept( this );
	string funcString = lastNodeName;
	node->expList->Accept( this );
	string argsString = lastNodeName;
	nextNameWithId( "call" );
	treeRepresentation.AddEdge( lastNodeName, funcString, "func" );
	treeRepresentation.AddEdge( lastNodeName, argsString, "args" );
}

void CIRTreeToGraphConverter::visit( const CIRESeq* node )
{
	node->stm->Accept( this );
	string stmString = lastNodeName;

	string expString;
	if( node->exp != nullptr ) {
		node->exp->Accept( this );
		expString = lastNodeName;
	}

	nextNameWithId( "eseq" );

	if( node->exp != nullptr ) {
		treeRepresentation.AddEdge( lastNodeName, expString, "exp" );
	}

	treeRepresentation.AddEdge( lastNodeName, stmString, "stm" );
}
void CIRTreeToGraphConverter::visit( const CIRExpList* node )
{
	nextNameWithId( "expList" );
	string previousExpName = lastNodeName;

	for( auto exp : node->expList ) {
		exp->Accept( this );
		treeRepresentation.AddEdge( lastNodeName, previousExpName, "expListElement" );
		string previousExpName = lastNodeName;
	}
}

void CIRTreeToGraphConverter::visit( const CIRLabel* node )
{
	if( node->label->Name() == "tempLabel1" ) {
		int a = 1;
	}
	nextNameWithId( string( "label:" ) + node->label->Name() );
}

void CIRTreeToGraphConverter::nextNameWithId( const std::string& label )
{
	lastNodeName = label + string( "__id_" ) + to_string( minId++ );
	treeRepresentation.SetNodeLabel( lastNodeName, label );
}

void CIRTreeToGraphConverter::LinkedVisit( const IIRStm* node )
{
	string fromName = lastNodeName;
	node->Accept( this );
	string toName = lastNodeName;
	if( !fromName.empty() ) {
		treeRepresentation.AddEdge( fromName, toName, "next" );
	}
}

void CIRTreeToGraphConverter::LinkedVisit( const IIRExp* node )
{
	string fromName = lastNodeName;
	node->Accept( this );
	string toName = lastNodeName;
	if( !fromName.empty() ) {
		treeRepresentation.AddEdge( fromName, toName, "next" );
	}
}
