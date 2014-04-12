//@author A0101568J

#include "Tokenizer.h"

Tokenizer::Tokenizer(string &userInput) {
	string temp = userInput;
	_uncategorizedInfo = &userInput;
	*_uncategorizedInfo = temp + SPACES;
}

Tokenizer::~Tokenizer() {
}

void Tokenizer::chopInfo(string &oldInfo, int position, int size) {
	unsigned int EndPos = position + size;

	if (EndPos < oldInfo.size()) {
		oldInfo = oldInfo.substr(START, position) + oldInfo.substr(position + size);
	} else {
		oldInfo = oldInfo.substr(START, position);
	}

	return;
}

bool Tokenizer::isNumber(string test) { 
	unsigned int matchCount = ZERO;
	bool result = false;

	for (unsigned int i = ZERO; i < test.size(); i++) {
		for (unsigned int j = ZERO; j < TEN_UNIT; j++) {
			if (test[i] == NUMBER[j]) {
				matchCount++;
			}
		}
	}

	if (matchCount == test.size() && matchCount != ZERO) {
		result = true;
	}

	return result;
}

void Tokenizer::changeToLowerCase(string &input) {
	for (unsigned int i = ZERO; i < input.size(); i++) {
		if (input[i] >= UPPER_A && input[i] <= UPPER_Z) {
			input[i] = input[i] - (UPPER_A - LOWER_A);
		}
	}

	return;
}

string Tokenizer::changeWordToNumber(string input) {
	int first = ZERO;
	int second = ZERO;
	unsigned int position = input.find_first_of(SPACE);
	string elementOne;
	string elementTwo;

	//find the position of space
	//to checke whether there are two words or one
	if (position == string::npos) {
		elementOne = input;
		elementTwo = SPACE;
	} else {
		elementOne = input.substr(START, position);
		elementTwo = input.substr(position + ONE_UNIT);
	}

	if (elementTwo == SPACE) {
		for (int i = ZERO; i < TEN_UNIT; i++) {
			if (elementOne == ONES[i]) {
				first = i;
				break;
			}
		}
	} else {
		for (int i = ZERO; i < TEN_UNIT + TEN_UNIT; i++) {
			if (elementOne == TENS[i]) {
				first = i * TEN_UNIT;
				break;
			}
		}

		for (int i = ZERO; i < TEN_UNIT; i++) {
			if (elementTwo == ONES[i]) {
				second = i;
				break;
			}
		}
	}

	//situation when "a" is inputed, return "1" as coresponding No.
	if (elementOne == STRING_A && elementTwo == SPACE) {
		first = ONE_UNIT;
	}

	int result = first + second;

	ostringstream out;

	out << result;

	return out.str();
}

void Tokenizer::changeDoubleDigit(string &Number) {
	if (isNumber(Number)) {
		if (stoi(Number) < 10 && Number.size() ==ONE_UNIT) {
			Number = ZERO_STRING + Number;
		}
	}

	return;
}

string Tokenizer::tokenize() {
	return *_uncategorizedInfo;
}