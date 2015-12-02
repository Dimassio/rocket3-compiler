#include "CStm.h"
#include "IRTree.h"

using namespace IRTree;

CIRMove::CIRMove(const IIRExp* _dst, const IIRExp* _src) :
	dst(_dst), src(_src)
{
}

CIRMove::~CIRMove()
{
}

CIRExp::CIRExp(const IIRExp* _exp) :
	exp(_exp)
{
}

CIRExp::~CIRExp()
{
}

CIRJump::CIRJump(const IIRExp* _exp, const Temp::CLabelList* _targets) :
	targets(_targets), exp(_exp)
{
}

CIRJump::~CIRJump()
{
}

CIRCJump::CIRCJump(const EOperation op, const IIRExp* _left, const IIRExp* _right, const Temp::CLabel* _iftrue, const Temp::CLabel* _iffalse) :
	relop(op), left(_left), right(_right), iftrue(_iftrue), iffalse(_iffalse)
{
}

CIRCJump::~CIRCJump()
{
}

CIRSeq::CIRSeq(const IIRStm* _left, const IIRStm* _right) :
	left(_left), right(_right)
{
}

CIRSeq::~CIRSeq()
{
}

CIRLabel::CIRLabel(const Temp::CLabel* _label) :
	label(_label)
{
}

CIRLabel::~CIRLabel()
{
}
