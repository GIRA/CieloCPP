#pragma once
#include "parser.h"
#include "ObjString.h"
#include <functional>
class PredicateParser :
	public Parser
{
public:
	PredicateParser(std::function<bool(char)>,std::string);
	~PredicateParser(void);
	
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	std::function<bool(char)> _f;
	std::string msg;
};

