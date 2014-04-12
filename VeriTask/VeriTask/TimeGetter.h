//@author A0101568J

/**
*This class is used to extract information about time from
*the given user input. And the user input will be choped
*accordingly.
*sample use:
*DimeGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "Tokenizer.h"
class TimeGetter :	public Tokenizer{
	//this variable is the command of operation, it tells
	//whether there is a need to find time or not
	string _command;

public:
	//constructor which takes in the use input and the command
	//word identified.
	TimeGetter(string&, string);

	~TimeGetter();

	//This function is used to get a time from description
	//of time in some common way, e.g 4pm, 12:00, 7:00
	//Pre-req: two string input
	//Pos-req: Date format returned
	string getTime(string, string);

	//This function is used to get a time from description
	//of time in the way like today morning, in the morning
	//while as the duration not clear from this kind of
	//description, the time will be returned as end time only
	//morning = noon dealine with 12:00
	//afternoon = deadline with 7pm
	//evening = night = midnight = deadline with 0:00
	//Pre-req: two string input
	//Pos-req: Date format returned
	string getTimeFromMorning(string, string);

	//This function is used to convert from description
	//of time to the time format: 7am to 0700
	//12:00 to 1200
	//Pre-req: string input
	//Pos-req: Date format returned
	string convertToTime(string);

	//This function is used to call the getTime method
	//so as to get a Date from the user input.
	//Pre-req: command is add or edit.
	//Pos-req: time format returned
	string tokenize();
};

