#include "EditTask.h"	

void EditTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI, File file) {
		int taskNum=std::stoi(infoIdentifier.GetTaskNum());
		unsigned long long taskIDToEdit = _dataStorage.retrieveTaskID(taskNum);
		Task temp = _dataStorage.retrieveTask(taskNum);
	
		_dataStorage.deleteData(taskIDToEdit);

		string date = infoIdentifier.GetDate();
	    string startTime = infoIdentifier.GetStartTime();
	    string endTime = infoIdentifier.GetEndTime();
	    string event = infoIdentifier.GetEvent();
		int index = _dataStorage.getTaskIndex();

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

		Task taskToEdit(event, date, startTime, endTime, index);
	    _dataStorage.saveData(taskToEdit);
		file.saveFile(_dataStorage.retrieveTaskList(), _dataStorage.getTaskIndex());
		textUI.printTaskToDisplay(_dataStorage);
		textUI.printEditConfirmation();
}