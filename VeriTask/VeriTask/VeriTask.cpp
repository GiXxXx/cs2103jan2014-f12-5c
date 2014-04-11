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
		cout << "asdasdasdasfsedfsdfsdfdgsdg1" << endl;
		newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		cout << "asdasdasdasfsedfsdfsdfdgsdg2" << endl;
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
	if (commandWord == "exit") { // change it
		return;
	}
	
	if (commandWord != UNDO_COMMAND) {
		//newTask->executeCommand(infoIdentifier, dataStorage, textUI);
		commandList.push_back(newTask);
	   // commandList.back()->executeCommand(infoIdentifier, dataStorage, textUI);
	    undoList.push_back(dataStorage);
	}

	if (commandWord == UNDO_COMMAND) {
		undoList.pop_back();
	    DataStorage newDataStorage = undoList.back();
		commandList.pop_back();
		textUI.printTaskToDisplay(newDataStorage);
	}	
}

