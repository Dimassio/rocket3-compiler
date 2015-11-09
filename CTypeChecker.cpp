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
		// ��� main
	}
	( program->MainClass() )->Accept( this );
	if( !( program->ClassDeclList() ) ) {
		return;
	}
	( program->ClassDeclList() )->Accept( this );
}

void CTypeChecker::visit( const CMainClass* mainClass )
{
	if( !mainClass->Statement() ) {
		// ��� main
	}
	mainClass->Statement()->Accept( this );
}

void CTypeChecker::visit( const CClassDecl* classDecl )
{
	currClass = classDecl->ClassName();
	if( classDecl->ExtendedClassSymbol() != nullptr ) {
		const CClassInfo *currentPredecessor = symbolTable->GetClass( classDecl->ExtendedClassSymbol() );

		while( currentPredecessor != nullptr ) {
			if( currentPredecessor->ExtendedClassSymbol() == classDecl->ClassSymbol() ) {
				// ����������� ����������

			}
			currentPredecessor = symbolTable->GetClass( currentPredecessor->ExtendedClassSymbol() );
		}
	}

	if( classDecl->VarDeclList() != 0 ) {
		classDecl->VarDeclList()->Accept( this );
	}
	if( classDecl->MethodDeclList() != 0 ) {
		classDecl->MethodDeclList()->Accept( this );
	}
	currClass = nullptr;
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
	std::string expName = lastTypeValue;
	std::string methodName = expMethodCall->GetId(); // todo: methods name
	const CClassInfo* expInfo = symbolTable->GetClass( expName );
	if( expInfo->GetMethod( expName ) == nullptr ) {
		// no method with such name
	}
	currMethodCall = expInfo->GetMethod( expName );
	numOfArgument = 0;
	expMethodCall->ExpList()->Accept( this ); // ������ ���������� ������
	lastTypeValue = currMethodCall->Type()->GetTypeName(); // ��������� ��������� ���
	currMethodCall = nullptr;
}

void CTypeChecker::visit( const CExpBinOperation* expBinOperation )
{
	std::string operation = expBinOperation->ExpName();
	expBinOperation->FirstExp()->Accept( this );
	std::string firstExpType = lastTypeValue;
	expBinOperation->SecondExp()->Accept( this );
	std::string secondExpType = lastTypeValue;
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
	lastTypeValue = "boolean"; // ��������� ��������� ���
}

void CTypeChecker::visit( const CExpNewIntArray* expNewIntArray )
{
	expNewIntArray->Exp()->Accept( this );
	if( lastTypeValue != "int" ) {
		// bad type
	}
	lastTypeValue = "int []"; // ��������� ��������� ���
}

void CTypeChecker::visit( const CExpNewCustomType* expNewCustomType )
{
	expNewCustomType->Type()->Accept( this );

	if( symbolTable->GetClass( lastTypeValue ) == nullptr ) { // todo: ��������� ����
		// ������ ���� �� ����������
	}
}

void CTypeChecker::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	if( lastTypeValue != "int []" ) {
		// bad type
	}
	expSquareBrackets->SecondExp()->Accept( this );
	if( lastTypeValue != "int" ) {
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
	if( lastTypeValue != "boolean" ) {
		// bad type
	}
	lastTypeValue = "boolean";
}

void CTypeChecker::visit( const CExpNumber* expNumber )
{
	lastTypeValue = "int";
}

void CTypeChecker::visit( const CExpId* expId )
{
	// ������ � ����� � ����� � ����
}

void CTypeChecker::visit( const CExpSingle* expSingle )
{
	if( expSingle->ExpName() == "True" || expSingle->ExpName() == "False" ) {
		lastTypeValue == "boolean";
	} else {
		lastTypeValue == currClass->ClassName(); //  todo: � ���� ��� ������
	}
}

void CTypeChecker::visit( const CExpLength* expLength )
{
	expLength->Exp()->Accept( this );
	if( lastTypeValue != "string" ) {
		// must be string
	}
	lastTypeValue = "int";
}

void CTypeChecker::visit( const CExpList* expList )  // TODO
{
	if( expList->Exp() ) {
		++numOfArgument;
		expList->Exp()->Accept( this );
		std::string expType = lastTypeValue;
		// using currMethodCall ��������� ��� �� �� ������� numOfArgument - ������� ������ ���������� �� ����
	}
	if( expList->ExpRestList() ) {
		expList->ExpRestList()->Accept( this );
	}
}

void CTypeChecker::visit( const CFormalList* formalList )
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
	currMethod = methodDecl->MethodName(); // todo: change name
	( methodDecl->Type() )->Accept( this );
	( methodDecl->FormalList() )->Accept( this );
	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this );
	}
	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}
	( methodDecl->Exp() )->Accept( this );
	currMethod = nullptr;
}

void CTypeChecker::visit( const CMethodDeclList* methodDeclList )
{
	if( methodDeclList->MethodDeclList() ) {
		methodDeclList->MethodDeclList()->Accept( this );
	}
	methodDeclList->MethodDecl()->Accept( this );
}

void CTypeChecker::visit( const CStatement* statement ) 
{
	if( statement->GetStatementType() == "BlockStatement" ) {
		statement->Statements()->Accept( this );
	} else if( statement->GetStatementType() == "IfStatement" ) {
		statement->FirstExpression()->Accept( this );
		if( lastTypeValue != "boolean" ) {
			// wrong type in condition
		}
		statement->FirstStatement()->Accept( this );
		statement->SecondStatement()->Accept( this );
	} else if( statement->GetStatementType() == "WhileStatement" ) {  
		statement->FirstExpression()->Accept( this );
		if( lastTypeValue != "boolean" ) {
			// wrong type in condition
		}
		statement->FirstStatement()->Accept( this );
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		statement->FirstExpression()->Accept( this );
		if( lastTypeValue != "int" ) {
			// wrong type in println
		}
	} else if( statement->GetStatementType() == "AssignStatement" ) {

		std::cout << statement->Symbol()->String();

		statement->FirstExpression()->Accept( this );

	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {

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
	lastTypeValue = type->GetTypeName();
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