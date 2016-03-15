#pragma once

#include "IRTree.h"
#include "Temp.h"
#include "EOperation.h"
#include "IIRTreeVisitor.h"

using namespace IRTree;

// 1. Move(Temp(t), e) - перенести e в temprorary t
// 2. Move(Mem(e1), e2) - закинуть результат e2 в память. начиная с адреса Mem(e1)
class CIRMove: public IIRStm {
public:
	CIRMove( const IIRExp* _dst, const IIRExp* _src );
	~CIRMove();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRExp* dst;
	const IIRExp* src;
};


class CIRExp: public IIRStm {
public:
	CIRExp( const IIRExp* _exp );
	~CIRExp();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRExp* exp;
};

class CIRJump: public IIRStm {
public:
	CIRJump( const IIRExp* _exp, const Temp::CLabel* _label );
	~CIRJump();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRExp* exp;
	const Temp::CLabel* label;
};


// Куда прыгать в CIRCJump, CIRJump
class CIRLabel: public IIRStm {
public:
	CIRLabel( const Temp::CLabel* _label );
	~CIRLabel();

	void Accept(IIRTreeVisitor* visitor) const;

	const Temp::CLabel* label;
};


class CIRCJump: public IIRStm {
public:
	CIRCJump( const EOperation op, const IIRExp* _left, const IIRExp* _right, const CIRLabel* _iftrue, const CIRLabel* _iffalse );
	~CIRCJump();

	void Accept(IIRTreeVisitor* visitor) const;

	const EOperation op;
	const IIRExp* left;
	const IIRExp* right;
	const CIRLabel* iftrue;
	const CIRLabel* iffalse;
};

// Связываем 2 stm: сначала идет left stm, потом right stm
class CIRSeq: public IIRStm {
public:
	CIRSeq( const IIRStm* _left, const IIRStm* _right );
	~CIRSeq();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRStm* left;
	const IIRStm* right;
};