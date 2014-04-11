#pragma once
#include "Tokenizer.h"
class EventGetter :public Tokenizer{
	string command;
public:
	EventGetter(string&, string);
	~EventGetter();
	string Tokenize();
};

