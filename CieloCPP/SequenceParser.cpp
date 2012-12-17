#include "StdAfx.h"
#include "SequenceParser.h"


SequenceParser::SequenceParser(Parser* first, Parser* second)
{
	_first=first;
	_second = second;
}


SequenceParser::~SequenceParser(void)
{
}

Parser* SequenceParser::Then(Parser* p)
{
	//read ChoiceParser's Or

	_second = new SequenceParser(_second,p);
	return this;
}

ParseResult* SequenceParser::ParseOn(stringStream* s)
{
	int start = s->getPosition();
	List* elements= new List();
	//this could be a problem, i think the method push of list actually makes a copy of the element.
	ParseResult* p = _first->ParseOn(s);
	if(p->IsSuccess())
	{
		elements->add(p->getActualResult());
	}
	else
	{
		s->setPosition(start);
		return p;
	}
	p = _second->ParseOn(s);
	if(p->IsSuccess())
	{
		elements->add(p->getActualResult());
	}
	else
	{
		s->setPosition(start);
		return p;
	}
	
	return new ParseSuccess(elements);
}