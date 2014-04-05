#include "EventGetter.h"


EventGetter::EventGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


EventGetter::~EventGetter(){
}

string EventGetter:: Tokenize(){
	string Event = space;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);
	unsigned int startPos = start;

	if(position == string::npos){
		Event = emptyString;
	}

	else if(command == Add || command == Edit){
		Event = (*uncategorizedInfo).substr(start, position + OneUnit);
    	unsigned int positionOne = Event.find_first_not_of(punctuationSet);

		if(positionOne != string::npos){
        	Event = Event.substr(positionOne);
		}

        positionOne = Event.find_last_not_of(punctuationSet);

    	if(positionOne != string::npos && positionOne != Event.size() - OneUnit && positionOne != Event.size() - TwoUnit){
    	    string punctuations = Event.substr(positionOne + OneUnit);
    		Event = Event.substr(start, positionOne + OneUnit);

			for(int i = zero; i < SixUnit; i++){
				positionOne = punctuations.find(punctuationArray[i]);
				if(positionOne != string::npos){
					Event = Event + punctuationArray[i];
					break;
				}
			}
		}

		do{
			positionOne = Event.find_first_of(punctuationSet, startPos);

			if(positionOne != string::npos){
				unsigned int positionTwo = Event.find_first_not_of(punctuationSet, positionOne);
				unsigned int size = zero;

				if(positionTwo != string::npos){
					size = positionTwo - positionOne;
				}

	    		if(size > OneUnit){
	    			char punctuation;
	    			string temp = Event.substr(positionOne, size);
    				unsigned int position;

	    			for(int i = zero; i < SixUnit; i++){
	    		    	position = temp.find(punctuationArray[i]);
	    	          	if(position != string::npos){
	    			    	Event = Event.substr(start, positionOne) + punctuationArray[i] + space + Event.substr(positionTwo);
	    		    		break;
	    	    		}
	    	    	}
	    		}
			}

			startPos = positionOne + OneUnit;

		}while(positionOne != string::npos && positionOne != Event.size() - OneUnit);
	}

	return Event;
}
