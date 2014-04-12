//@author A0101568J

#include "TaskNumGetter.h"

TaskNumGetter::TaskNumGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), _command(Command) {
}


TaskNumGetter::~TaskNumGetter() {
}

string TaskNumGetter::tokenize() {
	string TaskNumber = EMPTYSTRING;
	unsigned int position = (*_uncategorizedInfo).find_first_not_of(PUNCTUATIONSET);
	unsigned int positionTwo = (*_uncategorizedInfo).find_first_of(PUNCTUATIONSET, position);

	if ((_command == EDIT || _command == MARK) && position != string::npos) {
		TaskNumber =  (*_uncategorizedInfo).substr(position, positionTwo - position);
		chopInfo(*_uncategorizedInfo, START, positionTwo);
	} else if (_command == DELETE && position != string::npos) {
		TaskNumber =  (*_uncategorizedInfo).substr(position, positionTwo - position);
	}

	changeToLowerCase(TaskNumber);

	//for example input like delete one
	//edit twenty.
	if (!isNumber(TaskNumber)) {
		TaskNumber = changeWordToNumber(TaskNumber);
	}

	if (TaskNumber == ZERO_STRING) {
		TaskNumber = EMPTYSTRING;
	}

	return TaskNumber;
}
