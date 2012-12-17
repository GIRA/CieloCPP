#pragma once
#include "parser.h"
#include <functional>

class ActionParser :
	public Parser
{
public:
	ActionParser(Parser* p , std::function<Obj*(List*)> f);
	~ActionParser(void);
	ParseResult* ParseOn(stringStream*) override;
private:
	Parser* _innterParser;
	std::function<Obj*(List*)> _f;
	
};

