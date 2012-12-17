#include "CieloTokenParser.h"


CieloTokenParser::CieloTokenParser(Parser* p):TokenParser(p)
{
	
}


CieloTokenParser::~CieloTokenParser(void)
{
}


_Token* CieloTokenParser::createToken(std::string* s)
{
	return new CieloToken(s);
}
	
ParseResult* CieloTokenParser::ParseOn(stringStream* s)
{
	int start = s->getPosition();
	List* comments= new List();
	comments=this->ParseComments(comments,s);
	ParseResult* result = TokenParser::ParseOn(s);
	if(result->IsFailure())
	{
		s->setPosition(start);
		return result;
	}
	comments = this->ParseComments(comments,s);
	CieloToken * t = (CieloToken*)result->getActualResult();
	t->setComments(comments);
	
	return result;
}

List* CieloTokenParser::ParseComments(List* other,stringStream* s)
{
	List* elements = new List(other);
	delete other;
	std::function<bool()> f = [&s]()->bool{
		while(~(s->isAtEnd()) && std::isspace(s->peek()))
		{
			s->next();
		}
		return ~(s->isAtEnd()) && (s->peek() == '"');	
		 
	};

	while(f())
	{
		s->next();
		elements->add(new ObjString(s->upTo('"')));
	}

	return elements;
}