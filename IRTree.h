#pragma once
#include <list>

namespace IRTree
{
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
	};

	class CIRExpList {
	public:
		CIRExpList( IIRExp* head, CIRExpList* tail );
		CIRExpList( const std::list<IIRExp*>& expList );
		~CIRExpList();

		std::list<IIRExp*> GetExpList();
		void Add( IIRExp* exp );

	private:
		std::list<IIRExp*> expList;  // first IIRExp to this
	};

	/*We don't need it?*/
	class CIRStmList {
	public:
		CIRStmList( IIRStm* head, CIRStmList* tail );
		~CIRStmList();

		std::list<IIRStm*> GetStmList();
		void Add( IIRStm* exp );

	private:
		std::list<IIRStm*> stmList;
	};
}