#include "EventGetter.h"


EventGetter::EventGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


EventGetter::~EventGetter(){
}

string EventGetter:: Tokenize(){
	string Event = space;

	if(command == Add || command == Edit){
		Event = *uncategorizedInfo;
	}

	return Event;
}
