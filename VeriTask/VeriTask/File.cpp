#include "File.h"

File::File(void){
}


File::~File(void){
}

int File::accessIndex() {
	string taskIndex;
	ifstream readFile(FILENAME.c_str());

	getline(readFile, taskIndex);
	if (taskIndex == "") {
		return 0;
	}

	int taskIndex_int = stoi(taskIndex);

	readFile.close();
	return taskIndex_int;
}


vector<Task> File::accessFile() {
	vector<Task> taskList;
	string date, startTime, endTime, event, status, index, taskIndex;
	int index_int;
	ifstream readFile(FILENAME.c_str());
	
	getline(readFile, taskIndex);

	while(getline(readFile, event)){
		getline(readFile, date);
		getline(readFile, startTime);
		getline(readFile, endTime);
		getline(readFile, status);
		getline(readFile, index);
	    index_int = stoi(index);

		Task task(event, date, startTime, endTime, index_int);
		taskList.push_back(task);
	}

	readFile.close();
	return taskList;
}

void File::saveFile(vector<Task> taskList, int taskIndex) {
	string date, startTime, endTime, event, status;
	int index;

	ofstream write(FILENAME.c_str());
	write << taskIndex << endl;

	for (unsigned int i=0; i<taskList.size(); ++i) {
		date = taskList[i].getDate();
		startTime = taskList[i].getStartTime();
		endTime = taskList[i].getEndTime();
		event = taskList[i].getEvent();
		status = taskList[i].getStatus();
		index = taskList[i].getIndex();
		
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
