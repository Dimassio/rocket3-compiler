#include "RegistrarDistribution.h"
#include "BaseInstruction.h"
#include <iostream>

namespace Assembler
{
	CInterferenceGraph::CInterferenceGraph( const std::list<const CBaseInstruction*>& _asmFunction,
											const std::vector<std::string>& registers ):
		asmFunction( _asmFunction ),
		registers( registers )
	{
		// todo
	}

}