#pragma once
#include "parser.h"
#include "ParseFailure.h"
#include "ParseSuccess.h"
class NotParser :
	public Parser
{
public:
	NotParser(Parser* p);
	~NotParser(void);
	
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	Parser* _internalParser;

};

