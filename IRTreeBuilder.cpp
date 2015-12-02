#include "IRTreeBuilder.h"
#include "CStm.h"
#include "CExp.h"
#include "Common.h"
#include "Symbols.h"
#include "StaticVariables.h"

using namespace Frame;

CIRTreeBuilder::CIRTreeBuilder(const CTable* _symbTable) :
	symbTable(_symbTable)
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
	if( classDecl->VarDeclList() != 0 ) {
		classDecl->VarDeclList()->Accept( this );
	}
	if( classDecl->MethodDeclList() != 0 ) {
		classDecl->MethodDeclList()->Accept( this );
	}
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
	expMethodCall->ExpList()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpNewIntArray* expNewIntArray )
{
	expNewIntArray->Exp()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpNewCustomType* expNewCustomType )
{
	expNewCustomType->Type()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	IRTree::IIRExp* firstExp = lastNodeExp;

	expSquareBrackets->SecondExp()->Accept( this );
	IRTree::IIRExp* rightExp = lastNodeExp;

	IIRExp* offset = new CIRBinOp(MUL, rightExp, new CIRConst(CFrame::wordSize));
	lastNodeExp = new CIRMem(new CIRBinOp(PLUS, firstExp, offset));
}

void CIRTreeBuilder::visit( const CExpRoundBrackets* expRoundBrackets )
{
	expRoundBrackets->Exp()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpNot* expNot )
{
	expNot->Exp()->Accept( this );
	IRTree::IIRExp* exp = lastNodeExp;

	lastNodeExp = new CIRMem(new CIRBinOp(NOT, new CIRConst(0), exp));
}

void CIRTreeBuilder::visit( const CExpNumber* expNumber )
{
	lastNodeExp = new CIRConst(expNumber->Number());
}

void CIRTreeBuilder::visit( const CExpId* expId )
{
}

void CIRTreeBuilder::visit( const CExpSingle* expSingle )
{
}

void CIRTreeBuilder::visit( const CExpBinOperation* expBinOperation )
{
	expBinOperation->FirstExp()->Accept( this );
	IRTree::IIRExp* firstExp = lastNodeExp;

	expBinOperation->SecondExp()->Accept(this);
	IRTree::IIRExp* rightExp = lastNodeExp;

	if (expBinOperation->ExpName() == "+") {
		lastNodeExp = new CIRMem(new CIRBinOp(PLUS, firstExp, rightExp));
	}
	else if (expBinOperation->ExpName() == "-") {
		lastNodeExp = new CIRMem(new CIRBinOp(MINUS, firstExp, rightExp));
	}
	else if (expBinOperation->ExpName() == "*") {
		lastNodeExp = new CIRMem(new CIRBinOp(MUL, firstExp, rightExp));
	}
	else if (expBinOperation->ExpName() == "<") {
		lastNodeExp = new CIRMem(new CIRBinOp(LE, firstExp, rightExp));
	}
	else { // expBinOperation->ExpName() == "&&"
		lastNodeExp = new CIRMem(new CIRBinOp(AND, firstExp, rightExp));
	}
}

void CIRTreeBuilder::visit( const CExpLength* expLength )
{
	expLength->Exp()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpList* expList )
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
	}
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
	( methodDecl->Type() )->Accept( this );

	if( methodDecl->FormalList() ) {
		methodDecl->FormalList()->Accept( this );
	}
	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this );
	}
	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}
	( methodDecl->Exp() )->Accept( this );

}

void CIRTreeBuilder::visit( const CMethodDeclList* methodDeclList )
{
	if( methodDeclList->MethodDeclList() ) {
		methodDeclList->MethodDeclList()->Accept( this );
	}
	methodDeclList->MethodDecl()->Accept( this );
}

void CIRTreeBuilder::visit( const CStatement* statement )
{
	if( statement->GetStatementType() == "BlockStatement" ) {
		statement->Statements()->Accept( this );
	} else if( statement->GetStatementType() == "IfStatement" ) {
		statement->FirstExpression()->Accept( this );
		statement->FirstStatement()->Accept( this );
		statement->SecondStatement()->Accept( this );
	} else if( statement->GetStatementType() == "WhileStatement" ) {
		statement->FirstExpression()->Accept( this );
		statement->FirstStatement()->Accept( this );
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		statement->FirstExpression()->Accept( this );
	} else if( statement->GetStatementType() == "AssignStatement" ) {
		const IIRExp* firstExp = frames[frames.size()]->GetVar(statement->Id())->GetExp(frames[frames.size()]->GetFP());

		statement->FirstExpression()->Accept(this);
		const IIRExp* secondExp = lastNodeExp;

		lastNodeStm = new CIRMove(firstExp, secondExp);
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		statement->FirstExpression()->Accept(this);
		const IIRExp* firstExp = lastNodeExp;

		statement->SecondExpression()->Accept(this);
		const IIRExp* secondExp = lastNodeExp;

		IIRExp* offset = new CIRBinOp(MUL, firstExp, new CIRConst(CFrame::wordSize));
		IIRExp* array = new CIRMem(frames[frames.size()]->GetVar(statement->Id())->GetExp(frames[frames.size()]->GetFP()));
		firstExp = new CIRMem(new CIRBinOp(PLUS, array, offset));

		lastNodeStm = new CIRMove(firstExp, secondExp);
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
}

void CIRTreeBuilder::visit( const CVarDecl* varDecl )
{
	varDecl->Type()->Accept( this );
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
	if( expRestList->Exp() ) {
		( expRestList->Exp() )->Accept( this );
	}
}

void CIRTreeBuilder::visit( const CExpRest* expRest )
{
	( expRest->Exp() )->Accept( this );
}
