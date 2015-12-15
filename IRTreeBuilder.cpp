#include "IRTreeBuilder.h"
#include "CStm.h"
#include "CExp.h"
#include "Common.h"
#include "Symbols.h"
#include "StaticVariables.h"
#include "Temp.h"

using namespace Frame;

CIRTreeBuilder::CIRTreeBuilder( const CTable* _symbolTable ):
	symbolTable( _symbolTable )
{
}

void CIRTreeBuilder::visit( const CProgram* program )
{
	( program->MainClass() )->Accept( this );

	if( !( program->ClassDeclList() ) ) {
		return;
	}

	( program->ClassDeclList() )->Accept( this );
}

void CIRTreeBuilder::visit( const CMainClass* mainClass )
{
	CFrame* newFrame = new CFrame( "main", 0 );
	if( mainClass->Statement() ) {
		mainClass->Statement()->Accept( this );
		frames.push_back( newFrame );
	}
}

void CIRTreeBuilder::visit( const CClassDecl* classDecl )
{
	currClass = symbolTable->GetClass( classDecl->ClassId() );

	if( classDecl->VarDeclList() != 0 ) {
		classDecl->VarDeclList()->Accept( this );
	}
	if( classDecl->MethodDeclList() != 0 ) {
		classDecl->MethodDeclList()->Accept( this );
	}
	currClass = nullptr;
}

void CIRTreeBuilder::visit( const CClassDeclList* classDeclList )
{
	if( classDeclList->ClassDeclList() ) {
		classDeclList->ClassDeclList()->Accept( this );
	}
	classDeclList->ClassDecl()->Accept( this );
}

void CIRTreeBuilder::visit( const CExp* exp )
{
	if( exp->ExpMethodCall() ) {
		exp->ExpMethodCall()->Accept( this );
	} else if( exp->ExpBinOperation() ) {
		exp->ExpBinOperation()->Accept( this );
	} else if( exp->ExpNewIntArray() ) {
		exp->ExpNewIntArray()->Accept( this );
	} else if( exp->ExpNewCustomType() ) {
		exp->ExpNewCustomType()->Accept( this );
	} else if( exp->ExpSquareBrackets() ) {
		exp->ExpSquareBrackets()->Accept( this );
	} else if( exp->ExpRoundBrackets() ) {
		exp->ExpRoundBrackets()->Accept( this );
	} else if( exp->ExpNot() ) {
		exp->ExpNot()->Accept( this );
	} else if( exp->ExpNumber() ) {
		exp->ExpNumber()->Accept( this );
	} else if( exp->ExpId() ) {
		exp->ExpId()->Accept( this );
	} else if( exp->ExpSingle() ) {
		exp->ExpSingle()->Accept( this );
	} else if( exp->ExpLength() ) {
		exp->ExpLength()->Accept( this );
	}
}

void CIRTreeBuilder::visit( const CExpMethodCall* expMethodCall )
{
	expMethodCall->Exp()->Accept( this );
	IIRExp* expForCall = lastNodeExp;
	currExpList = new CIRExpList( lastNodeExp, nullptr ); // adding "this"

	expMethodCall->ExpList()->Accept( this );

	CIRCall* newCall = new CIRCall( expForCall, currExpList );
	currExpList = nullptr;
	lastNodeExp = newCall;
}

void CIRTreeBuilder::visit( const CExpNewIntArray* expNewIntArray )
{
	expNewIntArray->Exp()->Accept( this );

	IIRExp* count = lastNodeExp;
	IIRExp* allocationSize = new CIRBinOp( PLUS, count, new CIRConst( 1 ) );
	CIRTemp* tmp = new CIRTemp( new Temp::CTemp() );
	IIRStm* first = new CIRMove( tmp, new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "malloc" ) ) ), new CIRExpList( allocationSize, nullptr ) ) );
	IIRStm* second = new CIRExp( new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "memset" ) ) ), new CIRExpList( std::list< IIRExp* >{ new CIRConst( 0 ), allocationSize, tmp } ) ) );
	IIRStm* third = new CIRMove( tmp, count );
	second = new CIRSeq( second, third );

	lastNodeExp = new CIRESeq( new CIRSeq( first, second ), tmp );
}

void CIRTreeBuilder::visit( const CExpNewCustomType* expNewCustomType ) // todo
{
	expNewCustomType->Type()->Accept( this ); // MyClass b;
}

void CIRTreeBuilder::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	IRTree::IIRExp* firstExp = lastNodeExp;

	expSquareBrackets->SecondExp()->Accept( this );
	IRTree::IIRExp* secondExp = lastNodeExp;

	IIRExp* offset = new CIRBinOp( MUL, secondExp, new CIRConst( CFrame::wordSize ) );
	lastNodeExp = new CIRMem( new CIRBinOp( PLUS, firstExp, offset ) );
}

void CIRTreeBuilder::visit( const CExpRoundBrackets* expRoundBrackets )
{
	expRoundBrackets->Exp()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpNot* expNot )
{
	expNot->Exp()->Accept( this );
	IRTree::IIRExp* exp = lastNodeExp;

	lastNodeExp = new CIRMem( new CIRBinOp( NOT, new CIRConst( 0 ), exp ) );
}

void CIRTreeBuilder::visit( const CExpNumber* expNumber )
{
	lastNodeExp = new CIRConst( expNumber->Number() );
}

void CIRTreeBuilder::visit( const CExpId* expId )
{
	// nothing to do here
}

void CIRTreeBuilder::visit( const CExpSingle* expSingle )// ����
{

}

void CIRTreeBuilder::visit( const CExpBinOperation* expBinOperation )
{
	expBinOperation->FirstExp()->Accept( this );
	IRTree::IIRExp* firstExp = lastNodeExp;

	expBinOperation->SecondExp()->Accept( this );
	IRTree::IIRExp* secondExp = lastNodeExp;

	if( expBinOperation->ExpName() == "+" ) {
		lastNodeExp = new CIRMem( new CIRBinOp( PLUS, firstExp, secondExp ) );
	} else if( expBinOperation->ExpName() == "-" ) {
		lastNodeExp = new CIRMem( new CIRBinOp( MINUS, firstExp, secondExp ) );
	} else if( expBinOperation->ExpName() == "*" ) {
		lastNodeExp = new CIRMem( new CIRBinOp( MUL, firstExp, secondExp ) );
	} else if( expBinOperation->ExpName() == "<" ) {
		lastNodeExp = new CIRMem( new CIRBinOp( LT, firstExp, secondExp ) );
	} else { // expBinOperation->ExpName() == "&&"
		lastNodeExp = new CIRMem( new CIRBinOp( AND, firstExp, secondExp ) );
	}
}

void CIRTreeBuilder::visit( const CExpLength* expLength )
{
	expLength->Exp()->Accept( this );
	IIRExp* array = lastNodeExp;

	CIRTemp* length = new CIRTemp( new Temp::CTemp() );

	CIRMove* move = new CIRMove( length, /*instead of nullptr sholuld be arraylength*/nullptr );

	lastNodeExp = new CIRESeq( move, length );
}

void CIRTreeBuilder::visit( const CExpList* expList )
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
	}

	currExpList->Add( lastNodeExp );

	if( expList->ExpRestList() ) {
		expList->ExpRestList()->Accept( this );
	}
}

void CIRTreeBuilder::visit( const CFormalList* formalList )
{
	if( !formalList->Type() && formalList->Id().empty() ) {
		return;
	}

	formalList->Type()->Accept( this );
	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );

	}
}

void CIRTreeBuilder::visit( const CMethodDecl* methodDecl )
{
	currMethod = currClass->GetMethod( methodDecl->Id() );
	( methodDecl->Type() )->Accept( this );

	if( methodDecl->FormalList() ) {
		methodDecl->FormalList()->Accept( this );
	}

	CFrame* newFrame = new CFrame( methodDecl->Id(), currMethod->GetFormalsSize() );
	currFrame = newFrame;

	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this );
	}

	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}
	( methodDecl->Exp() )->Accept( this ); // todo: return label
	
	currMethod = nullptr;
	currFrame = nullptr;
}

void CIRTreeBuilder::visit( const CMethodDeclList* methodDeclList )
{
	if( methodDeclList->MethodDeclList() ) {
		methodDeclList->MethodDeclList()->Accept( this );
	}
	methodDeclList->MethodDecl()->Accept( this );
}

void CIRTreeBuilder::buildIfStatement( const IIRExp* condition, const IIRStm* trueStm, const IIRStm* falseStm )
{
	CIRLabel* trueLabel = new CIRLabel( new Temp::CLabel() );
	CIRLabel* falseLabel = new CIRLabel( new Temp::CLabel() );
	CIRLabel* endLabel = new CIRLabel( new Temp::CLabel() );

	// todo: what we gonna do with trueBLock, falseBlock
	IIRStm* trueBlock = new CIRSeq( trueLabel, new CIRSeq( trueStm, endLabel ) ); // example: true_label; true_stm; end_label;
	IIRStm* falseBlock = new CIRSeq( falseLabel, new CIRSeq( falseStm, endLabel ) );
	lastNodeStm = new CIRCJump( NE, condition, new CIRConst( 0 ), trueLabel, falseLabel ); // if condition != 0 then trueLabel else falseLabel
}

void CIRTreeBuilder::buildWhileStatement( const IIRExp* condition, const IIRStm* body )
{
	CIRLabel* begin = new CIRLabel( new Temp::CLabel() );
	CIRLabel* ifTrue = new CIRLabel( new Temp::CLabel() );
	CIRLabel* end = new CIRLabel( new Temp::CLabel() );

	IIRStm* cycleStep = new CIRSeq( ifTrue, body );
	IIRStm* checkCondition = new CIRCJump( NE, condition, new CIRConst( 0 ), ifTrue, end );

	//IIRStm* jumpToBegin = new CIRJump( nullptr,); // todo: first parameter - ??? and second is list i don't know how it works(

	lastNodeStm = new CIRSeq( begin, new CIRSeq( checkCondition, new CIRSeq( cycleStep, /*jumpToBegin instead nullptr*/ nullptr ) ) );
}

void CIRTreeBuilder::visit( const CStatement* statement )
{
	if( statement->GetStatementType() == "BlockStatement" ) {
		statement->Statements()->Accept( this );
	} else if( statement->GetStatementType() == "IfStatement" ) {
		statement->FirstExpression()->Accept( this );
		IIRExp* condition = lastNodeExp;
		statement->FirstStatement()->Accept( this );
		IIRStm* trueStm = lastNodeStm;
		statement->SecondStatement()->Accept( this );
		IIRStm* falseStm = lastNodeStm;

		buildIfStatement( condition, trueStm, falseStm );
	} else if( statement->GetStatementType() == "WhileStatement" ) {
		statement->FirstExpression()->Accept( this );
		IIRExp* condition = lastNodeExp;
		statement->FirstStatement()->Accept( this );
		IIRStm* body = lastNodeStm;

		buildWhileStatement( condition, body );
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		statement->FirstExpression()->Accept( this );
		IIRExp* toPrint = lastNodeExp;

		lastNodeExp = new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "print" ) ) ), new CIRExpList( toPrint, nullptr ) );
	} else if( statement->GetStatementType() == "AssignStatement" ) {
		const IIRExp* firstExp = frames[frames.size()]->GetVar( statement->Id() )->GetExp( frames[frames.size()]->GetFP() );

		statement->FirstExpression()->Accept( this );
		const IIRExp* secondExp = lastNodeExp;

		lastNodeStm = new CIRMove( firstExp, secondExp );
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		statement->FirstExpression()->Accept( this );
		const IIRExp* firstExp = lastNodeExp;

		statement->SecondExpression()->Accept( this );
		const IIRExp* secondExp = lastNodeExp;

		IIRExp* offset = new CIRBinOp( MUL, firstExp, new CIRConst( CFrame::wordSize ) );
		IIRExp* array = new CIRMem( frames[frames.size()]->GetVar( statement->Id() )->GetExp( frames[frames.size()]->GetFP() ) );
		firstExp = new CIRMem( new CIRBinOp( PLUS, array, offset ) );

		lastNodeStm = new CIRMove( firstExp, secondExp );
	}
}

void CIRTreeBuilder::visit( const CStatementList* statementList )
{
	if( statementList->StatementList() ) {
		( statementList->StatementList() )->Accept( this );
	}
	( statementList->Statement() )->Accept( this );
}

void CIRTreeBuilder::visit( const CType* type )
{
	// nothing to do here
}

void CIRTreeBuilder::visit( const CVarDecl* varDecl )
{
	varDecl->Type()->Accept( this );
	currFrame->AddLocal( new Symbols::CSymbol( varDecl->Id() ) );
}

void CIRTreeBuilder::visit( const CVarDeclList* varDeclList )
{
	if( varDeclList->VarDeclList() ) {
		varDeclList->VarDeclList()->Accept( this );
	}
	varDeclList->VarDecl()->Accept( this );
}

void CIRTreeBuilder::visit( const CFormalRestList* formalRestList )
{
	if( formalRestList->FormalRestList() ) {
		( formalRestList->FormalRestList() )->Accept( this );
	}
	( formalRestList->FormalRest() )->Accept( this );
}

void CIRTreeBuilder::visit( const CFormalRest* formalRest )
{
	formalRest->Type()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpRestList* expRestList )
{
	if( expRestList->ExpRestList() ) {
		( expRestList->ExpRestList() )->Accept( this );
	}
	if( expRestList->ExpRest() ) {
		( expRestList->ExpRest() )->Accept( this );
	}
}

void CIRTreeBuilder::visit( const CExpRest* expRest )
{
	( expRest->Exp() )->Accept( this );

	currExpList->Add( lastNodeExp );
}
