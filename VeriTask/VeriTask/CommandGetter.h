#pragma once
#include "Tokenizer.h"
class CommandGetter :public Tokenizer{
	string command;
public:
	CommandGetter(string&);
	~CommandGetter();
	string Tokenize();
};

