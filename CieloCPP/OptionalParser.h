#pragma once
#include "parser.h"
#include "Null.h"
class OptionalParser :
	public Parser
{
public:
	OptionalParser(Parser* p);
	~OptionalParser(void);
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	Parser* _internalParser;
};

