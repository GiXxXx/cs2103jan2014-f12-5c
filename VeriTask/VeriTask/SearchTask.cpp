#include "SearchTask.h"	

void SearchTask::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage, TextUI textUI) {
	bool isFound;
	string keyword=infoIdentifier.GetKeyword();
	isFound = dataStorage.searchData(keyword);
	if (!isFound) {
		//textUI.printSearchConfirmationNo();
	} else {
		//textUI.printSearchConfirmationYes();
		//textUI.printTaskToDisplay(dataStorage);
	}
}
