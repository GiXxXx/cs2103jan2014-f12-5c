#include "DeleteTask.h"	

void DeleteTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
	int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
	unsigned long long int taskIDToDelete = dataStorage.retrieveTaskID(taskNum);
	
	dataStorage.deleteData(taskIDToDelete);
	dataStorage.saveFile();
	textUI.printTaskToDisplay(dataStorage);
	textUI.printDeleteConfirmation();
}