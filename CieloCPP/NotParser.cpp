#include "StdAfx.h"
#include "NotParser.h"


NotParser::NotParser(Parser* p)
{
	_internalParser =p;
}


NotParser::~NotParser(void)
{
}

ParseResult* NotParser::ParseOn(stringStream* s)
{
	int position = s->getPosition();
	ParseResult * result = _internalParser->ParseOn(s);
	s->setPosition(position);
	if(result->IsSuccess())
	{
		return new ParseFailure("",s->getPosition());
	}else{
		//i should implement nothing..
		return new ParseSuccess(& Obj());
	}
}