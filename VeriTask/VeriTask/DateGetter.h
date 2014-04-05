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
	string GetDateFromDescriptionOne(string&, string);
	string GetDateFromDescriptionTwo(string&, string);
	string DateConvertorFromDescription(string, string);
	string Tokenize();
};

