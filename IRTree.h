#pragma once

namespace IRTree
{
	class IExp {
	public:
		/*CONST( int value )
		  NAME( Label label )
		  TEMP( Temp.Temp temp )
		  BINOP( int binop, Exp left, Exp right )
		  MEM( Exp exp )
		  CALL( Exp func, ExpList args )
		  ESEQ( Stm stm, Exp exp )*/
		virtual ~IExp();
	};

	class IStm {
	public:
		/*MOVE(Exp dst, Exp src):
			EXP(Exp exp)
			JUMP(Exp exp, Temp.LabelList targets)
			CJUMP(int relop, Exp left, Exp right, Label iftrue, Label iffalse)
			SEQ(Stm left, Stm right)
			LABEL(Label label)*/
		virtual ~IStm();
	};

	class CIRExpList {

	};


	class CIRStmList {

	};
}