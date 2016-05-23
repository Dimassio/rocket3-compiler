#include <cstdio>
#include <iostream>
#include "CPrettyVisitor.h"
#include "CSymbTableBuilder.h"
#include "CTypeChecker.h"
#include "IRTreeBuilder.h"
#include "CMiniJException.h"
#include "CIRTreeToGraphConverter.h"
#include "IRTreeCanonicalConverter.h"
#include "BasicBlocksBuilder.h"
#include "BaseInstruction.h"
#include "CodeGeneration.h"
#include "LifeTime.h"
#include "PrinterContext.h"

int yyparse( CProgram*& root );

void CanonizeIRTree( std::vector<Frame::CFrame*>& frames )
{
	// Canonicalize
	for( auto& frame : frames ) {
		CIRTreeCanonicalConverter irTreeCanonConverter( frame->root );
		frame->root->Accept( &irTreeCanonConverter );
		frame->canonRoot = irTreeCanonConverter.frameCanonRoot; // канонический!!!
	}
}

void BuildBasicBlocks( std::vector<Frame::CFrame*>& frames )
{
	for( auto& frame : frames ) {
		CBasicBlocksBuilder blockBuilder( frame->GetFrameName() );
		blockBuilder.BuildBlocks( frame->canonRoot );
		blockBuilder.SortBlocks();
		frame->blocks = blockBuilder.GetSortedBlocks();
	}
}

void GenerateCode( const std::vector<Frame::CFrame*>& frames )
{
	for( auto& frame : frames ) {
		// todo: Обязательно! 
		CCodeGeneration generator;
		generator.SetFrame( frame );
		// Склеиваем все стэйтмент в один
		std::list<const IIRStm*> statements;
		for( auto& block : frame->blocks ) {
			auto currList = block.GetStatements();
			statements.insert( statements.end(), currList.begin(), currList.end() );
		}

		// Генерация кода для функции
		std::list<const Assembler::CBaseInstruction*> funcInstructionList;
		generator.GenerateCode( statements, funcInstructionList );

		PrinterContext::PrintInstructions( funcInstructionList );
		// Мутки с переменными
		RegistrarAllocation::CLiveInOutCalculator calculator( funcInstructionList );
		// Далее используй как calculator.GetBlabla(...) в нужной вершине
		//CInterferenceGraph in RegisterDistribution cpp/h
	}
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

		PrinterContext::PrintIRTree( irTreeBuilder.GetFrames() );
		std::cout << "Printing frames: success" << std::endl;

		BuildBasicBlocks( irTreeBuilder.GetFrames() );
		std::cout << "Building basic blocks: success" << std::endl;

		// Каждая инструкция - move/label/exp
		GenerateCode( irTreeBuilder.GetFrames() );
		std::cout << "Code generating : success" << std::endl;

		fclose( yyin );
	}
	catch( CMiniJException& e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
