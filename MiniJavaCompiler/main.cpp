#include <cstdio>
extern "C" int yylex();

int main( int argc, char *argv[] )
{
	if( argc < 2 ) {
		printf( "Please, add <input file> parameter\n" );
	}

	extern FILE *yyin;
	yyin = fopen( argv[1], "r" );

	while( yylex() != 0 );

	fclose( yyin );
	return 0;
}