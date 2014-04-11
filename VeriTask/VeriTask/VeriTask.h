#ifndef HEADER_VERITASK_
#define HEADER_VERITASK_
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Command.h"
#include "AddTask.h"
#include "DeleteTask.h"
#include "EditTask.h"
#include "SearchTask.h"
#include "MarkTask.h"
#include "TaskDisplayer.h"

using namespace std;

class VeriTask {
private:
	vector<Command*> commandList;
	vector<vector<Task>> taskListVector;
	vector<vector<Task>> taskListToDisplayVector;
	vector<int> taskIndexVector;
//	vector<vector<Task>> taskListVector;
//	vector<vector<Task>> taskListToDisplayVector;
//	vector<int> taskIndexVector;
	vector<DataStorage> undoList;
	vector<DataStorage> redoList;
	int commandCount;
	
public:
	VeriTask(/*DataStorage&*/);
	~VeriTask();
    void pushCommand(string, Identifier, TextUI, DataStorage&); 
	void undoCommand();
	void redoCommand();
};
#endif