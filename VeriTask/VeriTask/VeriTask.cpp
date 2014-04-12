//@author A0101039X

#include "VeriTask.h"

VeriTask::VeriTask() {
	_commandCount = 0;
};

VeriTask::~VeriTask() {
	delete _newOperation;
};

void VeriTask::doCommand(string commandWord, Identifier infoIdentifier, DataStorage& dataStorage) {
	if ((commandWord != UNDO_COMMAND) || (commandWord != REDO_COMMAND)) {
		_undoList.push_back(dataStorage);
		
		//using command pattern
		if (commandWord == ADD_COMMAND) {
			_newOperation = new TaskAdder;
		} else if (commandWord == DELETE_COMMAND) {
			_newOperation = new TaskDeleter;
		} else if (commandWord == EDIT_COMMAND) {
			_newOperation = new TaskEditer;
		} else if (commandWord == SEARCH_COMMAND) {
			_newOperation = new TaskSearcher;
		} else if (commandWord == MARK_COMMAND) {
			_newOperation = new TaskMarker;
		} else if (commandWord == DISPLAY_COMMAND) {
			_newOperation = new TaskDisplayer;
		}

		_newOperation->executeCommand(infoIdentifier, dataStorage);
		_commandCount++;
		_redoList.clear();

	} else if (commandWord == UNDO_COMMAND) {
		_undoCommand(dataStorage);
	} else if (commandWord == REDO_COMMAND) {
		_redoCommand(dataStorage);
	}
}

