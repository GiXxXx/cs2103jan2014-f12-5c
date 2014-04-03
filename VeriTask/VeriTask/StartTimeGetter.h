#pragma once
#include "Tokenizer.h"
class StartTimeGetter :	public Tokenizer{
	string command;
public:
	StartTimeGetter(string&, string);
	~StartTimeGetter();
	string Tokenize();
};

