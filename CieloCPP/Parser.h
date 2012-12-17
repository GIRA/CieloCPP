#include "stringStream.h"
#include "ParseResult.h"
#include <limits.h>
#include <cctype>
#include <functional>
#include "List.h"
#pragma once

	
class Parser
{
public:
	Parser(void);
	~Parser(void);
	
	template <class T> T* Parse(stringStream* );
	
	Obj* Parse(stringStream*);
	
	virtual ParseResult* ParseOn(stringStream*);
	bool Matches(stringStream*);
	Parser* And();
	Parser* Token();
	Parser* Not();
	Parser* End();
	Parser* Optional();
	Parser* Start();
	Parser* Plus();
	Parser* Times(int);
	
	Parser* Negate();

	Parser* Map(std::function<Obj*(List*)>);

	Parser* Wrapped( std::function<ParseResult*(stringStream*,std::function<ParseResult*(void)>)>);
	static Parser* Any();
	static Parser* Digit();
	static Parser* Letter();
	static Parser* Word();
	static Parser* WhiteSpace();

	virtual Parser* Or(Parser* p);
	virtual Parser* Then(Parser* p);
};


#include "AndParser.h"
#include "TokenParser.h"
#include "NotParser.h"
#include "EndParser.h"
#include "ChoiceParser.h"
#include "SequenceParser.h"
#include "OptionalParser.h"
#include "RepeatingParser.h"
#include "PredicateParser.h"
#include "ActionParser.h"
#include "WrappingParser.h"
#include "LiteralParser.h"