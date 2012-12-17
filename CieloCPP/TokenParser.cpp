#include "StdAfx.h"
#include "TokenParser.h"


TokenParser::TokenParser(Parser* p)
{
	_internalParser=p;
}


TokenParser::~TokenParser(void)
{
}

_Token* TokenParser::createToken(std::string* s)
{
	return new _Token(s);
}


ParseResult* TokenParser::ParseOn(stringStream* s)
{
	int start,stop;
	start = s->getPosition();
	ParseResult * result = _internalParser->ParseOn(s);
	stop = s->getPosition()-1;
	if(result->IsSuccess())
	{
		_Token* t = this->createToken(s->ContentsFromTo(start,stop));
		ParseSuccess* result= new ParseSuccess(t);
		return result;
		//return ParseSuccess(createToken(s->ContentsFromTo(start,stop)));
	}else{
		s->setPosition(start);
		return result;
	}

}