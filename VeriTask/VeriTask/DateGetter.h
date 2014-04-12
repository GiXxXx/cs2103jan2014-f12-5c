//@author A0101568J

/**
*This class is used to extract information about date from
*the given user input. And the user input will be choped
*accordingly.
*sample use:
*DateGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "Tokenizer.h"

class DateGetter :public Tokenizer{
	//this variable is the command of operation, it tells
	//whether there is a need to find date or not
	string _command;

public:

	//constructor which takes in the user input and the command
	//word identified.
	DateGetter(string&, string);

	~DateGetter();

	//This function convert words like jan, january, october
	//to string made of numbers like "1", "10" which will be
	//used to calculate Date in the other functions;
	//Pre-req: string inputed
	//Pos-req: nil.
	void monthConvertor(string&);

	//This function convert words like fri, friday, FRIDAY
	//to string made of numbers like "1", "10" which will be
	//used to calculate Date in the other functions;
	//Pre-req: string inputed
	//Pos-req: nil.
	void weekConvertor(string&);

	//This function is used to perform decrement or increment to
	//the date by one day when the keyword is before or after.
	//Pre-req: two string inputs
	//Pos-req: Date returned with one day before or after
	string getDateForBeforeAfter(string, string);

	//This function is used to get a date from some standard
	//date input. E.g 2012-12-21, 21 Aug 2014, 2013.14.16
	//Pre-req: two string input
	//Pos-req: Date returned
	string getDateFromDate(string&, string);


	//This function is used to get a date from some standard
	//week input. E.g this mon, on next friday, this sunday
	//Pre-req: two string input
	//Pos-req: Date returned
	string getDateFromWeek(string&, string);

	//This function is used to get a date from year, month
	//day input in integers.
	//Pre-req: 3 integer inputs
	//Pos-req: Date format returned
	string convertToDate(int, int, int);

	//This function is used to get a date from description
	//of No. of days.E.g in 4 days, by three day, by next month
	//Pre-req: two string input
	//Pos-req: Date format returned
	string getDateFromNumberOfDays(string&, string);

	//This function is used to get a date from description
	//of tommorrow, today, the day after tomorrow
	//Pre-req: two string input
	//Pos-req: Date format returned
	string getDateFromTomorrow(string&, string);

	//This function is used to get a date from description
	//of national day, labour day, children's day
	//Pre-req: two string input
	//Pos-req: Date format returned
	string getDateFromFestival(string&, string);

	//This function is used to convert from description
	//of this year, this month
	//Pre-req: two string input
	//Pos-req: Date format returned
	string convertDateFromDescription(string, string);

	//This function is used to call the getDate method
	//so as to get a Date from the user input.
	//Pre-req: command is add or edit.
	//Pos-req: Date format returned
	string tokenize();
};

