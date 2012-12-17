#include "CieloToken.h"


CieloToken::CieloToken(std::string* value):_Token(value)
{
	_comments = new List();
}


CieloToken::~CieloToken(void)
{
}
void CieloToken::dispose()
{
	_comments->dispose();
	delete _comments;
}
List* CieloToken::getComments()
{
	return _comments;
}
void CieloToken::setComments(List* comments)
{
	delete _comments;
	_comments=comments;
}
void CieloToken::addComment(ObjString* comment)
{
	_comments->add(comment);
}
std::string* CieloToken::ToString()
{
	// i am not sure that this will work, i think i may have to change the + for +=
	std::string* s = new	 std::string();
	s->append("CieloToken: \"");
	s->append(_value->c_str());
	s->append("\"\n");
	s->append("Comments:\n");
	s->append((*_comments->ToString()));

	return s;

}