#include "CTypeChecker.h"
#include "StaticVariables.h"
#include "CMiniJException.h"
#include <string>

#ifndef CTYPECHECKER_CPP_INCLUDED
#define CTYPECHECKER_CPP_INCLUDED

CTypeChecker::CTypeChecker( const CTable* _symbTable )
{
	symbolTable = _symbTable;
	errorOccured = false;
}

void CTypeChecker::visit( const CProgram* program )
{
	program->MainClass()->Accept( this );

	if( !( program->ClassDeclList() ) ) {
		return;
	}
	( program->ClassDeclList() )->Accept( this );
}

void CTypeChecker::visit( const CMainClass* mainClass )
{
	if( mainClass->Statement() ) {
		mainClass->Statement()->Accept( this );
	}
}

void CTypeChecker::visit( const CClassDecl* classDecl )
{
	currClass = symbolTable->GetClass( classDecl->ClassId() );
	if( !classDecl->ExtendedClassId().empty() ) {
		const CClassInfo *currentPredecessor = symbolTable->GetClass( classDecl->ExtendedClassId() );
		while( currentPredecessor != nullptr ) {
			if( currentPredecessor->ExtendedClassSymbol()->String() == classDecl->ClassId() ) {
				throw CMiniJException( std::to_string(classDecl->yylineno) + " Cyclic dependance" );
				errorOccured = true;
				break;
			}
			currentPredecessor = symbolTable->GetClass( currentPredecessor->ExtendedClassName() );
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

bool CTypeChecker::isPODName( std::string name )
{
	return name == "int" || name == "void" || name == "boolean" || name == "string" || name == "int []";
}

void CTypeChecker::visit( const CExpMethodCall* expMethodCall )
{
	expMethodCall->Exp()->Accept( this ); // exp - for object
	std::string expName = lastTypeValue;
	if( isPODName( expName ) ) {
		throw CMiniJException( std::to_string( expMethodCall->yylineno) + " Can't call method with pod type" );
		errorOccured = true;
	}
	std::string methodName = expMethodCall->Id();
	const CClassInfo* expInfo = symbolTable->GetClass( expName );
	if( expInfo->GetMethod( methodName ) == nullptr ) {
		throw CMiniJException( std::to_string( expMethodCall->yylineno) + " No method with such name" );
		errorOccured = true;
	}
	currMethodCall.push( expInfo->GetMethod( methodName ) );
	numOfArgument.push( 0 );
	expMethodCall->ExpList()->Accept( this ); // Разбор аргументов метода
	lastTypeValue = currMethodCall.top()->Type()->GetTypeName(); // Запомнием последний тип
	currMethodCall.pop();
	numOfArgument.pop();
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
			throw CMiniJException( std::to_string( expBinOperation->yylineno) + " Bad type" );
			errorOccured = true;
		}

		lastTypeValue = "boolean"; // Запомнием последний тип
	} else if( operation == "-" || operation == "+" || operation == "*" || operation == "/" || operation == "<" ) {
		if( !( firstExpType == "int" && secondExpType == "int" ) ) {
			throw CMiniJException( std::to_string( expBinOperation->yylineno) + " Bad type" );
			errorOccured = true;
		}

		if( operation == "<" ) {
			lastTypeValue = "boolean";
		} else {
			lastTypeValue = "int"; // Запомнием последний тип
		}
	}
}

void CTypeChecker::visit( const CExpNewIntArray* expNewIntArray )
{
	expNewIntArray->Exp()->Accept( this );
	if( lastTypeValue != "int" ) {
		throw CMiniJException( std::to_string( expNewIntArray->yylineno) + " Bad type" );
		errorOccured = true;
	}
	lastTypeValue = "int []"; // Запомнием последний тип
}

void CTypeChecker::visit( const CExpNewCustomType* expNewCustomType )
{
	expNewCustomType->Type()->Accept( this );

	if( symbolTable->GetClass( lastTypeValue ) == nullptr ) {
		throw CMiniJException( std::to_string( expNewCustomType->yylineno) + " Bad type" );
		errorOccured = true;
	}
}

void CTypeChecker::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	if( lastTypeValue != "int []" ) {
		throw CMiniJException( std::to_string( expSquareBrackets->yylineno) + " Bad type" );
		errorOccured = true;
	}
	expSquareBrackets->SecondExp()->Accept( this );
	if( lastTypeValue != "int" ) {
		throw CMiniJException( std::to_string( expSquareBrackets->yylineno) + " Bad type" );
		errorOccured = true;
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
		throw CMiniJException( std::to_string( expNot->yylineno) + " Bad type" );
		errorOccured = true;
	}
	lastTypeValue = "boolean";
}

void CTypeChecker::visit( const CExpNumber* expNumber )
{
	lastTypeValue = "int";
}

void CTypeChecker::visit( const CExpId* expId )
{
	if( currMethod->GetLocalVariable( expId->Id() ) != nullptr ) {
		lastTypeValue = currMethod->GetLocalVariable( expId->Id() )->Type()->GetTypeName();
	} else if( currMethod->GetArgument( expId->Id() ) != nullptr ) {
		lastTypeValue = currMethod->GetArgument( expId->Id() )->Type()->GetTypeName();
	} else if( currClass->GetVariable( expId->Id() ) != nullptr ) {
		lastTypeValue = currClass->GetVariable( expId->Id() )->Type()->GetTypeName();
	} else {
		throw CMiniJException( std::to_string( expId->yylineno) + " Undeclared variable" );
		errorOccured = true;
	}
}

void CTypeChecker::visit( const CExpSingle* expSingle )
{
	if( expSingle->ExpName() == "True" || expSingle->ExpName() == "False" ) {
		lastTypeValue = "boolean";
	} else {
		lastTypeValue = currClass->ClassName();
	}
}

void CTypeChecker::visit( const CExpLength* expLength )
{
	expLength->Exp()->Accept( this );
	if( lastTypeValue != "string" && lastTypeValue != "int []" ) {
		throw CMiniJException( std::to_string( expLength->yylineno) + " Must be string" );
		errorOccured = true;
	}
	lastTypeValue = "int";
}

void CTypeChecker::visit( const CExpList* expList ) // Аргументы метода 
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
		if( currMethodCall.top()->GetArgument( numOfArgument.top() ) == nullptr ) { // сюда зашло, если хотя бы 1 аргумент передали в метод
			throw CMiniJException( std::to_string( expList->yylineno) + " argument type mismatch in " + 
								   currMethodCall.top()->MethodSymbol()->String() + ", argument #" + std::to_string( numOfArgument.top() + 1));
			errorOccured = true;
		} else
			if( lastTypeValue != currMethodCall.top()->GetArgument( numOfArgument.top() )->Type()->GetTypeName() ) {
				throw CMiniJException( std::to_string( expList->yylineno ) + " argument type mismatch in " +
									   currMethodCall.top()->MethodSymbol()->String() + ", argument #" + std::to_string( numOfArgument.top() + 1 ));
				errorOccured = true;
			}
		int num = numOfArgument.top() + 1;
		numOfArgument.pop();
		numOfArgument.push( num );
	}
	if( expList->ExpRestList() ) {
		expList->ExpRestList()->Accept( this );
	}
}

void CTypeChecker::visit( const CFormalList* formalList )
{
	std::string id = formalList->Id();
	if( !formalList->Type() && id.empty() ) {
		return;
	}
	formalList->Type()->Accept( this );
	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );
	}
}

void CTypeChecker::visit( const CMethodDecl* methodDecl )
{
	currMethod = currClass->GetMethod( methodDecl->Id() );
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
			throw CMiniJException( std::to_string( statement->yylineno )+ " Wrong type in condition");
			errorOccured = true;
		}
		statement->FirstStatement()->Accept( this );
		statement->SecondStatement()->Accept( this );
	} else if( statement->GetStatementType() == "WhileStatement" ) {
		statement->FirstExpression()->Accept( this );
		if( lastTypeValue != "boolean" ) {
			throw CMiniJException( std::to_string( statement->yylineno) + " Wrong type in condition" );
			errorOccured = true;
		}
		statement->FirstStatement()->Accept( this );
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		statement->FirstExpression()->Accept( this );

		if( lastTypeValue != "int" ) {
			throw CMiniJException( std::to_string( statement->yylineno) + " Wrong type in println" );
			errorOccured = true;
		}
	} else if( statement->GetStatementType() == "AssignStatement" ) {
		const CType* idType;

		if( currMethod->GetLocalVariable( statement->Id() ) != nullptr ) {
			idType = currMethod->GetLocalVariable( statement->Id() )->Type();
		} else if( currMethod->GetArgument( statement->Id() ) != nullptr ) {
			idType = currMethod->GetArgument( statement->Id() )->Type();
		} else if( currClass->GetVariable( statement->Id() ) != nullptr ) {
			idType = currClass->GetVariable( statement->Id() )->Type();
		} else {
			throw CMiniJException( std::to_string( statement->yylineno )+ " Undeclared variable" );
			errorOccured = true;
			return; // instead of exception - just for now
		}

		statement->FirstExpression()->Accept( this );

		if( idType->GetTypeName() != lastTypeValue ) {
			throw CMiniJException( std::to_string( statement->yylineno) + " Type mismatch" );
			errorOccured = true;
		}
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		const CType* idType;

		if( currMethod->GetLocalVariable( statement->Id() ) != nullptr ) {
			idType = currMethod->GetLocalVariable( statement->Id() )->Type();
		} else if( currMethod->GetArgument( statement->Id() ) != nullptr ) {
			idType = currMethod->GetArgument( statement->Id() )->Type();
		} else if( currClass->GetVariable( statement->Id() ) != nullptr ) {
			idType = currClass->GetVariable( statement->Id() )->Type();
		} else {
			throw CMiniJException( std::to_string( statement->yylineno) + " Undeclared variable" );
			errorOccured = true;
			return; // instead of exception - just for now
		}

		if( idType->GetTypeName() != "int []" ) {
			throw CMiniJException( std::to_string( statement->yylineno) + " The variable isn't an array" );
			errorOccured = true;
		}

		statement->FirstExpression()->Accept( this );

		if( lastTypeValue != "int" ) {
			throw CMiniJException( std::to_string( statement->yylineno) + " Wrong index type" );
			errorOccured = true;
		}


		statement->SecondExpression()->Accept( this );

		if( lastTypeValue != "int" ) {
			throw CMiniJException( std::to_string( statement->yylineno) + " Type mismatch" );
			errorOccured = true;
		}
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
	varDecl->Type()->Accept( this );

	if( !isPODName( lastTypeValue ) &&
		symbolTable->GetClass( lastTypeValue ) == nullptr
		) {
		throw CMiniJException( std::to_string( varDecl->yylineno) + " Undefined type" );
		errorOccured = true;
	}
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
	if( expRestList->ExpRest() ) {
		( expRestList->ExpRest() )->Accept( this );
	}
}

void CTypeChecker::visit( const CExpRest* expRest )
{
	( expRest->Exp() )->Accept( this );
}

#endif