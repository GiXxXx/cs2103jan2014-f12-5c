#include "EditTask.h"	

void EditTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
		int taskNum=std::stoi(infoIdentifier.GetTaskNum());
		unsigned long long int taskIDToEdit = dataStorage.retrieveTaskID(taskNum);
		vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();
		vector<Task>::iterator iter;
		Task temp = dataStorage.retrieveTask(taskNum);
	
		dataStorage.deleteData(taskIDToEdit);
		updatedTaskListToDisplay.erase(updatedTaskListToDisplay.begin()+taskNum-1);

		string date = infoIdentifier.GetDate();
	    string startTime = infoIdentifier.GetStartTime();
	    string endTime = infoIdentifier.GetEndTime();
	    string event = infoIdentifier.GetEvent();
		string status = UnDone;
		int index = dataStorage.getTaskIndex();
		dataStorage.setTaskIndex(dataStorage.getTaskIndex()+1);

		if(date == "        "){
			date = temp.getDate();
		}

		if(startTime == "    "){
			startTime = temp.getStartTime();
		}

		if(endTime == "    "){
			endTime = temp.getEndTime();
		}

		if(event == ""){
			event = temp.getEvent();
		}

		Task taskToEdit(event, date, startTime, endTime, UnDone, index);
	    dataStorage.saveData(taskToEdit);
		dataStorage.saveFile();
	//	dataStorage.searchDataDate(date);
	/*	vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();//
		(updatedTaskListToDisplay.begin() + (taskNum - 1))->setDate(date);//
		(updatedTaskListToDisplay.begin() + (taskNum - 1))->setStartTime(startTime);//
		(updatedTaskListToDisplay.begin() + (taskNum - 1))->setEndTime(endTime);//
		(updatedTaskListToDisplay.begin() + (taskNum - 1))->setEvent(event);//*/

		for (iter=updatedTaskListToDisplay.begin(); iter<updatedTaskListToDisplay.end(); ++iter) {
		if (iter->getID() > taskToEdit.getID()) {
			updatedTaskListToDisplay.insert(iter, taskToEdit);
			break;
		}
	}
		dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);//

		//textUI.printTaskToDisplay(dataStorage);
		//textUI.printEditConfirmation();
}