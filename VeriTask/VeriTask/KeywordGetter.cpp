#include "KeywordGetter.h"


KeywordGetter::KeywordGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


KeywordGetter::~KeywordGetter(){
}

string KeywordGetter::Tokenize(){
		string Keyword;
	if(command == Search){
		Keyword = *uncategorizedInfo;
	}
	return Keyword;
}
