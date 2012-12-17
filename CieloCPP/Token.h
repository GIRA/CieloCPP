#include "Obj.h"
#include <string>
#pragma once
 class _Token:
	public Obj
{
public:
	_Token(void);
	_Token(std::string* value);
	~_Token(void);
	std::string* ToString() override;
	std::string* getValue();
	void setValue(std::string* s);
protected:
	std::string* _value;

};

