//@author A0101568J

/**
*This class is used to extract information about status
*for mark from the given user input. And the user input will be choped
*accordingly.
*sample use:
*StatusGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "tokenizer.h"
class StatusGetter :public Tokenizer{
	//this variable is the command of operation, it tells
	//whether there is a need to find status or not
	string _command;

public:
	//constructor which takes in the use input and the command
	//word identified.
	StatusGetter(string&, string);

	~StatusGetter();

	//This function is used to extract the
	//status for mark from the user input.
	//Pre-req: StatusGetter initialized
	//Pos-req: string returned
	string tokenize();
};

