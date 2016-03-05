#pragma once

#include "IRTree.h"
#include "Temp.h"
#include "EOperation.h"

using namespace IRTree;

// 1. Move(Temp(t), e) - ��������� e � temprorary t
// 2. Move(Mem(e1), e2) - �������� ��������� e2 � ������. ������� � ������ Mem(e1)
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


// ���� ������� � CIRCJump, CIRJump
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

// ��������� 2 stm: ������� ���� left stm, ����� right stm
class CIRSeq: public IIRStm {
public:
	CIRSeq( const IIRStm* _left, const IIRStm* _right );

	~CIRSeq();

private:
	const IIRStm* left;
	const IIRStm* right;
};