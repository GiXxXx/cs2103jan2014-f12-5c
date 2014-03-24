#include "VeriTask.h"

VeriTask::VeriTask() {};

VeriTask::~VeriTask() {};

void VeriTask::pushCommand(string commandWord, Identifier infoIdentifier) {
	if (commandWord == ADD_COMMAND) {
		commandList.push_back(new AddTask);
	}
	if (commandWord == DELETE_COMMAND) {
		commandList.push_back(new DeleteTask);
	}
	if (commandWord == EDIT_COMMAND) {
		commandList.push_back(new EditTask);
	}
	if (commandWord == SEARCH_COMMAND) {
		commandList.push_back(new SearchTask);
	}
	if (commandWord == MARK_COMMAND) {
		commandList.push_back(new MarkTask);
	}
	if (commandWord == "exit") { // change it
		return;
	} 
	
	int i=commandList.size();
	commandList[i-1]->executeCommand(infoIdentifier, _dataStorage);
	undoList.push_back(_dataStorage);

}