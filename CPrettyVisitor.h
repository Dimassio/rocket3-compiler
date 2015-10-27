#include "Visitor.h"

class CPrettyPrinterVisitor : public IVisitor {
public:
	CPrettyPrinterVisitor();

	void visit( const CProgram* program );

	void visit( const CMainClass* mainClass );

	void visit( const CClassDecl* classDecl );

	void visit( const CClassDeclList* classDeclList );

	void visit( const CExp* expression );

	void visit( const CExpList* expList );

	void visit( const CFormalList* formalList );

	void visit( const CMethodDecl* methodDecl );

	void visit( const CMethodDeclList* methodDeclList );

	void visit( const CStatement* statement );

	void visit( const CStatementList* statementList );

	void visit( const CType* type );

	void visit( const CVarDecl* varDecl );

	void visit( const CVarDeclList* varDeclList );

	void visit( const CFormalRestList* formalRestList );

	void visit( const CFormalRest* formalRest );

	void visit( const CExpRestList* expRestList );

	void visit( const CExpRest* expRest );
};
