#pragma once
#include "obj.h"
#include <string>
class ObjString :
	public Obj
{
public:
	ObjString(char);
	ObjString(std::string*);


	~ObjString(void);
	std::string* ToString() override;
private:
	std::string* _innerString;
};

