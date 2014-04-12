//@author A0101039X

#include "TaskAdder.h"

TaskAdder::TaskAdder(void) {
}

void TaskAdder::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage) {
	//extract necessary information to create a new task
	string date = infoIdentifier.getDate();
	string startTime = infoIdentifier.getStartTime();
	string endTime = infoIdentifier.getEndTime();
	string event = infoIdentifier.getEvent();
	string status = UNDONE;	//defacult status of all status are undone
	int index = dataStorage.getTaskIndex();

	Task taskToAdd(event, date, startTime, endTime, UNDONE, index);
	dataStorage.saveData(taskToAdd);
	dataStorage.saveFile();
	
	//increase the running index in dataStorage by 1 as one new task is added
	dataStorage.setTaskIndex(dataStorage.getTaskIndex() + 1);

	//display all the tasks of the same date on the task sheet 
	dataStorage.searchDate(date);
}