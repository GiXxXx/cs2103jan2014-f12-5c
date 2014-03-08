#include "Task.h"

Task::Task(string Event, string Date, string StartTime, string EndTime, int Status) {
	_Event = Event;
	_Date = Date;
	_StartTime = StartTime;
	_EndTime = EndTime;
	_Status = Status;
	int Date_int, StartTime_int;
	istringstream (Date) >> Date_int;
	istringstream (StartTime) >> StartTime_int;
	_SequenceNum = Date_int * 100.0 + StartTime_int / 100.0;
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
