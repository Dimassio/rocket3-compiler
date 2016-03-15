#pragma once

#include "IRTreeBuilder.h"
#include "CExp.h"
#include "CStm.h"
#include "IRTree.h"

namespace IRTree {
	class IIRTreeVisitor {
	public:
		virtual void visit(const CIRMove* node) = 0;

		virtual void visit(const CIRExp* node) = 0;

		virtual void visit(const CIRJump* node) = 0;

		virtual void visit(const CIRCJump* node) = 0;

		virtual void visit(const CIRSeq* node) = 0;

		virtual void visit(const CIRConst* node) = 0;

		virtual void visit(const CIRName* node) = 0;

		virtual void visit(const CIRTemp* node) = 0;

		virtual void visit(const CIRBinOp* node) = 0;

		virtual void visit(const CIRMem* node) = 0;

		virtual void visit(const CIRCall* node) = 0;

		virtual void visit(const CIRESeq* node) = 0;

		virtual void visit(const CExpList* node) = 0;

		virtual void visit(const CIRLabel* node) = 0;
	};

} // namespace IRTree
