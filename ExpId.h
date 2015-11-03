#pragma once

#include "Grammar.h"
#include "Visitor.h"
#include <string>

class CExpId : public IExpId {
public:
	CExpId( std::string _id );

	void Accept(IVisitor* visitor) const;

	const std::string Id() const;

private:
	std::string id;
};
