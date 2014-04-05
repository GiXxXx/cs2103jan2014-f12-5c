#ifndef HEADER_COMMAND_
#define HEADER_COMMAND_
#include "DataStorage.h"
#include "Identifier.h"
#include "TextUI.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const string ADD_COMMAND = "add";
const string DELETE_COMMAND = "delete";
const string EDIT_COMMAND = "edit";
const string SEARCH_COMMAND = "search";
const string MARK_COMMAND = "mark";
const string UNDO_COMMAND = "undo";
const string ERROR_MESSAGE = "Invalid Command";

class Command {
protected:

public:
    virtual void executeCommand(Identifier, DataStorage &, TextUI textUI, File file);
	void pushCommand(string);

};

#endif