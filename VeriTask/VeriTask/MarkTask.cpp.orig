#include "MarkTask.h"	

void MarkTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
		string status=infoIdentifier.GetStatus();
	    int taskNum=std::stoi(infoIdentifier.GetTaskNum());
		unsigned long long int taskIDToMark = dataStorage.retrieveTaskID(taskNum);
		string date = dataStorage.retrieveTask(taskNum).getDate();

		dataStorage.markData(taskIDToMark, status);
		dataStorage.saveFile();
		//dataStorage.searchDataDate(date);
		vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();//
		(updatedTaskListToDisplay.begin() + taskNum - 1)->setStatus(status);//
		dataStorage.setTaskListToDisplay(updatedTaskListToDisplay);//
		//textUI.printTaskToDisplay(dataStorage);
		//textUI.printMarkConfirmation();
}

	