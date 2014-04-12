//@author A0101568J

/**
*This class is the parent class of the command pattern design,
*it helps to define all those Macro variables for its member class
*to use, and it have some shared method functions for its member
*to utilize. Also, it contains a virtual function tokenize()to be overided
*by its member class according to specific requirement.
*sample use:
*Tokenizer test(string sample);
*test.tokenize();
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

const char UPPER_A = 'A';
const char UPPER_Z = 'Z';
const char LOWER_A = 'a';
const char PUNCTUATION_ARRAY[5] = { '!', '.', '?', ';', ',' };
const unsigned int START = 0;
const unsigned int ONE_UNIT = 1;
const unsigned int TWO_UNIT = 2;
const unsigned int THREE_UNIT = 3;
const unsigned int FOUR_UNIT = 4;
const unsigned int FIVE_UNIT = 5;
const unsigned int SIX_UNIT = 6;
const unsigned int SEVEN_UNIT = 7;
const unsigned int EIGHT_UNIT = 8;
const unsigned int NINE_UNIT = 9;
const unsigned int TEN_UNIT = 10;
const int ZERO = 0;
const int ONE_PM = 1300;
const int HOUR_ADDER = 1200;
const int YEAR_ADDER = 1900;
const int MAX_SIZE = 100;
const int YEAR_DAYS = 365;
const int MONTH_DAYS = 31;
const int YEAR_MONTHS = 11;
const int TEN_THOUSAND = 10000;
const string NUMBER = "0123456789";
const string SLASH = "/";
const string COLON = ":";
const string DOT = ".";
const string DASH = "-";
const string SPACE = " ";
const string MARK = "mark";
const string ADD = "add";
const string DEL = "delete";
const string EDIT = "edit";
const string UNDO = "undo";
const string REDO = "redo";
const string EXIT = "exit";
const string DISPLAY = "display";
const string DONE = "done";
const string SEARCH = "search";
const string UNDONE = "undone";
const string CANNOT_BE_DONE = "cannot be done";
const string OVERDUE = "overdue";
const string ALL = "all";
const string NO_STATUS = "no status";
const string YEAR = "year";
const string YEARS = "years";
const string DAY = "day";
const string DAYS = "days";
const string MONTH = "month";
const string MONTHS = "months";
const string WEEK = "week";
const string WEEKS = "Weeks";
const string EMPTY_DATE = "        ";
const string EMPTY_TIME = "    ";
const string TEN_SPACES = "          ";
const string ON = " on ";
const string AT = " at ";
const string TO = " to ";
const string FROM = " from ";
const string BY = " by ";
const string MONDAY = "monday";
const string TUESDAY = "tuesday";
const string THURSDAY = "thursday";
const string WEDNESDAY = "wednesday";
const string FRIDAY = "friday";
const string SATURDAY = "saturday";
const string SUNDAY = "sunday";
const string MON = "mon";
const string TUE = "tue";
const string WED = "wed";
const string THU = "thu";
const string FRI = "fri";
const string SAT = "sat";
const string SUN = "sun";
const string NEXT = "next";
const string THIS_STRING = "this";
const string THE = "the";
const string ZERO_STRING = "0";
const string ONE_STRING = "1";
const string TWO_STRING = "2";
const string THREE_STRING = "3";
const string FOUR_STRING = "4";
const string FIVE_STRING = "5";
const string SIX_STRING = "6";
const string SEVEN_STRING = "7";
const string EIGHT_STRING = "8";
const string NINE_STRING = "9";
const string TEN_STRING = "10";
const string ELEVEN = "11";
const string TWELVE = "12";
const string JAN = "jan";
const string JANUARY = "january";
const string FEB = "feb";
const string FEBRUARY = "february";
const string MAR = "mar";
const string MARCH = "march";
const string APR = "apr";
const string APRIL = "april";
const string MAY = "may";
const string JUN = "jun";
const string JUNE = "june";
const string JUL = "jul";
const string JULY = "july";
const string AUG = "aug";
const string AUGUST = "august";
const string SEP = "sep";
const string SEPTEMBER = "september";
const string OCT = "oct";
const string OCTOBER = "october";
const string NOV = "nov";
const string NOVEMBER = "november";
const string DEC = "dec";
const string DECEMBER = "december";
const string SPACES = "                    ";
const string AM_ONE = "am";
const string AM_TWO = "a.m";
const string AM_THREE = "a.m.";
const string PM_ONE = "pm";
const string PM_TWO = "p.m";
const string PM_THREE = "p.m.";
const string TODAY = "today";
const string TOMORROW = "tomorrow";
const string TMR = "tmr";
const string THE_DAY_AFTER_TOMORROW = "the day after tomorrow";
const string THE_DAY_AFTER_TMR = "the day after tmr";
const string DAY_AFTER_TOMORROW = "day after tomorrow";
const string DAY_AFTER_TMR = "day after tmr";
const string DURING = " during ";
const string BEFORE = " before ";
const string AFTER = " after ";
const string EMPTY_STRING = "";
const string PUNCTUATION_SET = ",.?!; ";
const string STRING_A = "a";
const string DUMMY = "test by today    ";

const string ONES[20] = { "hundred", "one", "two", "three", "four", "five", 
                          "six", "seven", "eight", "nine", "ten", "eleven",
						  "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
						  "seventeen", "eighteen", "nineteen" };

const string TENS[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                          "seventy", "eighty", "ninety" };

const string FESTIVAL_DATE[23] = { "0101", "0214", "0215", "0401", "0418", 
                                   "0501", "0511", "0615", "0606", "0621", 
								   "0809", "0905", "1003", "1031", "1031", 
								   "1127", "1224", "1224", "1225", "1225", 
								   "1225", "1225", "1231" };

const string FESTIVAL[23] = { "new year", "valentines's day", "totoal defense day", 
                              "april fool's day", "good friday", "labour day",
							  "mother's day", "father's day", "youth day",
                              "racial harmony day", "national day", "teacher's day",
							  "chiledren's day", "holloween night", "holloween", 
							  "thanksgiving day", "christmas eve", "xmas eve",
                              "christmas day", "christmas", "xmas day", "xmas", 
							  "new year eve" };


const string ONE_WORD_STATUS[15] = { "cant", "can't", "cannot", "impossible", "unable",
                                     "doing", "finishing", "completing", "undone", "prepar",
									 "start", "done", "finish", "complete", "over"};

const string MULTI_WORD_STATUS[40] = { "have do", "have finished", "have complete",
                                       "done already", "do already", "already do",
									   "already finish", "finished already",
									   "finish already", "complete already", 
									   "completed already", "already complete", 
									   "cannot do", "can't do", "cant do", "no time",
									   "dont know", "not know", "how to", "cannot be done",
									   "not able", "cannot finish", "cannot complete", 
									   "cant finish", "cant complete", "can't finish", 
									   "can't complete", "haven't do", 
									   "haven't finish", "havent' complete", 
									   "haven't start", "havent do", 
									   "havent finish", "havent complete", "havent start",
									   "not yet", "never do", "not do", "not complete", 
									   "not finish" };

const string OVERDUE_STATUS[11] = { "overdue", "passed due", "past due", "fail", "the due",
                                    "over due", "pass due", "past due", "all", "every", "full" };

const string NOON_STATUS[7] = { "morning ", "afternoon ", "evening ", "noon ", "midnight ",
                                "tonight ", "night " };

const string CORRESPONDING_TIME[7] = { "1200", "1900", "2400", "1200", "2400", "2400", "2400" };

const string PREPOSITION[9] = { " after ", " during ", " from ", " before ",
                                " in ", " on ", " by ", " to ", " at " };

class Tokenizer{
protected:
	//This variable is used to store the remaining part of the user input
	//after each kind of elements are taken away from the whole string.
	string *_uncategorizedInfo;

public:
	//constructor for Tokenizer, the user input will be the variable
	//In this constructor, user input is store in the *_uncategorizedInfo,
	//and added 20 spaces at the end of the string for easy finding
	//substrings without exceed the size limit.
	Tokenizer(string&);

	~Tokenizer();

    //This function is used to chop off the string into a new one,
	//after some elements are identified from it. By chooping the
	//string into smaller sizes, information will thus not be repeatedly
	//analysed. For chopInfo(A, B, C), B will be the position of chopping,
	//and C will be the size of string being choped from string A
	//Pre-req: a string input, 2 ineger input
	//Post-req: nil.
	void chopInfo(string&, int, int);

	//This function is used to check whether a string is consisting of pure
	//numbers.
	//Pre-req: a string to be analysed
	//Pos-req: true or false returned accordingly.
	bool isNumber(string);

	//This function is used to change a pure number string into a string
	//consisting of two numbers by adding a zero to the front.
	//Pre-req: a string as input.
	//Pos-req: nil.
	void changeDoubleDigit(string&);

	//This function is used to change ths input string's every upper case letter
	//to lower cases for keyword recognition.
	//Pre-req: a string input
	//Pos-req: nil;
	void changeToLowerCase(string&);

	//This function is used to change the input like one, two, eleven..into strings
	//consisting of pure number, "1", "2", "11" for example;
	//Pre-req: string input
	//Pos-req: nil;
	string changeWordToNumber(string);

	//This function is the virtual function s to be overided by its member functions;
	//This function does nothing in the paretn class.
	virtual string tokenize();
};
