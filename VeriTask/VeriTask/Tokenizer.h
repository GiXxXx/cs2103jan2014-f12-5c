#ifndef HEADER_IDENTIFIER_
#define HEADER_IDENTIFIER_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

const string number = "0123456789";
const string slash = "/";
const string colon = ":";
const string space = " ";
const string Mark = "mark";
const string Add = "add";
const string Delete = "delete";
const string Edit = "edit";
const string Undo = "undo";
const string Done = "done";
const string Search = "search";
const string UnDone = "undone";
const string CannotBeDone = "cannot be done";
const string NoStatus = "no status";
const string LargeDate = "99999999";
const string LargeTime = "9999";
const string OnAndBy = "onby";
const string at = "at";
const string to = "to";
const string from = "from";
const string by = "by";
const string monday = "Mon";
const string tuesday = "Tue";
const string thursday = "thu";
const string wednesday = "wed";
const string friday = "fri";
const string saturday = "sat";
const string sunday = "sun";
const string NextMonday = "next Mon";
const string NextTuesday = "next Tue";
const string NextWednesday = "next Wed";
const string NextThursday = "next Thu";
const string NextFriday = "next Fri";
const string NextSaturday = "next Sat";
const string NextSunday = "next Sun";
const signed int start = 0;
const signed int unit = 1;
const int zero = 0;

class Tokenizer{

protected:
	string *uncategorizedInfo;

public:
	Tokenizer(string&);
	~Tokenizer();
	void chopInfo(string&, int, int);
	bool ifNumber(string);
	string getTime(string, string);
	string GetDateFromWeek(string);
	string DateConverter(int, int, int);
	virtual string Tokenize();
};

#endif