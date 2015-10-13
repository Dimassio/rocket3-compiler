#pragma once

#include "Grammar.h"
#include "Program.h"
#include "MainClass.h"
#include "ClassDecl.h"
#include "ClassDeclList.h"
#include "Exp.h"
#include "ExpList.h"
#include "FormalList.h"
#include "MethodDecl.h"
#include "MethodDeclList.h"
#include "Statement.h"
#include "StatementList.h"
#include "Type.h"
#include "VarDecl.h"
#include "VarDeclList.h"

class IVisitor {
public:
	virtual ~IVisitor()
	{
	}

	void visit( const IProgram* ); // todo: заменить интерфейсы на классы-реализации
	void visit( const IMainClass* );
	void visit( const IClassDecl* );
	void visit( const IClassDeclList* );
	void visit( const IExp* );
	void visit( const IExpList* );
	void visit( const IFormalList* );
	void visit( const IMethodDecl* );
	void visit( const IMethodDeclList* );
	void visit( const IStatement* );
	void visit( const IStatementList* );
	void visit( const IType* );
	void visit( const IVarDecl* );
	void visit( const IVarDeclList* );
};