//@author A0101568J

#include "TaskNumGetter.h"

TaskNumGetter::TaskNumGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), _command(Command) {
}


TaskNumGetter::~TaskNumGetter() {
}

string TaskNumGetter::tokenize() {
	string TaskNumber = EMPTY_STRING;
	unsigned int position = (*_uncategorizedInfo).find_first_not_of(PUNCTUATION_SET);
	unsigned int positionTwo = (*_uncategorizedInfo).find_first_of(PUNCTUATION_SET, position);

	if ((_command == EDIT || _command == MARK) && position != string::npos) {
		TaskNumber =  (*_uncategorizedInfo).substr(position, positionTwo - position);
		chopInfo(*_uncategorizedInfo, START, positionTwo);
	} else if (_command == DEL && position != string::npos) {
		TaskNumber =  (*_uncategorizedInfo).substr(position, positionTwo - position);
	}

	changeToLowerCase(TaskNumber);

	//for example input like delete one
	//edit twenty.
	if (!isNumber(TaskNumber)) {
		TaskNumber = changeWordToNumber(TaskNumber);
	}

	if (TaskNumber == ZERO_STRING) {
		TaskNumber = EMPTY_STRING;
	}

	return TaskNumber;
}
