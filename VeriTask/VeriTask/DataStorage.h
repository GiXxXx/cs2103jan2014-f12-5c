#ifndef HEADER_DATASTORAGE_
#define HEADER_DATASTORAGE_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Task.h"
#include "File.h"

using namespace std;

class DataStorage {
private:
	vector<Task> _taskList;
	vector<Task> _taskListToDisplay;
	vector<Task>::iterator iter;
	int _taskIndex;

public:
	DataStorage();
	
	vector<Task> retrieveTaskList();
	vector<Task> retrieveTaskListToDisplay();
	unsigned long long int retrieveTaskID(int);
	Task retrieveTask(int);
	void fillData(vector<Task>);
	void saveData(Task taskToSave);
	void deleteData(unsigned long long int taskID);
	bool searchData(string keyword);
	void markData(unsigned long long int taskID, string status);
	void setTaskIndex(int taskIndex);
	int getTaskIndex();
};
#endif