#pragma once

namespace PrinterContext
{

	void PrintInstructions( const std::list<const Assembler::CBaseInstruction*>& function )
	{
		for( auto inst : function ) {
			std::cout << inst->GetAssemblerInstruction() << std::endl;
		}
	}

	void PrintIRTree( const std::vector<Frame::CFrame*>& frames )
	{
		for( const auto& frame : frames ) {
			CIRTreeToGraphConverter irTreeToGraphConverter(
				std::string( "IRTree_" ) + frame->GetFrameName() + std::string( ".dot" ) );

			frame->canonRoot->Accept( &irTreeToGraphConverter );
			irTreeToGraphConverter.Flush();
		}
	}

} // namespace PrinterContext