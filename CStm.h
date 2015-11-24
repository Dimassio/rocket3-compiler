#include "IRTree.h"
#include "Temp.h"

using namespace IRTree;

class CIRMove: public IStm {
public:
	CIRMove( IExp* _dst, IExp* _src ):
		dst( _dst ), src( _src )
	{
	}

	~CIRMove();

private:
	IExp* dst;
	IExp* src;
};

class CIRExp: public IStm {
public:
	CIRExp( IExp* _exp ):
		exp( _exp )
	{
	}

	~CIRExp();

private:
	IExp* exp;
};

class CIRJump: public IStm {
public:
	CIRJump( IExp* _exp, Temp::CLabelList* _targets ):
		targets( _targets ), exp( _exp )
	{
	}

	~CIRJump();

private:
	IExp* exp;
	Temp::CLabelList* targets;
};

class CIRCJump: public IStm {
public:
	CIRCJump( int op, IExp* _left, IExp* _right, Temp::CLabel* _iftrue, Temp::CLabel* _iffalse ):
		relop( op ), left( _left ), right( _right ), iftrue( _iftrue ), iffalse( _iffalse )
	{
	}

	~CIRCJump();

private:
	int relop;
	IExp* left;
	IExp* right;
	Temp::CLabel* iftrue;
	Temp::CLabel* iffalse;
};


class CIRSeq: public IStm {
public:
	CIRSeq( IStm* _left, IStm* _right ):
		left( _left ), right( _right )
	{
	}

	~CIRSeq();

private:
	IStm* left;
	IStm* right;
};


class CIRLabel: public IStm {
public:
	CIRLabel( Temp::CLabel* _label ):
		label( _label )
	{
	}

	~CIRLabel();

private:
	Temp::CLabel* label;
};