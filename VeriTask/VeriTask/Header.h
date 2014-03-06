#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Task {

private:
	double _SequenceNo;
	string _Title;
	int _Deadline;
	double _StartTime;
	double _EndTime;
	int _Status;

	public:
	Task(); //default constructor
	void Undo();
	void Mark(string status);

};

class VeriTask {

private:
	vector<Task> Data;

};



#endif