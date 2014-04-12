//@author A0101039X

/**
* This is the class that manages all the storage.
* It contains 2 vectors of tasks: _taskList which stores all tasks and
* _taskListToDisplay which comtains tasks to be shown on the screen.
* _taskListToDisplay will be passed to GUI for display.
* This class manages two kinds of storage: temporary storage where data
* is stored in a vector, and file storage while data is stored into
* a text file after every operation from the user.
*/

#pragma once

#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include "Task.h"

using namespace std;

const string FILENAME = "data.txt";

class DataStorage {
private:
	vector<Task> _taskList; //stores all tasks, serve as a temporage storage
	vector<Task> _taskListToDisplay; //stores all tasks to be displayed on screen
	vector<Task>::iterator _iter;
	string _fileName;
	
	//this records the running index number of tasks;
	//it is used to distinguish tasks with same date and timings.
	int _taskIndex;

	//this function reads the data from the file and store it in _taskList in 
	//the temporary storage for further processing.
	//Pre-req: nil.
	//Post-req: nil.
	void _readFile(void) {
		string date, startTime, endTime, event, status, index, taskIndex;
		int index_int;
	
		ifstream readFile(_fileName.c_str());

		getline(readFile, taskIndex);

		if (taskIndex.size() == 0) {
			_taskIndex = 0;
		} else {
			_taskIndex = stoi(taskIndex);
		}

		while(getline(readFile, event)) {
			getline(readFile, date);
			getline(readFile, startTime);
			getline(readFile, endTime);
			getline(readFile, status);
			getline(readFile, index);
			index_int = stoi(index);

			Task task(event, date, startTime, endTime, status, index_int);
			_taskList.push_back(task);
		}
		
		readFile.close();
	}
	
	//this function searches for tasks of today, together with floating tasks,
	//to display them on task sheet on the screen.
	//Pre-req: nil;
	//Post-reqL nil;
	void _searchTaskToday(void) {
		for (_iter = _taskList.begin(); _iter < _taskList.end(); _iter++) {
			struct tm timeNow;
			time_t localTime = time(NULL);
			localtime_s(&timeNow, &localTime);

			int localYear = timeNow.tm_year + ONE_NINE_ZERO_ZERO;
			int localMonth = timeNow.tm_mon + ONE;
			int localDate = timeNow.tm_mday;

			if ((_iter->getDate() == EMPTY_DATES) || 
				localYear * FOUR_ZEROS + localMonth * TWO_ZEROS + localDate == std::stoi(_iter->getDate())) {
				_taskListToDisplay.push_back(*_iter);
			}
		}
	}


public:
	//this construtor reads data from the file "text.txt" and stores the data
	//in our temporage storage.
	DataStorage();

	//this constructor reads data from a particular file with name same as
	//fileName and stores the data in our temporary storage
	DataStorage(string fileName);

	//this method retrieves _taskList;
	//Pre-req: nil.
	//Post-req: it returns _taskList.
	vector<Task> retrieveTaskList();

	//this method retrieves _taskListToDisplay; it is reposible to interact with
	//GUI to update the task sheet on GUI
	//Pre-req: nil.
	//Post-req: it returns _taskListToDisplay.
	vector<Task> retrieveTaskListToDisplay();
	
	//this method retrieves the task ID of a particular task from
	//_taskListToDisplay
	//Pre-req: task number of the task
	//Post-req: task ID of the selected task
	unsigned long long int retrieveTaskID(int);

	//this method retrieves a particular task from _taskListToDisplay
	//Pre-req: task number of the task
	//Post-req: the selected task
	Task retrieveTask(int);

	//this method adds a new task to the tasklist in out temporary
	//storage, _taskList
	//Pre-req: task to be saved
	//Post-req: nil
	void saveData(Task taskToSave);

	//this method deletes a selected task from _taskList
	//Pre-req: ID of the task to be deleted
	//Post-req: nil
	void deleteData(unsigned long long int taskID);
	
	//this methods searches the event of tasks; if a match is
	//found, it will add that task into _taskListToDisplay for display
	//Pre-req: keyword to search for
	//Post-req: nil
	void searchData(string keyword);

	//this method searches the date of tasks; if a match is
	//found, it will add that task into _taskListToDisplay for display
	//Pre-req: keyword to search for
	//Post-req: nil
    void searchDate(string keyword);

    //this method searches the status of tasks; if a match is
	//found, it will add that task into _taskListToDisplay for display
	//Pre-req: keyword to search for
	//Post-req: nil
	void searchStatus(string keyword);

	//this method is used to mark the status of a status
	//Pre-req: ID of the task to be marked, status
	//Post-req: nil
	void markData(unsigned long long int taskID, string status);
	
	//this method is used to save all the data from our temporary storage
	//to the file.
	//Pre-req: nil
	//Post-req: nil
	void saveFile();

	//this method is used to set the running index
	//Pre-req: the index to be set
	//Post-req: nil
	void setTaskIndex(int taskIndex);
	
	//this method is used to retrieve the running index
	//Pre-req: nil
	//Post-req: running index
	int getTaskIndex();

	//this method is used to update _taskListToDisplay after operations from
	//the user
	//Pre-req: task list to be updated to
	//Post-req: nil
	void updateTaskListToDisplay(vector<Task> taskListToDisplay);
	
};
