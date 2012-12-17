#pragma once
#include "parser.h"
#include "ObjString.h"
#include "ParseSuccess.h"
#include "ParseFailure.h"
class LiteralParser :
	public Parser
{
public:
	LiteralParser(char c);
	~LiteralParser(void);
	static Parser* on(std::string);
	 ParseResult* ParseOn(stringStream*) override ;
private: 
	char _literal;
};

