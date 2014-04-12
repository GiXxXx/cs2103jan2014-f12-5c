#include "Task.h"

Task::Task(string event, string date, string startTime, string endTime, string status, int index) {
	_event = event;
	_date = date;
	_startTime = startTime;
	_endTime = endTime;
	_status = status;
	_index = index;
	unsigned long long int date_Int;
	unsigned long long int startTime_Int;
	unsigned long long int endTime_Int;

	if(date == "        "){
		date_Int = 99999;
	}
	else{
		date_Int = std::stoi(_date.substr(2,6));
	}
	if(startTime == "    "){
		startTime_Int = 9999;
	}
	else{
		startTime_Int = std::stoi(_startTime);
	}
	if(endTime == "    "){
		endTime_Int = 9999;
	}
	else{
		endTime_Int = std::stoi(_endTime);
	}

	struct tm timeNow;
	time_t localTime = time(NULL);

	localtime_s(&timeNow, &localTime);

	int localYear = timeNow.tm_year + 1900;
	int localMonth = timeNow.tm_mon + 1;
	int localDate = timeNow.tm_mday;
	int localHour = timeNow.tm_hour;
	int localMin = timeNow.tm_min;
	
	if ((date != "        ") && (status != "done")) {
	if (localYear*10000+localMonth*100+localDate > stoi(date)) {
		_status = "overdue";
	} else if (localYear*10000+localMonth*100+localDate == stoi(date)) {
		if ((startTime != "    ") && (endTime == "    ")) {
			if ((localHour*100+localMin) > stoi(startTime)) {
				_status = "overdue";
			}
		}
		if ((startTime != "    ") && (endTime != "    ")) {
			if ((localHour*100+localMin) > stoi(endTime)) {
				_status = "overdue";
			}
		}
	}
	}

	_ID = date_Int * 10000000000000 + startTime_Int * 1000000000  + endTime_Int * 100000 + index;
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

unsigned long long Task::getID() {
	return _ID;
}

int Task::getIndex() {
	return _index;
}

void Task::setEvent(string event) {
	_event = event;
}

void Task::setDate(string date) {
	_date = date;
}

void Task::setStartTime(string startTime) {
	_startTime = startTime;
}

void Task::setEndTime(string endTime) {
	_endTime = endTime;
}

void Task::setStatus(string status) {
	_status = status;
}

void Task::setID(unsigned long long ID) {
	_ID = ID;
}