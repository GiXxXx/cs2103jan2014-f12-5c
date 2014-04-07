#include "TaskNumGetter.h"


TaskNumGetter::TaskNumGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


TaskNumGetter::~TaskNumGetter(){
}

string TaskNumGetter::Tokenize(){
	string TaskNumber = emptyString;
	unsigned int position = (*uncategorizedInfo).find_first_not_of(space);
	unsigned int positionTwo = (*uncategorizedInfo).find_first_of(space, position);

	if((command == Edit || command == Mark) && position != string::npos){
		TaskNumber =  (*uncategorizedInfo).substr(position, positionTwo - position);
		chopInfo(*uncategorizedInfo, start, positionTwo);
	}
	else if(command == Delete && position != string::npos){
		TaskNumber =  (*uncategorizedInfo).substr(position, positionTwo - position);
	}

	ChangeToLowerCase(TaskNumber);

	if(!isNumber(TaskNumber)){
		TaskNumber = changeWordToNumber(TaskNumber);
	}

	if(TaskNumber == Zero){
		TaskNumber = emptyString;
	}

	return TaskNumber;
}
