#include "StatusGetter.h"


StatusGetter::StatusGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


StatusGetter::~StatusGetter(){
}

string StatusGetter::Tokenize(){
	string status = NoStatus, temp;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);
	unsigned int positionOne = (*uncategorizedInfo).find_first_not_of(space);
	
	if(positionOne != string::npos && position != string::npos){ 
		temp = (*uncategorizedInfo).substr(positionOne, position - positionOne + OneUnit);
		ChangeToLowerCase(temp);
	}
	
	if(command == Mark){
		if(temp == Done || temp == UnDone || temp == CannotBeDone) {
			status = temp;
		} 
	}
	return status;
}

