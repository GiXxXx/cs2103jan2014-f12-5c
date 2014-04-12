//@author A0101039X

#include "TaskDeleter.h"	

TaskDeleter::TaskDeleter(void) {
}

void TaskDeleter::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage) {
	int taskNum = stoi(infoIdentifier.getTaskNum());
	unsigned long long int taskIDToDelete = dataStorage.retrieveTaskID(taskNum);
	
	dataStorage.deleteData(taskIDToDelete);
	dataStorage.saveFile();

	vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();
	//update the tasks sheet on the screen by delete the task and refresh the vector
	updatedTaskListToDisplay.erase(updatedTaskListToDisplay.begin() + taskNum - 1);
	dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);
}