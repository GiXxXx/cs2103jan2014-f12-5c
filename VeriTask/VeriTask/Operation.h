//@author A0101039X

/**
* This class is the parent class of all user-operation classes,
* which are TaskAdder, TaskDeleter, TaskEditer, TaskSearcher, 
* TaskMarker, TaskDisplayer. It employs command pattern.
*/

#pragma once

#include "DataStorage.h"
#include "Identifier.h"

using namespace std;

const string ADD_COMMAND = "add";
const string DELETE_COMMAND = "delete";
const string EDIT_COMMAND = "edit";
const string SEARCH_COMMAND = "search";
const string MARK_COMMAND = "mark";
const string DISPLAY_COMMAND = "display";
const string UNDO_COMMAND = "undo";
const string REDO_COMMAND = "redo";



class Operation {
public:
	Operation(void);

	//this is the virtual function used to call its child classes' methods
	//Pre-req: information passer, infoIndentifier and DataStorage
	//Post-req: nil
    virtual void executeCommand(Identifier, DataStorage&);
};
