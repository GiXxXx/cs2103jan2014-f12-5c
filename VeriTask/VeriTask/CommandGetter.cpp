#include "CommandGetter.h"


CommandGetter::CommandGetter(string &uncategorizedInfo):Tokenizer(uncategorizedInfo){
}


CommandGetter::~CommandGetter(){
}

string CommandGetter::Tokenize(){
	unsigned int position = (*uncategorizedInfo).find_first_of(space);
	command = (*uncategorizedInfo).substr(start,position);
	Tokenizer::chopInfo((*uncategorizedInfo), start, position);
	*uncategorizedInfo = *uncategorizedInfo + Spaces;
	ChangeToLowerCase(command);
	
	string commandArray[NineUnit] = {Add, Edit, Delete, Mark, Display, Search, Undo, Redo, Exit};
    bool isValid = false;

	for(int i = zero; i < NineUnit; i++){
		if(command == commandArray[i]){
			isValid = true;
			break;
		}
	}

	if(!isValid){
		command = emptyString;
	}

	return command;
}
