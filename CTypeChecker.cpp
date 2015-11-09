#include "CTypeChecker.h"
#include "StaticVariables.h"

#ifndef CTYPECHECKER_CPP_INCLUDED
#define CTYPECHECKER_CPP_INCLUDED

CTypeChecker::CTypeChecker()
{
}

void CTypeChecker::visit( const CProgram* program )
{
	std::cout << "Program has started:" << std::endl << std::endl;
	if( program->MainClass() == nullptr ) {
		// нет main
	}
	( program->MainClass() )->Accept( this );
	if( !( program->ClassDeclList() ) ) {
		return;
	}
	( program->ClassDeclList() )->Accept( this );
}

void CTypeChecker::visit( const CMainClass* mainClass )
{
	if (!mainClass->Statement()) {
		// нет main
	}
	mainClass->Statement()->Accept( this );
}

void CTypeChecker::visit(const CClassDecl* classDecl)
{
	if (classDecl->ExtendedClassSymbol() != nullptr) {
		const CClassInfo *currentPredecessor = symbolTable->GetClass(classDecl->ExtendedClassSymbol());

		while (currentPredecessor != nullptr) {
			if (currentPredecessor->ExtendedClassSymbol() == classDecl->ClassSymbol()) {
				// Циклическая зависимось

			}
			currentPredecessor = symbolTable->GetClass(currentPredecessor->ExtendedClassSymbol());
		}
	}

	if (classDecl->VarDeclList() != 0) {
		classDecl->VarDeclList()->Accept(this);
	}
	if (classDecl->MethodDeclList() != 0) {
		classDecl->MethodDeclList()->Accept(this);
	}
}

void CTypeChecker::visit( const CClassDeclList* classDeclList )
{
	if( classDeclList->ClassDeclList() ) {
		classDeclList->ClassDeclList()->Accept( this );
	}
	classDeclList->ClassDecl()->Accept( this );
}

void CTypeChecker::visit( const CExp* exp )
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

void CTypeChecker::visit( const CExpMethodCall* expMethodCall ) 
{
	expMethodCall->Exp()->Accept( this );
	std::string expName = lastTypeValue->GetTypeName();
	expMethodCall->ExpList()->Accept( this );
	std::string methodName = expMethodCall->GetId(); // todo: methods name
	const CClassInfo* expInfo = symbolTable->GetClass( expName );
	if( expInfo->GetMethod( expName ) == nullptr ) {
		// no method with such name
	}
	currMethod = expInfo->GetMethod( expName );
}

void CTypeChecker::visit( const CExpBinOperation* expBinOperation ) 
{
	std::string operation = expBinOperation->ExpName();
	expBinOperation->FirstExp()->Accept( this );
	std::string firstExpType = lastTypeValue->GetTypeName();
	expBinOperation->SecondExp()->Accept( this );
	std::string secondExpType = lastTypeValue->GetTypeName();
	if( operation == "&&" ) {
		if( !( firstExpType == "boolean" && secondExpType == "boolean" ) ) {
			// bad type
		}
	}
	if( operation == "-" || operation == "+" || operation == "*" || operation == "/" || operation == "<" ) {
		if( !( firstExpType == "int" && secondExpType == "int" ) ) {
			// bad type
		}
	}
}

void CTypeChecker::visit( const CExpNewIntArray* expNewIntArray ) 
{
	expNewIntArray->Exp()->Accept( this );
	if( lastTypeValue->GetTypeName() != "int" ) {
		// bad type
	}
}

void CTypeChecker::visit( const CExpNewCustomType* expNewCustomType ) 
{
	expNewCustomType->Type()->Accept( this );
	
	if (symbolTable->GetClass(lastTypeValue->GetTypeName()) == nullptr) {
		// Такого типа не существует
	}
}

void CTypeChecker::visit( const CExpSquareBrackets* expSquareBrackets ) 
{
	expSquareBrackets->FirstExp()->Accept( this );
	if( lastTypeValue->GetTypeName() != "int []" ) {
		// bad type
	}
	expSquareBrackets->SecondExp()->Accept( this );
	if( lastTypeValue->GetTypeName() != "int" ) {
		// bad type
	}
}

void CTypeChecker::visit( const CExpRoundBrackets* expRoundBrackets )
{
	expRoundBrackets->Exp()->Accept( this );
}

void CTypeChecker::visit( const CExpNot* expNot )
{
	expNot->Exp()->Accept( this );
	if( lastTypeValue->GetTypeName() != "boolean" ) {
		// bad type
	}
}

void CTypeChecker::visit( const CExpNumber* expNumber )
{
}

void CTypeChecker::visit( const CExpId* expId ) 
{
}

void CTypeChecker::visit( const CExpSingle* expSingle ) 
{
}

void CTypeChecker::visit( const CExpLength* expLength ) 
{
	expLength->Exp()->Accept( this );
	if( lastTypeValue->GetTypeName() != "string" ) {
		// must be string
	}
}

void CTypeChecker::visit( const CExpList* expList )  // +
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
		std::string expType = lastTypeValue->GetTypeName();
		if( currMethod->GetArgument( expType ) == nullptr ) {
			// no such argument
		}
	}
	if( expList->ExpRestList() ) {
		expList->ExpRestList()->Accept( this );
	}
}

void CTypeChecker::visit( const CFormalList* formalList ) // +
{
	std::string id = formalList->Symbol()->String();
	if( !formalList->Type() && id == "" && !formalList->FormalRestList() ) {
		return;
	}
	formalList->Type()->Accept( this );
	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );
	}
}

void CTypeChecker::visit( const CMethodDecl* methodDecl )
{
	( methodDecl->Type() )->Accept( this );
	( methodDecl->FormalList() )->Accept( this );
	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this );
	}
	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}
	( methodDecl->Exp() )->Accept( this );
	currMethod = methodDecl->MethodName(); // todo: method name
}

void CTypeChecker::visit( const CMethodDeclList* methodDeclList ) // +
{
	if( methodDeclList->MethodDeclList() ) {
		methodDeclList->MethodDeclList()->Accept( this );
	}
	methodDeclList->MethodDecl()->Accept( this );
}

void CTypeChecker::visit( const CStatement* statement ) // +
{
	if( statement->GetStatementType() == "BlockStatement" ) {

		statement->Statements()->Accept( this );

	} else if( statement->GetStatementType() == "IfStatement" ) { // +

		statement->FirstExpression()->Accept( this );

		statement->FirstStatement()->Accept( this );


		statement->SecondStatement()->Accept( this );

	} else if( statement->GetStatementType() == "WhileStatement" ) { // +


		statement->FirstExpression()->Accept( this );

		statement->FirstStatement()->Accept( this );

	} else if( statement->GetStatementType() == "PrintlnStatement" ) { // +
		statement->FirstExpression()->Accept( this );

	} else if( statement->GetStatementType() == "AssignStatement" ) { // +

		std::cout << statement->Symbol()->String();

		statement->FirstExpression()->Accept( this );

	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) { // +

		statement->FirstExpression()->Accept( this );

		statement->SecondExpression()->Accept( this );
	}
}

void CTypeChecker::visit( const CStatementList* statementList )
{
	if( statementList->StatementList() ) {
		( statementList->StatementList() )->Accept( this );
	}
	( statementList->Statement() )->Accept( this );
}

void CTypeChecker::visit( const CType* type )
{
	// todo: lastTypeValue = type->GetTypeName();
}

void CTypeChecker::visit( const CVarDecl* varDecl )
{
	( varDecl->Type() )->Accept( this );
}

void CTypeChecker::visit( const CVarDeclList* varDeclList )
{
	if( varDeclList->VarDeclList() ) {
		varDeclList->VarDeclList()->Accept( this );
	}
	varDeclList->VarDecl()->Accept( this );
}

void CTypeChecker::visit( const CFormalRestList* formalRestList )
{
	if( formalRestList->FormalRestList() ) {
		( formalRestList->FormalRestList() )->Accept( this );
	}
	( formalRestList->FormalRest() )->Accept( this );
}

void CTypeChecker::visit( const CFormalRest* formalRest )
{
	formalRest->Type()->Accept( this );
}

void CTypeChecker::visit( const CExpRestList* expRestList )
{
	if( expRestList->ExpRestList() ) {
		( expRestList->ExpRestList() )->Accept( this );
	}
	if( expRestList->Exp() ) {
		( expRestList->Exp() )->Accept( this );
	}
}

void CTypeChecker::visit( const CExpRest* expRest )
{
	( expRest->Exp() )->Accept( this );
}

#endif