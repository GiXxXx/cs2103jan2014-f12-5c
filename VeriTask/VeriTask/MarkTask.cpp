#include "MarkTask.h"	

void MarkTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
		string status=infoIdentifier.GetStatus();
	    int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
		unsigned long long int taskIDToMark = dataStorage.retrieveTaskID(taskNum);
		string date = dataStorage.retrieveTask(taskIDToMark).getDate();

		dataStorage.markData(taskIDToMark, status);
		dataStorage.saveFile();
		dataStorage.searchDataDate(date);
		//textUI.printTaskToDisplay(dataStorage);
		//textUI.printMarkConfirmation();
}

	