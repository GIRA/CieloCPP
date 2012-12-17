#include "StdAfx.h"
#include "AndParser.h"


AndParser::AndParser(Parser* internalParser)
{
	 this->_internalParser=internalParser;
}


AndParser::~AndParser(void)
{
	
	delete this ->_internalParser;
}


 ParseResult* AndParser::ParseOn(stringStream* s)
 {
	 int position = s->getPosition();
	 ParseResult* result = _internalParser->ParseOn(s);
	 s->setPosition(position);
	 return result;
	
 };