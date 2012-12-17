#include "StdAfx.h"
#include "PredicateParser.h"


PredicateParser::PredicateParser(std::function<bool(char)> f ,std::string m)
{
	_f=f;
	msg=m;
}


PredicateParser::~PredicateParser(void)
{
}

ParseResult* PredicateParser::ParseOn(stringStream* s)
{
	if(!s->isAtEnd())
	{
		if(_f(s->peek()))
		{
			return new ParseSuccess(new ObjString( s->next()));
		}
	}
	return new ParseFailure("ended",s->getPosition());
}