#pragma once

#include <stack>
#include <set>
#include <list>
#include <map>
#include <vector>

namespace Assembler
{
	class CVariableNode {
	public:
		CVariableNode()
		{
			Color = -1;
			InStack = false;
		}
		int Color;
		bool InStack;
	};

	class CInterferenceGraph {
	public:
		explicit CInterferenceGraph( const std::list<const CBaseInstruction*>& asmFunction, const std::vector<std::string>& registers );

	private:
		std::list<const CBaseInstruction*> asmFunction;
		std::vector<std::string> registers;

	};
}
