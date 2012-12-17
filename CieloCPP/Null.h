#pragma once
#include "obj.h"
class Null :
	public Obj
{
public:
	Null(void);
	~Null(void);
	std::string* ToString() override;
	bool isNull() override;
};

