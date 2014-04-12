//@author A0101568J

/**
*This class is used to extract information about event
*for add or edit from the given user input. And the user
*input will be choped accordingly.
*sample use:
*EventGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "Tokenizer.h"

class EventGetter :public Tokenizer{
	//this variable is the command of operation, it tells
	//whether there is a need to find event or not
	string _command;

public:
	// constructor which takes in the use input and the command
	//word identified.
	EventGetter(string&, string);

	~EventGetter();

	//This function is used to extract the
	//event for add and edit from the user input.
	//Pre-req: EventGetter initialized
	//Pos-req: string returned
	string tokenize();
};

