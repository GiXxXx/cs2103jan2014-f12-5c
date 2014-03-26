#include "EditTask.h"	

void EditTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
		int taskNum=std::stoi(infoIdentifier.GetTaskNum());
		double taskIDToEdit = _dataStorage.retrieveTaskID(taskNum);
	
		_dataStorage.deleteData(taskIDToEdit);

		string date = infoIdentifier.GetDate();
	    string startTime = infoIdentifier.GetStartTime();
	    string endTime = infoIdentifier.GetEndTime();
	    string event = infoIdentifier.GetEvent();
	    Task taskToEdit(event, date, startTime, endTime);

	    _dataStorage.saveData(taskToEdit);

		textUI.printTask(_dataStorage);
		textUI.printEditConfirmation();
}