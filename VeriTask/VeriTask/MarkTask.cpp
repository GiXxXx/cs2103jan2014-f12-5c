#include "MarkTask.h"	

void MarkTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI, File file) {
		string status=infoIdentifier.GetStatus();
	    int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
		unsigned long long taskIDToMark = _dataStorage.retrieveTaskID(taskNum);

		_dataStorage.markData(taskIDToMark, status);
		file.saveFile(_dataStorage.retrieveTaskList(), _dataStorage.getTaskIndex());
		textUI.printTaskToDisplay(_dataStorage);
		textUI.printMarkConfirmation();
}

	