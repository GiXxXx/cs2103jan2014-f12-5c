//@author A0101568J

/**
*This class is used to extract information about command from
*the given user input. And the user input will be choped
*accordingly.
*sample use:
*CommandGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "Tokenizer.h"

class CommandGetter :public Tokenizer{
	//this variable is the command of operation, it stores
	//the command word from the user input
	string _command;

public:
	//constructor which takes in the use input
	CommandGetter(string&);

	~CommandGetter();

	//This function is used to extract the
	//command word from the user input.
	//Pre-req: CommandGetter initialized
	//Pos-req: string returned
	string tokenize();
};

