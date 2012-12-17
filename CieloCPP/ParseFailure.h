#pragma once
#include "parseresult.h"
class ParseFailure :
	public ParseResult
{
public:
	ParseFailure(std::string message, int position);
	~ParseFailure(void);
	std::string getMessage();
	int getPosition();
	bool virtual IsFailure() override;
	std::string* ToString() override;
	Obj* getActualResult() override;
private:
	std::string _message;
	int _position;
};

