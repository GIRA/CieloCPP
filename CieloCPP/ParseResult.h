#pragma once
#include "obj.h"
class ParseResult :
	public Obj
{
public:
	ParseResult(void);
	~ParseResult(void);
	virtual Obj*  getActualResult();
	virtual void setActualResult(Obj*);
	bool virtual IsSuccess();
	bool virtual IsFailure();
	
	Obj* _actualResult;
};

