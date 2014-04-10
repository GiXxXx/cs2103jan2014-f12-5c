#ifndef HEADER_DATASTORAGE_
#define HEADER_DATASTORAGE_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Task.h"

const string FILENAME = "data.txt";

using namespace std;

class DataStorage {
private:
	vector<Task> _taskList;
	vector<Task> _pastDueTaskList;
	vector<Task> _doneTaskList;
	vector<Task> _taskListToDisplay;
	vector<Task>::iterator iter;
	string _fileName;
	int _taskIndex;

public:
	DataStorage();
	DataStorage(string);

	vector<Task> retrieveTaskList();
	vector<Task> retrieveTaskListToDisplay();
	unsigned long long int retrieveTaskID(int);
	Task retrieveTask(int);

	void saveFile();

//	void printTask();
//	void printTaskToDisplay(); 
	void saveData(Task taskToSave);
	void deleteData(unsigned long long int taskID);
	bool searchData(string keyword);
	bool searchDataDate(string keyword);
	bool searchDataStatus(string keyword);
	void markData(unsigned long long int taskID, string status);
	void setTaskIndex(int taskIndex);
	void setTaskListToDisplay(vector<Task> taskListToDisplay);
	int getTaskIndex();
};

#endif