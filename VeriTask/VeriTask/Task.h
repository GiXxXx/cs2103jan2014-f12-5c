#ifndef HEADER_TASK_
#define HEADER_TASK_
//@author A0101540A
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Task {

private:
	string _event;
	string _date;
	string _startTime;
	string _endTime;
	string _status;
	int _index;
	unsigned long long _ID;

public:
	Task(string event, string date, string startTime, string endTime, string _status, int index);
	string getEvent();
	string getDate();
	string getStartTime();
	string getEndTime();
	string getStatus();
	unsigned long long getID();
	int getIndex();

	void setEvent(string event);
	void setDate(string date);
	void setStartTime(string startTime);
	void setEndTime(string endTime);
	void setStatus(string status);
	void setID(unsigned long long ID);
};

#endif