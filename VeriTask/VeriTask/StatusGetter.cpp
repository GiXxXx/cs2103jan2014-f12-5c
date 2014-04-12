//@author A0101568J

#include "StatusGetter.h"

StatusGetter::StatusGetter(string& uncategorizedInfo, string Command) :Tokenizer(uncategorizedInfo), _command(Command) {
}


StatusGetter::~StatusGetter() {
}

string StatusGetter::tokenize() {
	string status = NOSTATUS;
	string temp = status;
	int wordCount = ZERO;
	int indicator = ZERO;
	int sizeOne = TEN_UNIT + FIVE_UNIT;
	int sizeTwo = FOUR_UNIT * TEN_UNIT;
	int sizeThree = TEN_UNIT + ONE_UNIT;
	unsigned int positionOne = ZERO;
	unsigned int positionTwo = ZERO;
	unsigned int startPos = ZERO;

	positionOne = (*_uncategorizedInfo).find_first_not_of(PUNCTUATIONSET, startPos);

	if (positionOne != string::npos) {
		temp = (*_uncategorizedInfo).substr(positionOne);
	}

	//check number of words inside the user input
	while (positionOne != string::npos && startPos != string::npos) {
		positionOne = (*_uncategorizedInfo).find_first_not_of(PUNCTUATIONSET, startPos);

		if (positionOne != string::npos) {
			positionTwo = (*_uncategorizedInfo).find_first_of(PUNCTUATIONSET, positionOne);
		}

		if (positionTwo != string::npos && positionOne != string::npos) {
			wordCount++;
		}

		startPos = positionTwo;
	}

	if (wordCount == ZERO) {
		status = EMPTYSTRING;
	}

	//if more than one word, check status from the
	//MULTI_WORD_STATUS array
	if (wordCount > ONE_UNIT) {
		for (int i = ZERO; i < sizeTwo; i++) {
			if (temp.find(MULTI_WORD_STATUS[i]) != string::npos) {
				if (i <= TEN_UNIT + ONE_UNIT) {
					status = DONE;
					break;
				} else if (i <= TEN_UNIT + TEN_UNIT +SIX_UNIT) {
					status = CANNOT_BE_DONE;
					break;
				} else if (i < sizeTwo) {
					status = UNDONE;
					break;
				}
			}
		}
	}

	//if only one word or status not found
	//check the ONE_WORD_STATUS array
	if (wordCount == ONE_UNIT || (status != DONE && status != UNDONE && status != CANNOT_BE_DONE)) {
		for (int i = ZERO; i < sizeOne; i++) {
			if (temp.find(ONE_WORD_STATUS[i]) != string::npos) {
				if (i <= FOUR_UNIT) {
					status = CANNOT_BE_DONE;
					break;
				} else if (i < TEN_UNIT) {
					status = UNDONE;
					break;
				} else if (i < sizeOne) {
					status = DONE;
					break;
				}
			}
		}
	}

	//for display, overdue or all status can be get
	//while for mark, cannot
	if (_command == DISPLAY && (status != OVERDUE || status != ALL)) {
		for (int i = ZERO; i < sizeThree; i++) {
			if (temp.find(OVERDUE_STATUS[i]) != string::npos) {
				if (i <= SEVEN_UNIT) {
					status = OVERDUE;
					break;
				} else if (i < sizeThree) {
					status = ALL;
					break;
				}
			}
		}
	}

	if (_command == MARK || _command == DISPLAY) {
		if (status == DONE || status == UNDONE || 
			status == CANNOT_BE_DONE || 
			status == OVERDUE || status == ALL) {
			status = status;
		}
	} else {
		status = EMPTYSTRING;
	}

	return status;
}

