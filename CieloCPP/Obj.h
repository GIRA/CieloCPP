#include <string>
#pragma once
class Obj
{
public:
	Obj(void);
	~Obj(void);
	virtual std::string* ToString(void);
	virtual bool isNull(void);
	virtual bool isList(void);
	virtual void dispose(void);
};

