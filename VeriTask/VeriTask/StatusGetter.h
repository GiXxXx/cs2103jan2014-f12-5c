#pragma once
#include "tokenizer.h"
class StatusGetter :public Tokenizer{
		string command;
public:
	StatusGetter(string&, string);
	~StatusGetter();
	string Tokenize();
};

