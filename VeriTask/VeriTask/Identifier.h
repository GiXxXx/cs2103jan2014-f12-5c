//@author A0101568J

/**
*This class is used to gather all the tokenizing method
*to break a sentence from the user input into different
*segments, and store them into corresponding variables.
*sample use:
*string sample = "add I am going to have lunch at 3pm";
*identifier test(sample);
*test.getCommand();
*/

#pragma once
#include "CommandGetter.h"
#include "DateGetter.h"
#include "EndTimeGetter.h"
#include "EventGetter.h"
#include "KeywordGetter.h"
#include "TimeGetter.h"
#include "StatusGetter.h"
#include "TaskNumGetter.h"
#include "Tokenizer.h"

class Identifier{
private:
	//This variable is used to hold the command word extracted
	//from the user input.
	string _command;

	//This variable is used to store the event extracted
	string _event;

	//This vatiasble is used to store the date extracted
	string _date;

	//this vatiable is used to store the starting time extracted.
	string _startTime;

	//this variable is used to store the ending time extracted.
	string _endTime;

	//this variable is used to store the keyword for search.
	string _keyword;

	//this variable is used to store the external index for the event.
	string _taskNum;

	//this variable is used to store the status of a task.
	string _status;

	//this variable is used to store the internal index of a event
	//which is used to sort the event in the database .txt file
	int _index;

public:
	Identifier();
	~Identifier();

	//This function is used to identify a sentence input by the user.
	//The user is expected to give a natrual sentence with a typical
	//command word like add, edit, delete, mark, display, search, undo,
	//redo, exit.
	//Pre-req: sentence input from user
	//Post-req: nil
	void identify(string);

	
	//This function is used to identify the command word from
	//the user input and store it into _command.
	//Pre-req: identify(string) called to identify a given input.
	//Pos-req: _command is returned.
	string getCommand();

	//This function is used to identify the task number from
	//the user input and store it into _taskNum.
	//Pre-req: Command word must be delete or edit.
	//Pos-req: _taskNum is returned.
	string getTaskNum();

	//This function is used to identify the date from
	//the user input and store it into _date.
	//Pre-req: Command word must be add, edit or display.
	//Pos-req: _date is returned.
	string getDate();

	//This function is used to identify the starting time from
	//the user input and store it into _startTime.
	//Pre-req: Command word must be add or edit.
	//Pos-req: _startTime is returned.
	string getStartTime();

	//This function is used to identify the ending time from
	//the user input and store it into _endTime.
	//Pre-req: Command word must be add or edit.
	//Pos-req: _endTime is returned.
	string getEndTime();

	//This function is used to identify the event to be added from
	//the user input and store it into _event.
	//Pre-req: Command word must be add or edit.
	//Pos-req: _event is returned.
	string getEvent();

	//This function is used to identify the keyword from
	//the user input and store it into _keyword.
	//Pre-req: Command word must be search.
	//Pos-req: _keyword is returned.
	string getKeyword();

	//This function is used to identify task status from
	//the user input and store it into _status.
	//Pre-req: Command must be display or mark
	//Pos-req: _status is returned.
	string getStatus();
};

