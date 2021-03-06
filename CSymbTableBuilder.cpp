#include "StaticVariables.h"
#include "CSymbTableBuilder.h"
#include "Symbols.h"
#include "CMiniJException.h"
#include <iostream>


CSymbTableBuilder::CSymbTableBuilder():
	symbTable( new CTable() )
{
}

void CSymbTableBuilder::visit( const CProgram* program )
{
	( program->MainClass() )->Accept( this );
	if( !( program->ClassDeclList() ) ) {
		return;
	}
	( program->ClassDeclList() )->Accept( this );
}

void CSymbTableBuilder::visit( const CMainClass* mainClass )
{
	if( !symbTable->AddClass( mainClass->ClassId(), "" ) ) {
		throw CMiniJException( "table builder: duplicated definition in " + std::to_string( mainClass->yylineno ) );
	} else {
		currClass = symbTable->GetClass( mainClass->ClassId() );

		CType* type = new CType( std::string( "void" ), mainClass->yylineno );

		if( !currClass->AddMethod( std::string( "main" ), type ) ) {
			throw CMiniJException( "table builder: duplicated definition in " + std::to_string( mainClass->yylineno ) );
		} else {
			if( mainClass->Statement() ) {
				mainClass->Statement()->Accept( this );
			}
		}

		currClass = nullptr;
	}
}

void CSymbTableBuilder::visit( const CClassDecl* classDecl )
{
	if( !symbTable->AddClass( classDecl->ClassId(), classDecl->ExtendedClassId() ) ) {
		throw CMiniJException( "table builder: duplicated class definition in " + std::to_string( classDecl->yylineno ) );
	} else {
		currClass = symbTable->GetClass( classDecl->ClassId() );
		if( classDecl->VarDeclList() != 0 ) {
			classDecl->VarDeclList()->Accept( this );
		}
		if( classDecl->MethodDeclList() != 0 ) {
			classDecl->MethodDeclList()->Accept( this );
		}

		currClass = nullptr;
	}
}

void CSymbTableBuilder::visit( const CClassDeclList* classDeclList )
{
	if( classDeclList->ClassDeclList() ) {
		classDeclList->ClassDeclList()->Accept( this );
	}
	classDeclList->ClassDecl()->Accept( this );
}

void CSymbTableBuilder::visit( const CExp* exp )
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

void CSymbTableBuilder::visit( const CExpMethodCall* expMethodCall )
{
	expMethodCall->Exp()->Accept( this );
	expMethodCall->ExpList()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpNewIntArray* expNewIntArray )
{
	expNewIntArray->Exp()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpNewCustomType* expNewCustomType )
{
	expNewCustomType->Type()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpSquareBrackets* expSquareBrackets )
{
	expSquareBrackets->FirstExp()->Accept( this );
	expSquareBrackets->SecondExp()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpRoundBrackets* expRoundBrackets )
{
	expRoundBrackets->Exp()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpNot* expNot )
{
	expNot->Exp()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpNumber* expNumber )
{
}

void CSymbTableBuilder::visit( const CExpId* expId )
{
}

void CSymbTableBuilder::visit( const CExpSingle* expSingle )
{
}

void CSymbTableBuilder::visit( const CExpBinOperation* expBinOperation )
{
	expBinOperation->FirstExp()->Accept( this );
	expBinOperation->SecondExp()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpLength* expLength )
{
	expLength->Exp()->Accept( this );
}

void CSymbTableBuilder::visit( const CExpList* expList )
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
	}
	if( expList->ExpRestList() ) {
		expList->ExpRestList()->Accept( this );
	}
}

void CSymbTableBuilder::visit( const CFormalList* formalList )
{
	if( !formalList->Type() && formalList->Id().empty() ) {
		return;
	}

	formalList->Type()->Accept( this );
	CType* type = lastTypeValue;

	if( !currMethod ) {
		throw CMiniJException( "table builder: no such method in " + std::to_string( formalList->yylineno ) );
	} else {
		if( !currMethod->AddArgument( formalList->Id(), type ) ) {
			throw CMiniJException( "table builder: duplicated definition in " + std::to_string( formalList->yylineno ) );
		}
	}

	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );
	}
}

void CSymbTableBuilder::visit( const CMethodDecl* methodDecl )
{
	( methodDecl->Type() )->Accept( this );
	CType* type = lastTypeValue;
	if( !currClass->AddMethod( methodDecl->Id(), type ) ) {
		throw CMiniJException( "table builder: duplicated method definition in " + std::to_string( methodDecl->yylineno ) );
	} else {
		currMethod = currClass->GetMethod( methodDecl->Id() );
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

		currMethod = nullptr;
	}
}

void CSymbTableBuilder::visit( const CMethodDeclList* methodDeclList )
{
	if( methodDeclList->MethodDeclList() ) {
		methodDeclList->MethodDeclList()->Accept( this );
	}
	methodDeclList->MethodDecl()->Accept( this );
}

void CSymbTableBuilder::visit( const CStatement* statement )
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
		statement->FirstExpression()->Accept( this );
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		statement->FirstExpression()->Accept( this );
		statement->SecondExpression()->Accept( this );
	}
}

void CSymbTableBuilder::visit( const CStatementList* statementList )
{
	if( statementList->StatementList() ) {
		( statementList->StatementList() )->Accept( this );
	}
	( statementList->Statement() )->Accept( this );
}

void CSymbTableBuilder::visit( const CType* type )
{
	lastTypeValue = const_cast< CType* >( type );
}

void CSymbTableBuilder::visit( const CVarDecl* varDecl )
{
	varDecl->Type()->Accept( this );
	CType* type = lastTypeValue;
	const std::string id = varDecl->Id();
	if( currMethod == nullptr ) {
		if( !currClass->AddVariable( id, type ) ) {
			throw CMiniJException( "table builder: duplicated definition in class in " + std::to_string( varDecl->yylineno ) );
		}
	} else if( !currMethod->AddLocalVariable( id, type ) ) {
		throw CMiniJException( "table builder: duplicated definition in method in " + std::to_string( varDecl->yylineno ) );
	}
}

void CSymbTableBuilder::visit( const CVarDeclList* varDeclList )
{
	if( varDeclList->VarDeclList() ) {
		varDeclList->VarDeclList()->Accept( this );
	}
	varDeclList->VarDecl()->Accept( this );
}

void CSymbTableBuilder::visit( const CFormalRestList* formalRestList )
{
	if( formalRestList->FormalRestList() ) {
		( formalRestList->FormalRestList() )->Accept( this );
	}
	( formalRestList->FormalRest() )->Accept( this );
}

void CSymbTableBuilder::visit( const CFormalRest* formalRest )
{
	formalRest->Type()->Accept( this );
	CType* type = lastTypeValue;

	if( !currMethod ) {
		throw CMiniJException( "table builder: no such method in " + std::to_string( formalRest->yylineno ));
	} else {
		if( !currMethod->AddArgument( formalRest->Id(), type ) ) {
			throw CMiniJException( "table builder: duplicated definition in " + std::to_string( formalRest->yylineno) );
		}
	}
}

void CSymbTableBuilder::visit( const CExpRestList* expRestList )
{
	if( expRestList->ExpRestList() ) {
		( expRestList->ExpRestList() )->Accept( this );
	}
	if( expRestList->ExpRest() ) {
		( expRestList->ExpRest() )->Accept( this );
	}
}

void CSymbTableBuilder::visit( const CExpRest* expRest )
{
	( expRest->Exp() )->Accept( this );
}

const CTable * CSymbTableBuilder::GetSymbolTable() const
{
	return symbTable;
}
