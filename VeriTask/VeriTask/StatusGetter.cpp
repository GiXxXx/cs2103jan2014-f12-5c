#include "StatusGetter.h"


StatusGetter::StatusGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


StatusGetter::~StatusGetter(){
}

string StatusGetter::Tokenize(){
	string status = NoStatus;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);

	if(command == Mark){
		if(*uncategorizedInfo == Done || *uncategorizedInfo == UnDone || *uncategorizedInfo == CannotBeDone) {
			status = (*uncategorizedInfo).substr(start, position + OneUnit);
		} 
	}

	return status;
}
