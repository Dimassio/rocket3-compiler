#include <cstdio>
#include <iostream>
#include "StaticVariables.h"
#include "CPrettyVisitor.h"
#include "CSymbTableBuilder.h"
#include "CTypeChecker.h"
#include "IRTreeBuilder.h"
#include "CMiniJException.h"
#include "CIRTreeToGraphConverter.h"

int yyparse( CProgram*& root );

/* TODO: Don't forget to add definition of memset and malloc to symbol table!*/

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

		for (const auto& frame : irTreeBuilder.frames) {
			IRTree::CIRTreeToGraphConverter irTreeToGraphConverter(
				std::string("IRTree_") + frame->GetFrameName() + std::string(".dot"));

			frame->root->Accept(&irTreeToGraphConverter);
			irTreeToGraphConverter.Flush();
		}

		fclose( yyin );
	}
	catch( CMiniJException& e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
