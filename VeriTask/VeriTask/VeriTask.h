#ifndef HEADER_VERITASK_
#define HEADER_VERITASK_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Identifier.h"
#include "Task.h"

using namespace std;

class VeriTask {

private:
	vector<Task> _taskList;
	vector<Task> _taskListToDisplay;


public:
	VeriTask(); //default constructor
	void addTask(Task);
	void deleteTask(vector<Task>, int);
	void editTask(int, string);
	vector<Task> showTask();
	vector<Task> searchTask(string);
	void undoCommand();
	void markTask(int, int);

	/* 
	Show
	Select
	Identifier (must recognise "exit" also) */

};

#endif