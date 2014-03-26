#include "Identifier.h"


Identifier::Identifier(){
}


Identifier::~Identifier(){
}

void Identifier::Identify(string userInput){
	CommandGetter CommandIdentifier(userInput);
	Command = CommandIdentifier.Tokenize();
	DateGetter DateIdentifier(userInput, Command);
	Date = DateIdentifier.Tokenize();
	StartTimeGetter StartIdentifier(userInput, Command);
	StartTime = StartIdentifier.Tokenize();
	EndTimeGetter EndIdentifier(userInput, Command);
	EndTime = EndIdentifier.Tokenize();
	EventGetter EventIdentifier(userInput, Command);
	Event = EventIdentifier.Tokenize();
	TaskNumGetter TaskNumIdentifier(userInput, Command);
	TaskNum = TaskNumIdentifier.Tokenize();
	KeywordGetter KeywordIdentifier(userInput, Command);
	Keyword = KeywordIdentifier.Tokenize();
	StatusGetter StatusIdentifier(userInput, Command);
	Status = StatusIdentifier.Tokenize();
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



