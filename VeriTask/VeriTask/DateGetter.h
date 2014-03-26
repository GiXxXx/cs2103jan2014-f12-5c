#pragma once
#include "Tokenizer.h"
class DateGetter :public Tokenizer{
	string command;
public:
	DateGetter(string&, string);
	~DateGetter();
	string Tokenize();
};

