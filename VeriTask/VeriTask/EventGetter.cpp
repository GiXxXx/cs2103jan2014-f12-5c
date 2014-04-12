//@author A0101568J

#include "EventGetter.h"


EventGetter::EventGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), _command(Command) {
}


EventGetter::~EventGetter() {
}

string EventGetter:: tokenize() {
	string Event = EMPTYSTRING;
	unsigned int position = (*_uncategorizedInfo).find_last_not_of(SPACE);
	unsigned int startPos = START;

	if (position == string::npos) {
		Event = EMPTYSTRING;
	} else if (_command == ADD || _command == EDIT) {
		Event = (*_uncategorizedInfo).substr(START, position + ONE_UNIT);
    	unsigned int positionOne = Event.find_first_not_of(PUNCTUATIONSET);

		if (positionOne != string::npos) {
        	Event = Event.substr(positionOne);
		}

        positionOne = Event.find_last_not_of(PUNCTUATIONSET);

		//remove the extra punctuation at the end of
		//the string, and replace the extra punctuations
		//with the most significant punctuation inside
		//the original string
    	if (positionOne != string::npos && positionOne != Event.size() - ONE_UNIT
			&& positionOne != Event.size() - TWO_UNIT) {
    	    string punctuations = Event.substr(positionOne + ONE_UNIT);
    		Event = Event.substr(START, positionOne + ONE_UNIT);

			for (int i = ZERO; i < FIVE_UNIT; i++) {
				positionOne = punctuations.find(PUNCTUATIONARRAY[i]);
				if (positionOne != string::npos) {
					Event = Event + PUNCTUATIONARRAY[i];
					break;
				}
			}
		}

		//remove all the extra punctuations start from the beginning
		do {
			positionOne = Event.find_first_of(PUNCTUATIONSET, startPos);

			if (positionOne != string::npos) {
				unsigned int positionTwo = Event.find_first_not_of(PUNCTUATIONSET, positionOne);
				unsigned int size = ZERO;

				if (positionTwo != string::npos) {
					size = positionTwo - positionOne;
				}

	    		if (size > ONE_UNIT) {
	    			string temp = Event.substr(positionOne, size);
    				unsigned int position;

	    			for (int i = ZERO; i < SIX_UNIT; i++) {
	    		    	position = temp.find(PUNCTUATIONARRAY[i]);
	    	          	if (position != string::npos) {
	    			    	Event = Event.substr(START, positionOne) + PUNCTUATIONARRAY[i]
								    + SPACE + Event.substr(positionTwo);
	    		    		break;
	    	    		}
	    	    	}
	    		}
			}

			startPos = positionOne +ONE_UNIT;

		} while (positionOne != string::npos && positionOne != Event.size() - ONE_UNIT);
	}

	return Event;
}
