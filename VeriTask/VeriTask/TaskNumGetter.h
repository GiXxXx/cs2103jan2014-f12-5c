//@author A0101568J

/**
*This class is used to extract information about task number from
*the given user input. And the user input will be choped
*accordingly.
*sample use:
*TaskNumGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "Tokenizer.h"

class TaskNumGetter :public Tokenizer{
	//this variable is the command of operation, it tells
	//whether there is a need to find time or not
	string _command;

public:
	//constructor which takes in the use input and the command
	//word identified.
	TaskNumGetter(string&, string);

	~TaskNumGetter();

	//This function is used to extract the
	//task number word from the user input.
	//Pre-req: TaskNumGetter initialized
	//Pos-req: string returned
	string tokenize();
};

