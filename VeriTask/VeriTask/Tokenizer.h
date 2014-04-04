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
const string dot = ".";
const string dash = "-";
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
const string LargeDate = "        ";
const string LargeTime = "    ";
const string OnAndBy = "onby";
const string at = "at";
const string to = "to";
const string from = "from";
const string by = "by";
const string monday = "monday";
const string tuesday = "tuesday";
const string thursday = "thursday";
const string wednesday = "wednesday";
const string friday = "friday";
const string saturday = "saturday";
const string sunday = "sunday";
const string mon = "mon";
const string tue = "tue";
const string wed = "wed";
const string thu = "thu";
const string fri = "fri";
const string sat = "sat";
const string sun = "sun";
const string Next = "next";
const string This = "this";
const string Zero = "0";
const string one = "1";
const string two = "2";
const string three = "3";
const string four = "4";
const string five = "5";
const string six = "6";
const string seven = "7";
const string eight = "8";
const string nine = "9";
const string ten = "10";
const string eleven = "11";
const string twelve = "12";
const string jan = "jan";
const string january = "january";
const string feb = "feb";
const string february = "february";
const string mar = "mar";
const string march = "march";
const string apr = "apr";
const string april = "april";
const string may = "may";
const string jun = "jun";
const string june = "june";
const string jul = "jul";
const string july = "july";
const string aug = "aug";
const string august = "august";
const string sep = "sep";
const string september = "september";
const string octo = "oct";
const string october = "october";
const string nov = "nov";
const string november = "november";
const string dece = "dec";
const string december = "december";
const string Spaces = "                    ";
const string amOne = "am";
const string amTwo = "a.m";
const string amThree = "a.m.";
const string pmOne = "pm";
const string pmTwo = "p.m";
const string pmThree = "p.m.";
const char A = 'A';
const char Z = 'Z';
const char a = 'a';
const unsigned int start = 0;
const unsigned int OneUnit = 1;
const unsigned int TwoUnit = 2;
const unsigned int ThreeUnit = 3;
const unsigned int FourUnit = 4;
const unsigned int FiveUnit = 5;
const unsigned int SixUnit = 6;
const unsigned int SevenUnit = 7;
const unsigned int EightUnit = 8;
const unsigned int NineUnit = 9;
const unsigned int TenUnit = 10;
const int zero = 0;
const int hourAdder = 1200;

class Tokenizer{

protected:
	string *uncategorizedInfo;

public:
	Tokenizer(string&);
	~Tokenizer();
	void chopInfo(string&, int, int);
	bool isNumber(string);
	void ChangeDoubleDigit(string&);
	string getTime(string, string);
	string GetDateFormatTwo(string);
	virtual string Tokenize();
};

#endif