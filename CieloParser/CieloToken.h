#include "Token.h"
#include "List.h"
#include "ObjString.h"
#pragma once
class CieloToken :
	public _Token
{
public:
	CieloToken(std::string* value);
	~CieloToken(void);
	void addComment(ObjString*);
	List* getComments();
	void setComments(List*);
	void dispose(void);
	std::string* ToString() override;
protected:
	List* _comments;
};

