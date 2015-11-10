#include "Exp.h"

CExp::CExp(IExpLength* _expLength,
	IExpMethodCall* _expMethodCall,
	IExpNewIntArray* _expNewIntArray,
	IExpNewCustomType* _expNewCustomType,
	IExpSquareBrackets* _expSquareBrackets,
	IExpRoundBrackets* _expRoundBrackets,
	IExpNot* _expNot,
	IExpNumber* _expNumber,
	IExpId* _expId,
	IExpSingle* _expSingle,
	IExpBinOperation* _expBinOperation,
	int _yylineno
	)
	: expLength(_expLength),
	expMethodCall(_expMethodCall),
	expNewIntArray(_expNewIntArray),
	expNewCustomType(_expNewCustomType),
	expSquareBrackets(_expSquareBrackets),
	expRoundBrackets(_expRoundBrackets),
	expBinOperation(_expBinOperation),
	expNot(_expNot),
	expNumber(_expNumber),
	expId(_expId),
	expSingle(_expSingle),
	yylineno(_yylineno )
{
}

void CExp::Accept(IVisitor* visitor) const {
	visitor->visit(this);
}

const IExpLength* CExp::ExpLength() const {
	return expLength;
}

const IExpMethodCall* CExp::ExpMethodCall() const {
	return expMethodCall;
}

const IExpBinOperation* CExp::ExpBinOperation() const {
	return expBinOperation;
}

const IExpNewIntArray* CExp::ExpNewIntArray() const {
	return expNewIntArray;
}

const IExpNewCustomType* CExp::ExpNewCustomType() const {
	return expNewCustomType;
}

const IExpSquareBrackets* CExp::ExpSquareBrackets() const {
	return expSquareBrackets;
}

const IExpRoundBrackets* CExp::ExpRoundBrackets() const {
	return expRoundBrackets;
}

const IExpNot* CExp::ExpNot() const {
	return expNot;
}

const IExpNumber* CExp::ExpNumber() const {
	return expNumber;
}

const IExpId* CExp::ExpId() const {
	return expId;
}

const IExpSingle* CExp::ExpSingle() const {
	return expSingle;
}
