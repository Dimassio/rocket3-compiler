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
	1. �������� CPrettyVisitor(Visitor.cpp) (� ��������� ������� - ����� ���������� ������ � ������)
	2. ����� ����� �������� �� ������ � ������ ���������� ������� �Program, CClassDecls, .....
	3. ����� �� ���������� �� ������ �� �������, �� �������� ��������� �������.
	*/
	CPrettyPrinterVisitor prettyVisitor;
	prettyVisitor.visit( root );

	fclose( yyin );

	return 0;
}