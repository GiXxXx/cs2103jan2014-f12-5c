#include "Task.h"

Task::Task(string event, string date, string startTime, string endTime, int index) {
	_event = event;
	_date = date;
	_startTime = startTime;
	_endTime = endTime;
	_index = index;
	unsigned long long int date_Int;
	unsigned long long int startTime_Int;
	unsigned long long int endTime_Int;

	if(date == "        "){
		date_Int = 99999999;
	}
	else{
		date_Int = std::stoi(_date);
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

	//index = index/10000000000000.0;

	_ID = date_Int * 100000000000 + startTime_Int * 10000000  + endTime_Int * 1000 + index;
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