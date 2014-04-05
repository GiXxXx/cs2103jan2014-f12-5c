#include "CommandGetter.h"


CommandGetter::CommandGetter(string &uncategorizedInfo):Tokenizer(uncategorizedInfo){
}


CommandGetter::~CommandGetter(){
}

string CommandGetter::Tokenize(){
	unsigned int position = (*uncategorizedInfo).find_first_of(space);
	command = (*uncategorizedInfo).substr(start,position);
	Tokenizer::chopInfo((*uncategorizedInfo), start, position);
	ChangeToLowerCase(command);
	return command;
}
