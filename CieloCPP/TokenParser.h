#pragma once
#include "parser.h"
#include "Token.h"
#include "ParseSuccess.h"
class TokenParser :
	public Parser
{
public:
	TokenParser(Parser* p);
	~TokenParser(void);
	virtual _Token* createToken(std::string*);
	
	virtual ParseResult* ParseOn(stringStream*) override;
protected:
	Parser* _internalParser;

};

