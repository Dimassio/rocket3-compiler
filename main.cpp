#include <cstdio>
#include <iostream>
#include "miniJava.tab.hpp"

int main( int argc, char *argv[] )
{
	if( argc < 2 ) {
		printf( "Please, add <input file> parameter\n" );
	}

	extern FILE *yyin;
	yyin = fopen( argv[1], "r" );
	int* error = new int;
	if( !yyparse( error ) ) {
		std::cout << "SUCCESS" << std::endl;
	}

	fclose( yyin );

	return 0;
}