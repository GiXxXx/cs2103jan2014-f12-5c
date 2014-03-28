#include "EditTask.h"	

void EditTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
		int taskNum=std::stoi(infoIdentifier.GetTaskNum());
		double taskIDToEdit = _dataStorage.retrieveTaskID(taskNum);
		Task temp = _dataStorage.retrieveTask(taskNum);
	
		_dataStorage.deleteData(taskIDToEdit);

		string date = infoIdentifier.GetDate();
	    string startTime = infoIdentifier.GetStartTime();
	    string endTime = infoIdentifier.GetEndTime();
	    string event = infoIdentifier.GetEvent();

		if(date == "        "){
			date = temp.getDate();
		}

		if(startTime == "    "){
			startTime = temp.getStartTime();
		}

		if(endTime == "    "){
			endTime = temp.getEndTime();
		}

		if(event == ""){
			event = temp.getEvent();
		}

		Task taskToEdit(event, date, startTime, endTime);
	    _dataStorage.saveData(taskToEdit);

		textUI.printTask(_dataStorage);
		textUI.printEditConfirmation();
}