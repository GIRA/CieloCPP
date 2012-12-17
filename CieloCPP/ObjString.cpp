#include "StdAfx.h"
#include "ObjString.h"


ObjString::ObjString(char c)
 {
	_innerString=new std::string();
	_innerString->append(&c);
}
ObjString::ObjString(std::string* s)
{
	_innerString =s;
}

std::string* ObjString::ToString()
{return _innerString;
}

ObjString::~ObjString(void)
{
}

