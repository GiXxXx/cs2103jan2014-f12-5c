#include "AddTask.h"

void AddTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage) {
	string date = infoIdentifier.getDate();
	string startTime = infoIdentifier.getStartTime();
	string endTime = infoIdentifier.getEndTime();
	string event = infoIdentifier.getEvent();
	Task taskToAdd(event, date, startTime, endTime);

	_dataStorage.saveData(taskToAdd);
}