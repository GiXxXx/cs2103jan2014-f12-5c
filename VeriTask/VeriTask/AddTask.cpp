#include "AddTask.h"

void AddTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI, File file) {
	string date = infoIdentifier.GetDate();
	string startTime = infoIdentifier.GetStartTime();
	string endTime = infoIdentifier.GetEndTime();
	string event = infoIdentifier.GetEvent();
	int index= _dataStorage.getTaskIndex();
	Task taskToAdd(event, date, startTime, endTime, index);

	_dataStorage.saveData(taskToAdd);
	file.saveFile(_dataStorage.retrieveTaskList(), _dataStorage.getTaskIndex());
	textUI.printTaskToDisplay(_dataStorage);
	textUI.printAddConfirmation();
}