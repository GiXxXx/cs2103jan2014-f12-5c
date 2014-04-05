#include "StartTimeGetter.h"


StartTimeGetter::StartTimeGetter(string& uncategorizedInfo, string Command):Tokenizer(uncategorizedInfo), command(Command){
}


StartTimeGetter::~StartTimeGetter(){
}

string StartTimeGetter::Tokenize(){
	string StartTime, tempTime;

	if(command == Add || command == Edit){
		StartTime = getTime(*uncategorizedInfo, from);

		if(StartTime == LargeTime)
			StartTime = getTime(*uncategorizedInfo, during);
	}



	return StartTime;
}
