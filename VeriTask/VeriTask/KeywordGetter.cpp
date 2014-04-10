#include "KeywordGetter.h"


KeywordGetter::KeywordGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


KeywordGetter::~KeywordGetter(){
}

string KeywordGetter::Tokenize(){
	string Keyword;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);
	unsigned int positionOne = (*uncategorizedInfo).find_first_not_of(space);

	if(position == string::npos){
		Keyword = emptyString;
	}
	else if(command == Search){
		Keyword = (*uncategorizedInfo).substr(positionOne, position - positionOne + OneUnit);
	}
	return Keyword;
}
