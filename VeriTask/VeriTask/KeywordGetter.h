//@author A0101568J

/**
*This class is used to extract information about keyword
*for search from the given user input. And the user input will be choped
*accordingly.
*sample use:
*KeywordGetter sample(string userInput, string command);
*sample.tokenize();
*/

#pragma once
#include "Tokenizer.h"

class KeywordGetter :public Tokenizer{
	//this variable is the command of operation, it tells
	//whether there is a need to find keyword or not
	string _command;
public:
	//constructor which takes in the use input and the command
	//word identified.
	KeywordGetter(string&, string);

	~KeywordGetter();

	//This function is used to extract the
	//keyword for search from the user input.
	//Pre-req: KeywordGetter initialized
	//Pos-req: string returned
	string tokenize();
};

