#include <cstdio>
#include <iostream>
#include "Visitor.cpp"

int yyparse();

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

	/*
	1. Написать CPrettyVisitor(Visitor.cpp) (в последнюю очередь - после построение дерева в бизоне)
	2. Далее нужно написать по методу н каждую реализацию классов СProgram, CClassDecls, .....
	3. Когда он вызывается от одного из классов, он печатает структуру вершины.
	*/
	CPrettyPrinterVisitor prettyVisitor;
	prettyVisitor.visit( root );

	fclose( yyin );

	return 0;
}