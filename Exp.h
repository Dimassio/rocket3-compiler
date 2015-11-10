#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExp : public IExp {
public:
	CExp(IExpLength* _expLength,
		IExpMethodCall* _expMethodCall,
		IExpNewIntArray* _expNewIntArray,
		IExpNewCustomType* _expNewCustomType,
		IExpSquareBrackets* _expSquareBrackets,
		IExpRoundBrackets* _expRoundBrackets,
		IExpNot* _expNot,
		IExpNumber* _expNumber,
		IExpId* _expId,
		IExpSingle* _expSingle,
		IExpBinOperation* _expBinOperation, int yylineno
	);

	void Accept(IVisitor* visitor) const;

	const IExpLength* ExpLength() const;
	const IExpMethodCall* ExpMethodCall() const;
	const IExpNewIntArray* ExpNewIntArray() const;
	const IExpBinOperation* ExpBinOperation() const;
	const IExpNewCustomType* ExpNewCustomType() const;
	const IExpSquareBrackets* ExpSquareBrackets() const;
	const IExpRoundBrackets* ExpRoundBrackets() const;
	const IExpNot* ExpNot() const;
	const IExpNumber* ExpNumber() const;
	const IExpId* ExpId() const;
	const IExpSingle* ExpSingle() const;
	int yylineno;
private:
	IExpLength* expLength;
	IExpMethodCall* expMethodCall;
	IExpNewIntArray* expNewIntArray;
	IExpNewCustomType* expNewCustomType;
	IExpSquareBrackets* expSquareBrackets;
	IExpBinOperation* expBinOperation;
	IExpRoundBrackets* expRoundBrackets;
	IExpNot* expNot;
	IExpNumber* expNumber;
	IExpId* expId;
	IExpSingle* expSingle;
};
