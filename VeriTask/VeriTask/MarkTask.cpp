#include "MarkTask.h"	

void MarkTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
		string status=infoIdentifier.GetStatus();
	    int taskNum=std::stoi(infoIdentifier.GetTaskNum());;
		double taskIDToMark = _dataStorage.retrieveTaskID(taskNum);

		_dataStorage.markData(taskIDToMark, status);

		textUI.printTaskToDisplay(_dataStorage);
		textUI.printMarkConfirmation();
}

	