#include "StdAfx.h"
#include "Null.h"


Null::Null(void)
{
}


Null::~Null(void)
{
}

std::string* Null::ToString()
{
	return new std::string("NULL");
}
bool Null::isNull()
{return true;}