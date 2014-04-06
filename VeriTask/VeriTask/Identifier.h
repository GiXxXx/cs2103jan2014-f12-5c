#pragma once
#include "CommandGetter.h"
#include "DateGetter.h"
#include "EndTimeGetter.h"
#include "EventGetter.h"
#include "KeywordGetter.h"
#include "StartTimeGetter.h"
#include "StatusGetter.h"
#include "TaskNumGetter.h"
#include "Tokenizer.h"

class Identifier{
private:
	string Command;
	string Event;
	string Date;
	string StartTime;
	string EndTime;
	string Keyword;
	string TaskNum;
	string Status;
	int index;
public:
	Identifier();
	~Identifier();
	void Identify(string);
	string GetEvent();
	string GetDate();
	string GetStartTime();
	string GetEndTime();
	string GetKeyword();
	string GetTaskNum();
	string GetCommand();
	string GetStatus();
};

