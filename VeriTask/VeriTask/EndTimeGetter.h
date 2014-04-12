#pragma once
#include "Tokenizer.h"
class EndTimeGetter :public Tokenizer{
	string command;
public:
	EndTimeGetter(string&, string);
	~EndTimeGetter();
	string Tokenize();
};

