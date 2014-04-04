#include "VeriTask.h"

VeriTask::VeriTask(File file) {
	int taskIndex;
	vector<Task> taskList = file.accessFile();
	_dataStorage.fillData(taskList);
	if (file.accessIndex() == 0) {
		taskIndex = 1;
	} else {
	      taskIndex =file.accessIndex();
	}
	
	_dataStorage.setTaskIndex(taskIndex);
	undoList.push_back(_dataStorage);
};

VeriTask::~VeriTask() {};

void VeriTask::pushCommand(string commandWord, Identifier infoIdentifier, TextUI textUI, File file) {
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
	    commandList.back()->executeCommand(infoIdentifier, _dataStorage, textUI, file);
	    undoList.push_back(_dataStorage);
	}

	if (commandWord == UNDO_COMMAND) {
		undoList.pop_back();
	    _dataStorage = undoList.back();
		commandList.pop_back();
		textUI.printTaskToDisplay(_dataStorage);
	}	
}

DataStorage VeriTask::getDataStorage() {
	return _dataStorage;
}
