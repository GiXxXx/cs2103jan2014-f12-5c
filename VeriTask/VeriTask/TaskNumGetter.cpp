#include "TaskNumGetter.h"


TaskNumGetter::TaskNumGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


TaskNumGetter::~TaskNumGetter(){
}

string TaskNumGetter::Tokenize(){
	string TaskNumber;
	int position = start, size = unit;
	if(command == Edit || command == Mark){
		TaskNumber =  (*uncategorizedInfo).substr(position,size);
		chopInfo(*uncategorizedInfo, position, size);
	}
	else if(command == Delete){
		TaskNumber = *uncategorizedInfo;
	}
	return TaskNumber;
}
