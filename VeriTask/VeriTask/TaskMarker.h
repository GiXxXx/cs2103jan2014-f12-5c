//@author A0101039X

/**
* This class is used to perform Mark command from the user.
* It marks the status of the selected task the user chooses. 
* It is the child class of Operation class for command pattern. 
* Sample usage:
* TaskMarker taskMarker;
* taskMarker.executeCommand(infoIdentifier, dataStorage);
*/

#pragma once

#include <vector>
#include <string>
#include "Operation.h"

using namespace std;

class TaskMarker:public Operation {
public:
	TaskMarker(void);

	//This method is used to mark the status of tasks. The status 
	//supported are: undone(default), done, cannot be done and 
	//overdue(marked by system automatically if pass deadline and left
	//undone).
	//Pre-req: information passer (infoIndentifier) and dataStorage
	//Post-req: nil
	void executeCommand(Identifier, DataStorage&);	
};
