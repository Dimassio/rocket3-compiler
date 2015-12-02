#include "CExp.h"
#include "IRTree.h"

using namespace IRTree;

CIRCall::CIRCall(const  IIRExp* _exp, const CIRExpList* _expList) :
	exp(_exp), expList(_expList)
{
}

CIRCall::~CIRCall()
{
}

CIRConst::CIRConst(const int _value) :
	value(_value)
{
}

CIRConst::~CIRConst()
{
}

CIRBinOp::CIRBinOp(const EOperation binop, const IIRExp* _left, const IIRExp* _right) :
	opId(binop), left(_left), right(_right)
{
}

CIRBinOp::~CIRBinOp()
{
}

CIRESeq::CIRESeq(const IIRStm* _stm, const IIRExp* _exp) :
	exp(_exp), stm(_stm)
{
}

CIRESeq::~CIRESeq()
{
}

CIRMem::CIRMem(const IIRExp* _exp) :
	exp(_exp)
{
}

CIRMem::~CIRMem()
{
}

CIRName::CIRName(const Temp::CLabel* _label) :
	label(_label)
{
}

CIRName::~CIRName()
{
}

CIRTemp::CIRTemp(const Temp::CTemp* _temp) :
	temp(_temp)
{
}

CIRTemp::~CIRTemp()
{
}
