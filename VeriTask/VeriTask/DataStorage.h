#ifndef HEADER_DATASTORAGE_
#define HEADER_DATASTORAGE_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Task.h"

using namespace std;

class DataStorage {
private:
	vector<Task> _taskList;
	vector<Task> _taskListToDisplay;
	vector<Task>::iterator iter;

public:
	DataStorage();
	
	vector<Task> retrieveTaskList();
	vector<Task> retrieveTaskListToDisplay();
	double retrieveTaskID(int);

//	void printTask();
//	void printTaskToDisplay(); 

	void saveData(Task taskToSave);
	void deleteData(double taskID);
	bool searchData(string keyword);
	void markData(double taskID, string status);
};

#endif