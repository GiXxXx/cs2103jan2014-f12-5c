//@author A0101039X

/**
* This class is used to perform Display command from the user.
* It will display relevant information based on user's request.
* It can: display all tasks, display tasks of a certain day,
* display tasks of certain status.
* Sample usage:
* TaskDisplayer taskDisplayer;
* taskDisplayer.executeCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <vector>
#include <string>
#include "Operation.h"

using namespace std;

//const string EMPTY_DATE = "        ";
//const string EMPTY_STRING = "";
//const string ALL = "all";


class TaskDisplayer: public Operation {
public:
	TaskDisplayer(void);

	//This method is used to display tasks based on the keyword from
	//the user. It can display all tasks, tasks on a particular day or status.
	//Pre-req: information passer (infoIndentifier) and dataStorage
	//Post-req: nil
	void executeCommand(Identifier, DataStorage&);	
};

