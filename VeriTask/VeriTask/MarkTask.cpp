#include "MarkTask.h"	

void MarkTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage) {
		string status=infoIdentifier.getStatus();
	    int taskNum=infoIdentifier.getTaskNumber();
		double taskIDToMark = _dataStorage.retrieveTaskID(taskNum);

		_dataStorage.markData(taskIDToMark, status);
}

	