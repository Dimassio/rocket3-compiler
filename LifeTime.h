#pragma once

#include "BaseInstruction.h"
#include <set>
#include <string>
#include <vector>
#include <map>

namespace RegistrarAllocation
{
	struct CNode {
		std::vector<int> in;
		std::vector<int> out;
	};

	// Ориентированный граф
	class CGraph {
	public:
		explicit CGraph( size_t size );
		void AddEdge( size_t from, size_t to );
		size_t Size() const;
		const CNode& GetNode( size_t index ) const;

	protected:
		std::vector<CNode> nodes;
	};


	class CWorkFlowGraph: public CGraph {
	public:
		explicit CWorkFlowGraph( const std::list<const Assembler::CBaseInstruction*>& asmFunction );

	private:
		// На какую вершину по лэйблу прыгнем
		std::map<std::string, int> labels;

		void buildLabelMap( const std::list<const Assembler::CBaseInstruction*>& asmFunction );
		void addEdges( const std::list<const Assembler::CBaseInstruction*>& asmFunction );
	};


	class CLiveInOutCalculator {
	public:
		explicit CLiveInOutCalculator( const std::list<const Assembler::CBaseInstruction*>& asmFunction );
		const std::set<std::string>& GetLiveIn( int nodeIndex ) const;
		const std::set<std::string>& GetLiveOut( int nodeIndex ) const;
		const std::set<std::string>& GetDefines( int nodeIndex ) const;
		const std::set<std::string>& GetUses( int nodeIndex ) const;

	private:
		CWorkFlowGraph workflow;

		std::vector<std::set<std::string>> liveIn;
		std::vector<std::set<std::string>> liveOut;
		std::vector<std::set<std::string>> defines;
		std::vector<std::set<std::string>> uses;

		std::vector<const Assembler::CBaseInstruction*> commands;

		bool theSame( const std::set<std::string>& x, const std::set<std::string>& y ) const;
		void buildCommands( const std::list<const Assembler::CBaseInstruction*>& asmFunction );
		void buildDefines( const std::list<const Assembler::CBaseInstruction*>& asmFunction );
		void buildUses( const std::list<const Assembler::CBaseInstruction*>& asmFunction );
	};

} // namespace RegistrarAllocation