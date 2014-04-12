//@author A0101568J

#include "Identifier.h"


Identifier::Identifier() {
	_index = ZERO;
}

Identifier::~Identifier() {
}

void Identifier::identify(string userInput) {
	_index++;

	try{
		CommandGetter commandIdentifier(userInput);
		_command = commandIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		TaskNumGetter taskNumIdentifier(userInput, _command);
		_taskNum = taskNumIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		DateGetter dateIdentifier(userInput, _command);
		_date = dateIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		TimeGetter startTimeIdentifier(userInput, _command);
		_startTime = startTimeIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		TimeGetter endTimeIdentifier(userInput, _command);
		_endTime = endTimeIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		StatusGetter statusIdentifier(userInput, _command);
		_status = statusIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		KeywordGetter keywordIdentifier(userInput, _command);
		_keyword = keywordIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}

	try{
		EventGetter eventIdentifier(userInput, _command);
		_event = eventIdentifier.tokenize();
		throw userInput;
	} catch (string userInput) {
	}
	
	//If In the end, there is no date identified from the user input
	//when there are a specific time given, make the date returned 
	//ne date of the day.
	//This only applies to the condition when adding a task.
	if (_startTime != EMPTY_TIME && _date == EMPTY_DATE && _command == ADD) {
		string dummyString = DUMMY;
		DateGetter dummyDateIdentifier(dummyString, ADD);
		_date = dummyDateIdentifier.tokenize();
	}
}

string Identifier::getDate() {
	return _date;
}

string Identifier::getStartTime() {
	return _startTime;
}

string Identifier::getEndTime() {
	return _endTime;
}

string Identifier::getEvent() {
	return _event;
}

string Identifier::getTaskNum() {
	return _taskNum;
}

string Identifier::getKeyword() {
	return _keyword;
}

string Identifier::getCommand() {
	return _command;
}

string Identifier::getStatus() {
	return _status;
}

/*int Identifier::getIndex() {
	return index;
} */

