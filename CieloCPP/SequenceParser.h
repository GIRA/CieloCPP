#pragma once
#include "parser.h"
#include "List.h"
#include "ParseSuccess.h"
class SequenceParser :
	public Parser
{
public:
	SequenceParser(Parser* first, Parser* second);
	~SequenceParser(void);
	virtual Parser* Then(Parser* p) override;	
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	//i will change the implementation, instead of having an array a ChoiceParser will only work with 2 parts
	//when added a condition the second parser will become a choice, creatint a linked list of parsers
	Parser* _first;
	Parser* _second;
};

