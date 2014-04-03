#include "DeleteTask.h"	

void DeleteTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI, File file) {
	int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
	double taskIDToDelete = _dataStorage.retrieveTaskID(taskNum);
	
	_dataStorage.deleteData(taskIDToDelete);
	file.saveFile(_dataStorage.retrieveTaskList(), _dataStorage.getTaskIndex());
	textUI.printTaskToDisplay(_dataStorage);
	textUI.printDeleteConfirmation();
}