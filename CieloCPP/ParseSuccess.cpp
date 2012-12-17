#include "StdAfx.h"
#include "ParseSuccess.h"

bool  ParseSuccess::IsSuccess() 
{
	return true;
}

std::string* ParseSuccess::ToString()
{
	std::string* s = new std::string();
	s->append("a ParseSuccess( ");
	s->append(getActualResult()->ToString()->c_str());
	s->append(" )");
	return s;
}
ParseSuccess::ParseSuccess(Obj* o)
{
	this-> setActualResult(o);
}

ParseSuccess::~ParseSuccess()
{
}

Obj* ParseSuccess::getActualResult()
{
	return _actualResult;
}

void ParseSuccess::setActualResult(Obj* o)
{
	_actualResult = o;
}