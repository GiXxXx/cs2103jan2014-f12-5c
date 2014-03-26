#include "EndTimeGetter.h"


EndTimeGetter::EndTimeGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


EndTimeGetter::~EndTimeGetter(void){
}

string EndTimeGetter::Tokenize(){
	string EndTime;
	if(command == Add || command == Edit){
		EndTime = getTime(*uncategorizedInfo, at);

		if(EndTime == LargeTime)
			EndTime = getTime(*uncategorizedInfo, by);

		if(EndTime == LargeTime)
			EndTime = getTime(*uncategorizedInfo, to);
		}

	return EndTime;
}
