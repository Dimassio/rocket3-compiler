#include "CPrettyVisitor.h"

namespace PrinterContext
{

	// �� ��������� ����� ����, ��� ��������� � ���� ������.
	CPrettyPrinterVisitor::CPrettyPrinterVisitor():
		identation( 0 )
	{
	}

	void CPrettyPrinterVisitor::printIdentation()
	{
		for( size_t i = 0; i < identation; ++i ) {
			std::cout << "  ";
		}
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
		printIdentation();
		std::cout << "class " << mainClass->ClassId() << " {" << std::endl;
		++identation;
		printIdentation();
		std::cout << "public static void main(String[] " << mainClass->ArgId() << " ) { " << std::endl;
		++identation;
		mainClass->Statement()->Accept( this );
		--identation;
		printIdentation();
		std::cout << "}" << std::endl;
		--identation;
		printIdentation();
		std::cout << "}" << std::endl << std::endl;
	}

	void CPrettyPrinterVisitor::visit( const CClassDecl* classDecl )
	{
		printIdentation();
		std::cout << "class " << classDecl->ClassId();
		if( !classDecl->ExtendedClassId().empty() ) {
			std::cout << " extends " << classDecl->ExtendedClassId();
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

	void CPrettyPrinterVisitor::visit( const CClassDeclList* classDeclList )
	{
		if( classDeclList->ClassDeclList() ) {
			classDeclList->ClassDeclList()->Accept( this );
		}
		classDeclList->ClassDecl()->Accept( this );
	}

	void CPrettyPrinterVisitor::visit( const CExp* exp )
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

	void CPrettyPrinterVisitor::visit( const CExpMethodCall* expMethodCall )
	{
		expMethodCall->Exp()->Accept( this );
		std::cout << "." << expMethodCall->Id() << "(";

		expMethodCall->ExpList()->Accept( this );
		std::cout << ")";
	}

	void CPrettyPrinterVisitor::visit( const CExpBinOperation* expBinOperation )
	{
		expBinOperation->FirstExp()->Accept( this );
		std::cout << " " << expBinOperation->ExpName() << " ";
		expBinOperation->SecondExp()->Accept( this );
	}

	void CPrettyPrinterVisitor::visit( const CExpNewIntArray* expNewIntArray )
	{
		std::cout << "new int[";
		expNewIntArray->Exp()->Accept( this );
		std::cout << "]";
	}

	void CPrettyPrinterVisitor::visit( const CExpNewCustomType* expNewCustomType )
	{
		expNewCustomType->Type()->Accept( this );
		std::cout << "()";
	}

	void CPrettyPrinterVisitor::visit( const CExpSquareBrackets* expSquareBrackets )
	{
		expSquareBrackets->FirstExp()->Accept( this );
		std::cout << "[";
		expSquareBrackets->SecondExp()->Accept( this );
		std::cout << "]";
	}

	void CPrettyPrinterVisitor::visit( const CExpRoundBrackets* expRoundBrackets )
	{
		std::cout << "(";
		expRoundBrackets->Exp()->Accept( this );
		std::cout << ")";
	}

	void CPrettyPrinterVisitor::visit( const CExpNot* expNot )
	{
		std::cout << "!";
		expNot->Exp()->Accept( this );
	}

	void CPrettyPrinterVisitor::visit( const CExpNumber* expNumber )
	{
		std::cout << expNumber->Number();
	}

	void CPrettyPrinterVisitor::visit( const CExpId* expId )
	{
		std::cout << expId->Id();
	}

	void CPrettyPrinterVisitor::visit( const CExpSingle* expSingle )
	{
		std::cout << expSingle->ExpName();
	}

	void CPrettyPrinterVisitor::visit( const CExpLength* expLength )
	{
		expLength->Exp()->Accept( this );
		std::cout << ".Length";
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
		if( !formalList->Type() && id.empty() ) {
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
		printIdentation();
		std::cout << "public ";
		( methodDecl->Type() )->Accept( this );
		std::cout << methodDecl->Id() << "(";
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

	void CPrettyPrinterVisitor::visit( const CMethodDeclList* methodDeclList )
	{
		if( methodDeclList->MethodDeclList() ) {
			methodDeclList->MethodDeclList()->Accept( this );
		}
		methodDeclList->MethodDecl()->Accept( this );
	}

	void CPrettyPrinterVisitor::visit( const CStatement* statement )
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
			std::cout << statement->Id();
			std::cout << " = ";
			statement->FirstExpression()->Accept( this );
			std::cout << ";" << std::endl;
		} else if( statement->GetStatementType() == "ArrayAssignStatement" ) {
			printIdentation();
			std::cout << statement->Id();
			std::cout << "[";
			statement->FirstExpression()->Accept( this );
			std::cout << "] = ";
			statement->SecondExpression()->Accept( this );
			std::cout << ";" << std::endl;
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
		std::cout << type->GetTypeName() << " ";
	}

	void CPrettyPrinterVisitor::visit( const CVarDecl* varDecl )
	{
		printIdentation();
		( varDecl->Type() )->Accept( this );
		std::cout << varDecl->Id() << ";" << std::endl;
	}

	void CPrettyPrinterVisitor::visit( const CVarDeclList* varDeclList )
	{
		if( varDeclList->VarDeclList() ) {
			varDeclList->VarDeclList()->Accept( this );
		}
		varDeclList->VarDecl()->Accept( this );
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
		std::cout << formalRest->Id();
	}

	void CPrettyPrinterVisitor::visit( const CExpRestList* expRestList )
	{
		if( expRestList->ExpRestList() ) {
			( expRestList->ExpRestList() )->Accept( this );
		}
		if( expRestList->ExpRest() ) {
			( expRestList->ExpRest() )->Accept( this );
		}
	}

	void CPrettyPrinterVisitor::visit( const CExpRest* expRest )
	{
		std::cout << ", ";
		( expRest->Exp() )->Accept( this );
	}

} // namespace PrinterContext