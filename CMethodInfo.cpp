#include "StaticVariables.h"
#include "CMethodInfo.h"
#include <utility>

CMethodInfo::CMethodInfo()
{
}

CMethodInfo::CMethodInfo( const Symbols::CSymbol* _methodSymbol, CType* _type ):
	methodSymbol( _methodSymbol ),
	type( _type )
{
}

const Symbols::CSymbol* CMethodInfo::MethodSymbol() const
{
	return methodSymbol;
}

CType* CMethodInfo::Type()
{
	return type;
}

const CType * CMethodInfo::Type() const
{
	return type;
}

const CVarInfo* CMethodInfo::GetArgument( int number ) const
{
	if( number > arguments.size() ) {
		// very bad
		return nullptr;
	} else {
		return &arguments[number].second;
	}
}

bool CMethodInfo::AddArgument( const std::string &argumentId, CType* type )
{
	const Symbols::CSymbol* argumentSymbol = symbolStorage.Get( argumentId );
	for( size_t i = 0; i < arguments.size(); ++i ) {
		if( arguments[i].first == argumentSymbol ) {
			return false;
		}
	}
	arguments.push_back( std::pair<const Symbols::CSymbol*, CVarInfo>( argumentSymbol, CVarInfo( argumentSymbol, type ) ) );
	return true;
}

CVarInfo* CMethodInfo::GetArgument( const std::string &argumentId )
{
	const Symbols::CSymbol* argumentSymbol = symbolStorage.Get( argumentId );

	for( size_t i = 0; i < arguments.size(); ++i ) {
		if( arguments[i].first == argumentSymbol ) {
			return &arguments[i].second;
		}
	}
	return nullptr;
}

const CVarInfo * CMethodInfo::GetArgument( const std::string & argumentId ) const
{
	const Symbols::CSymbol* argumentSymbol = symbolStorage.Get( argumentId );

	for( size_t i = 0; i < arguments.size(); ++i ) {
		if( arguments[i].first == argumentSymbol ) {
			return &arguments[i].second;
		}
	}
	return nullptr;
}

bool CMethodInfo::AddLocalVariable( const std::string &variableId, CType* type )
{
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	for( size_t i = 0; i < localVariables.size(); ++i ) {
		if( localVariables[i].first == variableSymbol ) {
			return false;
		}
	}
	localVariables.push_back( std::pair<const Symbols::CSymbol*, CVarInfo>( variableSymbol, CVarInfo( variableSymbol, type ) ) );
	return true;
}

CVarInfo* CMethodInfo::GetLocalVariable( const std::string &variableId )
{
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	for( size_t i = 0; i < localVariables.size(); ++i ) {
		if( localVariables[i].first == variableSymbol ) {
			return &localVariables[i].second;
		}
	}
	return nullptr;
}

const CVarInfo* CMethodInfo::GetLocalVariable( const std::string &variableId ) const
{
	const Symbols::CSymbol* variableSymbol = symbolStorage.Get( variableId );

	for( size_t i = 0; i < localVariables.size(); ++i ) {
		if( localVariables[i].first == variableSymbol ) {
			return &localVariables[i].second;
		}
	}
	return nullptr;
}