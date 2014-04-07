#pragma once
#include "Tokenizer.h"
class TimeGetter :	public Tokenizer{
	string command;
public:
	TimeGetter(string&, string);
	~TimeGetter();
	string getTimeFromTwentyFourHour(string, string);
	string getTimeFromTwelveHour(string, string);
	string convertToTime(string);
	string Tokenize();
};

