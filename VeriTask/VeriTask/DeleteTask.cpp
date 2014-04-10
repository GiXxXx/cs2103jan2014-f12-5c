#include "DeleteTask.h"	

void DeleteTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
	int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
	unsigned long long int taskIDToDelete = dataStorage.retrieveTaskID(taskNum);
	string date = dataStorage.retrieveTask(taskNum).getDate();
	dataStorage.deleteData(taskIDToDelete);
	dataStorage.saveFile();
	//dataStorage.searchDataDate(date);

	vector<Task> updatedTaskListToDisplay = dataStorage.retrieveTaskListToDisplay();//
	updatedTaskListToDisplay.erase(updatedTaskListToDisplay.begin() + taskNum - 1);//
	dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);//

	//textUI.printTaskToDisplay(dataStorage);
	//textUI.printDeleteConfirmation();
}