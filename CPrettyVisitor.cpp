#ifndef CPRETTYVISITOP_CPP_INCLUDED
#define CPRETTYVISITOP_CPP_INCLUDED
#include "CPrettyVisitor.h"

// ќн выполн€ет вывод того, что находитс€ в узле дерева.
CPrettyPrinterVisitor::CPrettyPrinterVisitor()
{
}

void CPrettyPrinterVisitor::visit( const CProgram* program )
{
	std::cout << "Program has started:" << std::endl << std::endl;
	( program->MainClass() )->Accept( this );
	if( !( program->ClassDeclList() ) ) {
		return;
	}
	( program->ClassDeclList() )->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CMainClass* mainClass )
{
	std::cout << "class " << mainClass->GetClassName() << " public static void main(String[] "
		<< mainClass->GetArgName() << " ) { " << std::endl;
	mainClass->Statement()->Accept( this );
	std::cout << "}" << std::endl;
	std::cout << "}" << std::endl;
}

void CPrettyPrinterVisitor::visit( const CClassDecl* classDecl )
{
	std::cout << "class " << classDecl->GetClassName();
	if( classDecl->GetExtendedClassName() != "" ) {
		std::cout << " extends " << classDecl->GetExtendedClassName();
	}
	std::cout << " { ";
	if( classDecl->VarDeclList() != 0 ) {
		classDecl->VarDeclList()->Accept( this );
	}
	if( classDecl->MethodDeclList() != 0 ) {
		classDecl->MethodDeclList()->Accept( this );
	}
	std::cout << " } " << std::endl;
}

void CPrettyPrinterVisitor::visit( const CClassDeclList* classDeclList )
{
	classDeclList->ClassDecl()->Accept( this );
	if( !classDeclList->ClassDeclList() ) {
		return;
	}
	classDeclList->ClassDeclList()->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CExp* expression )
{
	/*std::cout " " << expression->GetExpressionName() << std::endl;*/
	if( expression->GetExpressionType() == "BinOp" ) {
		expression->FirstExpression()->Accept( this );
		std::cout << " " << expression->GetExpressionName() << " ";
		expression->SecondExpression()->Accept( this );
	} else if( expression->GetExpressionType() == "SquareBrackets" ) {
		expression->FirstExpression()->Accept( this );
		std::cout << "[";
		expression->SecondExpression()->Accept( this );
		std::cout << "]";
	} else if( expression->GetExpressionType() == "Length" ) {
		expression->FirstExpression()->Accept( this );
		std::cout << ".Length";
	} else if( expression->GetExpressionType() == "MethodCall" ) {
		expression->FirstExpression()->Accept( this );
		std::cout << "." << expression->GetId() << "(";
		expression->ExpressionList()->Accept( this );
		std::cout << ")";
	} else if( expression->GetExpressionType() == "SingleExp" ) {
		if( expression->GetExpressionName() == "Number" || expression->GetExpressionName() == "Id" ) {
			std::cout << expression->GetId();
		} else {
			std::cout << expression->GetExpressionName();
		}
	} else if( expression->GetExpressionType() == "NewIntArray" ) {
		std::cout << "new int[";
		expression->FirstExpression()->Accept( this );
		std::cout << "]";
	} else if( expression->GetExpressionType() == "NewCustomType" ) {
		std::cout << "new " << expression->GetId() << "()";
	} else if( expression->GetExpressionType() == "NotExp" ) {
		std::cout << "!";
		expression->FirstExpression()->Accept( this );
	} else if( expression->GetExpressionType() == "RoundBrackets" ) {
		std::cout << "(";
		expression->FirstExpression()->Accept( this );
		std::cout << ")";
	}
	std::cout << std::endl;
}

void CPrettyPrinterVisitor::visit( const CExpList* expList )
{
	if( expList->Exp() ) {
		expList->Exp()->Accept( this );
	}
	if( expList->ExpRestList() ) {
		expList->ExpRestList()->Accept( this );
	}
}

void CPrettyPrinterVisitor::visit( const CFormalList* formalList )
{
	std::string id = formalList->Id();
	if( !formalList->Type() && id == "" && !formalList->FormalRestList() ) {
		return;
	}
	formalList->Type()->Accept( this );
	std::cout << id;
	if( formalList->FormalRestList() ) {
		formalList->FormalRestList()->Accept( this );
	}
}

void CPrettyPrinterVisitor::visit( const CMethodDecl* methodDecl )
{
	std::cout << "public ";
	( methodDecl->Type() )->Accept( this );
	std::cout << methodDecl->Id() << "( ";
	( methodDecl->FormalList() )->Accept( this );
	std::cout << ") {";
	if( methodDecl->VarDeclList() ) {
		( methodDecl->VarDeclList() )->Accept( this );
	}
	if( methodDecl->StatementList() ) {
		( methodDecl->StatementList() )->Accept( this );
	}
	std::cout << "return ";
	( methodDecl->Exp() )->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CMethodDeclList* methodDeclList )
{
	methodDeclList->MethodDecl()->Accept( this );
	if( !methodDeclList->MethodDeclList() ) {
		return;
	}
	methodDeclList->MethodDeclList()->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CStatement* statement )
{
	//std::cout << statement->GetStatementType() << std::endl;

	if( statement->GetStatementType() == "BlockStatement" ) {
		std::cout << "{";
		statement->Statements()->Accept( this );
		std::cout << "}";
	} else if( statement->GetStatementType() == "IfStatement" ) {
		std::cout << "if (";
		statement->FirstExpression()->Accept( this );
		std::cout << ")" << std::endl;
		statement->FirstStatement()->Accept( this );
		std::cout << std::endl << "else" << std::endl;
		statement->SecondStatement()->Accept( this );
		std::cout << std::endl;
	} else if( statement->GetStatementType() == "WhileStatement" ) {
		std::cout << "while (";
		statement->FirstExpression()->Accept( this );
		std::cout << ")" << std::endl;
		statement->FirstStatement()->Accept( this );
		std::cout << std::endl;
	} else if( statement->GetStatementType() == "PrintlnStatement" ) {
		std::cout << "System.out.println(";
		statement->FirstExpression()->Accept( this );
		std::cout << ");" << std::endl;
	} else if( statement->GetStatementType() == "AssignStatement" ) {
		std::cout << statement->GetId();
		std::cout << " = ";
		statement->FirstExpression()->Accept( this );
		std::cout << ";";
	} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
		std::cout << statement->GetId();
		std::cout << "[";
		statement->FirstExpression()->Accept( this );
		std::cout << "] = ";
		statement->SecondExpression()->Accept( this );
		std::cout << ";";
	}
}

void CPrettyPrinterVisitor::visit( const CStatementList* statementList )
{
	if( statementList->StatementList() ) {
		( statementList->StatementList() )->Accept( this );
	}
	( statementList->Statement() )->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CType* type )
{
	std::cout /*<< "Type: "*/ << type->GetTypeName() << std::endl;
}

void CPrettyPrinterVisitor::visit( const CVarDecl* varDecl )
{
	( varDecl->Type() )->Accept( this );
	std::cout << varDecl->VarName() << ";" << std::endl;
}

void CPrettyPrinterVisitor::visit( const CVarDeclList* varDeclList )
{
	varDeclList->VarDecl()->Accept( this );
	if( !varDeclList->VarDeclList() ) {
		return;
	}
	varDeclList->VarDeclList()->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CFormalRestList* formalRestList )
{
	if( formalRestList->FormalRestList() ) {
		( formalRestList->FormalRestList() )->Accept( this );
	}
	( formalRestList->FormalRest() )->Accept( this );
}

void CPrettyPrinterVisitor::visit( const CFormalRest* formalRest )
{
	std::cout << ", ";
	formalRest->Type()->Accept( this );
	std::cout << formalRest->Id() << std::endl;
}

void CPrettyPrinterVisitor::visit( const CExpRestList* expRestList )
{
	if( expRestList->ExpRestList() ) {
		( expRestList->ExpRestList() )->Accept( this );
	}
	if( expRestList->Exp() ) {
		( expRestList->Exp() )->Accept( this );
	}
}

void CPrettyPrinterVisitor::visit( const CExpRest* expRest )
{
	std::cout << ", ";
	( expRest->Exp() )->Accept( this );
}

#endif