#pragma once
#include "parser.h"
class ChoiceParser :
	public Parser
{
public:
	ChoiceParser(Parser* first, Parser* second);
	~ChoiceParser(void);
	virtual Parser* Or(Parser* p) override;	
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	//i will change the implementation, instead of having an array a ChoiceParser will only work with 2 parts
	//when added a condition the second parser will become a choice, creatint a linked list of parsers
	Parser* _first;
	Parser* _second;
};

