//@author A0101039X

#include "TaskEditer.h"	

TaskEditer::TaskEditer(void) {
}

void TaskEditer::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage) {
		int taskNum = stoi(infoIdentifier.getTaskNum());
		Task taskSelected = dataStorage.retrieveTask(taskNum);
		unsigned long long int taskIDToEdit = dataStorage.retrieveTaskID(taskNum);
		vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();
	    
		//delete task and update the task sheet on the screen
		dataStorage.deleteData(taskIDToEdit);
		updatedTaskListToDisplay.erase(updatedTaskListToDisplay.begin() + taskNum - 1);

		//obtain the information user wants to edit
		string date = infoIdentifier.getDate();
	    string startTime = infoIdentifier.getStartTime();
	    string endTime = infoIdentifier.getEndTime();
	    string event = infoIdentifier.getEvent();
		string status = taskSelected.getStatus();
		int index = dataStorage.getTaskIndex();
		dataStorage.setTaskIndex(dataStorage.getTaskIndex() + 1);

		//check if the user has input relevant information, if not
		//there will be no change in that part.
		if(date == EMPTY_DATE) {
			date =  taskSelected.getDate();
		}
		if(startTime == EMPTY_TIME) {
			startTime =  taskSelected.getStartTime();
		}
		if(endTime == EMPTY_TIME) {
			endTime =  taskSelected.getEndTime();
		}
		if(event == EMPTY_STRING) {
			event = taskSelected.getEvent();
		}

		//create and save the file with relevant information
		Task taskToEdit(event, date, startTime, endTime, taskSelected.getStatus(), index);
	    dataStorage.saveData(taskToEdit);
		dataStorage.saveFile();

		//if there is a change in the date of the task, refresh the task sheet to
		//display the task of the same date; if there is no change, just refresh the sheet
		if (date != taskSelected.getDate()) {
			dataStorage.searchDate(date);
		} else {
			for (vector<Task>::iterator iter = updatedTaskListToDisplay.begin(); iter < updatedTaskListToDisplay.end(); ++iter) {
				if (iter->getID() > taskToEdit.getID()) {
					updatedTaskListToDisplay.insert(iter, taskToEdit);
					break;
				}
			}
			dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);
		}
}