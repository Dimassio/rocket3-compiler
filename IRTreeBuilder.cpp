#include "IRTreeBuilder.h"
#include "CStm.h"
#include "CExp.h"
#include "Common.h"
#include "Symbols.h"
#include "StaticVariables.h"
#include "Temp.h"
#include "Translate.h"

using namespace Frame;

CIRTreeBuilder::CIRTreeBuilder( const CTable* _symbolTable ):
	symbolTable( _symbolTable )
{
}

std::vector<Frame::CFrame*> CIRTreeBuilder::GetFrames() const
{
	return frames;
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
	// CurrClass and CurrMethod we do not set for main only
	CFrame* newFrame = new CFrame( "main", 1 );
	frames.push_back( newFrame );
	currFrame = newFrame; // we now in main

	if( mainClass->Statement() ) {
		mainClass->Statement()->Accept( this );
	}
	// Для совместимости с Exp
	// В Main всего один Statement, левое поддерево пусть будет пустое
	currFrame->HangToRoot( new CIRESeq( lastNodeStm, nullptr ) );

	currFrame = nullptr; // out of main
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
	CIRExpList* prevCurExpList = currExpList;

	expMethodCall->Exp()->Accept( this );
	IIRExp* expForCall = lastNodeExp;
	currExpList = new CIRExpList( lastNodeExp, nullptr ); // adding "this"

	expMethodCall->ExpList()->Accept( this );

	CIRName* functionName = new CIRName( new Temp::CLabel( symbolStorage.Get( expMethodCall->Id() ) ) );

	CIRCall* newCall = new CIRCall( functionName, currExpList );
	CIRTemp* temp = new CIRTemp( new Temp::CTemp() );
	IIRStm* move = new CIRMove( temp, newCall );
	currExpList = prevCurExpList;
	lastNodeExp = new CIRESeq( move, temp );
}

void CIRTreeBuilder::visit( const CExpNewIntArray* expNewIntArray )
{
	// a = new int[exp]
	// malloc (exp * wordSize)
	// memset(mallocExp, 0, exp)
	expNewIntArray->Exp()->Accept( this );
	//malloc:
	IIRExp* size = new CIRBinOp( PLUS, lastNodeExp, new CIRConst( 1 ) );
	IIRExp* allocationSize = new CIRBinOp( MUL, size, new CIRConst( currFrame->wordSize ) );
	IIRExp* mallocExp = new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "malloc" ) ) ), new CIRExpList( allocationSize, nullptr ) );
	IIRExp* temp = new CIRTemp( new Temp::CTemp() );
	IIRStm* move = new CIRMove( temp, mallocExp );
	// memset:
	CIRExpList* memsetArgs = new CIRExpList( mallocExp, nullptr );
	memsetArgs->Add( new CIRConst( 0 ) );
	memsetArgs->Add( size );
	IIRExp* memsetCall = new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "memset" ) ) ), memsetArgs );
	// making new ESEQ node:
	Translate::CExpConverter memsetConverter( memsetCall );
	IIRStm* newIntArrStm = new CIRSeq( move, memsetConverter.ToStm() ); // seq = move + memset
	lastNodeExp = new CIRESeq( newIntArrStm, temp ); // то есть возвращается тут mallocExp
}

void CIRTreeBuilder::visit( const CExpNewCustomType* expNewCustomType )
{
	expNewCustomType->Type()->Accept( this ); // b = new MyClass()
	// malloc:
	IIRExp* allocationSize = new CIRBinOp( MUL, new CIRConst( currFrame->GetFieldCount() + 1 ), new CIRConst( currFrame->wordSize ) );
	IIRExp* mallocExp = new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "malloc" ) ) ), new CIRExpList( allocationSize, nullptr ) );
	IIRExp* temp = new CIRTemp( new Temp::CTemp() );
	IIRStm* move = new CIRMove( temp, mallocExp ); // malloc result to Temp
	lastNodeExp = new CIRESeq( move, temp );
}

void CIRTreeBuilder::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	IIRExp* firstExp = lastNodeExp;

	expSquareBrackets->SecondExp()->Accept( this );
	IIRExp* secondExp = lastNodeExp;

	IIRExp* offset = new CIRBinOp( MUL, secondExp, new CIRConst( CFrame::wordSize ) );
	lastNodeExp = new CIRMem( new CIRBinOp( PLUS, firstExp, offset ) );
}

void CIRTreeBuilder::visit( const CExpRoundBrackets* expRoundBrackets ) // ?
{
	expRoundBrackets->Exp()->Accept( this );
}

void CIRTreeBuilder::visit( const CExpNot* expNot )
{
	expNot->Exp()->Accept( this );
	IIRExp* exp = lastNodeExp;
	// NOT exp
	// запомнить! отрицание применяем ко второму аргументу
	lastNodeExp = new CIRMem( new CIRBinOp( NOT, new CIRConst( 0 ), exp ) );
}

void CIRTreeBuilder::visit( const CExpNumber* expNumber )
{
	lastNodeExp = new CIRConst( expNumber->Number() );
}

void CIRTreeBuilder::visit( const CExpId* expId )
{
	lastNodeExp = const_cast< IIRExp* >( currFrame->GetVar( expId->Id() )->GetExp( currFrame->GetFP() ) );
}

void CIRTreeBuilder::visit( const CExpSingle* expSingle )
{
	if( expSingle->ExpName() == "this" ) {
		lastNodeExp = new CIRName( new Temp::CLabel( currClass->ClassSymbol() ) );
	}
	if( expSingle->ExpName() == "True" ) {
		lastNodeExp = new CIRConst( 1 );
	}
	if( expSingle->ExpName() == "False" ) {
		lastNodeExp = new CIRConst( 0 );
	}
}

void CIRTreeBuilder::visit( const CExpBinOperation* expBinOperation )
{
	expBinOperation->FirstExp()->Accept( this );
	IIRExp* firstExp = lastNodeExp;

	expBinOperation->SecondExp()->Accept( this );
	IIRExp* secondExp = lastNodeExp;

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

	IIRExp* sizeofCall = new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "sizeof" ) ) ), new CIRExpList( array, nullptr ) );
	CIRTemp* length = new CIRTemp( new Temp::CTemp() );
	// length = sizeof(array) / wordsize
	CIRMove* move = new CIRMove( length, new CIRMem( new CIRBinOp( DIV, sizeofCall, new CIRConst( currFrame->wordSize ) ) ) );
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

	if( currFrame != nullptr ) {
		currFrame->AddFormal( symbolStorage.Get( formalList->Id() ) );
	}

	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );

	}
}

void CIRTreeBuilder::visit( const CMethodDecl* methodDecl )
{
	currMethod = currClass->GetMethod( methodDecl->Id() );

	CFrame* newFrame = new CFrame( methodDecl->Id(), currMethod->GetFormalsSize() );
	frames.push_back( newFrame );
	currFrame = newFrame;

	std::vector<const CClassInfo*> classNames;
	const CClassInfo* currentClass = symbolTable->GetClass( currClass->ClassName() );
	while( currentClass != nullptr ) {
		classNames.push_back( currentClass );
		if( currentClass->ExtendedClassSymbol() != nullptr ) {
			currentClass = symbolTable->GetClass( currentClass->ExtendedClassName() );
		} else {
			currentClass = nullptr;
		}
	}

	// Добавляем поля класса к фрейму
	int counter = 0;
	for( int i = classNames.size() - 1; i >= 0; i-- ) {
		for( const auto& variable : classNames.at( i )->GetVariables() ) {
			currFrame->AddFormal( variable.first );
			++counter;
		}
	}
	currFrame->SetFieldCount( counter );

	( methodDecl->Type() )->Accept( this );

	if( methodDecl->FormalList() ) {
		methodDecl->FormalList()->Accept( this );
	}

	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this ); //  adding locals HERE
	}

	lastNodeStm = nullptr;
	lastNodeExp = nullptr;
	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}

	IIRStm* lastStm = lastNodeStm;
	// return:
	( methodDecl->Exp() )->Accept( this );
	CIRTemp* returnValue = new CIRTemp( new Temp::CTemp( new Symbols::CSymbol( "ReturnValue" ) ) );
	CIRESeq* eseq = new CIRESeq( lastStm, lastNodeExp );
	currFrame->HangToRoot( eseq ); // подвесили дерево фрейма

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

void CIRTreeBuilder::visit( const CStatement* statement )
{
	if( statement->GetStatementType() == "BlockStatement" ) {
		statement->Statements()->Accept( this );
	} else if( statement->GetStatementType() == "IfStatement" ) {
		statement->FirstExpression()->Accept( this );
		const IIRExp* condition = lastNodeExp;
		lastNodeExp = nullptr;
		lastNodeStm = nullptr;
		Temp::CLabel* trueLabelTemp = new Temp::CLabel();
		Temp::CLabel* falseLabelTemp = new Temp::CLabel();
		Temp::CLabel* endLabelTemp = new Temp::CLabel();
		CIRLabel* trueLabel = new CIRLabel( trueLabelTemp );
		CIRLabel* falseLabel = new CIRLabel( falseLabelTemp );
		CIRLabel* endLabel = new CIRLabel( endLabelTemp );
		CIRJump* trueJumpToEnd = new CIRJump( endLabelTemp ); // from if
		CIRJump* falseJumpToEnd = new CIRJump( endLabelTemp ); // from false

		statement->FirstStatement()->Accept( this );
		IIRStm* trueStm = new CIRSeq( trueLabel,
									  new CIRSeq( lastNodeStm, trueJumpToEnd ) );
		lastNodeExp = nullptr;
		lastNodeStm = nullptr;
		IIRStm* falseStm = 0;
		if( statement->SecondStatement() != 0 ) {
			statement->SecondStatement()->Accept( this );
			falseStm = new CIRSeq( falseLabel,
								   new CIRSeq( lastNodeStm, falseJumpToEnd ) );
			lastNodeExp = nullptr;
			lastNodeStm = nullptr;
		}
		Translate::CExpConverter converter( condition );
		lastNodeStm = new CIRSeq( converter.ToConditional( trueLabelTemp, falseLabelTemp ),
								  new CIRSeq( trueStm,
											  new CIRSeq( falseStm, endLabel ) ) );
	} else if( statement->GetStatementType() == "WhileStatement" ) {
		Temp::CLabel* beforeConditionLabelTemp = new Temp::CLabel();
		Temp::CLabel* inLoopLabelTemp = new Temp::CLabel();
		Temp::CLabel* endLabelTemp = new Temp::CLabel();
		CIRLabel* beforeConditionLabel = new CIRLabel( beforeConditionLabelTemp );
		CIRLabel* inLoopLabel = new CIRLabel( inLoopLabelTemp );
		CIRLabel* endLabel = new CIRLabel( endLabelTemp );

		statement->FirstExpression()->Accept( this );
		Translate::CExpConverter expConverter( lastNodeExp );
		const IIRStm* whileStm = expConverter.ToConditional( inLoopLabelTemp, endLabelTemp );
		lastNodeExp = nullptr;
		lastNodeStm = nullptr;
		IIRStm* conditionStm = new CIRSeq( beforeConditionLabel, new CIRSeq( whileStm, inLoopLabel ) );

		statement->FirstStatement()->Accept( this );
		lastNodeStm = new CIRSeq( conditionStm,
								  new CIRSeq( lastNodeStm,
											  new CIRSeq( new CIRJump( beforeConditionLabelTemp ), endLabel ) ) );
		lastNodeExp = nullptr;
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		statement->FirstExpression()->Accept( this );
		IIRExp* toPrint = lastNodeExp;
		IIRExp* printCall = new CIRCall( new CIRName( new Temp::CLabel( symbolStorage.Get( "print" ) ) ), new CIRExpList( toPrint, nullptr ) );
		Translate::CExpConverter printConverter( printCall );
		lastNodeStm = const_cast< IIRStm* >( printConverter.ToStm() );
	} else if( statement->GetStatementType() == "AssignStatement" ) {
		const IIRExp* firstExp = currFrame->GetVar( statement->Id() )->GetExp( currFrame->GetFP() );

		statement->FirstExpression()->Accept( this );
		const IIRExp* secondExp = lastNodeExp;

		lastNodeStm = new CIRMove( firstExp, secondExp );
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		statement->FirstExpression()->Accept( this );
		const IIRExp* firstExp = lastNodeExp;

		statement->SecondExpression()->Accept( this );
		const IIRExp* secondExp = lastNodeExp;

		IIRExp* offset = new CIRBinOp( MUL, firstExp, new CIRConst( CFrame::wordSize ) );
		IIRExp* array = new CIRMem( currFrame->GetVar( statement->Id() )->GetExp( currFrame->GetFP() ) );
		firstExp = new CIRMem( new CIRBinOp( PLUS, array, offset ) );

		lastNodeStm = new CIRMove( firstExp, secondExp );
	}
}

void CIRTreeBuilder::visit( const CStatementList* statementList )
{
	if( statementList->StatementList() ) {
		( statementList->StatementList() )->Accept( this );
	}

	IIRStm* firstStm = lastNodeStm;

	( statementList->Statement() )->Accept( this );

	IIRStm* secondStm = lastNodeStm;
	lastNodeStm = new CIRSeq( firstStm, secondStm );
}

void CIRTreeBuilder::visit( const CType* type )
{
	// nothing to do here
}

void CIRTreeBuilder::visit( const CVarDecl* varDecl )
{
	varDecl->Type()->Accept( this );

	if( currFrame != nullptr ) {
		currFrame->AddLocal( symbolStorage.Get( varDecl->Id() ) );
	}
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

	if( currFrame != nullptr ) {
		currFrame->AddFormal( symbolStorage.Get( formalRest->Id() ) );
	}
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
