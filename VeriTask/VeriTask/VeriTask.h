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
	void deleteTask(int);
	void editTask(string, int);
	vector<Task> showTask(); //combine it with confirmation info
	vector<Task> searchTask(string);
	void undoCommand();
	void markTask(string, int);

	/* 
	Show
	Select
	Identifier (must recognise "exit" also) */

};

#endif