#include "CTypeChecker.h"

#ifndef CTYPECHECKER_CPP_INCLUDED
#define CTYPECHECKER_CPP_INCLUDED

CTypeChecker::CTypeChecker()
{
}

void CTypeChecker::visit( const CProgram* program )
{
	std::cout << "Program has started:" << std::endl << std::endl;
	( program->MainClass() )->Accept( this );
	if( !( program->ClassDeclList() ) ) {
		return;
	}
	( program->ClassDeclList() )->Accept( this );
}

void CTypeChecker::visit( const CMainClass* mainClass )
{
	printIdentation();
	std::cout << "class " << mainClass->ClassSymbol()->String() << " {" << std::endl;
	++identation;
	printIdentation();
	std::cout << "public static void main(String[] " << mainClass->ArgSymbol()->String() << " ) { " << std::endl;
	++identation;
	mainClass->Statement()->Accept( this );
	--identation;
	printIdentation();
	std::cout << "}" << std::endl;
	--identation;
	printIdentation();
	std::cout << "}" << std::endl << std::endl;
}

void CTypeChecker::visit( const CClassDecl* classDecl )
{
	printIdentation();
	std::cout << "class " << classDecl->ClassSymbol()->String();
	if( classDecl->ExtendedClassSymbol()->String() != "" ) {
		std::cout << " extends " << classDecl->ExtendedClassSymbol()->String();
	}
	std::cout << " { " << std::endl;
	++identation;
	if( classDecl->VarDeclList() != 0 ) {
		classDecl->VarDeclList()->Accept( this );
	}
	if( classDecl->MethodDeclList() != 0 ) {
		classDecl->MethodDeclList()->Accept( this );
	}
	--identation;
	printIdentation();
	std::cout << "}" << std::endl << std::endl;
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
	std::cout << "." << expMethodCall->Symbol()->String() << "(";

	expMethodCall->ExpList()->Accept( this );
	std::cout << ")";
}

void CTypeChecker::visit( const CExpBinOperation* expBinOperation )
{
	expBinOperation->FirstExp()->Accept( this );
	std::cout << " " << expBinOperation->ExpName() << " ";
	expBinOperation->SecondExp()->Accept( this );
}

void CTypeChecker::visit( const CExpNewIntArray* expNewIntArray )
{
	std::cout << "new int[";
	expNewIntArray->Exp()->Accept( this );
	std::cout << "]";
}

void CTypeChecker::visit( const CExpNewCustomType* expNewCustomType )
{
	std::cout << "new" << expNewCustomType->Type() << "()";
}

void CTypeChecker::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	std::cout << "[";
	expSquareBrackets->SecondExp()->Accept( this );
	std::cout << "]";
}

void CTypeChecker::visit( const CExpRoundBrackets* expRoundBrackets )
{
	std::cout << "(";
	expRoundBrackets->Exp()->Accept( this );
	std::cout << ")";
}

void CTypeChecker::visit( const CExpNot* expNot )
{
	std::cout << "!";
	expNot->Exp()->Accept( this );
}

void CTypeChecker::visit( const CExpNumber* expNumber )
{
	std::cout << expNumber->Number();
}

void CTypeChecker::visit( const CExpId* expId )
{
	std::cout << expId->Symbol()->String();
}

void CTypeChecker::visit( const CExpSingle* expSingle )
{
	std::cout << expSingle->ExpName();
}

void CTypeChecker::visit( const CExpLength* expLength )
{
	expLength->Exp()->Accept( this );
	std::cout << ".Length";
}

void CTypeChecker::visit( const CExpList* expList )
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
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
	std::cout << id;
	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );
	}
}

void CTypeChecker::visit( const CMethodDecl* methodDecl )
{
	printIdentation();
	std::cout << "public ";
	( methodDecl->Type() )->Accept( this );
	std::cout << methodDecl->Symbol()->String() << "(";
	( methodDecl->FormalList() )->Accept( this );
	std::cout << ") {" << std::endl;
	++identation;
	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this );
	}
	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}
	printIdentation();
	std::cout << "return ";
	( methodDecl->Exp() )->Accept( this );
	std::cout << ";" << std::endl;
	--identation;
	printIdentation();
	std::cout << "}" << std::endl << std::endl;
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
		--identation;
		printIdentation();
		std::cout << "{" << std::endl;
		++identation;
		statement->Statements()->Accept( this );
		--identation;
		printIdentation();
		std::cout << "}" << std::endl;
		++identation;
	} else if( statement->GetStatementType() == "IfStatement" ) {
		printIdentation();
		std::cout << "if (";
		statement->FirstExpression()->Accept( this );
		std::cout << ")" << std::endl;
		++identation;
		statement->FirstStatement()->Accept( this );
		--identation;
		printIdentation();
		std::cout << "else" << std::endl;
		++identation;
		statement->SecondStatement()->Accept( this );
		std::cout << std::endl;
		--identation;
	} else if( statement->GetStatementType() == "WhileStatement" ) {
		printIdentation();
		std::cout << "while (";
		statement->FirstExpression()->Accept( this );
		std::cout << ")" << std::endl;
		++identation;
		statement->FirstStatement()->Accept( this );
		std::cout << std::endl;
		--identation;
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		printIdentation();
		std::cout << "System.out.println(";
		statement->FirstExpression()->Accept( this );
		std::cout << ");" << std::endl;
	} else if( statement->GetStatementType() == "AssignStatement" ) {
		printIdentation();
		std::cout << statement->Symbol()->String();
		std::cout << " = ";
		statement->FirstExpression()->Accept( this );
		std::cout << ";" << std::endl;
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		printIdentation();
		std::cout << statement->Symbol()->String();
		std::cout << "[";
		statement->FirstExpression()->Accept( this );
		std::cout << "] = ";
		statement->SecondExpression()->Accept( this );
		std::cout << ";" << std::endl;
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
	std::cout << type->GetTypeName() << " ";
}

void CTypeChecker::visit( const CVarDecl* varDecl )
{
	printIdentation();
	( varDecl->Type() )->Accept( this );
	std::cout << varDecl->Symbol()->String() << ";" << std::endl;
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
	std::cout << ", ";
	formalRest->Type()->Accept( this );
	std::cout << formalRest->Symbol()->String();
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
	std::cout << ", ";
	( expRest->Exp() )->Accept( this );
}

#endif