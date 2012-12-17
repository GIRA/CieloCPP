#include "StdAfx.h"
#include "ParseFailure.h"
#include <sstream>
ParseFailure::ParseFailure(std::string msg, int pos)
{
	_message=msg;
	_position=pos;
}


ParseFailure::~ParseFailure(void)
{
}


std::string ParseFailure::getMessage()
{
	return _message;
}


int ParseFailure::getPosition()
{
	return _position;
}

std::string* ParseFailure::ToString()
{
	std::stringstream* ss = new std::stringstream();
	*ss<<getPosition();

	return &(getMessage() + " at " + ss->str());
}

// 10 -> parse exception for now.
Obj* ParseFailure::getActualResult()
{
	throw 10;

}

bool ParseFailure::IsFailure()
{return true;}