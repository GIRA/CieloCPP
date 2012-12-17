#pragma once
#include "parseresult.h"
class ParseSuccess :
	public ParseResult
{
public:
	ParseSuccess(Obj* result);
	~ParseSuccess(void);
	bool virtual IsSuccess() override;
	std::string* ToString() override;
	virtual Obj*  getActualResult();
	virtual void setActualResult(Obj*);
	
};

