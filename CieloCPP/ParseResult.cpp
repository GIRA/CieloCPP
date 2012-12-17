#include "StdAfx.h"
#include "ParseResult.h"


ParseResult::ParseResult(void)
{
}



ParseResult::~ParseResult(void)
{
}

bool ParseResult::IsFailure()
{
	return false;
}

bool ParseResult::IsSuccess()
{
	return false;
}

Obj* ParseResult::getActualResult()
{
	return _actualResult;
}

void ParseResult::setActualResult(Obj* o)
{
	_actualResult = o;
}