#pragma once
#include "Temp.h"
#include "IRTree.h"

using namespace IRTree;

class CIRCall: public  IExp {
public:
	CIRCall( const  IExp* _exp, const CIRExpList* _expList ):
		exp( _exp ), expList( _expList )
	{
	}

	~CIRCall();

private:
	const IExp* exp;
	const CIRExpList* expList;
};

class CIRConst: public  IExp {
public:
	CIRConst( const int _value ):
		value( _value )
	{
	}

	~CIRConst();

private:
	const int value;
};


class CIRBinOp: public  IExp {
public:
	CIRBinOp( const int binop, const IExp* _left, const IExp* _right ):
		opId( binop ), left( _left ), right( _right )
	{
	}

	~CIRBinOp();

private:
	const int opId; // 0 +, 1-, 2*, 3 /, 4 &&
	const IExp* left;
	const IExp* right;
};

class CIRESeq: public  IExp {
public:
	CIRESeq( const IStm* _stm, const IExp* _exp ):
		exp( _exp ), stm( _stm )
	{
	}

	~CIRESeq();

private:
	const IExp* exp;
	const IStm* stm;
};


class CIRMem: public  IExp {
public:
	CIRMem( const IExp* _exp ):
		exp( _exp )
	{
	}

	~CIRMem();

private:
	const IExp* exp;
};

class CIRName: public  IExp {
public:
	CIRName( const Temp::CLabel* _label ):
		label( _label )
	{
	}

	~CIRName();

private:
	const Temp::CLabel* label;
};

class CIRTemp: public  IExp {
public:
	CIRTemp( const Temp::CTemp* _temp ):
		temp( _temp )
	{
	}

	~CIRTemp();

private:
	const Temp::CTemp* temp;
};