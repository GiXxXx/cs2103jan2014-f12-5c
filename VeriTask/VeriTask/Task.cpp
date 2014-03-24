#include "Task.h"

Task::Task(string Event, string Date, string StartTime, string EndTime) {
	_event = Event;
	_date = Date;
	_startTime = StartTime;
	_endTime = EndTime;
	//_Status = Status;
    int date_Int = std::stoi(_date);
	int startTime_Int = std::stoi(_startTime);
	int endTime_Int = std::stoi(_endTime);
	_ID = date_Int + startTime_Int/10000.0 + endTime_Int/100000000.0;
}

string Task::getEvent() {
	return _event;
}

string Task::getDate() {
	return _date;
}

string Task::getStartTime() {
	return _startTime;
}

string Task::getEndTime() {
	return _endTime;
}

string Task::getStatus() {
	return _status;
}

double Task::getID() {
	return _ID;
}

void Task::setStatus(string status) {
	_status = status;
}


