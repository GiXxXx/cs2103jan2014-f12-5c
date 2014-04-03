#ifndef HEADER_TASK_
#define HEADER_TASK_
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
	double _ID;

public:
	Task(string event, string date, string startTime, string endTime, int index);
	string getEvent();
	string getDate();
	string getStartTime();
	string getEndTime();
	string getStatus();
	double getID();

	void setStatus(string status);

/*	string setDate(string Date);
	string setStartTime(string StartTime);
	string setEndTime(string EndTime);
	string setEvent(string Event);
	double setSeqenceNum(double SequenceNum);
	 */
};

#endif