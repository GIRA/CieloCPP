#pragma once
#include "parser.h"
#include <functional>
class WrappingParser :
	public Parser
{
public:
	WrappingParser(Parser* , std::function<ParseResult*(stringStream*,std::function<ParseResult*(void)>)> );
	~WrappingParser(void);
	ParseResult* ParseOn(stringStream*)override;
private:
	Parser * _internalParser;
	std::function<ParseResult*(stringStream*,std::function<ParseResult*(void)>)> _f;
};

