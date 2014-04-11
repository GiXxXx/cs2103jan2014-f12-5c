#include "VeriTask.h"

VeriTask::VeriTask(/*DataStorage& dataStorage*/) {
	//undoList.push_back(dataStorage);
};

VeriTask::~VeriTask() {};

void VeriTask::pushCommand(string commandWord, Identifier infoIdentifier, TextUI textUI, DataStorage& dataStorage) {
	Command* newTask;
	cout << commandWord <<" = " << ADD_COMMAND <<  endl;
	if (commandWord == ADD_COMMAND) {
		newTask = new AddTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
	}
	if (commandWord == DELETE_COMMAND) {
		newTask = new DeleteTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
	}
	if (commandWord == EDIT_COMMAND) {
		newTask = new EditTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
	}
	if (commandWord == SEARCH_COMMAND) {
		newTask = new SearchTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
	}
	if (commandWord == MARK_COMMAND) {
		newTask = new MarkTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
	}
	if (commandWord == DISPLAY_COMMAND) {
		newTask = new TaskDisplayer;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
	}
	if (commandWord == "exit") { // change it
		return;
	}
	
	if (commandWord != UNDO_COMMAND) {
		//newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandList.push_back(newTask);
	   // commandList.back()->executeCommand(infoIdentifier, dataStorage, textUI);
	    taskListVector.push_back(dataStorage.retrieveTaskList());
		taskListToDisplayVector.push_back(dataStorage.retrieveTaskListToDisplay());
		taskIndexVector.push_back(dataStorage.getTaskIndex());
	}

	if (commandWord == UNDO_COMMAND) {
		taskListVector.pop_back();
		taskListToDisplayVector.pop_back();
		taskIndexVector.pop_back();
	    vector<Task> updatedTaskList = taskListVector.back();
		vector<Task> updatedTaskListToDisplay = taskListToDisplayVector.back();
		int newTaskIndex = taskIndexVector.back();
		dataStorage.updateTaskList(updatedTaskList);
		dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);
		dataStorage.setTaskIndex(newTaskIndex);
		//commandList.pop_back();
		//textUI.printTaskToDisplay(newDataStorage);
	}	
}

