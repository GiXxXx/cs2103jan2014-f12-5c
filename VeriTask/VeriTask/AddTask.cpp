#include "AddTask.h"

void AddTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
	string date = infoIdentifier.GetDate();
	string startTime = infoIdentifier.GetStartTime();
	string endTime = infoIdentifier.GetEndTime();
	string event = infoIdentifier.GetEvent();
	int index= dataStorage.getTaskIndex();
	dataStorage.setTaskIndex(dataStorage.getTaskIndex()+1);
	Task taskToAdd(event, date, startTime, endTime, index);

	dataStorage.saveData(taskToAdd);
	dataStorage.saveFile();
	
	dataStorage.searchDataDate(date);
	textUI.printTaskToDisplay(dataStorage);
	textUI.printAddConfirmation();
}