#include "MethodDecl.h"

CMethodDecl::CMethodDecl( IType* _type, std::string _id, IFormalList* _formalList, IVarDeclList* _varDeclList, IStatementList* _statementList, IExp* _exp ) :
	type( _type ), id( _id ), formalList( _formalList ), varDeclList( _varDeclList ), statementList( _statementList ), exp( _exp )
{
}

void CMethodDecl::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IType* CMethodDecl::Type() const
{
	return type;
}

const std::string CMethodDecl::Id() const
{
	return id;
}

const IFormalList* CMethodDecl::FormalList() const
{
	return formalList;
}

const IVarDeclList* CMethodDecl::VarDeclList() const
{
	return varDeclList;
}

const IStatementList* CMethodDecl::StatementList() const
{
	return statementList;
}

const IExp* CMethodDecl::Exp() const
{
	return exp;
}
