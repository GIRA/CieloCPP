#include <string>
#pragma once
class stringStream
{
public:
	stringStream(std::string* s);
	~stringStream(void);
	int getPosition();
	void setPosition(int position);
	std::string* ContentsFromTo(int,int);
	bool isAtEnd();
	char peek();
	std::string* upTo(char c);
	void reset();
	char next();
private:
	std::string* _innerString;
	int _position;

	
};

