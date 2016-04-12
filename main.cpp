#include <cstdio>
#include <iostream>
#include "CPrettyVisitor.h"
#include "CSymbTableBuilder.h"
#include "CTypeChecker.h"
#include "IRTreeBuilder.h"
#include "CMiniJException.h"
#include "CIRTreeToGraphConverter.h"
#include "IRTreeCanonicalConverter.h"
#include "IRTreeLinearConverter.h"
#include "IRTreeCallConverter.h"

int yyparse( CProgram*& root );

void PrintIRTree( const std::vector<Frame::CFrame*>& frames )
{
	for( const auto& frame : frames ) {
		CIRTreeToGraphConverter irTreeToGraphConverter(
			std::string( "IRTree_" ) + frame->GetFrameName() + std::string( ".dot" ) );

		frame->root->Accept( &irTreeToGraphConverter );
		irTreeToGraphConverter.Flush();
	}
}

void ConvertIRTree( std::vector<Frame::CFrame*>& frames )
{
	// Canocicalize
	for( auto& frame : frames ) {
		CIRTreeCanonicalConverter irTreeCanonConverter(frame->root);
		frame->root = irTreeCanonConverter.frameRoot;
		frame->root->Accept( &irTreeCanonConverter );
	}
	std::cout << "	Canocicolize: done" << std::endl;
	// Move calls to top level
	for( auto& frame : frames ) {
		CIRTreeCallConverter irTreeCallConverter( frame->root );
		frame->root->Accept( &irTreeCallConverter );
	}
	std::cout << "	Calls->TopLevel: done" << std::endl;
	// Linearize
	for( auto& frame : frames ) {
		CIRTreeLinearConverter irTreeLinearConverter( frame->root );
		frame->root->Accept( &irTreeLinearConverter );
	}
	std::cout << "	Linearize: done" << std::endl;
}

int main( int argc, char *argv[] )
{
	if( argc < 2 ) {
		printf( "Please, add <input file> parameter\n" );
	}

	extern FILE* yyin;
	yyin = fopen( argv[1], "r" );

	CProgram* root;

	try {
		if( !yyparse( root ) ) {
			std::cout << "Syntax analysis: success" << std::endl;
		}

		// CPrettyPrinterVisitor prettyVisitor;
		// prettyVisitor.visit( root );

		CSymbTableBuilder symbTableBuilder;
		symbTableBuilder.visit( root );
		std::cout << "Symbol table: success" << std::endl;

		CTypeChecker typeChecker( symbTableBuilder.GetSymbolTable() );
		typeChecker.visit( root );
		std::cout << "Type checker: success" << std::endl;

		CIRTreeBuilder irTreeBuilder( symbTableBuilder.GetSymbolTable() );
		irTreeBuilder.visit( root );
		std::cout << "IRTree builder: success" << std::endl;

		CanonizeIRTree( irTreeBuilder.GetFrames() );
		std::cout << "Canonizing IRTree: success" << std::endl;

		PrintIRTree(irTreeBuilder.GetFrames());
		std::cout << "Printing frames: success" << std::endl;

		fclose( yyin );
	}
	catch( CMiniJException& e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
