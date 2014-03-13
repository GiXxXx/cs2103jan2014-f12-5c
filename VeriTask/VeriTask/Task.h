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
	string _Event;
	string _Date;
	string _StartTime;
	string _EndTime;
	string _Status;
	double _SequenceNum;

	public:
	Task(string Event, string Date, string StartTime, string EndTime, string Status);
	Task(); //default constructor
	string getEvent();
	string getDate();
	string getStartTime();
	string getEndTime();
	string getStatus();
	double getSequenceNum();

	string setDate(string Date);
	string setStartTime(string StartTime);
	string setEndTime(string EndTime);
	string setEvent(string Event);
	double setSeqenceNum(double SequenceNum);
	string setStatus(string Status);
};

#endif