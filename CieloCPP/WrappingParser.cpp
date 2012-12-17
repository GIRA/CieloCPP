#include "StdAfx.h"
#include "WrappingParser.h"


WrappingParser::WrappingParser(Parser* p, std::function<ParseResult*(stringStream*,std::function<ParseResult*(void)>)> f)
{
	_internalParser=p;
	_f=f;

}


WrappingParser::~WrappingParser(void)
{
}

ParseResult* WrappingParser::ParseOn(stringStream* s)
{
	Parser* p = _internalParser;
	std::function<ParseResult*(void)> temp;
	temp = [s,p]{return p->ParseOn(s);};
	return _f(s,temp);
}