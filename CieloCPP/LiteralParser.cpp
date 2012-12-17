#include "StdAfx.h"
#include "LiteralParser.h"


LiteralParser::LiteralParser(char c)
{
	_literal=c;
}


LiteralParser::~LiteralParser(void)
{
}

ParseResult* LiteralParser::ParseOn(stringStream* s)
{
	if( ~s->isAtEnd() && s->peek()==_literal) 
	{
		ParseSuccess * p = new ParseSuccess(new ObjString( s->next()));
		
		return p;}
	ObjString* str= new ObjString(_literal);
	return new ParseFailure("Literal " + (*str->ToString()) + " Expected", s->getPosition());
}

 Parser* LiteralParser::on(std::string s)
{
	Parser* p;
	for(unsigned int i=0; i<s.size();i++)
	{
		Parser* _p= new LiteralParser(s.at(i));
		if(i==0)
		{p=_p;}
		else{
			p=p->Then(_p);
		}

	}
	return p;
}