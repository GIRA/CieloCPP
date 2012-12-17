#pragma once
#include "obj.h"
#include <list>
#include <functional>
class List :
	public Obj
{
public:
	List(void);
	List(Obj*);
	~List(void);
	int size(void);
	void add(List*);
	void add(Obj*);
	Obj* at(int );
	std::string* ToString(void) override;
	bool isList(void) override;
	void Do(std::function<void(Obj*)>);

	void dispose(void) override;
	std::list<Obj*>* elements;
};

