#include "StdAfx.h"
#include "EndParser.h"


EndParser::EndParser(Parser* p)
{
	_internalParser=p;
}


EndParser::~EndParser(void)
{
}

ParseResult* EndParser::ParseOn(stringStream* s)
{
	int position = s->getPosition();
	ParseResult* result = _internalParser->ParseOn(s);
	if(result->IsFailure() || s->isAtEnd())
	{
		return result;
	}
	s->setPosition(position);
	return  new ParseFailure("End of input expected", position);
}