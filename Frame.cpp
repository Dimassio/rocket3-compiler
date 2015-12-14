#include "Frame.h"
#include "Symbols.h"
#include "CExp.h"
#include "EOperation.h"
#include "StaticVariables.h"

using namespace Frame;

IAccess::~IAccess()
{
}

const IRTree::IIRExp* CInFrame::GetExp( const Temp::CTemp* framePtr ) const
{
	return new CIRMem( new CIRBinOp( PLUS, new CIRTemp( framePtr ), new CIRConst( offset ) ) );
}

const IRTree::IIRExp* CInReg::GetExp( const Temp::CTemp* framePtr ) const
{
	return new CIRTemp( framePtr );
}

CInFrame::CInFrame( int _offset ):
	offset( _offset )
{
}

CInReg::CInReg( Temp::CTemp _temp ) :
	temp( _temp )
{
}

CFrame::CFrame( const std::string& name, int formalCount )
{
	const Symbols::CSymbol* symbol = symbolStorage.Get( name );

	FP = new Temp::CTemp();
	for( size_t i = 0; i < formalCount; ++i, offSet += wordSize ) {
		formals[symbol] = new CInFrame( offSet );
	}
}

CFrame::~CFrame()
{
	delete FP;
}

int CFrame::FormalCount() const
{
	return formals.size();
}

const IAccess* CFrame::Formal( size_t index ) const
{
	// todo:: unordered_map?
	return nullptr; // todo
}

const Temp::CTemp* CFrame::GetFP() const
{
	return FP;
}

const IAccess* CFrame::GetVar( const std::string& id ) const
{
	const Symbols::CSymbol* symbol = symbolStorage.Get( id );

	if( formals.find( symbol ) != formals.end() ) {
		return formals.at( symbol );
	} else if( locals.find( symbol ) != formals.end() ) {
		return locals.at( symbol );
	} else if( temproraries.find( symbol ) != formals.end() ) {
		return temproraries.at( symbol );
	} else {
		return nullptr;
	}
}

const bool CFrame::AddLocal( const Symbols::CSymbol* symbol )
{
	if( locals.find( symbol ) != locals.end() ) {
		locals[symbol] = new CInFrame(offSet);
		offSet += wordSize;
		return true;
	} else {
		return false;
	}
}

const bool CFrame::AddTemprorary( const Symbols::CSymbol* symbol )
{
	if( temproraries.find( symbol ) != temproraries.end() ) {
		temproraries[symbol] = new CInFrame( offSet );
		offSet += wordSize;
		return true;
	} else {
		return false;
	}
}