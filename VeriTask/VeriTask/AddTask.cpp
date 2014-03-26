#include "AddTask.h"

void AddTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
	string date = infoIdentifier.GetDate();
	string startTime = infoIdentifier.GetStartTime();
	string endTime = infoIdentifier.GetEndTime();
	string event = infoIdentifier.GetEvent();
	Task taskToAdd(event, date, startTime, endTime);

	_dataStorage.saveData(taskToAdd);
	textUI.printTask(_dataStorage);
	textUI.printAddConfirmation();
}