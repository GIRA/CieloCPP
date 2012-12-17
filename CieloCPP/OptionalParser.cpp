#include "StdAfx.h"
#include "OptionalParser.h"


OptionalParser::OptionalParser(Parser* p)
{
	_internalParser=p;
}


OptionalParser::~OptionalParser(void)
{
}

ParseResult* OptionalParser::ParseOn(stringStream* s)
{
	ParseResult* p = _internalParser->ParseOn(s);
	if(p->IsSuccess()) return p;
	return new ParseSuccess(new Null());
}