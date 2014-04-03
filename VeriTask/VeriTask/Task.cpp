#include "Task.h"

Task::Task(string Event, string Date, string StartTime, string EndTime) {
	_event = Event;
	_date = Date;
	_startTime = StartTime;
	_endTime = EndTime;
	//_Status = Status;
	int date_Int;
	int startTime_Int;
	int endTime_Int;

	if(Date == "        "){
		date_Int = 99999999;
	}
	else{
		date_Int = std::stoi(_date);
	}
	if(StartTime == "    "){
		startTime_Int = 9999;
	}
	else{
		startTime_Int = std::stoi(_startTime);
	}
	if(EndTime == "    "){
		endTime_Int = 9999;
	}
	else{
		endTime_Int = std::stoi(_endTime);
	}

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


