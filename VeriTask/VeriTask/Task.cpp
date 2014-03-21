#include "Task.h"

Task::Task(string Event, string Date, string StartTime, string EndTime) {
	_Event = Event;
	_Date = Date;
	_StartTime = StartTime;
	_EndTime = EndTime;
	//_Status = Status;
    int Date_Int = std::stoi(_Date);
	int StartTime_Int = std::stoi(_StartTime);
	_SequenceNum = Date_Int + StartTime_Int/10000.0;
}

string Task::getEvent() {
	return _Event;
}

string Task::getDate() {
	return _Date;
}

string Task::getStartTime() {
	return _StartTime;
}

string Task::getEndTime() {
	return _EndTime;
}

double Task::getSequenceNum() {
	return _SequenceNum;
}
