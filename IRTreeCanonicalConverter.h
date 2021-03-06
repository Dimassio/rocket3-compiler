#pragma once

#include "IRTree.h"
#include "IIRTreeVisitor.h"

class CIRTreeCanonicalConverter: public IIRTreeVisitor {
public:
	CIRTreeCanonicalConverter(IIRExp*);

	void visit( const CIRMove* node );

	void visit( const CIRExp* node );

	void visit( const CIRJump* node );

	void visit( const CIRCJump* node );

	void visit( const CIRSeq* node );

	void visit( const CIRConst* node );

	void visit( const CIRName* node );

	void visit( const CIRTemp* node );

	void visit( const CIRBinOp* node );

	void visit( const CIRMem* node );

	void visit( const CIRCall* node );

	void visit( const CIRESeq* node );

	void visit( const CIRExpList* node );

	void visit( const CIRLabel* node );

	void siftUpEseqs(const CIRCall* node);

	IIRStm* lastNodeStm;
	IIRExp* lastNodeExp;
	CIRExpList* lastNodeExpList;

	IIRExp* frameRoot;
	IIRStm* frameCanonRoot;

};