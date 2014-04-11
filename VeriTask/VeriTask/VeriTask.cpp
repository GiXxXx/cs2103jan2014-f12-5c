#include "VeriTask.h"

VeriTask::VeriTask(/*DataStorage& dataStorage*/) {
	//undoList.push_back(dataStorage);
	commandCount = 0;
};

VeriTask::~VeriTask() {};

void VeriTask::pushCommand(string commandWord, Identifier infoIdentifier, TextUI textUI, DataStorage& dataStorage) {
	Command* newTask;

	if (commandWord == ADD_COMMAND) {
		undoList.push_back(dataStorage);
		newTask = new AddTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandCount++;
		redoList.clear();
	}
	if (commandWord == DELETE_COMMAND) {
		undoList.push_back(dataStorage);
		newTask = new DeleteTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandCount++;
		redoList.clear();
	}
	if (commandWord == EDIT_COMMAND) {
		undoList.push_back(dataStorage);
		newTask = new EditTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandCount++;
		redoList.clear();
	}
	if (commandWord == SEARCH_COMMAND) {
		undoList.push_back(dataStorage);
		newTask = new SearchTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandCount++;
		redoList.clear();
	}
	if (commandWord == MARK_COMMAND) {
		undoList.push_back(dataStorage);
		newTask = new MarkTask;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandCount++;
		redoList.clear();
	}
	if (commandWord == DISPLAY_COMMAND) {
		undoList.push_back(dataStorage);
		newTask = new TaskDisplayer;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandCount++;
		redoList.clear();
	}
	
	if (commandWord == UNDO_COMMAND) {
		//newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		//undoList.push_back(dataStorage);
		//commandList.push_back(newTask);
	   // commandList.back()->executeCommand(infoIdentifier, dataStorage, textUI);
	   // taskListVector.push_back(dataStorage.retrieveTaskList());
		//taskListToDisplayVector.push_back(dataStorage.retrieveTaskListToDisplay());
		//taskIndexVector.push_back(dataStorage.getTaskIndex());
		//newTask = new TaskUndoRedoer;
		//newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		redoList.push_back(dataStorage);
		dataStorage = undoList.back();
		undoList.pop_back();
		commandCount--;
	}

	if (commandWord == REDO_COMMAND) {
	//	taskListVector.pop_back();
	//	taskListToDisplayVector.pop_back();
	//	taskIndexVector.pop_back();
	   // redoList.push_back();
	//	undoList.pop_back();
	//	dataStorage = undoList.back();
	//	vector<Task> updatedTaskList = taskListVector.back();
	//	vector<Task> updatedTaskListToDisplay = taskListToDisplayVector.back();
	//	int newTaskIndex = taskIndexVector.back();
		//dataStorage.updateTaskList(updatedTaskList);
		//dataStorage.updateTaskListToDisplay(updatedTaskListToDisplay);
		//dataStorage.setTaskIndex(newTaskIndex);
		//commandList.pop_back();
		//textUI.printTaskToDisplay(newDataStorage);
		//newTask = new TaskUndoRedoer;
		//newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		undoList.push_back(dataStorage);
		dataStorage = redoList.back();
		redoList.pop_back();
		commandCount++;
	}	
}

