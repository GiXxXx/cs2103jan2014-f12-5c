#include "AddTask.h"

void AddTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
	string date = infoIdentifier.GetDate();
	string startTime = infoIdentifier.GetStartTime();
	string endTime = infoIdentifier.GetEndTime();
	string event = infoIdentifier.GetEvent();
	string status = UnDone;
	int index= dataStorage.getTaskIndex();
	dataStorage.setTaskIndex(dataStorage.getTaskIndex()+1);
	Task taskToAdd(event, date, startTime, endTime, UnDone, index);

	dataStorage.saveData(taskToAdd);
	dataStorage.saveFile();

	dataStorage.searchDataDate(date);
	textUI.printTaskToDisplay(dataStorage);
	textUI.printAddConfirmation();
}