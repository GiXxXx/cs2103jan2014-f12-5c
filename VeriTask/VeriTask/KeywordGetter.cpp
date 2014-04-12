//@author A0101568J

#include "KeywordGetter.h"


KeywordGetter::KeywordGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), _command(Command) {
}


KeywordGetter::~KeywordGetter() {
}

string KeywordGetter::tokenize() {
	string Keyword;
	unsigned int position = (*_uncategorizedInfo).find_last_not_of(PUNCTUATION_SET);
	unsigned int positionOne = (*_uncategorizedInfo).find_first_not_of(PUNCTUATION_SET);

	//if empty, the keyword will be empty string
	if (position == string::npos) {
		Keyword = EMPTY_STRING;
	} else if (_command == SEARCH) {
		Keyword = (*_uncategorizedInfo).substr(positionOne, position - positionOne + ONE_UNIT);
	}
	return Keyword;
}
