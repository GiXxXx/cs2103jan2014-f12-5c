//@author A0101568J

#include "CommandGetter.h"


CommandGetter::CommandGetter(string &uncategorizedInfo):Tokenizer(uncategorizedInfo) {
}


CommandGetter::~CommandGetter() {
}

string CommandGetter::tokenize() {
	unsigned int position = (*_uncategorizedInfo).find_first_of(PUNCTUATION_SET);
	_command = (*_uncategorizedInfo).substr(START,position);
	Tokenizer::chopInfo((*_uncategorizedInfo), START, position);
	*_uncategorizedInfo = *_uncategorizedInfo + SPACES;
	changeToLowerCase(_command);
	
	string commandArray[NINE_UNIT] = {ADD, EDIT, DEL, MARK, DISPLAY, SEARCH,
		                              UNDO, REDO, EXIT};
    bool isValid = false;

	for (int i = ZERO; i < NINE_UNIT; i++) {
		if (_command == commandArray[i]) {
			isValid = true;
			break;
		}
	}

	//when command word is not in given format
	//retuen empty string
	if (!isValid) {
		_command = EMPTY_STRING;
	}

	return _command;
}
