#include "StdAfx.h"
#include "ChoiceParser.h"


ChoiceParser::ChoiceParser(Parser* first, Parser* second)
{
	_first=first;
	_second = second;
}


ChoiceParser::~ChoiceParser(void)
{
}

Parser* ChoiceParser::Or(Parser* p)
{
	//here i say that if you want to add another condition
	//the second condition of this choice will be replaced with a new choice
	//whose first choice will be the original second of this condition
	//and the second choice will be the new one.

	_second = new ChoiceParser(_second,p);
	return this;
}

ParseResult* ChoiceParser::ParseOn(stringStream* s)
{
	ParseResult* fail = new ParseFailure("",0);
	
	ParseResult* p = _first->ParseOn(s);
	if(p->IsSuccess()) 
	{return p;}else{fail = p;}
	p = _second->ParseOn(s);
	if(p->IsSuccess()) 
	{return p;}else{fail=p;}

	return fail;
}