#pragma once

#include "Graph.h"
#include "IIRTreeVisitor.h"

namespace IRTree {
	class CIRTreeToGraphConverter : public IIRTreeVisitor {
	public:
		CIRTreeToGraphConverter(const std::string& treeFileName)
			: treeRepresentation(treeFileName)
			, minId(0)
		{
		}

		// ћетоды позвол€ют строить линейно св€занные деревь€
		void LinkedVisit(const IIRStm* node);
		void LinkedVisit(const IIRExp* node);

		virtual void visit(const CIRMove* node);

		virtual void visit(const CIRExp* node);

		virtual void visit(const CIRJump* node);

		virtual void visit(const CIRCJump* node);

		virtual void visit(const CIRSeq* node);

		virtual void visit(const CIRConst* node);

		virtual void visit(const CIRName* node);

		virtual void visit(const CIRTemp* node);

		virtual void visit(const CIRBinOp* node);

		virtual void visit(const CIRMem* node);

		virtual void visit(const CIRCall* node);

		virtual void visit(const CIRESeq* node);

		virtual void visit(const CIRExpList* node);

		virtual void visit(const CIRLabel* node);

		void Flush() { treeRepresentation.Flush(); }

	private:

		int minId;

		std::string lastNodeName;

		CGraph treeRepresentation;

		void nextNameWithId(const std::string& label);
	};

} // namespace IRTree