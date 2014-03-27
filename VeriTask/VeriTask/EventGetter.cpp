#include "EventGetter.h"


EventGetter::EventGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


EventGetter::~EventGetter(){
}

string EventGetter:: Tokenize(){
	string Event = space;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);

	if(position == string::npos){
		Event = "";
	}

	else if(command == Add || command == Edit){
		Event = (*uncategorizedInfo).substr(start, position + OneUnit);
	}

	return Event;
}
