#include "StaticVariables.h"
#include "ClassDecl.h"

CClassDecl::CClassDecl( const std::string &_classId, const std::string &_extendedClassId, IVarDeclList* _varDeclList, IMethodDeclList* _methodDeclList, int _yylineno ) :
	classId(_classId),
	extendedClassId( _extendedClassId ),
	varDeclList( _varDeclList ),
	methodDeclList( _methodDeclList ),
	yylineno(_yylineno )
{
}

void CClassDecl::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IVarDeclList* CClassDecl::VarDeclList() const
{
	return varDeclList;
}

const IMethodDeclList*  CClassDecl::MethodDeclList() const
{
	return methodDeclList;
}

const std::string& CClassDecl::ClassId() const
{
	return classId;
}

const std::string& CClassDecl::ExtendedClassId() const
{
	return extendedClassId;
}
