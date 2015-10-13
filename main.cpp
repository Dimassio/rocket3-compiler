#include <cstdio>
#include <iostream>

int yyparse();

int main( int argc, char *argv[] )
{
	if( argc < 2 ) {
		printf( "Please, add <input file> parameter\n" );
	}

	extern FILE *yyin;
	yyin = fopen( argv[1], "r" );
	if( !yyparse() ) {
		std::cout << "SUCCESS" << std::endl;
	}

	fclose( yyin );

	return 0;
}