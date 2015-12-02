#include "Translate.h"

using namespace Translate;

CExpConverter::CExpConverter(const IRTree::IIRExp* _exp)
	: exp(_exp)
{
}

const IRTree::IIRExp* CExpConverter::ToExp() const
{
	return exp;
}

const IRTree::IIRStm* CExpConverter::ToStm() const
{
	return nullptr;
}

const IRTree::IIRStm* CExpConverter::ToConditional(const Temp::CLabel* trueLable, const Temp::CLabel* falseLable) const
{
	return nullptr;
}

CStmConverter::CStmConverter(const IRTree::IIRStm * _stm) :
	stm(_stm)
{
}

const IRTree::IIRExp* CStmConverter::ToExp() const
{
	return nullptr;
}

const IRTree::IIRStm* CStmConverter::ToStm() const
{
	return stm;
}

const IRTree::IIRStm* CStmConverter::ToConditional(const Temp::CLabel* trueLable, const Temp::CLabel* falseLable) const
{
	return nullptr;
}
