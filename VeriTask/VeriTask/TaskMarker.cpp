//@author A0101039X

#include "TaskMarker.h"	

TaskMarker::TaskMarker(void) {
}

void TaskMarker::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage) {
		string status = infoIdentifier.getStatus();
	    int taskNum = stoi(infoIdentifier.getTaskNum());
		unsigned long long int taskIDToMark = dataStorage.retrieveTaskID(taskNum);

		dataStorage.markData(taskIDToMark, status);
		dataStorage.saveFile();

		//update the task sheet
		vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();
		(updatedTaskListToDisplay.begin() + taskNum - 1)->setStatus(status);
		dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);

}

	