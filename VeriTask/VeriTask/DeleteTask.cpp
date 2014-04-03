#include "DeleteTask.h"	

void DeleteTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
	int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
	double taskIDToDelete = _dataStorage.retrieveTaskID(taskNum);
	
	_dataStorage.deleteData(taskIDToDelete);
	textUI.printTaskToDisplay(_dataStorage);
	textUI.printDeleteConfirmation();
}