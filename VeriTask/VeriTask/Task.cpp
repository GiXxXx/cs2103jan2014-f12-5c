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

inline string Task::getEvent() { 
	return _event; 
}

inline string Task::getDate() { 
	return _date; 
}

inline string Task::getStartTime() {
	return _startTime;
}

inline string Task::getEndTime() {
	return _endTime;
}

inline string Task::getStatus() {
	return _status;
}

inline unsigned long long Task::getID() {
	return _ID;
}

inline int Task::getIndex() {
	return _index;
}

inline void Task::setEvent(string event) {
	_event = event;
}

inline void Task::setDate(string date) {
	_date = date;
}

inline void Task::setStartTime(string startTime) {
	_startTime = startTime;
}

inline void Task::setEndTime(string endTime) {
	_endTime = endTime;
}

inline void Task::setStatus(string status) {
	_status = status;
}

inline void Task::setID(unsigned long long ID) {
	_ID = ID;
}