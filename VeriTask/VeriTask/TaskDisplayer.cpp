#include "TaskDisplayer.h"


TaskDisplayer::TaskDisplayer(void) {
}


TaskDisplayer::~TaskDisplayer(void) {
}

void TaskDisplayer::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
	string date = infoIdentifier.GetDate();
	string startTime = infoIdentifier.GetStartTime();
	string endTime = infoIdentifier.GetEndTime();
	string event = infoIdentifier.GetEvent();
	string keyword = infoIdentifier.GetKeyword();
	string status = infoIdentifier.GetStatus();
	bool isFound;

	if (date != "        ") {
		isFound = dataStorage.searchDataDate(keyword);
		if (isFound) {
			textUI.printSearchConfirmationYes();
			textUI.printTaskToDisplay(dataStorage);
		} else {
			textUI.printSearchConfirmationNo();
		}
	}
	if (status !="no status") {
		isFound = dataStorage.searchDataStatus(keyword);
		if (isFound) {
			textUI.printSearchConfirmationYes();
			textUI.printTaskToDisplay(dataStorage);
		} else {
			textUI.printSearchConfirmationNo();
		}
	}
	if (date == "        " || status == "no status") {
		textUI.printTask();
		}
	}
}