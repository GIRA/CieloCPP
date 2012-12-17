#include "StdAfx.h"
#include "RepeatingParser.h"


RepeatingParser::RepeatingParser(Parser* p, int min, int max)
{
	_min=min;
	_max=max;
	_internalParser=p;
}


RepeatingParser::~RepeatingParser(void)
{
}


ParseResult* RepeatingParser::ParseOn(stringStream* s)
{
	List* elements = new List();
	int start = s->getPosition();
	while(elements->size() < _min)
	{
		ParseResult* p = _internalParser->ParseOn(s);
		if(p->IsSuccess())
		{
			elements->add(p->getActualResult());

		}else{
			return p;
		}
	}

	while(elements->size()<_max)
	{
		ParseResult* p = _internalParser->ParseOn(s);
		if(p->IsSuccess())
		{
			elements->add(p->getActualResult());

		}else{
			return new ParseSuccess(elements);
		}
	}
	return new ParseSuccess(elements);
}