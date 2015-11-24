#include "Frame.h"
#include "Symbols.h"

using namespace Frame;

CFrame::CFrame( const Symbols::CSymbol* name, int formalCount )
{
	FP = new Temp::CTemp();
	for( size_t i = 0; i < formalCount; ++i, offSet += wordSize ) {
		formals.push_back( new CInFrame( offSet ) );
	}
}

CFrame::~CFrame()
{
	delete FP;
}