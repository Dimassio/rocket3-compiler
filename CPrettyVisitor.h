#include "Visitor.h"

// Он выполняет вывод того, что находится в узле дерева.


class CPrettyPrinterVisitor : public IVisitor {
public:

	CPrettyPrinterVisitor()
	{
	}

	void visit( const CProgram* program )
	{
		std::cout << "Program has started:" << std::endl;
		CMainClass* mainClass = program->MainClass;
		mainClass->Accept( this );
		CClassDeclList* classDeclList = program->ClassDeclList;
		if( !classDeclList ) {
			return;
		}
		classDeclList->Accept( this );
	}

	void visit( const CMainClass* mainClass )
	{
		std::cout << "class " << mainClass->GetClassName << " public static void main(String[] "
			<< mainClass->GetArgName << " ) { " << std::endl;
		CStatement* statement = mainClass->Statement;
		statement->Accept( this );
		std::cout << "}" << std::endl;
		std::cout << "}" << std::endl;
	}

	void visit( const CClassDecl* classDecl )
	{
		std::cout << "class " << classDecl->GetClassName;
		if( classDecl->GetExtendedClassName != "" ) {
			std::cout << " extends " << classDecl->GetExtendedClassName;
		}
		std::cout << " { ";
		CVarDeclList* varDeclList = classDecl->VarDeclList;
		if( varDeclList != 0 ) {
			varDeclList->Accept( this );
		}
		CMethodDeclList* methodDeclList = classDecl->MethodDeclList;
		if( methodDeclList != 0 ) {
			methodDeclList->Accept( this );
		}
		std::cout << " } " << std::endl;
	}

	void visit( const CClassDeclList* classDeclList )
	{
		std::cout << "Class declarations:" << std::endl; // todo: или не нужен тут вывод?
		CClassDecl* classDecl = classDeclList->ClassDecl;
		classDecl->Accept( this );
		CClassDeclList* newClassDeclList = classDeclList->ClassDeclList;
		if( !newClassDeclList ) {
			return;
		}
		newClassDeclList->Accept( this );
	}

	void visit( const CExp* expression )
	{
		std::cout << "Expression: " << expression->GetExpressionType() << " " << expression->GetExpressionName() << std::endl;

		if (expression->GetExpressionType() == "BinOp") {
			expression->FirstExpression()->Accept(this);
			std::cout << " " << expression->GetExpressionName() << " ";
			expression->SecondExpression()->Accept(this);
		}
		else if (expression->GetExpressionType() == "SquareBrackets") {
			expression->FirstExpression()->Accept(this);
			std::cout << "[";
			expression->SecondExpression()->Accept(this);
			std::cout << "]";
		}
		else if (expression->GetExpressionType() == "Length") {
			expression->FirstExpression()->Accept(this);
			std::cout << ".Length";
		}
		else if (expression->GetExpressionType() == "MethodCall") {
			expression->FirstExpression()->Accept(this);
			std::cout << "." << expression->GetId() << "(";
			expression->ExpressionList()->Accept(this);
			std::cout << ")";
		}
		else if (expression->GetExpressionType() == "SingleExp") {
			if (expression->GetExpressionName() == "Number" || expression->GetExpressionName() == "Id") {
				std::cout << expression->GetId();
			}
			else {
				std::cout << expression->GetExpressionName();
			}
		}
		else if (expression->GetExpressionType() == "NewIntArray") {
			std::cout << "new int[";
			expression->FirstExpression()->Accept(this);
			std::cout << "]";
		}
		else if (expression->GetExpressionType() == "NewCustomType") {
			std::cout << "new " << expression->GetId() << "()";
		}
		else if (expression->GetExpressionType() == "NotExp") {
			std::cout << "!";
			expression->FirstExpression()->Accept(this);
		}
		else if (expression->GetExpressionType() == "RoundBrackets") {
			std::cout << "(";
			expression->FirstExpression()->Accept(this);
			std::cout << ")";
		}

		std::cout << std::endl;
	}

	void visit( const IExpList* )
	{

	}

	void visit( const CFormalList* formalList )
	{
		std::string id = formalList->Id;
		CType* type = formalList->Type;
		CFormalRestList* formalRestList = formalList->FormalRestList;
		if( !type && id == "" && !formalRestList ) {
			return;
		}
		type->Accept( this );
		std::cout << id;
		if( formalRestList ) {
			formalRestList->Accept( this );
		}
	}

	void visit( const CMethodDecl* methodDecl )
	{
		std::cout << "public ";
		( methodDecl->Type )->Accept( this );
		std::cout << methodDecl->Id << "( ";
		( methodDecl->FormalList )->Accept( this );
		std::cout << ") {";
		if( methodDecl->VarDeclList ) {
			( methodDecl->VarDeclList )->Accept( this );
		}
		if( methodDecl->StatementList ) {
			( methodDecl->StatementList )->Accept( this );
		}
		std::cout << "return ";
		( methodDecl->Exp )->Accept( this );
	}

	void visit( const CMethodDeclList* methodDeclList )
	{
		std::cout << "Methods declaration list" << std::endl; // todo: или не нужен тут вывод?
		CMethodDecl* methodDecl = methodDeclList->MethodDecl;
		methodDecl->Accept( this );
		CMethodDeclList* newMethodDeclList = methodDeclList->MethodDeclList;
		if( !newMethodDeclList ) {
			return;
		}
		newMethodDeclList->Accept( this );
	}

	void visit( const CStatement* statement)
	{
		std::cout << "Statement: " << statement->GetStatementType() << std::endl;

		if (statement->GetStatementType() == "BlockStatement") {
			std::cout << "{";
			statement->Statements()->Accept(this);
			std::cout << "}";
		}
		else if (statement->GetStatementType() == "IfStatement") {
			std::cout << "if (";
			statement->FirstExpression()->Accept(this);
			std::cout << ")" << std::endl;
			statement->FirstStatement()->Accept(this);
			std::cout << std::endl << "else" << std::endl;
			statement->SecondStatement()->Accept(this);
			std::cout << std::endl;
		}
		else if (statement->GetStatementType() == "WhileStatement") {
			std::cout << "while (";
			statement->FirstExpression()->Accept(this);
			std::cout << ")" << std::endl;
			statement->FirstStatement()->Accept(this);
			std::cout << std::endl;
		}
		else if (statement->GetStatementType() == "PrintlnStatement") {
			std::cout << "System.out.println(";
			statement->FirstExpression()->Accept(this);
			std::cout << ");" << std::endl;
		}
		else if (statement->GetStatementType() == "AssignStatement") {
			std::cout << statement->GetId();
			std::cout << " = ";
			statement->FirstExpression()->Accept(this);
			std::cout << ";";
		}
		else if (statement->GetStatementType() == "ArrayAssignStatement") {
			std::cout << statement->GetId();
			std::cout << "[";
			statement->FirstExpression()->Accept(this);
			std::cout << "] = ";
			statement->SecondExpression()->Accept(this);
			std::cout << ";";
		}
	}

	void visit( const CStatementList* statementList )
	{
		if( statementList->StatementList ) {
			( statementList->StatementList )->Accept( this );
		}
		( statementList->Statement )->Accept( this );
	}

	void visit(const CType* type)
	{
		std::cout << "Type: " << type->GetTypeName() << std::endl;
	}

	void visit( const CVarDecl* varDecl )
	{
		( varDecl->Type )->Accept( this );
		std::cout << varDecl->VarName << ";" << std::endl;
	}

	void visit( const CVarDeclList* varDeclList )
	{
		std::cout << "Variables declaration list" << std::endl; // todo: или не нужен тут вывод?
		CVarDecl* varDecl = varDeclList->VarDecl;
		varDecl->Accept( this );
		CVarDeclList* newVarDeclList = varDeclList->VarDeclList;
		if( !newVarDeclList ) {
			return;
		}
		newVarDeclList->Accept( this );
	}

	void visit( const CFormalRestList* formalRestList )
	{
		if( formalRestList->FormalRestList ) {
			( formalRestList->FormalRestList )->Accept( this );
		}
		( formalRestList->FormalRest )->Accept( this );
	}

	void visit( const CFormalRest* formalRest )
	{
		std::cout << ", ";
		formalRest->Type->Accept( this );
		std::cout << formalRest->Id << std::endl;
	}
};
