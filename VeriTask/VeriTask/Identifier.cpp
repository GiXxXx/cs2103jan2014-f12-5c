#include "Identifier.h"


Identifier::Identifier(){
	index = 0;
}

Identifier::~Identifier(){
}

void Identifier::Identify(string userInput) {
	index++;
	CommandGetter CommandIdentifier(userInput);
	Command = CommandIdentifier.Tokenize();
	TaskNumGetter TaskNumIdentifier(userInput, Command);
	TaskNum = TaskNumIdentifier.Tokenize();
	DateGetter DateIdentifier(userInput, Command);
	Date = DateIdentifier.Tokenize();
	TimeGetter StartTimeIdentifier(userInput, Command);
	StartTime = StartTimeIdentifier.Tokenize();
	TimeGetter EndTimeIdentifier(userInput, Command);
	EndTime = EndTimeIdentifier.Tokenize();
	StatusGetter StatusIdentifier(userInput, Command);
	Status = StatusIdentifier.Tokenize();
	KeywordGetter KeywordIdentifier(userInput, Command);
	Keyword = KeywordIdentifier.Tokenize();
	EventGetter EventIdentifier(userInput, Command);
	Event = EventIdentifier.Tokenize();
	
	if(StartTime != LargeTime && Date == LargeDate){
		string dummyString = dummy;
		DateGetter dummyDateIdentifier(dummyString, Add);
		Date = dummyDateIdentifier.Tokenize();
	}
}

string Identifier::GetDate(){
	return Date;
}

string Identifier::GetStartTime(){
	return StartTime;
}

string Identifier::GetEndTime(){
	return EndTime;
}

string Identifier::GetEvent(){
	return Event;
}

string Identifier::GetTaskNum(){
	return TaskNum;
}

string Identifier::GetKeyword(){
	return Keyword;
}

string Identifier::GetCommand(){
	return Command;
}

string Identifier::GetStatus(){
	return Status;
}

/*int Identifier::getIndex() {
	return index;
} */

