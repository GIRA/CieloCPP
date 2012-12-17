#include "StdAfx.h"
#include "ActionParser.h"


ActionParser::ActionParser(Parser* p , std::function<Obj*(List*)> f)
{
	_innterParser = p;
	_f=f;
}

ActionParser::~ActionParser(void)
{
}


ParseResult * ActionParser::ParseOn(stringStream* s)
{
	ParseResult* p = _innterParser->ParseOn(s);
	List* temp = new List(p->getActualResult());

	if(p ->IsSuccess()) return new ParseSuccess(_f(temp));
	delete temp;
	return p;

}


