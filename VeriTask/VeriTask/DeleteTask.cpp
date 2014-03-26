#include "DeleteTask.h"	

void DeleteTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage) {
	int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
	double taskIDToDelete = _dataStorage.retrieveTaskID(taskNum);
	
	_dataStorage.deleteData(taskIDToDelete);
	textUI.printDeleteConfirmation();
}