#include "StatusGetter.h"


StatusGetter::StatusGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


StatusGetter::~StatusGetter(){
}

string StatusGetter::Tokenize(){
	string status = NoStatus;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);
	string temp = (*uncategorizedInfo).substr(start, position + OneUnit);
	if(command == Mark){
		if(temp == Done || temp == UnDone || temp == CannotBeDone) {
			status = temp;
		} 
	}

	return status;
}

