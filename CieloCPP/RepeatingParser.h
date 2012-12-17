#pragma once
#include "parser.h"
#include "ParseSuccess.h"
class RepeatingParser :
	public Parser
{
public:
	RepeatingParser(Parser* p, int min , int max);
	~RepeatingParser(void);
	
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	Parser* _internalParser;
	int _min,_max;
};

