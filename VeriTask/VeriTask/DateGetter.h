#pragma once
#include "Tokenizer.h"
class DateGetter :public Tokenizer{
	string command;
public:
	DateGetter(string&, string);
	~DateGetter();
	void MonthConvertor(string&);
	void WeekConvertor(string&);
	string GetDateFromDate(string&, string);
	string GetDateFromWeek(string&, string);
	string DateConverter(int, int, int);
	string Tokenize();
};

