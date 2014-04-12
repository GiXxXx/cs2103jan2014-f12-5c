//@author A0101039X

/**
* This class is used to perform Edit command from the user.
* It edits the selected task the user chooses from the storage. 
* It is the child class of Operation class for command pattern. 
* Sample usage:
* TaskEditer taskEditer;
* taskEditer.executeCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <vector>
#include <string>
#include "Operation.h"

using namespace std;

//const string EMPTY_DATE = "        ";
//const string EMPTY_TIME = "    ";
//const string EMPTY_STRING = "";

class TaskEditer:public Operation {
public:
	TaskEditer(void);

	//This method is used to perform edition of tasks from
	//our storage, dataStorage. Task selected is located in dataStorage
	//by taskID and then deleted. New information from the user is 
	//used to create a new task and it is added back to dataStorage.
	//Pre-req: information passer (infoIndentifier) and dataStorage
	//Post-req: nil
	void executeCommand(Identifier, DataStorage &);	
};
