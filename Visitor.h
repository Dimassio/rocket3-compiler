#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

class CProgram;
class CMainClass;
class CClassDecl;
class CClassDeclList;
class CExp;
class CExpMethodCall;
class CExpNewIntArray;
class CExpNewCustomType;
class CExpSquareBrackets;
class CExpRoundBrackets;
class CExpNot;
class CExpNumber;
class CExpId;
class CExpSingle;
class CExpLength;
class CExpBinOperation;
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

	virtual void visit( const CProgram* ) = 0; 
	virtual void visit( const CMainClass* ) = 0;
	virtual void visit( const CClassDecl* ) = 0;
	virtual void visit( const CClassDeclList* ) = 0;
	virtual void visit( const CExp* ) = 0;
	virtual void visit( const CExpMethodCall*) = 0;
	virtual void visit( const CExpNewIntArray*) = 0;
	virtual void visit( const CExpNewCustomType*) = 0;
	virtual void visit( const CExpSquareBrackets*) = 0;
	virtual void visit( const CExpRoundBrackets*) = 0;
	virtual void visit( const CExpNot*) = 0;
	virtual void visit( const CExpNumber*) = 0;
	virtual void visit( const CExpId*) = 0;
	virtual void visit( const CExpSingle*) = 0;
	virtual void visit(const CExpBinOperation*) = 0;
	virtual void visit(const CExpLength*) = 0;
	virtual void visit( const CExpList* ) = 0;
	virtual void visit( const CFormalList* ) = 0;
	virtual void visit( const CFormalRest* ) = 0;
	virtual void visit( const CFormalRestList* ) = 0;
	virtual void visit( const CMethodDecl* ) = 0;
	virtual void visit( const CMethodDeclList* ) = 0;
	virtual void visit( const CStatement* ) = 0;
	virtual void visit( const CStatementList* ) = 0;
	virtual void visit( const CType* ) = 0;
	virtual void visit( const CVarDecl* ) = 0;
	virtual void visit( const CVarDeclList* ) = 0;
	virtual void visit( const CExpRest* ) = 0;
	virtual void visit( const CExpRestList* ) = 0;
};

#endif