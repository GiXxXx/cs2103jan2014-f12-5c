#include "StatusGetter.h"


StatusGetter::StatusGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


StatusGetter::~StatusGetter(){
}

string StatusGetter::Tokenize(){
	string status = NoStatus;

	if(command == Mark){
		if(*uncategorizedInfo == Done || *uncategorizedInfo == UnDone || *uncategorizedInfo == CannotBeDone) {
			status = *uncategorizedInfo;
		} 
	}

	return status;
}
