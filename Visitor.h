#pragma once

class CProgram;
class CMainClass;
class CClassDecl;
class CClassDeclList;
class CExp;
class CExpList;
class CFormalList;
class CFormalRest;
class CFormalRestList;
class CMethodDecl;
class CMethodDeclList;
class CStatement;
class CStatementList;
class CType;
class CVarDecl;
class CVarDeclList;
class CExpRest;
class CExpRestList;

class IVisitor {
public:
	virtual ~IVisitor()
	{
	}

	void visit( const CProgram* ); // todo: заменить интерфейсы на классы-реализации
	void visit( const CMainClass* );
	void visit( const CClassDecl* );
	void visit( const CClassDeclList* );
	void visit( const CExp* );
	void visit( const CExpList* );
	void visit( const CFormalList* );
	void visit( const CFormalRest* );
	void visit( const CFormalRestList* );
	void visit( const CMethodDecl* );
	void visit( const CMethodDeclList* );
	void visit( const CStatement* );
	void visit( const CStatementList* );
	void visit( const CType* );
	void visit( const CVarDecl* );
	void visit( const CVarDeclList* );
	void visit( const CExpRest* );
	void visit( const CExpRestList* );
};