//@author A0101039X

#include "TaskSearcher.h"	

TaskSearcher::TaskSearcher(void) {
}

void TaskSearcher::executeCommand(Identifier infoIdentifier, DataStorage &dataStorage) {
	string keyword = infoIdentifier.getKeyword();
	dataStorage.searchData(keyword);
}
