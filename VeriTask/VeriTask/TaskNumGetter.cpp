#include "TaskNumGetter.h"


TaskNumGetter::TaskNumGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


TaskNumGetter::~TaskNumGetter(){
}

string TaskNumGetter::Tokenize(){
	string TaskNumber = Zero;
	unsigned int position = (*uncategorizedInfo).find_first_not_of(space);
	unsigned int positionTwo = (*uncategorizedInfo).find_first_of(space, position);

	if(command == Edit || command == Mark){
		TaskNumber =  (*uncategorizedInfo).substr(position, positionTwo - position);
		chopInfo(*uncategorizedInfo, start, positionTwo);
	}
	else if(command == Delete){
		TaskNumber =  (*uncategorizedInfo).substr(position, positionTwo - position);
	}

	if(!isNumber(TaskNumber)){
		TaskNumber = changeWordToNumber(TaskNumber);
	}

	return TaskNumber;
}
