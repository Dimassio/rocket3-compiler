#include <cstdio>
#include <iostream>
#include "StaticVariables.h"
#include "CPrettyVisitor.h"
#include "CSymbTableBuilder.h"
#include "CTypeChecker.h"
#include "IRTreeBuilder.h"
#include "CMiniJException.h"

int yyparse( CProgram*& root );

int main( int argc, char *argv[] )
{
	if( argc < 2 ) {
		printf( "Please, add <input file> parameter\n" );
	}

	extern FILE *yyin;
	yyin = fopen( argv[1], "r" );

	CProgram* root;

	try {
		if( !yyparse( root ) ) {
			std::cout << "syntax analysis: success" << std::endl;
		}

		// CPrettyPrinterVisitor prettyVisitor;
		// prettyVisitor.visit( root );

		CSymbTableBuilder symbTableBuilder;
		symbTableBuilder.visit( root );

		CTypeChecker typeChecker( symbTableBuilder.GetSymbolTable() );
		typeChecker.visit( root );

		CIRTreeBuilder irTreeBuilder( symbTableBuilder.GetSymbolTable() );
		//irTreeBuilder.visit(root);

		fclose( yyin );
	}
	catch( CMiniJException& e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
