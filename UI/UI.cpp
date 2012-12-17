// UI.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include "Parser.h"
#include "Obj.h"
#include "stringStream.h"
#include "ParseResult.h"
#include <functional>
#include "CieloTokenParser.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{  
	string s;
	Parser* word = (new TokenParser(Parser::WhiteSpace()->Start())) ->Then( new  TokenParser( Parser::Word()->Plus())) ->Then(new TokenParser(Parser::WhiteSpace()->Start()));
	Parser* p = new ActionParser(word,[](List* l){
		return l->at(1);
		});
	p = new CieloTokenParser(p);
	do{
		cout<< "Ingrese un texto \n";
		getline(cin,s);
		stringStream* ss = new stringStream(&s);
	
		Obj* r =  p->Parse(ss);

		delete ss;
		cout << (r->ToString()->c_str())<< "\n";
		r->dispose();
		delete r;
	}while(s != "exit");


	

	return 0;

}

