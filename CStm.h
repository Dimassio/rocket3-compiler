#include "IRTree.h"
#include "Temp.h"

using namespace IRTree;

class CIRMove: public IStm {
public:
	CIRMove( const IExp* _dst, const IExp* _src ):
		dst( _dst ), src( _src )
	{
	}

	~CIRMove();

private:
	const IExp* dst;
	const IExp* src;
};

class CIRExp: public IStm {
public:
	CIRExp( const IExp* _exp ):
		exp( _exp )
	{
	}

	~CIRExp();

private:
	const IExp* exp;
};

class CIRJump: public IStm {
public:
	CIRJump( const IExp* _exp, const Temp::CLabelList* _targets ):
		targets( _targets ), exp( _exp )
	{
	}

	~CIRJump();

private:
	const IExp* exp;
	const Temp::CLabelList* targets;
};

class CIRCJump: public IStm {
public:
	CIRCJump( const int op, const IExp* _left, const IExp* _right, const Temp::CLabel* _iftrue, const Temp::CLabel* _iffalse ):
		relop( op ), left( _left ), right( _right ), iftrue( _iftrue ), iffalse( _iffalse )
	{
	}

	~CIRCJump();

private:
	const int relop;
	const IExp* left;
	const IExp* right;
	const Temp::CLabel* iftrue;
	const Temp::CLabel* iffalse;
};


class CIRSeq: public IStm {
public:
	CIRSeq( const IStm* _left, const IStm* _right ):
		left( _left ), right( _right )
	{
	}

	~CIRSeq();

private:
	const IStm* left;
	const IStm* right;
};


class CIRLabel: public IStm {
public:
	CIRLabel( const Temp::CLabel* _label ):
		label( _label )
	{
	}

	~CIRLabel();

private:
	const Temp::CLabel* label;
};