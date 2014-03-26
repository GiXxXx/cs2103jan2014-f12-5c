#include "SearchTask.h"	

void SearchTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage, TextUI textUI) {
	bool isFound;
	string keyword=infoIdentifier.GetKeyword();
	isFound = _dataStorage.searchData(keyword);
	if (!isFound) {
		cout << "Not Found!\n";
	}
}
