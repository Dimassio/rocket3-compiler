#include "BaseInstruction.h"
#include <iostream>

std::string Assembler::CBaseInstruction::Format( const std::map<std::string, std::string>& varsMapping ) const
{
	Temp::CTempList* src = UsedVars();
	Temp::CTempList* dst = DefindedVars();
	Temp::CLabelList* jumps = JumpTargets();

	std::string instr;
	for( int i = 0; i < assemblerInstruction.length(); ++i ) {
		if( assemblerInstruction[i] == '\'' ) {
			bool breakFlag = false;
			switch( assemblerInstruction[++i] ) {
				case 's':
				{
					int n = assemblerInstruction[++i] - '0';
					instr += varsMapping.at( getNthTemp( src, n )->Name() );
					break;
				}
				case 'd':
				{
					int n = assemblerInstruction[++i] - '0';
					instr += varsMapping.at( getNthTemp( dst, n )->Name() );
					break;
				}
				case 'j':
				{
					int n = assemblerInstruction[++i] - '0';
					instr += getNthLabel( jumps, n )->Name();
					break;
				}
				case 'l':
				{
					instr += jumps->Head()->Name() + '\n';
					breakFlag = true;
					break;
				}
			}
			if( breakFlag ) {
				break;
			}
		} else {
			instr += assemblerInstruction[i];
		}
	}

	return instr;
}

const Temp::CTemp* Assembler::CBaseInstruction::getNthTemp( Temp::CTempList* list, int i ) const
{
	if( i == 0 ) {
		return list->Head();
	}
	return getNthTemp( const_cast< Temp::CTempList* >( list->Tail() ), i - 1 );
}

const Temp::CLabel* Assembler::CBaseInstruction::getNthLabel( Temp::CLabelList* list, int i ) const
{
	if( i == 0 ) {
		return list->Head();
	}
	return getNthLabel( const_cast< Temp::CLabelList* >( list->Tail() ), i - 1 );
}
