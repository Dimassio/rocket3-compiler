#pragma once
#include "Temp.h"
#include "IRTree.h"
#include "EOperation.h"

using namespace IRTree;

class CIRCall: public IIRExp {
public:
	CIRCall(const  IIRExp* _exp, const CIRExpList* _expList);

	~CIRCall();

private:
	const IIRExp* exp;
	const CIRExpList* expList;
};

class CIRConst: public IIRExp {
public:
	CIRConst(const int _value);

	~CIRConst();

private:
	const int value;
};

class CIRBinOp: public IIRExp {
public:
	CIRBinOp(const EOperation binop, const IIRExp* _left, const IIRExp* _right);

	~CIRBinOp();

private:
	const EOperation opId; // 0 +, 1-, 2*, 3 /, 4 &&
	const IIRExp* left;
	const IIRExp* right;
};

class CIRESeq: public IIRExp {
public:
	CIRESeq(const IIRStm* _stm, const IIRExp* _exp);

	~CIRESeq();

private:
	const IIRExp* exp;
	const IIRStm* stm;
};

class CIRMem: public IIRExp {
public:
	CIRMem(const IIRExp* _exp);

	~CIRMem();

private:
	const IIRExp* exp;
};

class CIRName: public IIRExp {
public:
	CIRName(const Temp::CLabel* _label);

	~CIRName();

private:
	const Temp::CLabel* label;
};

class CIRTemp: public IIRExp {
public:
	CIRTemp(const Temp::CTemp* _temp);

	~CIRTemp();

private:
	const Temp::CTemp* temp;
};
