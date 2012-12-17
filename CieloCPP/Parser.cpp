#include "StdAfx.h"
#include "Parser.h"
Parser::Parser(void)
{
}

Parser::~Parser(void)
{
}

template <class T>
 T* Parser::Parse(stringStream* s)
 {
	 return (T*) this->ParseOn(s)->getActualResult();
 }

 Obj* Parser::Parse(stringStream*s)
 {
	 ParseResult* r=this->ParseOn(s);
	 Obj* t = r->getActualResult();
	 delete r;
	 return t;
 }
 bool Parser::Matches(stringStream* s)
 {
	 return this->ParseOn(s)->IsSuccess();
 }
 
 ParseResult* Parser::ParseOn(stringStream* s)
 {
	 return new ParseResult();
 }
 
 Parser* Parser::And()
 {
	 return new AndParser(this);
 }

 Parser* Parser::Token()
 {
	 return new TokenParser(this);
 }
	
 Parser* Parser::Not()
 {
	 return new NotParser(this);
 }

 Parser* Parser::End()
 {
	 return new EndParser(this);
 }
 Parser* Parser::Or(Parser* p)
 {
	 return new ChoiceParser(this,p);
 }
 Parser* Parser::Then(Parser* p)
 {
	 return new SequenceParser(this,p);
 }
 Parser* Parser::Optional()
 {
	 return new OptionalParser(this);
 }
 
 Parser* Parser::Start()
 {
	 return new RepeatingParser(this,0,INT_MAX);
 }
	
 Parser* Parser::Plus()
 {
		 return new RepeatingParser(this,1,INT_MAX);
 }

 Parser* Parser::Times(int i)
 {
	 	 return new RepeatingParser(this,i,i);
 }


 Parser* Parser::Any()
{
	return new PredicateParser([](char c){return true;},"Input expected");
 }
Parser* Parser::Digit()
{
	return new PredicateParser([](char c){return std::isdigit(c);},"Digit expected");
}
Parser* Parser::Letter()
{
	return new PredicateParser([](char c){return std::islower(c) || std::isupper(c);},"Letter expected");
}
Parser* Parser::Word()
{
	return new PredicateParser([](char c){return std::isalnum(c);},"Letter or Digit expected");
}

Parser* Parser::WhiteSpace()
{	
	return new PredicateParser([](char c){return  std::isspace(c);},"whitespace expected");
}

Parser* Parser::Negate()
{//this may be at(0)
	return this->Not()->Then(this->Any())->Map([](List* elements){return elements->at(1);});
}
Parser* Parser::Wrapped( std::function<ParseResult*(stringStream*,std::function<ParseResult*(void)>)> f)
{
	return new WrappingParser(this,f);
}
Parser* Parser::Map(std::function<Obj*(List*)> f)
	{
		return new ActionParser(this,f);
	}