//@author A0101039X

#include "TaskDisplayer.h"


TaskDisplayer::TaskDisplayer(void) {
}


void TaskDisplayer::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage) {
	//retrieve relevant user input
	string date = infoIdentifier.getDate();
	string status = infoIdentifier.getStatus();

	//display tasks of a certain date
	if (date != EMPTY_DATE) {
		dataStorage.searchDate(date);
	}

	//display tasks based on status
	if (status !=EMPTY_STRING) {
		if (status == ALL) {
			dataStorage.searchData(EMPTY_STRING);
		} else {
		    dataStorage.searchStatus(status);
	    }

	//display all tasks
	if (date == EMPTY_DATE && status == EMPTY_STRING) {
		dataStorage.searchData(EMPTY_STRING);
		}
	}
}