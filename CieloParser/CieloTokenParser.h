#include "TokenParser.h"
#include "CieloToken.h"
#include "List.h"
#include <functional>
#include <cctype>

#pragma once
class CieloTokenParser :
	public TokenParser
{
public:
	CieloTokenParser(Parser* );
	~CieloTokenParser(void);
	virtual _Token* createToken(std::string*)override ;
	virtual ParseResult* ParseOn(stringStream*) override;
private:
	List* ParseComments(List*,stringStream*);
};

