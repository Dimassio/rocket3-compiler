#include <cstdio>
#include <iostream>
#include "StaticVariables.h"
#include "CPrettyVisitor.h"
#include "CSymbTableBuilder.h"
#include "CTypeChecker.h"

int yyparse( CProgram*& root );

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

	// CPrettyPrinterVisitor prettyVisitor;
	// prettyVisitor.visit( root );
	
	CSymbTableBuilder symbTableBuilder; 
	symbTableBuilder.visit( root );

	CTypeChecker typeChecker( symbTableBuilder.GetSymbolTable() );
	typeChecker.visit( root );

	// todo: CIRTreeBuilder: IVisitor{};
	// CIRTreeBuilder irTreeBuilder;
	// irTreeBuilder.visit(root); - ���� ������� - ��������� �������. ������� � ������ IRTree c ��������� IStm, IExp. 
	// ���� ������ ������������� �� ���� (����� ��� ������)

	fclose( yyin );

	return 0;
}
