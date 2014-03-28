#include "AddTask.h"

void AddTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
	string date = infoIdentifier.GetDate();
	string startTime = infoIdentifier.GetStartTime();
	string endTime = infoIdentifier.GetEndTime();
	string event = infoIdentifier.GetEvent();
	int index= infoIdentifier.getIndex();
	Task taskToAdd(event, date, startTime, endTime, index);

	_dataStorage.saveData(taskToAdd);
	textUI.printTaskToDisplay(_dataStorage);
	textUI.printAddConfirmation();
}