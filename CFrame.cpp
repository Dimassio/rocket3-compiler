#include "Frame.h"
#include "Symbols.h"
#include "CExp.h"

using namespace Frame;

CFrame::CFrame( const Symbols::CSymbol* name, int formalCount ) // todo: check if correct
{
	FP = new Temp::CTemp();
	for( size_t i = 0; i < formalCount; ++i, offSet += wordSize ) {
		formals[name] = new CInFrame( offSet );
	}
}

CFrame::~CFrame()
{
	delete FP;
}

const IRTree::IExp* CInFrame::GetExp( const Temp::CTemp* framePtr ) const
{
	return new CIRMem( new CIRBinOp( 0, new CIRTemp( framePtr ), new CIRConst( offset ) ) );
}

const IRTree::IExp* CInReg::GetExp( const Temp::CTemp* framePtr ) const
{
	return new CIRTemp( framePtr );
}