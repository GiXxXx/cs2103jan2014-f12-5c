//@author A0101039X

#include "Task.h"

Task::Task(string event, string date, string startTime, string endTime, string status, int index) {
	_event = event;
	_date = date;
	_startTime = startTime;
	_endTime = endTime;
	_status = status;
	_index = index;

	_ID = _calculateTaskID( _date, _startTime, _endTime, _index);
    _checkOverdue(_date, _startTime, _endTime, _status);
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