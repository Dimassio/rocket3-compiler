#pragma once
#include "Temp.h"
#include "IRTree.h"

using namespace IRTree;

class CIRCall: public  IExp {
public:
	CIRCall( IExp* _exp, CIRExpList* _expList ):
		exp( _exp ), expList( _expList )
	{
	}

	~CIRCall();

private:
	IExp* exp;
	CIRExpList* expList;
};

class CIRConst: public  IExp {
public:
	CIRConst( int _value ):
		value( _value )
	{
	}

	~CIRConst();

private:
	int value;
};


class CIRBinOp: public  IExp {
public:
	CIRBinOp( int binop, IExp* _left, IExp* _right ):
		opId( binop ), left( _left ), right( _right )
	{
	}

	~CIRBinOp();

private:
	int opId;
	IExp* left;
	IExp* right;
};

class CIRESeq: public  IExp {
public:
	CIRESeq( IStm* _stm, IExp* _exp ):
		exp( _exp ), stm( _stm )
	{
	}

	~CIRESeq();

private:
	IExp* exp;
	IStm* stm;
};


class CIRMem: public  IExp {
public:
	CIRMem( IExp* _func, CIRExpList* _args ):
		func( _func ), args( _args )
	{
	}

	~CIRMem();

private:
	IExp* func;
	CIRExpList* args;
};

class CIRName: public  IExp {
public:
	CIRName( Temp::CLabel _label ):
		label( _label )
	{
	}

	~CIRName();

private:
	Temp::CLabel label;
};

class CIRTemp: public  IExp {
public:
	CIRTemp( Temp::CTemp _temp ):
		temp( _temp )
	{
	}

	~CIRTemp();

private:
	Temp::CTemp temp;
};