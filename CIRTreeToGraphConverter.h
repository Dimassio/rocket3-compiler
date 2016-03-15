#pragma once

#include "Graph.h"
#include "IRTree.h"
#include "IIRTreeVisitor.h"

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

	void visit(const CIRMove* node);

	void visit(const CIRExp* node);

	void visit(const CIRJump* node);

	void visit(const CIRCJump* node);

	void visit(const CIRSeq* node);

	void visit(const CIRConst* node);

	void visit(const CIRName* node);

	void visit(const CIRTemp* node);

	void visit(const CIRBinOp* node);

	void visit(const CIRMem* node);

	void visit(const CIRCall* node);

	void visit(const CIRESeq* node);

	void visit(const CIRExpList* node);

	void visit(const CIRLabel* node);

	void Flush() { treeRepresentation.Flush(); }

private:

	int minId;

	std::string lastNodeName;

	CGraph treeRepresentation;

	void nextNameWithId(const std::string& label);
};