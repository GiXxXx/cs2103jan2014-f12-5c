#include "DataStorage.h"

DataStorage::DataStorage() {
}
	
vector<Task> DataStorage::retrieveTaskList() {
	return _taskList;
}

vector<Task> DataStorage::retrieveTaskListToDisplay() {
	return _taskListToDisplay;
}

double DataStorage::retrieveTaskID(int taskNum) {
	double taskID = _taskListToDisplay[taskNum-1].getID();
	return taskID;
}

Task DataStorage::retrieveTask(int taskNum) {
	Task task = _taskListToDisplay[taskNum-1];
	return task;
}

void DataStorage::saveData(Task taskToSave) {
	bool isSaved = false;
	
	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) {
		if (iter->getID() > taskToSave.getID()) {
			_taskList.insert(iter, taskToSave);
			isSaved = true;
			break;
		}
	}

	if (!isSaved) {
		_taskList.push_back(taskToSave);
	}

	_taskListToDisplay = _taskList;
	/*_taskListToDisplay.clear();
	for (unsigned int i=0; i<_taskList.size(); ++i) {
		_taskListToDisplay.push_back(_taskList[i]);
	}*/
	//void printTaskToDisplay();
}

void DataStorage::deleteData(double taskID) {
	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) { 
		if (iter->getID() == taskID) {
			_taskList.erase(iter);
			break;
		}
	}

	_taskListToDisplay = _taskList;
	/*_taskListToDisplay.clear();
	for (unsigned int i=0; i<_taskList.size(); ++i) {
		_taskListToDisplay.push_back(_taskList[i]);
	}
	//void printTaskToDisplay();*/
}

bool DataStorage::searchData(string keyword) {
	bool isFound = true;
	 _taskListToDisplay.clear();

	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) {
		string tempDate = iter->getDate();
		string tempStartTime = iter->getStartTime();
		string tempEndTime = iter->getEndTime();
		string tempEvent = iter->getEvent();
		
		if ((tempEvent.find(keyword)!=string::npos)||
			(tempDate.find(keyword)!=string::npos) ||
			(tempStartTime.find(keyword)!=string::npos) ||
			(tempEndTime.find(keyword)!=string::npos)) {
			    _taskListToDisplay.push_back(*iter);
		    }
	}

	if (_taskListToDisplay.empty()) {
		return (isFound = false);
	}

	return isFound;
}

void DataStorage::markData(double taskID, string status) {
	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) {
		if (iter->getID() == taskID) {
			iter->setStatus(status);
			break;
		}
	}

	_taskListToDisplay = _taskList;
}
/*
void DataStorage::printTask() {
	if (_taskList.empty()) {
		cout << "There are no tasks!\n";
	} else {
	for (unsigned int i=0; i<_taskList.size(); i++) {
		cout << i+1 << ". "
			 << _taskList[i].getEvent() << " " 
			 << _taskList[i].getDate() << " "
			 << _taskList[i].getStartTime() << " "
			 << _taskList[i].getEndTime() << " "
			 << _taskList[i].getStatus() << " "
			 << endl;
	}
	}
}

void DataStorage::printTaskToDisplay() {
	if (_taskListToDisplay.empty()) {
		cout << "There are no tasks!\n";
	} else {
	for (unsigned int i=0; i<_taskListToDisplay.size(); i++) {
		cout << i+1 << ". "
			 << _taskListToDisplay[i].getEvent() << " " 
			 << _taskListToDisplay[i].getDate() << " "
			 << _taskListToDisplay[i].getStartTime() << " "
			 << _taskListToDisplay[i].getEndTime() << " "
			 << _taskListToDisplay[i].getStatus() << " "
			 << endl;
	}
	}
}
*/