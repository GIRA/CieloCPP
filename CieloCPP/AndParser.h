#pragma once
#include "Parser.h"
class AndParser :
	public Parser
{
public:
	AndParser(Parser* internalParser);
	~AndParser(void);
	
	Parser* _internalParser;
	
	virtual ParseResult* ParseOn(stringStream*) override;
};

