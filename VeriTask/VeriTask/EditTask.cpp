#include "EditTask.h"	

void EditTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage) {
		int taskNum=infoIdentifier.getTaskNumber();
		double taskIDToEdit = _dataStorage.retrieveTaskID(taskNum);
	
		_dataStorage.deleteData(taskIDToEdit);

		string date = infoIdentifier.getDate();
	    string startTime = infoIdentifier.getStartTime();
	    string endTime = infoIdentifier.getEndTime();
	    string event = infoIdentifier.getEvent();
	    Task taskToEdit(event, date, startTime, endTime);

	    _dataStorage.saveData(taskToEdit);
}