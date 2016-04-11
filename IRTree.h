#pragma once
#include "IIRTreeVisitor.h"
#include <list>
#include <cassert>

class IIRExp {
public:
	/*CONST( int value )
	  NAME( Label label )
	  TEMP( Temp.Temp temp )
	  BINOP( int binop, Exp left, Exp right )
	  MEM( Exp exp )
	  CALL( Exp func, ExpList args )
	  ESEQ( Stm stm, Exp exp )*/

	virtual ~IIRExp()
	{
	}

	virtual void Accept( IIRTreeVisitor* visitor ) const = 0;

	// for tree converting
	virtual void Accept( IIRTreeConvertVisitor* visitor ) = 0;
};

class IIRStm {
public:
	/*MOVE(Exp dst, Exp src):
		EXP(Exp exp)
		JUMP(Exp exp, Temp.LabelList targets)
		CJUMP(int relop, Exp left, Exp right, Label iftrue, Label iffalse)
		SEQ(Stm left, Stm right)
		LABEL(Label label)*/

	virtual ~IIRStm()
	{
	}

	virtual void Accept( IIRTreeVisitor* visitor ) const = 0;

	// for tree converting
	virtual void Accept( IIRTreeConvertVisitor* visitor ) = 0;
};

class CIRExpList {
public:
	CIRExpList( IIRExp* head, CIRExpList* tail );
	CIRExpList( const std::list<IIRExp*>& expList );
	~CIRExpList();

	void Accept( IIRTreeVisitor* visitor ) const;
	void Accept( IIRTreeConvertVisitor* visitor ) const;
	void Add( IIRExp* exp );

	std::list<IIRExp*> expList;  // first IIRExp to this
};