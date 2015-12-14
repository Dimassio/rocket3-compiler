#pragma once

#include "IRTree.h"
#include "Temp.h"
#include "EOperation.h"

using namespace IRTree;

class CIRMove: public IIRStm {
public:
	CIRMove( const IIRExp* _dst, const IIRExp* _src );

	~CIRMove();

private:
	const IIRExp* dst;
	const IIRExp* src;
};

class CIRExp: public IIRStm {
public:
	CIRExp( const IIRExp* _exp );

	~CIRExp();

private:
	const IIRExp* exp;
};

class CIRJump: public IIRStm {
public:
	CIRJump( const IIRExp* _exp, const Temp::CLabelList* _targets );

	~CIRJump();

private:
	const IIRExp* exp;
	const Temp::CLabelList* targets;
};

class CIRLabel: public IIRStm {
public:
	CIRLabel( const Temp::CLabel* _label );

	~CIRLabel();

private:
	const Temp::CLabel* label;
};


class CIRCJump: public IIRStm {
public:
	CIRCJump( const EOperation op, const IIRExp* _left, const IIRExp* _right, const CIRLabel* _iftrue, const CIRLabel* _iffalse );

	~CIRCJump();

private:
	const EOperation op;
	const IIRExp* left;
	const IIRExp* right;
	const CIRLabel* iftrue;
	const CIRLabel* iffalse;
};

class CIRSeq: public IIRStm {
public:
	CIRSeq( const IIRStm* _left, const IIRStm* _right );

	~CIRSeq();

private:
	const IIRStm* left;
	const IIRStm* right;
};


class CIRPrint: public IIRStm {
public:
	CIRPrint( const IIRExp* _exp );

	~CIRPrint();

private:
	const IIRExp* exp;
};