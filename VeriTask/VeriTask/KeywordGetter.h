#pragma once
#include "Tokenizer.h"
class KeywordGetter :public Tokenizer{
	string command;
public:
	KeywordGetter(string&, string);
	~KeywordGetter();
	string Tokenize();
};

