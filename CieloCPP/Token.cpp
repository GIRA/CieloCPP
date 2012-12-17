#include "StdAfx.h"
#include "Token.h"


_Token::_Token(std::string* s)
{
	this->setValue(s);
}
_Token::_Token()
{
}

_Token::~_Token(void)
{
	delete _value;
}

void _Token::setValue(std::string* s)
{
	_value=s;
}

std::string* _Token::getValue()
{
	return _value;
}

std::string* _Token::ToString()
{
	// i am not sure that this will work, i think i may have to change the + for +=
	std::string* s = new	 std::string();
	s->append("Token: \"");
	s->append(_value->c_str());
	s->append("\"");
	return s;

}