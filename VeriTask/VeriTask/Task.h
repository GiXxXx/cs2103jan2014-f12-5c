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
	int _Status;
	double _SequenceNum;

	public:
	Task(string Event, string Date, string StartTime, string EndTime, int Status);
	string getEvent();
	string getDate();
	string getStartTime();
	string getEndTime();
	double getSequenceNum();
};

#endif