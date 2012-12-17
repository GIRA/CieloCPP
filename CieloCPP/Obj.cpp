#include "StdAfx.h"
#include "Obj.h"

Obj::Obj(void)
{
}


Obj::~Obj(void)
{
}

std::string* Obj::ToString()
{
	std::string* s = new std::string();
	s->append("AnObject");
	return s;
}
bool Obj::isNull()
{return false;}

bool Obj::isList()
{return false;}

void Obj::dispose()
{
}