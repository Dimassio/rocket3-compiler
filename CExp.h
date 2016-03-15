#pragma once
#include "Temp.h"
#include "IRTree.h"
#include "EOperation.h"
#include "IIRTreeVisitor.h"

using namespace IRTree;

// Вызов фунции exp, от параметров expList
class CIRCall: public IIRExp {
public:
	CIRCall( const  IIRExp* _exp, const CIRExpList* _expList );
	~CIRCall();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRExp* exp;
	const CIRExpList* expList;
};


// Представление константы value
class CIRConst: public IIRExp {
public:
	CIRConst( const int _value );
	~CIRConst();

	void Accept(IIRTreeVisitor* visitor) const;

	const int value;
};

// Обычная бинарная операция
class CIRBinOp: public IIRExp {
public:
	CIRBinOp( const EOperation binop, const IIRExp* _left, const IIRExp* _right );
	~CIRBinOp();

	void Accept(IIRTreeVisitor* visitor) const;

	const EOperation opId;
	const IIRExp* left;
	const IIRExp* right;
};

// exp + stm => return exp
class CIRESeq: public IIRExp {
public:
	CIRESeq( const IIRStm* _stm, const IIRExp* _exp );
	~CIRESeq();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRExp* exp; // left node expression
	const IIRStm* stm; // right node statement
};


// Получение адрес exp
class CIRMem: public IIRExp {
public:
	CIRMem( const IIRExp* _exp );
	~CIRMem();

	void Accept(IIRTreeVisitor* visitor) const;

	const IIRExp* exp;
};

// Представляет собой Label
class CIRName: public IIRExp { 
public:
	CIRName( const Temp::CLabel* _label );
	~CIRName();

	void Accept(IIRTreeVisitor* visitor) const;

	const Temp::CLabel* label;
};

// Temprorary
class CIRTemp: public IIRExp {
public:
	CIRTemp( const Temp::CTemp* _temp );
	~CIRTemp();

	void Accept(IIRTreeVisitor* visitor) const;

	const Temp::CTemp* temp;
};
