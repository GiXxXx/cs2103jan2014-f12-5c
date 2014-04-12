#include "DataStorage.h"

DataStorage::DataStorage() {
	_fileName = FILENAME;

	string date, startTime, endTime, event, status, index, taskIndex;
	int index_int;
	
	struct tm timeNow;
	time_t localTime = time(NULL);

	localtime_s(&timeNow, &localTime);

	int localYear = timeNow.tm_year + 1900;
	int localMonth = timeNow.tm_mon + 1;
	int localDate = timeNow.tm_mday;
	int localHour = timeNow.tm_hour;
	int localMin = timeNow.tm_min;
	
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
	
	/*if (date != "        ") {
	if (localYear*10000+localMonth*100+localDate > stoi(date)) {
		task.setStatus("overdue");
	} else if (localYear*10000+localMonth*100+localDate == stoi(date)) {
		if ((startTime != "    ") && (endTime == "    ")) {
			if ((localHour*100+localMin) > stoi(startTime)) {
				task.setStatus("overdue");
			}
		}
		if ((startTime != "    ") && (endTime != "    ")) {
			if ((localHour*100+localMin) > stoi(endTime)) {
				task.setStatus("overdue");
			}
		}
	}
	}*/

	_taskList.push_back(task);
	if ((date == "        ") || localYear*10000+localMonth*100+localDate == std::stoi(date)) {
		_taskListToDisplay.push_back(task);
	}
}
	readFile.close();
	/*if (_taskListToDisplay.empty()) {
		cout << "No match!\n";
	} else {
	for (unsigned int i=0; i<_taskListToDisplay.size(); i++) {
		cout << i+1 << ". "
			 << _taskListToDisplay[i].getEvent() << " " 
			 << _taskListToDisplay[i].getDate() << " "
			 << _taskListToDisplay[i].getStartTime() << " "
			 << _taskListToDisplay[i].getEndTime() << " "
			 << _taskListToDisplay[i].getStatus() << " "
			 << endl;*/
	
	
}

DataStorage::DataStorage(string fileName) {
	_fileName = fileName;

	string date, startTime, endTime, event, status, index, taskIndex;
	int index_int;
	
	ifstream readFile(_fileName.c_str());

	getline(readFile, taskIndex);

	if (taskIndex.size() == 0) {
		_taskIndex = 0;
	} else {
		 _taskIndex = stoi(taskIndex);
	}

	while(getline(readFile, event)){
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


vector<Task> DataStorage::retrieveTaskList() {
	return _taskList;
}

vector<Task> DataStorage::retrieveTaskListToDisplay() {
	return _taskListToDisplay;
}

unsigned long long int DataStorage::retrieveTaskID(int taskNum) {
	unsigned long long int taskID = _taskListToDisplay[taskNum-1].getID();
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

	string date = taskToSave.getDate();
	searchDataDate(date);

	//_taskListToDisplay = _taskList;
	/*_taskListToDisplay.clear();
	for (unsigned int i=0; i<_taskList.size(); ++i) {
		_taskListToDisplay.push_back(_taskList[i]);
	}*/
	//void printTaskToDisplay();
}

void DataStorage::deleteData(unsigned long long int taskID) {
	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) { 
		if (iter->getID() == taskID) {
			_taskList.erase(iter);
			break;
		}
	}

	//_taskListToDisplay = _taskList;
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

bool DataStorage::searchDataDate(string keyword) {
	bool isFound = true;
	 _taskListToDisplay.clear();

	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) {
		string tempDate = iter->getDate();
		
		if (tempDate.find(keyword)!=string::npos) {
			    _taskListToDisplay.push_back(*iter);
		    }

		if (tempDate == "        ") {
			_taskListToDisplay.push_back(*iter);
		}

	}

	if (_taskListToDisplay.empty()) {
		return (isFound = false);
	}

	return isFound;
}

bool DataStorage::searchDataStatus(string keyword) {
	bool isFound = true;
	 _taskListToDisplay.clear();

	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) {
		string tempStatus = iter->getStatus();
		
		if (tempStatus == keyword) {
			    _taskListToDisplay.push_back(*iter);
		    }
	}

	if (_taskListToDisplay.empty()) {
		return (isFound = false);
	}

	return isFound;
}


void DataStorage::markData(unsigned long long int taskID, string status) {
	for (iter=_taskList.begin(); iter<_taskList.end(); ++iter) {
		if (iter->getID() == taskID) {
			iter->setStatus(status);
			break;
		}
	}

	//_taskListToDisplay = _taskList;
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
	return;
}

void DataStorage::setTaskIndex(int taskIndex) {
	_taskIndex = taskIndex;
}

int DataStorage::getTaskIndex() {
	return _taskIndex;
}

void DataStorage::updateTaskList(vector<Task> taskList){
	_taskList = taskList;
}

void DataStorage::updateTaskListToDisplay(vector<Task> taskListToDisplay){
	_taskListToDisplay = taskListToDisplay;
}