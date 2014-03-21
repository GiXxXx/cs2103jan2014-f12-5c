#ifndef HEADER_VERITASK_
#define HEADER_VERITASK_
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Identifier.h"
#include "Task.h"

using namespace std;

const string ADD_COMMAND = "add";
const string DELETE_COMMAND = "delete";
const string EDIT_COMMAND = "edit";
const string SEARCH_COMMAND = "search";
const string MARK_COMMAND = "mark";
const string ERROR_MESSAGE = "Invalid Command";

enum CommandType {
	ADD, DELETE, EDIT, SEARCH, MARK, INVALID
};

class VeriTask {

private:
	vector<Task> _taskList;
	vector<Task> _taskListToDisplay;
	Identifier _commandIdentifier(string);

public:
	VeriTask(); //default constructor
	CommandType determineCommand(string);
	void doCommand(CommandType, Identifier);
	void executeCommand(string, Identifier);
	void addTask(Task);
	void deleteTask(int);
	//void editTask(string, int);
	//vector<Task> showTask(); //combine it with confirmation info
	void searchTask(string);
	//void undoCommand();
	//void markTask(string, int);
	void printTask();

};

#endif