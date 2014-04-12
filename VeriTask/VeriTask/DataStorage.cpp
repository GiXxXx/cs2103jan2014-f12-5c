//@author A0101039X

#include "DataStorage.h"

DataStorage::DataStorage() {
	_fileName = FILENAME;

	_readFile();
	_searchTaskToday();	
}

DataStorage::DataStorage(string fileName) {
	_fileName = fileName;

	_readFile();
	_searchTaskToday();
}

vector<Task> DataStorage::retrieveTaskList() {
	return _taskList;
}

vector<Task> DataStorage::retrieveTaskListToDisplay() {
	return _taskListToDisplay;
}

unsigned long long int DataStorage::retrieveTaskID(int taskNum) {
	unsigned long long int taskID = _taskListToDisplay[taskNum - 1].getID();
	return taskID;
}

Task DataStorage::retrieveTask(int taskNum) {
	Task task = _taskListToDisplay[taskNum - 1];
	return task;
}

void DataStorage::saveData(Task taskToSave) {
	bool isSaved = false;
	
	//add task according to ID
	for (_iter = _taskList.begin(); _iter < _taskList.end(); ++_iter) {
		if (_iter->getID() > taskToSave.getID()) {
			_taskList.insert(_iter, taskToSave);
			isSaved = true;
			break;
		}
	}

	//if the task has a large ID, it is a floating task;
	//floating task is saved to the end of the storage
	if (!isSaved) {
		_taskList.push_back(taskToSave);
	}
}

void DataStorage::deleteData(unsigned long long int taskID) {
	for (_iter = _taskList.begin(); _iter < _taskList.end(); ++_iter) { 
		bool isIDFound = _iter->getID() == taskID;
		
		if (isIDFound) {
			_taskList.erase(_iter);
			break;
		}
	}
}

void DataStorage::searchData(string keyword) {
	 _taskListToDisplay.clear();

	for (_iter = _taskList.begin(); _iter < _taskList.end(); ++_iter) {		
		bool isFoundEvent = (_iter->getEvent().find(keyword) != string::npos);

		if (isFoundEvent) {
			_taskListToDisplay.push_back(*_iter);
		}
	}
}

void DataStorage::searchDate(string keyword) {
	 _taskListToDisplay.clear();

	 for (_iter = _taskList.begin(); _iter < _taskList.end(); ++_iter) {
	    bool isDateFound = _iter->getDate().find(keyword) != string::npos;
		bool isDateEmpty = _iter->getDate() == EMPTY_DATES;
		
		//tasks with matching date and floating tasks are to be displayed
		if (isDateFound) {
			_taskListToDisplay.push_back(*_iter);
		} else if (isDateEmpty) {
			_taskListToDisplay.push_back(*_iter);
		}
	}
}

void DataStorage::searchStatus(string keyword) {
	 _taskListToDisplay.clear();

	for (_iter=_taskList.begin(); _iter<_taskList.end(); ++_iter) {
		bool isStatusFound = _iter->getStatus() == keyword;
		
		if (isStatusFound) {
			    _taskListToDisplay.push_back(*_iter);
		}
	}
}

void DataStorage::markData(unsigned long long int taskID, string status) {
	for (_iter=_taskList.begin(); _iter<_taskList.end(); ++_iter) {
		bool isIDFound = _iter->getID() == taskID;
		
		if (isIDFound) {
			_iter->setStatus(status);
			break;
		}
	}
}

void DataStorage::saveFile() {
	string date, startTime, endTime, event, status;
	int index;

	ofstream write(_fileName.c_str());
	write << _taskIndex << endl;

	for (unsigned int i=0; i<_taskList.size(); ++i) {
		date = _taskList[i].getDate();
		startTime = _taskList[i].getStartTime();
		endTime = _taskList[i].getEndTime();
		event = _taskList[i].getEvent();
		status = _taskList[i].getStatus();
		index = _taskList[i].getIndex();
		
		write << event << endl 
			  << date << endl 
			  << startTime << endl 
			  << endTime << endl   
			  << status << endl
			  << index << endl;
	}

	write.close();
}

void DataStorage::setTaskIndex(int taskIndex) {
	_taskIndex = taskIndex;
}

int DataStorage::getTaskIndex() {
	return _taskIndex;
}

void DataStorage::updateTaskListToDisplay(vector<Task> taskListToDisplay) {
	_taskListToDisplay = taskListToDisplay;
}