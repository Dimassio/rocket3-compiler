#pragma once

class CIRMove;
class CIRExp;
class CIRJump;
class CIRCJump;
class CIRSeq;
class CIRConst;
class CIRName;
class CIRTemp;
class CIRBinOp;
class CIRMem;
class CIRCall;
class CIRESeq;
class CIRExpList;
class CIRLabel;

class IIRTreeVisitor {
public:
	virtual ~IIRTreeVisitor()
	{
	}

	virtual void visit( const CIRMove* node ) = 0;

	virtual void visit( const CIRExp* node ) = 0;

	virtual void visit( const CIRJump* node ) = 0;

	virtual void visit( const CIRCJump* node ) = 0;

	virtual void visit( const CIRSeq* node ) = 0;

	virtual void visit( const CIRConst* node ) = 0;

	virtual void visit( const CIRName* node ) = 0;

	virtual void visit( const CIRTemp* node ) = 0;

	virtual void visit( const CIRBinOp* node ) = 0;

	virtual void visit( const CIRMem* node ) = 0;

	virtual void visit( const CIRCall* node ) = 0;

	virtual void visit( const CIRESeq* node ) = 0;

	virtual void visit( const CIRExpList* node ) = 0;

	virtual void visit( const CIRLabel* node ) = 0;
};

// =================================================

class IIRTreeConvertVisitor {
public:
	virtual ~IIRTreeConvertVisitor()
	{
	}

	virtual void visit( CIRMove* node ) = 0;

	virtual void visit( CIRExp* node ) = 0;

	virtual void visit( CIRJump* node ) = 0;

	virtual void visit( CIRCJump* node ) = 0;

	virtual void visit( CIRSeq* node ) = 0;

	virtual void visit( CIRConst* node ) = 0;

	virtual void visit( CIRName* node ) = 0;

	virtual void visit( CIRTemp* node ) = 0;

	virtual void visit( CIRBinOp* node ) = 0;

	virtual void visit( CIRMem* node ) = 0;

	virtual void visit( CIRCall* node ) = 0;

	virtual void visit( CIRESeq* node ) = 0;

	virtual void visit( CIRExpList* node ) = 0;

	virtual void visit( CIRLabel* node ) = 0;
};
