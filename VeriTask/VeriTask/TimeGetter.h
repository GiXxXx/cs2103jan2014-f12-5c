#pragma once
#include "Tokenizer.h"
class TimeGetter :	public Tokenizer{
	string command;
public:
	TimeGetter(string&, string);
	~TimeGetter();
	string getTime(string, string);
	string convertToTime(string);
	string Tokenize();
};

