#pragma once
#include "parser.h"
class EndParser :
	public Parser
{
public:
	EndParser(Parser* p);
	~EndParser(void);	
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	Parser* _internalParser;
};

