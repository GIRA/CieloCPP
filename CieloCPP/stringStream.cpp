#include "StdAfx.h"
#include "stringStream.h"


stringStream::stringStream(std::string* s)
{
	_position=0;
	_innerString=s;
}
char stringStream::peek()
{
	if(isAtEnd())return char(0);
	return _innerString->at(_position);
}

stringStream::~stringStream(void)
{
	
}
void stringStream::setPosition(int position)
{
	_position=position;
}
int stringStream::getPosition()
{
	return _position;
}

std::string* stringStream::ContentsFromTo(int start, int stop)
{
	if(start>=stop) return new std::string("");

	char* c = (char*) malloc( (stop-start));
	int count=0;
	for(int i=start; i<stop;i++)
	{
		c[count]  = _innerString->at(i); 
		count++;
	}
	std::string* s = new std::string(c,stop-start);
	return s;

}

bool stringStream::isAtEnd()
{
	return _position >= _innerString->length();
}

void stringStream::reset()
{_position=0;}

char stringStream::next()
{
	//out of range 
	if(isAtEnd()) throw  -1;
	_position++;
	return _innerString->at(_position-1);
}
std::string* stringStream::upTo(char c)
{
	int start = _position;
	while(!isAtEnd() && next()!=c)
	{
	}
	return ContentsFromTo(start,_position-1);

}