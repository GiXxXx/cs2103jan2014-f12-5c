//@author A0101039X

/**
* This class is used to perform Search command from the user.
* It will search for matching information from task event.
* It is the child class of Operation class for command pattern. 
* Sample usage:
* TaskSearcher taskSearcher;
* taskSearcher.executeCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <string>
#include "Operation.h"

using namespace std;

class TaskSearcher:public Operation {
public:
	TaskSearcher(void);

	//This method is used to search for matching tasks based on the 
	//keywords from the user. It searches task description.
	//Pre-req: information passer (infoIndentifier) and dataStorage
	//Post-req: nil
	void executeCommand(Identifier, DataStorage&);	
};
