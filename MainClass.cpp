#include "MainClass.h"

CMainClass::CMainClass( const std::string &_classId, const std::string &_argId, IStatement* _statement, int _yylineno ) :
	classId(_classId),
	argId(_argId),
	statement( _statement ),
	yylineno(_yylineno )
{
}

void CMainClass::Accept( IVisitor* visitor ) const
{
	visitor->visit( this );
}

const IStatement* CMainClass::Statement() const
{
	return statement;
}

const std::string& CMainClass::ClassId() const {
	return classId;
}

const std::string& CMainClass::ArgId() const {
	return argId;
}
