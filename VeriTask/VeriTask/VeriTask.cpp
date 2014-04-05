#include "VeriTask.h"

VeriTask::VeriTask(DataStorage& dataStorage) {
	undoList.push_back(dataStorage);
};

VeriTask::~VeriTask() {};

void VeriTask::pushCommand(string commandWord, Identifier infoIdentifier, TextUI textUI, DataStorage& dataStorage) {
	Command* newTask;
	if (commandWord == ADD_COMMAND) {
		newTask = new AddTask;
	}
	if (commandWord == DELETE_COMMAND) {
		newTask = new DeleteTask;
	}
	if (commandWord == EDIT_COMMAND) {
		newTask = new EditTask;
	}
	if (commandWord == SEARCH_COMMAND) {
		newTask = new SearchTask;
	}
	if (commandWord == MARK_COMMAND) {
		newTask = new MarkTask;
	}
	if (commandWord == "exit") { // change it
		return;
	}
	
	if (commandWord != UNDO_COMMAND) {
		commandList.push_back(newTask);
	    commandList.back()->executeCommand(infoIdentifier, dataStorage, textUI);
	    undoList.push_back(dataStorage);
	}

	if (commandWord == UNDO_COMMAND) {
		undoList.pop_back();
	    DataStorage newDataStorage = undoList.back();
		commandList.pop_back();
		textUI.printTaskToDisplay(newDataStorage);
	}	
}

