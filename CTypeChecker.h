#ifndef CTYPECHECKER_H_INCLUDED
#define CTYPECHECKER_H_INCLUDED

#include <iostream>
#include <string>
#include "Visitor.h"
#include "Common.h"
#include "CTable.h"
#include <stack>

class CTypeChecker: public IVisitor {
public:
	CTypeChecker(const CTable* _symbTable);

	void visit( const CProgram* program );

	void visit( const CMainClass* mainClass );

	void visit( const CClassDecl* classDecl );

	void visit( const CClassDeclList* classDeclList );

	void visit( const CExp* exp );

	void visit( const CExpMethodCall* expMethodCall );

	void visit( const CExpNewIntArray* expNewIntArray );

	void visit( const CExpNewCustomType* expNewCustomType );

	void visit( const CExpSquareBrackets* expSquareBrackets );

	void visit( const CExpRoundBrackets* expRoundBrackets );

	void visit( const CExpNot* expNot );

	void visit( const CExpNumber* expNumber );

	void visit( const CExpId* expId );

	void visit( const CExpSingle* expSingle );

	void visit( const CExpBinOperation* expBinOperation );

	void visit( const CExpLength* expLength );

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

private:
	const CTable* symbolTable;	
	const CClassInfo* currClass;
	const CMethodInfo* currMethod;
	std::stack<const CMethodInfo*> currMethodCall; // ����� ���� foo = obj.Method(obj2.doo())
	std::stack<int> numOfArgument;
	std::string lastTypeValue;
	
	bool errorOccured;

	bool isPODName(std::string name);
};

#endif
