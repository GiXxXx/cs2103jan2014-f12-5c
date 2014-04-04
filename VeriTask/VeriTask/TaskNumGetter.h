#pragma once
#include "Tokenizer.h"
class TaskNumGetter :public Tokenizer{
	string command;
public:
	TaskNumGetter(string&, string);
	~TaskNumGetter();
	string Tokenize();
};

