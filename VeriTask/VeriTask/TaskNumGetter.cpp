#include "TaskNumGetter.h"


TaskNumGetter::TaskNumGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


TaskNumGetter::~TaskNumGetter(){
}

string TaskNumGetter::Tokenize(){
	string TaskNumber;

	if(command == Edit || command == Mark){
		TaskNumber =  (*uncategorizedInfo).substr(start, OneUnit);
		chopInfo(*uncategorizedInfo, start, OneUnit);
	}
	else if(command == Delete){
		TaskNumber =  (*uncategorizedInfo).substr(start, OneUnit);
	}
	return TaskNumber;
}
