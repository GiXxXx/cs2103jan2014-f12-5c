#include "SearchTask.h"	

void SearchTask::executeCommand(Identifier infoIdentifier, DataStorage &_dataStorage) {
	bool isFound;
	string keyword=infoIdentifier.getKeyword();
	isFound = _dataStorage.searchData(keyword);
	if (!isFound) {
		cout << "Not Found!\n";
	}
}
