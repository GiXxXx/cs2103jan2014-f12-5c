#include "KeywordGetter.h"


KeywordGetter::KeywordGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


KeywordGetter::~KeywordGetter(){
}

string KeywordGetter::Tokenize(){
	string Keyword;
	unsigned int position = (*uncategorizedInfo).find_last_not_of(space);

	if(position == string::npos){
		Keyword = "";
	}
	else if(command == Search){
		Keyword = (*uncategorizedInfo).substr(start, position + OneUnit);
	}
	return Keyword;
}
