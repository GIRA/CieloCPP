#include "StdAfx.h"
#include "List.h"


List::List(void)
{
	elements= new std::list<Obj*>();
}
List::List(Obj* o)
{
	elements= new std::list<Obj*>();
	add(o);
}

List::~List(void)
{
}


int List::size()
{
	return elements->size();
}
void List::add(List* l)
{
	//this should really be optimized	
	
	for(int i=0; i<l->size();i++)
	{
		Obj* o = l->at(i);
		add(o);
	}

}
bool List::isList()
{return true;}
void List::add(Obj* o)
{
	if(o->isList())
	{
		List* temp = (List*) o;
		this->add(temp);
	}else{
		elements->push_back(o);
	}
}
//-1 = out of range exception
Obj* List::at(int i)
{
	if(i>= size()) throw -1;
	 std::list<Obj*>::iterator it;
	 int count = 0;
	 for ( it=elements->begin() ; it != elements->end(); it++ )
	 {
		 Obj* o = *it;
		 if(count==i) return o;
		 count++;
	 }
    
  return 0;
}

std::string* List::ToString()
{
	std::string* s = new std::string();
	s->append("aList");

	for(int i=0; i<elements->size();i++)
	{
		s->append("\n");
		s->append(this->at(i)->ToString()->c_str());
	}
	return s;
}


void List::Do(std::function<void(Obj*)>f)
{
	 std::list<Obj*>::iterator it;
	 for ( it=elements->begin() ; it != elements->end(); it++ )
	 {
		 Obj* o = *it;
		 f(o);
	 }
}

void List::dispose()
{
	this->Do([](Obj* o){delete o;});
	delete elements;
}