#include <cstdio>
#include <iostream>
#include "CPrettyVisitor.h"

int yyparse(CProgram*& root);

int main( int argc, char *argv[] )
{
	if( argc < 2 ) {
		printf( "Please, add <input file> parameter\n" );
	}

	extern FILE *yyin;
	yyin = fopen( argv[1], "r" );

	CProgram* root;

	if( !yyparse( root ) ) {
		std::cout << "SUCCESS" << std::endl;
	}

	CPrettyPrinterVisitor prettyVisitor;
	prettyVisitor.visit( root );

	fclose( yyin );

	return 0;
}